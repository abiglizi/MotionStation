/****************************************************************************
*****************************************************************************
    birdcmds        - Bird Command Routines

    written for:    Ascension Technology Corporation
		    PO Box 527
		    Burlington, Vermont  05402
			 802-655-7879

    by:             Vlad Kogan


    Modification History:
1/13/96  vk..the new file asuming either ISA or serial interface released.
2/2/96   vk..bird_xonxoff() changed not to send XON/XOFF command if ISA interface
	 isa in use, because it's illegal ISA command.
2/13/96  vk..Bug fixed in showfbbconfig(). When formed words from
	 sequential bytes used to do like this:

	 j = *(unsigned char *)&fbbconfig[5] +
		((*(unsigned char *)&fbbconfig[6]) >> 8),

	meaning that all bits of the 2nd byte disappeare
	instead of going to the MSByte of j.
	Changed to be:

	 j = *(unsigned char *)&fbbconfig[5] +
		((*(unsigned char *)&fbbconfig[6]) << 8)

2/16/96  vk..global data_rdy_output introduced to have it veaseble to the
	 whole 'cbird'.
	 - bird_changevalue() changed to use global variable 'data_rdy_output'
	 instead of automatic data_temp.
	 - bird_mousebuttons(), bird_examinevalue(), bird_crtsync() changed
	 to clear BIRD output buffers if the command expect the data
	 to be returned. Done to get read of the rest of the data in the
	 buffer (should not be there any way) AND TO DISABLE DATA READY OUTPUT
	 Otherwise if it was enabled there is Data Ready sitting in the buffer
	 and we'll read it instead of good data.
	 - clearbuff() changed. IF ISA interface THEN
	 send OUTPUT BUFFER CLEAR command.
	 - getsamplesoverrange to call clearbuff() if either RS232 or ISA
	 (used to be for RS232 only).
	 - getsinglebirddata() changed to clear Bird Output Buffers
	 when enabling STREAM mode. Done to get rid of Data Ready Char
	 sitting in the buffer IF Data Ready Output enabled
	 - bird_changevalue() changed  to clear Bird Output Buffers
	 when disabling Data Ready Char Output or changing Data Ready Char.
	 Done to get rid of old Data Ready Char sitting in the buffer
	 IF Data Ready Output was enabled previously.
	 - bird_changevalue() changed. IF ISA Bus in use then call
	 set_system_isa_protocol() to let every unit know about that.
2/20/96  vk..getsamplesoverrange() changed. Now precompute for the
	 user lowest measurements rate from the crystal frequency.

2/27/96  vk..New Bird Commands implemented.
	 'q' Angle Align2 Command instead of 'J' Angle Align Command
	 'r' Reference Frame2 Command instead of 'H' Reference Frame Command
	 - bird_changevalue(), bird_examinevalue() changed to use
	 EXAMINE/CHANGE Parameter 7 ( Measurement Rate) instead
	 of Parameter 6 (Measurement Rate Count).


		<<<< Copyright 1996 Ascension Technology Corporation >>>>
*****************************************************************************
****************************************************************************/
#include <stdio.h>          /* general I/O */
#include <math.h>           /* trig math funcs */
#include "asctech.h"        /* general definitions */
#include "birdcmds.h"
#include "cmdutil.h"        /* command utilities */
#include "compiler.h"       /* Compiler Specific Header */
#include "iface.h"          /* Interface Functions Prototypes */
#ifdef DOS
  #include "isacmds.h"        /* ISA interface commands */
  #include "isadpcpl.h"       /* ISA protocol related functions */
#endif
#include "pctimer.h"
#include "menu.h"           /* for menus */
#include "sercmds.h"        /* serial port interface commands */
#include "serial.h"         /* serial I/O */
/***********************
	 Globals
***********************/

#define AUTOCONFIG_TIMEOUTINSECS 2

/*
	 External Varibles
*/
extern FILE * datafilestream;
extern unsigned char displaymultidataflg;
extern short numfbbaddrs;

/*
	 Position Variable
*/
float posk;
float crystalfreq = DEFAULTCRYSTALFREQ;
float clockvalue = DEFAULTCLOCKVALUE;
short buttonvalue = 0;
unsigned char fbbgroupdataflg = FALSE;
short flocksize = 1;
unsigned char fbbsystemstatus[128];
short numfbbrcvrs;
unsigned data_ready_char = ',';
short data_rdy_output = FALSE;          /* data ready character disabled */
/*
  data returned
*/
short birddata[14];    /* holds the data from the BIRD for buttondata */

/************************
    Routines
************************/

/*
    getsinglebirddata   Get Data from a Single Bird

	 Prototype in:       birdcmds.h

    Parameters Passed:  outputmode  - POINT,CONTINUOUS or STREAM
			datamode    - POS, ANGLE, POSANGLE..
			displayon   - 
			buttonmode  - current button mode, 0 if button
				      data is not appended to data,
				      1 if button data is appended

    Return Value:       TRUE if successful
			FALSE otherwise

    Remarks:            Displays current Bird Data in POINT, CONTINUOUS
			or STREAM mode
*/
int getsinglebirddata(outputmode, datamode, displayon, buttonmode)
short outputmode;
unsigned char datamode;
unsigned char displayon;
short buttonmode;
{
    unsigned char datasize;
    unsigned char posorientcmd;

	 /*
       Set the for the number of WORDs (16 bits) and the
       Pos/Orientation Mode command
    */
    switch(datamode)
    {
	case POS:
	    datasize = 3;
	    posorientcmd = 'V';
	    break;

	case ANGLE:
	    datasize = 3;
	    posorientcmd = 'W';
	    break;

	case MATRIX:
	    datasize = 9;
	    posorientcmd = 'X';
	    break;

	case QUATER:
	    datasize = 4;
		 posorientcmd = 92;
		 break;

	case POSANGLE:
	    datasize = 6;
	    posorientcmd = 'Y';
	    break;

	case POSMATRIX:
	    datasize = 12;
	    posorientcmd = 'Z';
	    break;

	case POSQUATER:
	    datasize = 7;
	    posorientcmd = ']';
	    break;

	default:
	    printf("\n\r** ERROR ** illegal data mode in getbirddata\n\r");
	    return(FALSE);
    }


	 /*
	Send the Mode Command (ie. POS, ANGLES...
    */
    if (send_cmd(&posorientcmd,1) != 1)
	return(FALSE);

    /*
	Send the Stream command if in STREAM mode
    */
#ifdef DOS
    if (outputmode == STREAM)
    {
       if (interface == ISA_BUS)
	  /* clear Bird output buffer */
	  bird_clearoutputbuffer_isa();
	   if (send_cmd((unsigned char *)"@",1) != 1)
	      return(FALSE);
    }
#endif
    /*
	 Send the User a Prompt if in Point mode
    */
    if (outputmode == POINT)
	 printf ("\n\rHit the 'B' Key to read Bird data or any other key to Quit\n\r");

	 /*
	Now read the data from the Bird
	storing the data in birddata[]
	check for done condition, keyboard hit while displaying the data
    */

    while (!check_done(outputmode))
    {
	/*
	    Get the data NOW
	*/
	if (!readbirddata(birddata,datasize,outputmode,buttonmode))
	    return(FALSE);

	/*
	    Display and File (if required) the Data Now
	*/
	if (!displaybirddata(birddata, datamode, buttonmode, displayon,0,datafilestream))
	    return(FALSE);
    }
    return(TRUE);
}

/*
	 bird_anglealign     - Align the Bird User Specified Direction

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       TRUE if successful
			FALSE otherwise

    Remarks:            prompts the user for Azimuth, Elevation and Roll of
			the User Direction and sends these values to the Bird
			to reorient the Birds direction
*/
int bird_anglealign()
{
    float angle[3];         /* angles input by the user */

    /*
	Get the 3 angles from the User
    */
    if (getangles("\n\rInput Azimuth, Elevation, and Roll angles from receiver\n\rto reference direction in degrees: ",
		&angle[0]) == ESC_SEL)
	{
		return(FALSE); 
		}

    if (interface == RS232)   /* IF Serial Interface THEN ...*/
	{                         /* use commands from serial interface commands file */
	if(bird_anglealign_serial(angle[0],angle[1],angle[2]) == FALSE) 
		{
		return(FALSE); 
		}
	}
#ifdef DOS
    else                      /* ELSE - ISA interface */
		{                         /* use commands from ISA interface commands file */
	if(bird_anglealign_isa(angle[0],angle[1],angle[2]) == FALSE) 
		{
		return(FALSE); 
		}       
	}
#endif

    printf("Angle Alignment Data sent to the Bird\n\r");
    hitkeycontinue();

    return(TRUE);

}

/*
	 bird_hemisphere     -   Set the Birds Hemisphere

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       TRUE if successful
			FALSE if unsuccessful
			ESC_SEL if ESC selected

    Remarks:            prompt the user for the Bird hemisphere and send
			down coresponding hemisphere command to the Bird
*/
int bird_hemisphere()
{
    static char * hemisphere_menuptr[] =
				  {"Hemisphere Options:",  /* menu options */
				   "Forward",
				   "Aft",
				   "Upper",
				   "Lower",
				   "Left",
				   "Right"};
	 int hemisphere;

    /*
	Send the Menu to the User and get the answer
    */
    if((hemisphere = sendmenu(hemisphere_menuptr,6)) == ESC_SEL)
	    return(ESC_SEL);

    if(interface == RS232)   /* IF Serial Interface THEN ...*/
			     /* use commands from serial interface commands file */
    {
       if(bird_hemisphere_serial(hemisphere) == FALSE)
	  return(FALSE);
    }
#ifdef DOS
    else                      /* ELSE - ISA interface */
			      /* use commands from ISA interface commands file */
    {
       if(bird_hemisphere_isa(hemisphere) == FALSE)
	  return(FALSE);
    }
#endif

    printf("Hemisphere Data Sent to the Bird\n\r");
    hitkeycontinue();

	 return(TRUE);

}

/*
    bird_referframe -   Define a new Bird Reference Frame

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       TRUE if successful
			FALSE otherwise

    Remarks:
*/
int bird_referframe()
{
    float angle[3];         /* angles input by the user */

    /*
	Get the user to input Azimuth, Elevation, and Roll
    */
    if (getangles("\n\rInput Azimuth, Elevation, and Roll angles\n\rof new reference frame: ",&angle[0]) == ESC_SEL)
	return(FALSE);

    if (interface == RS232)   /* IF Serial Interface THEN ...*/
    {                         /* use commands from serial interface commands file */
       if(bird_referframe_serial(angle[0],angle[1],angle[2]) == FALSE)
	       return(FALSE);
    }
#ifdef DOS
    else                      /* ELSE - ISA interface */
    {                         /* use commands from ISA interface commands file */
       if(bird_referframe_isa(angle[0],angle[1],angle[2]) == FALSE)
	       return(FALSE);
    }
#endif
    printf("Reference Frame Sent to the Bird\n\r");
    hitkeycontinue();

    return(TRUE);

}

/*
    bird_reportrate -   Select the Report Rate for Stream Mode

    Prototype in:       birdcmds.h

	 Parameters Passed:  void

    Return Value:       TRUE if successful
			FALSE if unsuccessful
			ESC_SEL if user selected ESC

    Remarks:            Queries the User for Bird Report Rate for STREAM
			mode...can be MAX, MAX/2, MAX/8, or MAX/32
*/
int bird_reportrate()
{
    unsigned char rate_cdata;
    static char * reportrate_menuptr[] =
				  {"Select the Report Rate (for STREAM mode):",  /* menu options */
				   "MAX",
				   "MAX/2",
				   "MAX/8",
				   "MAX/32"};
    /*
	Send the Menu to the User
    */
    switch (sendmenu(reportrate_menuptr,4))
    {
	case 0:
		 rate_cdata = 'Q';
		 break;

	case 1:
	    rate_cdata = 'R';
	    break;

	case 2:
	    rate_cdata = 'S';
	    break;

	case 3:
	    rate_cdata = 'T';
	    break;

	case ESC_SEL:
	    return(ESC_SEL);
    }

    /*
	Send of the 1 char
    */
    if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
	 {
		 if (bird_reportrate_serial(rate_cdata) == FALSE)
	   return(FALSE);
    }
#ifdef DOS
    else                 /* ELSE - ISA interface */
			 /* use commands from ISA interface commands file */
    {
       if (bird_reportrate_isa(rate_cdata) == FALSE)
	   return(FALSE);
    }
#endif

    printf("Report Rate Sent to Bird\n\r");
    hitkeycontinue();

    return(TRUE);
}

/*
	 bird_sleepwake  -   Implements the Sleep ('G') or Wake ('F') command

    Prototype in:       birdcmds.h

    Parameters Passed:  void

	 Return Value:       TRUE if successful
			FALSE if unsuccessfull
			ESC_SEL if user selects ESC

    Remarks:            prompts the user for Sleep or Wake and send the
			corresponding command to the Bird
*/
int bird_sleepwake()
{
    static char * sleepwake_menuptr[] =
				 {"Enter Selection:",
				  "Sleep",
				  "FBB Run/Wake"};

//    unsigned char sleepwake_cdata;

    /*
	Get the User selection
    */
    switch (sendmenu(sleepwake_menuptr,2))
    {
	case 0:
    if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
	 {
		 if (bird_sleep_serial() == FALSE)
	   return(FALSE);
    }
#ifdef DOS
    else                 /* ELSE - ISA interface */
			 /* use commands from ISA interface commands file */
    {
       if (bird_sleep_isa() == FALSE)
	   return(FALSE);
    }
#endif
	break;

	case 1:
    if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
    {
       if (bird_wakeup_serial() == FALSE)
	   return(FALSE);
    }
#ifdef DOS
    else                 /* ELSE - ISA interface */
			 /* use commands from ISA interface commands file */
    {
       if (bird_wakeup_isa() == FALSE)
	   return(FALSE);
	 }
#endif
	break;

	case ESC_SEL:
	return(ESC_SEL);
    }

	 printf("Sent the Sleep/Wake Command to the Bird\n\r");
	 #ifdef TC
		delay (2000);
	 #endif
    return(TRUE);
}

/*
    bird_mousebuttons   -   Implements the M and N mouse button commands

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       0, if buttonmode is off
			1, if buttonmode is on, 'M'
			ESC_SEL, if the user selected ESC_SEL

    Remarks:            sends down the button mode to the Bird and allows
			the user to view the Button state.
*/
int bird_mousebuttons()
{
   unsigned buttonchar;                /* buffer for button value */
   short buttonmode;
   short tempchar;
   long  tempword;

   /*
   Ask if they want the Button Commands to always be sent
   */
   buttonmode = 0;     /* assume button mode off */
   if (askyesno("Do you want the Button Byte added to the End of Data Stream"))
     buttonmode = 1;

   /*
   Send Button Mode Command
   */
   if (interface == RS232) /* IF Serial Interface THEN ...*/
                           /* use commands from serial interface commands file */
     if (bird_buttonmode_serial(buttonmode) == FALSE)
       return(ESC_SEL);                        /* can't return FALSE */
#ifdef DOS
     else                    /* ELSE - ISA interface */
			    /* use commands from ISA interface commands file */
       if (bird_buttonmode_isa(buttonmode) == FALSE)
         return(ESC_SEL);                        /* can't return FALSE */
#endif

   /*
   See if the User wants to display the button now if in 'N' mode
   */
   if (askyesno("\n\rDisplay Button Value Now "))
   {
      printf("\n\rHit a key to stop printing the button value\n\r");
      while (!ckkbhit())
      {
         /*
	 Send Read Button Command
	 */
         if (interface == RS232)  /* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
           if (bird_buttonread_serial() == FALSE)
	   {
	      printf("Could not send Button Read Command\n\r");
	      hitkeycontinue();
	      return(buttonmode);
           }
#ifdef DOS
           else                  /* ELSE - ISA interface */
			   /* use commands from ISA interface commands file */
           {
              bird_clearoutputbuffer_isa();  /* clear Bird output buffer */
              if (bird_buttonread_isa() == FALSE)
	      {
                 printf("Could not send Button Read Command\n\r");
		 hitkeycontinue();
		 return(buttonmode);
              }
           }
#endif

         if (interface == RS232)
         {
            /*
            Get button byte
            */
            if ((tempchar = waitforchar()) < 0)
            {
               printf("Could not read button byte\n\r");
	       hitkeycontinue();
	       return(buttonmode);
            }
            buttonchar = tempchar;
         }
#ifdef DOS
         else   /* ISA */
         {
	    /*
	    Get button word
	    */
	    if ((tempword = waitforword()) < 0)
	    {
	       printf("Could not read button word\n\r");
	       hitkeycontinue();
	       return(buttonmode);
	    }
	    buttonchar = (short)(tempword);
         }
#endif
         printf("Button = %d\n\r",buttonchar);
      }
      clearkey();
   }
   return(buttonmode);
}

/*
	 bird_xonxoff        - Implements the XON / XOFF commands

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       TRUE if sent XON or XOFF
			FALSE if could not send the command
			ESC_SEL if the User selected ESC

    Remarks:            sends down the XON or XOFF command to the BIRD
*/
int bird_xonxoff()
{
    unsigned char birdflowcmd;
    static char * xonxoffmenu[] = {"Select Flow Command:",
				   "XON",
					"XOFF"};
	 /*
	Ask the user which they want, XON or XOFF
    */
    switch (sendmenu(xonxoffmenu,2))
    {
	case 0:
		  birdflowcmd = XON;
	     break;

	case 1:
	     birdflowcmd = XOFF;
	     break;

	case ESC_SEL:
	     return(ESC_SEL);
    }

    /*
	Send the command to the Bird
    */

    if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
	 {
		 if (bird_xonxoff_serial(birdflowcmd) == FALSE)
       return(FALSE);
    }
    else                 /* ELSE - ISA interface */
			 /* don't send anything - it's illegal ISA command */

		return(ESC_SEL);

    printf("Sent the XON/XOFF command to the Bird\n\r");

    hitkeycontinue();

    return(TRUE);
}
/*
    bird_changevalue    - Implements the Change Value Commmand

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       TRUE if Command was sent to the Bird
			FALSE if could not send the command
			ESC_SEL if the User selected ESC

    Remarks:            Routine queries the user for the PARAMETER to change
			and sends down the new information to the Bird
*/
int bird_changevalue()
{
  float           float_angle[3];         /* angles input by the user                     */
  int             int_angle[3];           /* array to store azim,elev,roll                */
  short           answer;
  short           menusel;
  unsigned short  i,j;
  short           invalid;
  unsigned short  *dcfiltervalue;
  char            **dcfiltermsg;
  double          floatvalue;
  char            floatstring[80];
  int             parameter_number;
  char            data_temp;  
  char            data_temp2;
//double          min_rate;
  static char     parameter_data[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static char     *changevaluemenu[] = {  
					"Select Parameter to Change:",
					"Previous Menu",
					"Maximum Range Scaling",
					"Filter ON/OFF Status",
					"Filter Const - Alpha_Min",
					"Bird Measurement Rate",
					"Disable/Enable Data Ready Output",
					"Change Data Ready Character",
					"Set ON ERROR Mask",
					"Filter Const - Vm",
					"Filter Const - Alpha_Max",
					"Block/Allow Sudden Output Changes",
					"XYZ Reference Frame",
					"Transmitter Mode",
					"Addressing Mode",  
					"Line Frequency",   
					"FBB Address",    
					"Hemisphere",
					"Angle Align",
					"Reference Frame",
					"Set FBB Host Delay",
					"Enable/Disable Group Data Mode",
					"FBB Auto Config - 1 Trans/N Rec",
		                	"Set FBB Configuration"
			               };
  static char * rangemenu[] = {
                               "Select Scaling Range:",
                               "36 inch range",
			       "72 inch range"
                              };
  static char * errormaskmenu[] = {
                                   "Select Error Mask Mode:",
				   "Fatal Errors are Blinked Forever",
				   "Fatal Errors are Blinked Once",
				   "Fatal and Warning Errors are NOT Blinked"
                                  };  
  static char * transmitterModeMenu[] = {
					 "Select Transmitter Mode:",
					 "Non-Pulsed [OFF-axis, X-axis,      Y-axis,      Z-axis]",
					 "Pulsed     [OFF,      X-axis, OFF, Y-axis, OFF, Z-axis]",
					 "Cool-Down  [OFF-axis, X-axis, off, Y-axis, off, Z-axis]"
					};
  static char * hemisphereMenu[] = {
				    "Select Hemisphere:",
				    "Front",
				    "Rear",
				    "Upper",
				    "Lower",
				    "Left",
				    "Right"
				   };
  static char * addressModeMenu[] = {
				     "Select Address Mode:",
				     "Normal:		 14 FBB devices",
				     "Extended:		 30 FBB devices",
				     "Super-Extended:	126 FBB devices"
				    };
  static char * configmodemenu[] = {
                                    "FBB Configuration Mode:",
				    "Standalone",
				    "1 Transmitter, N Receivers"
                                   };
  static char * bird_dcfiltermsg[] = {
                                      "0 to 12 inches",
				      "12 to 15 inches",
				      "15 to 19 inches",
				      "19 to 24 inches",
				      "24 to 30 inches",
				      "30 to 38 inches",
				      "38+ inches"
                                     };
  static unsigned short bird_dcfiltervalue[] = {2,6,26,99,396,1615,6460};
  static char * erc_dcfiltermsg[] = {
                                     "0 to 35 inches",
				     "35 to 49 inches",
				     "49 to 63 inches",
				     "63 to 79 inches",
				     "79 to 96 inches",
				     "96 to 116 inches",
				     "116+ inches"
                                    };
  static unsigned short erc_dcfiltervalue[] = {2,2,2,45,90,180,360};
  static unsigned short fbbdevices = 0;
  static unsigned short fbbdependents = 0;
  long    autoconfig_delay;
  long    starttime;
  int     done;

    /*
    Initialize the Parameter Bytes
    */
    data_temp = 0;

    /*
    Setup to use either the 6DFOB parameters or the ERC parameters
    */
    if (posk == POSK144)
    {
      dcfiltervalue = erc_dcfiltervalue;
      dcfiltermsg = erc_dcfiltermsg;
    }
    else
    {
      dcfiltervalue = bird_dcfiltervalue;
      dcfiltermsg = bird_dcfiltermsg;
    }

    /*
    Get the Number of FBB Addrs
    */
    if (getaddrmode() == 0)
      return(FALSE);

    /*
    Send the Menu to the Screen and take appropriate action
    */
    if (interface == RS232)
      menusel = sendmenu(changevaluemenu,23);
    else                                       /* IF ISA THEN */
      menusel = sendmenu(changevaluemenu,22); /* no Change FBB Configuration Parameter */

    switch (menusel)
    {
      case ESC_SEL:

      case 0:     /* return */
	return(ESC_SEL);

      case 1:     /* Range Scale */
	/*
	Set the Parameter number and command size
	*/
	parameter_number = 3;
	/*
	Set the parameter Scale Data, 0 for 36" or 1 for 72"
	*/
	switch(sendmenu(rangemenu,2))
	{
	  case 0: /* 36" */
	    data_temp = 0x00;
	    posk = POSK36;
	    break;
	  case 1: /* 72" */
	    data_temp = 0x01;
	    posk = POSK72;
	    break;
	  case ESC_SEL:
	    return(ESC_SEL);
	}
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp; /* ...Parameter goes in LSByte      */
	                                 /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
					       in the 1st byte */
	  parameter_data[0] = data_temp;

	break;

      case 2:    /* Filter ON/OFF Status */
	/*
	Set the Parameter number and the command size
	*/
	parameter_number = 4;

	/*
	Ask the user to 'fill in the bits'...filter ON/OFF selection
	*/
	if ((answer = askyesno("\n\rDo you want the AC Narrow Notch filter OFF")) == TRUE)
	  data_temp = 4;
	else if (answer == ESC_SEL)
	  return(ESC_SEL);

        if ((answer = askyesno("\n\rDo you want the AC Wide Notch OFF")) == TRUE)
	  data_temp += 2;
	else if (answer == ESC_SEL)
	  return(ESC_SEL);

	if ((answer = askyesno("\n\rDo you want the DC filter OFF")) == TRUE)
	  data_temp += 1;
	else if (answer == ESC_SEL)
	  return(ESC_SEL);

	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp; /* ...Parameter goes in LSByte      */
	                                 /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
						 in the 1st byte */
	  parameter_data[0] = data_temp;
	break;

      case 3:    /* Filter Constant Table - Alpha Min */
	/*
	Set the Parameter number and the command size
	*/
	parameter_number = 5;

	/*
	Set all 7 table entries
	*/
	for (i=0; i < 7; i++)
	{
	  /*
	  Get the Filter Value from the User..with validation 0 to 0.99996
          */
	  do
	  {
	    invalid = FALSE;
	    printf ("For range %s, \n\rInput the New Filter Value (0 to 0.99996): ",
	    dcfiltermsg[i]);
	    if (getfloatstring(floatstring) != NULL)
	      floatvalue = atof(floatstring);
	    else
	      return(ESC_SEL);

	    /*
	    Validate the number
	    */
	    if ((floatvalue < 0.0) || (floatvalue >= 1.00))
	    {
	      invalid = TRUE;
	      printf("** ERROR ** invalid value\n\r");
	    }
	  } while(invalid);

	  /*
	  Convert float to word 0 to 32767 and store in the command
	  */
	  j =  (unsigned)(floatvalue * FTW);
	  if(interface == RS232)     /* Swap MSByte and LSByte if RS232 */
	  {
	    *((unsigned char *)&parameter_data[2*i + 0])        = (unsigned char)((j & 0x00ff) >> 0);
	    *((unsigned char *)&parameter_data[2*i + 1])        = (unsigned char)((j & 0xff00) >> 8);
	  }
	  else                       /* Keep MSByte, LSByte order if ISA */
	  {
	    *((unsigned char *)&parameter_data[2*i + 0])        = (unsigned char)((j & 0xff00) >> 8);
	    *((unsigned char *)&parameter_data[2*i + 1])        = (unsigned char)((j & 0x00ff) >> 0);
	  }
        }
        break;

      case 4:    /* Measurement Rate */
        /*
        Set the Parameter number and the command size
	*/
	parameter_number = 7;
	printf("**NOTE** do not reduce measurement frequency if the Bird\n\r        is synchronized to the CRT\n\r");

	/*
	Get the Measurement frequency from the User
	*/
	do
	{
	  printf ("Input the desired measurement frequency (20 to 144 Hz): " /* ,min_rate */);
          invalid = FALSE;
	  if (getfloatstring(floatstring) != NULL)
	    floatvalue = atof(floatstring);
	  else
	    return(ESC_SEL);

	  /*
	  Validate the number
	  */
	  if ((floatvalue < 20.0) || (floatvalue > 144.0))
	  {
	    invalid = TRUE;
	    printf("** ERROR ** invalid value\n\r");
	  }
	} while(invalid);

	/*
	scale the rate. 256 Hz is a full scale = 65536.
	*/
	i = (unsigned int) (floatvalue * MEAS_RATE_TO_INT);

	/*
	put the data into the parameter data string
	*/
	if(interface == RS232)     /* Swap MSByte and LSByte if RS232 */
	{
	  *(unsigned char *)&parameter_data[0] = (unsigned char) (i & 0xff);
	  *(unsigned char *)&parameter_data[1] = (unsigned char) ((i & 0xff00) >> 8);
	}
	else                       /* Keep MSByte, LSByte order if ISA */
	{
	  *(unsigned char *)&parameter_data[0] = (unsigned char) ((i & 0xff00) >> 8);
	  *(unsigned char *)&parameter_data[1] = (unsigned char) (i & 0xff);
	}
        break;

      case 5:    /* Disable/Enable Data Ready Output */
	/*
	Set the Parameter number and the command size
	*/
	parameter_number = 8;
	
        /*
	Ask the User if they want to Enable the Data Output Character
	*/
	data_rdy_output = FALSE;
	if ((answer = askyesno("Do you want Data Ready Output enabled")) == YES)
	  data_rdy_output = TRUE;
	else if (answer == ESC_SEL)
	  return(ESC_SEL);

	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;            /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = (char)(data_rdy_output); /* ...Parameter goes in LSByte      */
						  /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
					       in the 1st byte */
	  parameter_data[0] = (char)(data_rdy_output);
        break;

      case 6:    /* Change Data Ready Character */
        /*
	Set the Parameter number and the command size
	*/
	parameter_number = 9;
	
        /*
	Ask the User for the Data Ready Character to Send
	*/
	do
	{
	  invalid = FALSE;
	  printf("\n\rEnter the desired data ready character in decimal (0-255): ");
	  if (((answer = getnumber()) < 0) || (answer > 255))
	  {
	    invalid = TRUE;
	    printf("\n\r** ERROR ** invalid entry, please try again\n\r");
	    hitkeycontinue();
	  }
          data_temp = (unsigned char) answer;
	  data_ready_char = (unsigned char) answer;
	} while (invalid);

	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp; /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
							 in the 1st byte */
	  parameter_data[0] = data_temp;
        break;

      case 7:    /* Set ON ERROR Mask */
	/*
        Set the Parameter number and the command size
	*/
	parameter_number = 11;
	
        /*
	Ask the user the Error Mask Mode
	*/
	switch(sendmenu(errormaskmenu,3))
	{
	  case 0: /* Fatal Error Blink and Stop system  */
	    data_temp = 0x00;
	    break;
	  case 1: /* Fatal Error Blink and system resumes */
	    data_temp = 0x01;
	    break;
	  case 2: /* Fatal Error Does NOT Blink and system resumes */
	    data_temp = 0x03;
	    break;
	  case ESC_SEL:
	    return(ESC_SEL);
	}
	printf("\n\r");
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp; /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
					       in the 1st byte */
	  parameter_data[0] = data_temp;
        break;

      case 8:    /* Set DC Filter Constant Table */
        /*
        Set the Parameter number and the command size
	*/
        parameter_number = 12;

        /*
	Ask the user to enter the DC Filter Table
	*/
	for (i=0;i<7;i++)
	{
	  printf("\n\rFor the range %s, current value is %d (decimal)\n\r",
	  dcfiltermsg[i],dcfiltervalue[i]);
	  printf("\n\rEnter the new value for this range, or ESC for no change: ");
	  if ((answer = getnumber()) != ESC_SEL)
	    dcfiltervalue[i] = answer;

	  /*
	  Store the Value in the Parameter Data String
	  */
	  j = dcfiltervalue[i];
	  if(interface == RS232)     /* Swap MSByte and LSByte if RS232 */
	  {
	    *((unsigned char *)&parameter_data[(2*i) + 0]) = (unsigned char)((j & 0x00ff) >> 0);
	    *((unsigned char *)&parameter_data[(2*i) + 1]) = (unsigned char)((j & 0xff00) >> 8);
	  }
	  else                       /* Keep MSByte, LSByte order if ISA */
	  {
	    *((unsigned char *)&parameter_data[(2*i) + 0]) = (unsigned char)((j & 0xff00) >> 8);
	    *((unsigned char *)&parameter_data[(2*i) + 1]) = (unsigned char)((j & 0x00ff) >> 0);
	  }
	}
	break;

      case 9:    /* Filter Constant Table - Alpha Max */
	/*
	Set the Parameter number and the command size
	*/
	parameter_number = 13;
	
        /*
        Set all 7 table entries
	*/
	for (i=0; i < 7; i++)
	{
	  /*
	  Get the Filter Value from the User..with validation 0 to 0.99996
          */
	  do
	  {
            invalid = FALSE;
	    printf ("For the range %s,\n\rInput the New Filter Value (0 to 0.99996): ",
			      dcfiltermsg[i]);
	    if (getfloatstring(floatstring) != NULL)
	      floatvalue = atof(floatstring);
	    else
	      return(ESC_SEL);

	    /*
	    Validate the number
	    */
	    if ((floatvalue < 0.0) || (floatvalue >= 1.00))
	    {
	      invalid = TRUE;
	      printf("** ERROR ** invalid value\n\r");
	    }
	  } while(invalid);

          /*
          Convert float to word 0 to 32767 and store in the command
	  */
	  j = (unsigned)(floatvalue * FTW);
	  if(interface == RS232)     /* Swap MSByte and LSByte if RS232 */
	  {
	    *((unsigned char *)&parameter_data[(2*i)+0]) = (unsigned char)((j & 0x00ff) >> 0);
	    *((unsigned char *)&parameter_data[(2*i)+1]) = (unsigned char)((j & 0xff00) >> 8);
	  }
	  else                       /* Keep MSByte, LSByte order if ISA */
	  {
	    *((unsigned char *)&parameter_data[(2*i)+0]) = (unsigned char)((j & 0xff00) >> 8);
	    *((unsigned char *)&parameter_data[(2*i)+1]) = (unsigned char)((j & 0x00ff) >> 0);
	  }
	}
	break;

      case 10:    /* Glitch Checking */
	/*
	Set the Parameter number and the command size
	*/
	parameter_number = 14;

        /*
        Ask the User if they want to Enable Glitch Checking
	*/
	data_temp = FALSE;
	if ((answer = askyesno("Do you want to Block Sudden Output Changes")) == YES)
	  data_temp = TRUE;
	else if (answer == ESC_SEL)
	  return(ESC_SEL);

	/*
	Set the Parameter Data String
	*/
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp; /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
					       in the 1st byte */
	  parameter_data[0] = data_temp;
	break;

      case 11:    /* Set XYZ Reference Frame */
        /*
        Set the Parameter number and the command size
	*/
	parameter_number = 17;

	/*
	Ask user about value to send
	*/
	if ((answer = askyesno("Do you want to define Reference Frame")) == YES)
	  data_temp = 1;
	else
	  data_temp = 0;

        /*
	Set the Parameter Data String
	*/
	if (interface == ISA_BUS)
	{
	  *(unsigned char *) &parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  *(unsigned char *) &parameter_data[1] = data_temp; /* ...Parameter goes in LSByte      */
								/* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
					       in the 1st byte */
	  *(unsigned char *) &parameter_data[0] = data_temp;
        break;

      case 12:  
	/* set the transmitter mode */ 
	parameter_number = 18;
		
	/*
	Ask the user the Transmitter Mode
	*/
	switch(sendmenu(transmitterModeMenu,3))
	{
	  case 0: /* NON-PULSE  */
	    data_temp = 0x00;
	    break; 
	  case 1: /* PULSED */
	    data_temp = 0x01;
	    break;  
	  case 2: /* COOL-DOWN */
	    data_temp = 0x02;
	    break;  
	  case ESC_SEL:
	    return(ESC_SEL);
	}
	printf("\n\r");

        /*
	Ask user about dual transmitter mode
	*/
	if ((answer = askyesno("Do you want to run in Dual Transmitter mode?")) == YES)
	  data_temp = data_temp | 0x80;   /* set the msb */
        else
	  data_temp = data_temp & 0x7F;   /* clear the msb */

	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;           /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp;      /* ...Parameter goes in LSByte      */
						 /* ...of the Parameter Data Word    */
	}
	else                                    /* It's RS232 - Parameter is in the 1st byte */
	  parameter_data[0] = data_temp;
	break;

      case 13: 
	/* set the addressing mode */
	parameter_number = 19;
		
	/*
	Ask the user for the Address Mode
	*/
	switch(sendmenu(addressModeMenu,3))
	{
	  case 0: /* NORMAL  */
	    data_temp = 0x00;
	    break; 
	  case 1: /* EXTENDED */
	    data_temp = 0x01;
	    break;  
	  case 2: /* SUPER_EXTENDED */
	    data_temp = 0x03;
	    break;  
	  case ESC_SEL:
	    return(ESC_SEL);
	}

	printf("\n\r");
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;           /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp;      /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}
	else                                    /* It's RS232 - Parameter is in the 1st byte */
	  parameter_data[0] = data_temp;
	break;

      case 14:
	/* set the line frequency */
	/*
	Set the Parameter number and the command size
	*/
	parameter_number = 20;

        /*
	Ask the user to enter the line frequency (default = 60)
	*/
	do
	{
	  invalid = FALSE;
	  printf ("\n\rEnter the Line Frequency: ");
	  if ((answer = getnumber()) == ESC_SEL)
	    return(ESC_SEL);
	  if ((answer < 1) || (answer > 255))
	  {
	    invalid = TRUE;
	    printf("\n\r** ERROR ** invalid entry, try again\n\r");
	    hitkeycontinue();
	  } 
				
	} while(invalid);

	/*
	Set the Parameter Data String
	*/
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = (unsigned char) answer; /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}   
	else  /* It's RS232 - Parameter is in the 1st byte */
          parameter_data[0] = (unsigned char) answer;
        break;

      case 15:        /* Set the FBB address */
	/*
	Set the Parameter number and the command size
	*/
	parameter_number = 21;

        /*
        Ask the user to enter the fbb address (default = 1)
	*/
	do
	{
	  invalid = FALSE;
	  printf ("\n\rEnter the FBB Address: ");
	  if ((answer = getnumber()) == ESC_SEL)
	    return(ESC_SEL);
          if ( (answer < 1) ||
	       ((answer >  14) && (addressMode==NORMAL)) ||
	       ((answer >  30) && (addressMode==EXTENDED)) ||
	       ((answer > 126) && (addressMode==SUPER_EXTENDED)) )
          {
	    invalid = TRUE;
	    printf("\n\r** ERROR ** invalid entry, try again\n\r");
	    hitkeycontinue();
	  } 
				
	} while(invalid);

	/*
	Set the Parameter Data String
	*/
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = (unsigned char) answer; /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
							 in the 1st byte */
	  parameter_data[0] = (unsigned char) answer;
        break;

      case 16: 
	parameter_number = 22;

	/*
	Ask the user for the Hemisphere
        */
	switch(sendmenu(hemisphereMenu, 6))
	{
	  case 0: /* Front  */
	    data_temp       = 0x00; 
	    data_temp2      = 0x00;
	    break; 
	  case 1: /* Rear */
	    data_temp       = 0x00;
	    data_temp2      = 0x01;
	    break;  
	  case 2: /* Upper */
	    data_temp       = 0x0C; 
	    data_temp2      = 0x01;
	    break; 
	  case 3: /* Lower */
	    data_temp       = 0x0C; 
	    data_temp2      = 0x00;
	    break; 
	  case 4: /* Left */
	    data_temp       = 0x06; 
	    data_temp2      = 0x01;
	    break; 
	  case 5: /* Right */ 
	    data_temp       = 0x06; 
	    data_temp2      = 0x00;
	    break; 
          case ESC_SEL:
	    return(ESC_SEL);
	}
	printf("\n\r");    
	parameter_data[0] = data_temp;
	parameter_data[1] = data_temp2;
	break;
	
      case 17: 
	parameter_number = 23;

	/*
	Get the 3 angles from the User
        */
	if (getangles("\n\rInput Azimuth, Elevation, and Roll angles from receiver\n\rto reference direction in degrees: ",
	                                                                                       &float_angle[0]) == ESC_SEL)
          return(FALSE);
			
	/*
	Form the array of 3 angles for convenience.
	Convert angles to the integers. Full scale = 180 deg
	*/
	int_angle[0] =  (int)(float_angle[0] * ANG_TO_INT);
	int_angle[1] =  (int)(float_angle[1] * ANG_TO_INT);
	int_angle[2] =  (int)(float_angle[2] * ANG_TO_INT);    
	    
	if(interface==RS232)
	{  
	  parameter_data[0] = ((int_angle[0] & 0x00FF) >> 0);   
	  parameter_data[1] = ((int_angle[0] & 0xFF00) >> 8);
	  parameter_data[2] = ((int_angle[1] & 0x00FF) >> 0);   
	  parameter_data[3] = ((int_angle[1] & 0xFF00) >> 8);
	  parameter_data[4] = ((int_angle[2] & 0x00FF) >> 0);   
	  parameter_data[5] = ((int_angle[2] & 0xFF00) >> 8);
	}
	else if(interface==ISA_BUS)
	{
	  parameter_data[0] = ((int_angle[0] & 0x00FF) >> 0);   
	  parameter_data[1] = ((int_angle[0] & 0xFF00) >> 8);
	  parameter_data[2] = ((int_angle[1] & 0x00FF) >> 0);   
	  parameter_data[3] = ((int_angle[1] & 0xFF00) >> 8);
	  parameter_data[4] = ((int_angle[2] & 0x00FF) >> 0);   
	  parameter_data[5] = ((int_angle[2] & 0xFF00) >> 8);
	}
	break;
		
      case 18:  
	parameter_number = 24;
	
        /*
	Get the user to input Azimuth, Elevation, and Roll
	*/
	if (getangles("\n\rInput Azimuth, Elevation, and Roll angles\n\rof new reference frame: ",
	                                                              &float_angle[0]) == ESC_SEL)
	  return(FALSE);
			
	/*
	Form the array of 3 angles for convenience.
	Convert angles to the integers. Full scale = 180 deg
	*/
	int_angle[0] =  (int)(float_angle[0] * ANG_TO_INT);
	int_angle[1] =  (int)(float_angle[1] * ANG_TO_INT);
	int_angle[2] =  (int)(float_angle[2] * ANG_TO_INT);    
	    
	if(interface==RS232)
	{  
	  parameter_data[0] = ((int_angle[0] & 0x00FF) >> 0);
	  parameter_data[1] = ((int_angle[0] & 0xFF00) >> 8);
	  parameter_data[2] = ((int_angle[1] & 0x00FF) >> 0);   
	  parameter_data[3] = ((int_angle[1] & 0xFF00) >> 8);
	  parameter_data[4] = ((int_angle[2] & 0x00FF) >> 0);   
	  parameter_data[5] = ((int_angle[2] & 0xFF00) >> 8);
	}
	else if(interface==ISA_BUS)
	{
	  parameter_data[0] = ((int_angle[0] & 0x00FF) >> 0);   
	  parameter_data[1] = ((int_angle[0] & 0xFF00) >> 8);
	  parameter_data[2] = ((int_angle[1] & 0x00FF) >> 0);   
	  parameter_data[3] = ((int_angle[1] & 0xFF00) >> 8);
	  parameter_data[4] = ((int_angle[2] & 0x00FF) >> 0);   
	  parameter_data[5] = ((int_angle[2] & 0xFF00) >> 8);
	}
	break;                  

      case 19:    /* Set FBB Host Delay */
        /*
        Set the Parameter number and the command size
	*/
	parameter_number = 32;

        /*
	Ask the user to enter the FBB Response Delay
	*/
	printf("\n\rEnter the desired delay in units of 10 microseconds: ");
	if ((answer = getnumber()) == ESC_SEL)
	  return(ESC_SEL);

	/*
	Setup for units of 10 uS
	*/
	if (answer < 200)
	  answer = 20;   /* 200 uS minimum */
	else
	  if (answer % 10)
	    answer = (answer / 10) + 1;
	  else
	    answer = (answer / 10);

        if(interface == RS232)     /* Swap MSByte and LSByte if RS232 */
	{
	  *(unsigned char *)&parameter_data[0] = answer & 0xff;
	  *(unsigned char *)&parameter_data[1] = ((answer & 0xff00) >> 8);
	}
	else                       /* Keep MSByte, LSByte order if ISA */
	{
	  *(unsigned char *)&parameter_data[0] = ((answer & 0xff00) >> 8);
	  *(unsigned char *)&parameter_data[1] = answer & 0xff;
	}
	break;

      case 20:   /* Enable/Disable Group Mode */
        /*
        Set the Parameter number and the command size
	*/
	parameter_number = 35;

	/* Init to not group mode */
	fbbgroupdataflg = FALSE;
	data_temp = FALSE;

	/*
	Ask the user if they want to Save the Configuration
	*/
	if ((answer = askyesno("Do you want to Enable the Group Data Mode")) == YES)
	{
	  /*
	  Indicate that we are in the Group Mode
	  */
	  data_temp = TRUE;
	  fbbgroupdataflg = TRUE;
	}
	else if (answer == ESC_SEL)
          return(ESC_SEL);

        /*
	Set the Parameter Data String
	*/
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = data_temp; /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
					       in the 1st byte */
	  parameter_data[0] = data_temp;
        break;

      case 21:   /* FBB Auto Configuration - 1 Trans/N Rec */
        /*
        Set the Parameter number and the command size
	*/
	parameter_number = 50;

        /*
        Ask the user to enter the number of receivers
	*/
        printf("\
NOTE:  This Auto Configuration mode assumes that Bird 1 will be a\n\r\
       Master and Birds 2 through N will be Slaves");

	do
	{
	  invalid = FALSE;
	  printf ("\n\rEnter the number of Bird Units in the Flock: ");
	  if ((answer = getnumber()) == ESC_SEL)
	    return(ESC_SEL);
	  if ((answer < 1) || (answer > numfbbaddrs))
	  {
	    invalid = TRUE;
	    printf("\n\r** ERROR ** invalid entry, try again\n\r");
	    hitkeycontinue();
	  }
	} while(invalid);

	/*
	Set the Parameter Data String
	*/
	if (interface == ISA_BUS)
	{
	  parameter_data[0] = 0x00;      /*MSByte of Parameter data word = 0 */
	  parameter_data[1] = (unsigned char) answer; /* ...Parameter goes in LSByte      */
					    /* ...of the Parameter Data Word    */
	}
	else                            /* It's RS232 - Parameter is
					       in the 1st byte */
	  parameter_data[0] = (unsigned char) answer;

        /*
	Store the number of Units in the Flock
	...for use by other routines
	*/
	flocksize = answer;
	displaymultidataflg = TRUE;
	break; 

      case 22:    /* Set FBB Configuration */
        /*
        Set the Parameter number and the command size
	*/
	parameter_number = 33;

        /*
        Ask the user for the Configuration Mode
	*/
	switch(sendmenu(configmodemenu,2))
	{
	  case 0: /* standalone */
	    parameter_data[0] = 0x00;
	    break;
          case 1: /* one trans/ n rec */
	    parameter_data[0] = 0x01;
	    break;
          case ESC_SEL:
	    return(ESC_SEL);
	}

	/*
	Ask the user for the FBB Device Numbers
	*/
	do
	{
	  printf("\n\rFBB Devices..");
          for (i=1;i<=14;i++)
	  {
	    printf("\n\rDevice at FBB address %d is ", i);
	    if ((0x1 << i) & fbbdevices)
	      printf("ACTIVE");
	    else
	      printf("NOT ACTIVE");
	  }
	  printf("\n\n\rEnter the FBB address to change, 0 if complete: ");
	  if ((answer = getnumber()) == ESC_SEL)
	    return(ESC_SEL);
	  else if (answer != 0)
	    fbbdevices ^= (0x1 << answer);  /* flip the bit state */
	} while (answer != 0);

	if (interface == RS232)     /* Swap MSByte and LSByte if RS232 */
	{
	  *((unsigned char *)&parameter_data[(2*i)+0]) = (unsigned char)((j & 0x00ff) >> 0);
	  *((unsigned char *)&parameter_data[(2*i)+1]) = (unsigned char)((j & 0xff00) >> 8);
	}
	else                       /* Keep MSByte, LSByte order if ISA */
	{
	  *((unsigned char *)&parameter_data[(2*i)+0]) = (unsigned char)((j & 0xff00) >> 8);
	  *((unsigned char *)&parameter_data[(2*i)+1]) = (unsigned char)((j & 0x00ff) >> 0);
	}

	/*
	Ask the user for the FBB Dependents
	*/
	do
	{
	  printf("\n\rFBB Dependents..");
          for (i=1;i<=14;i++)
	  {
	    /*
	    Only Active devices can be dependents
	    */
	    if ((0x1 << i) & fbbdevices)
	    {
	      printf("\n\rDevice at FBB address %d is ", i);
	      if ((0x1 << i) & fbbdependents)
		printf("DEPENDENT");
	      else
		printf("NOT DEPENDENT");
	    }
	  }
	  printf("\n\n\rEnter the FBB address to change, 0 if complete: ");
	  if ((answer = getnumber()) == ESC_SEL)
	    return(ESC_SEL);
	  else
	    if (((0x1 << answer) & fbbdevices) && (answer != 0))
	      fbbdependents ^= (0x1 << answer);  /* flip the bit state */
	    else  /* device is not active */
	      printf("\n\rDevice at FBB address %d is NOT ACTIVE\n\r", answer);
	} while (answer != 0);

	if (interface == RS232)     /* Swap MSByte and LSByte if RS232 */
	{
	  *((unsigned char *)&parameter_data[(2*i)+0]) = (unsigned char)((j & 0x00ff) >> 0);
	  *((unsigned char *)&parameter_data[(2*i)+1]) = (unsigned char)((j & 0xff00) >> 8);
	}
	else                       /* Keep MSByte, LSByte order if ISA */
	{
	  *((unsigned char *)&parameter_data[(2*i)+0]) = (unsigned char)((j & 0xff00) >> 8);
	  *((unsigned char *)&parameter_data[(2*i)+1]) = (unsigned char)((j & 0x00ff) >> 0);
	}
        break;
    }

    /*
    Send the Command to the Bird
    */
    if(interface == RS232)      /* IF Serial Interface THEN ...*/
    {                       /* use commands from serial interface commands file */
      if (bird_changevalue_serial(parameter_number,parameter_data) == FALSE)
	return(FALSE);
      printf("\n\rNew Value(s) sent to the Bird\n\r");
    }
#ifdef DOS
    else if(interface == ISA_BUS)       /* ELSE - ISA interface */
    {                                       /* use commands from ISA interface commands file */
      if (bird_changevalue_isa(parameter_number,parameter_data) == FALSE)
        return(FALSE);
      printf("\n\rNew Value(s) sent to the Bird\n\r");     
    }
#endif
    #ifdef DOS
      /*
      we need a delay here because of the auto-config command
      */
      if(menusel==21)
      {
        /* Get the delay to wait for next command */
        autoconfig_delay = AUTOCONFIG_TIMEOUTINSECS;

        /* Get the time now in ticks */
        starttime = GETTICKS;

        /* Wait until the command has been read by the Bird
        ....leave loop when read or timeout */
        done = false;
        while (!done)
	  /*  Check to see if a timeout occured  */
	  if (((long)(GETTICKS) - starttime) > (long)((autoconfig_delay * 1000) / TICK_MSECS))
	    done = true;
      }
    #endif
    hitkeycontinue(); 

    /*
    If the Command was the Autoconfiguration...than
    get the current system status
    */
    if (menusel == 21)
    {
      if (getsystemstatus())
      {
	displayflocksys(&fbbsystemstatus[1]);
	/*
	If the ISA interface THEN
	need to let each unit know about that.
	*/
#ifdef DOS
	if (interface == ISA_BUS)
	  set_system_isa_protocol();
#endif
      }
      else
        return(FALSE);

    } 

    /*
    If the Command was Change Parameter 9 - Change Data Ready Char
    or Change Parameter 8 - Disable Data Ready Output Char, then
    clear Bird output buffers to get rid of old Data Ready Character
    possibly sitting there.
    */
#ifdef DOS
    if ((menusel == 6) && (interface == ISA_BUS)) /* Change Data Ready Char */
       /* clear Bird output buffer */
      bird_clearoutputbuffer_isa();

    /* if disable data ready char output */
    if ((menusel == 5) && (interface == ISA_BUS) && (data_rdy_output == FALSE))
		 /* clear Bird output buffer */
      bird_clearoutputbuffer_isa();
#endif
    return(TRUE);
}

/*
    bird_examinevalue    - Implements the Examine Value Commmand

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       TRUE if Command was sent to the Bird
			FALSE if could not send the command
			ESC_SEL if the User selected ESC

    Remarks:
*/
int bird_examinevalue()
{   
  unsigned int   serial_number;
  int            int_angle[3];
  float          float_angle[3];
  unsigned short i;
  int            parameter_number;
  unsigned char  temp_char;
  unsigned char  temp_char2;
  float          temp_float;
  unsigned short temp_short;
  short          answer;
  char           **dcfiltermsg;
  unsigned char  parameter[128];         /* room for a 126 byte response */
  double         measurementrate;
  static char *  examinevaluemenu[] = {"Select Parameter to Examine:",
                                       "Previous Menu",
                                       "Bird System Status",
                                       "Software Revision",
                                       "Bird CPU Crystal Frequency",
                                       "Maximum Range Scaling",
                                       "Filter ON/OFF Status",
                                       "Filter Const - Alpha_Min",
                                       "Bird Measurement Rate",
                                       "Data Ready Output",
                                       "Data Ready Character",
                                       "Error Code",
                                       "ON ERROR Mask",
                                       "Filter Const - Vm",
                                       "Filter Const - Alpha_Max",
                                       "Sudden Output Changes",
                                       "Model",
                                       "Expanded Error Code",
                                       "XYZ Reference Frame",
                                       "Transmitter Mode",
                                       "Addressing Mode",
                                       "Line Frequency",
                                       "FBB Address",
                                       "Hemisphere",
                                       "Angle Align",
                                       "Reference Frame",
                                       "Bird Serial Number",
                                       "Sensor Serial Number",
                                       "Xmtr Serial Number",
                                       "FBB Host Delay",
                                       "Group Data Mode",
                                       "Flock System Status",
                                       "FBB Auto Config - 1 Trans/N Rec",
                                       "FBB Configuration"
                                      };
  /*
  Parameternumbers for menu items
  */
  static unsigned short examinevalueparanumber[] =
    {0,0,1,2,3,4,5,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,32,35,36,50,33};
  static char * bird_dcfiltermsg[] = {"0 to 12 inches",
                                      "12 to 15 inches",
                                      "15 to 19 inches",
                                      "19 to 24 inches",
                                      "24 to 30 inches",
                                      "30 to 38 inches",
                                      "38+ inches"
                                     };
  static char * erc_dcfiltermsg[] = {"0 to 35 inches",
                                     "35 to 49 inches",
                                     "49 to 63 inches",
                                     "63 to 79 inches",
                                     "79 to 96 inches",
                                     "96 to 116 inches",
                                     "116+ inches"
                                    };
  /*
  Set up for ERC or 6DFOB
  */
  if (posk == POSK144)
    dcfiltermsg = erc_dcfiltermsg;
  else
    dcfiltermsg = bird_dcfiltermsg;

  /*
  Find out which Value the User wants to look at and take
  appropriate action
  */
  if (interface == RS232)
	  answer = sendmenu(examinevaluemenu,33);
  else                                       /* IF ISA THEN */
	  answer = sendmenu(examinevaluemenu,32); /* no examine Parameter 33 (FBB Configuration) */

  if (answer > 0)
  {
	/*
	Check the command and only inquire about address mode
	when the user request a function that needs the information
	*/

	  if ( answer==20 || answer==21 || answer==22 )
	    if (getaddrmode() == 0)      /* Get the Number of FBB Addrs	*/
		    return(FALSE);

    /*
	  Store the command parameter number
	  */
	  parameter_number = (unsigned char) examinevalueparanumber[answer];

	  /*
	  Send the command to the Bird
	  */
    if (interface == RS232)  /* IF Serial Interface THEN ...*/
		{	   /* use commands from serial interface commands file */
      if (bird_examinevalue_serial(parameter_number,parameter) == FALSE)
	      return(FALSE);
    }
    #ifdef DOS
	    else                 /* ELSE - ISA interface */
			{  /* use commands from ISA interface commands file */
         /* clear Bird output buffer */
        bird_clearoutputbuffer_isa();
        if (bird_examinevalue_isa(parameter_number,parameter) == FALSE)
	        return(FALSE);
      }
    #endif

	  /*
	  Decode the information retrieved
	  */
	  switch (answer)
	  {
      case 1:     /* System Status */
        /*
		    check Master/Slave bird .. bit 15
		    */
		    if (interface == RS232)        /* Serial Interface Sends swapped bytes */
			    temp_char = parameter[1];
		    else                           /* ISA interface does not swap bytes */
			    temp_char = parameter[0];

		    if ( ((unsigned char) temp_char) & 0x80 )
			    printf("Bird is Master\n\r");
		    else
			    printf("Bird is Slave\n\r");

		    /*
		    check bird initialization status .. bit 14
		    */
		    if ( ((unsigned char) temp_char) & 0x40 )
			    printf("Bird has been initialized\n\r");
		    else
			    printf("Bird has not been initialized\n\r");

		    /*
		    check if an error has been detected .. bit 13
		    */
		    if ( ((unsigned char) temp_char) & 0x20 )
			    printf("An error has been detected\n\r");
		    else
			    printf("No error detected\n\r");

		    /*
		    check if bird is NOT RUNNING / RUNNING .. bit 12
		    */
		    if ( ((unsigned char) temp_char) & 0x10 )
		      printf("Bird is NOT RUNNING\n\r");
		    else
		      printf("Bird is RUNNING\n\r");

		    /*
		    check if bird is in HOST SYNC .. bit 11
		    */
		    if ( ((unsigned char) temp_char) & 0x08 )
		      printf("Bird is in HOST SYNC\n\r");
		    else
		      printf("Bird is not in HOST SYNC\n\r");

        /*
		    Print Expanded Addressing or Expanded .. bit 10
		    */
		    if ( ((unsigned char) temp_char) & 0x04 )
		      printf("Bird in Expanded Addressing Mode\n\r");
		    else
		      printf("Bird in Normal Addressing Mode\n\r");

        /*
		    check if in CRTSYNC mode .. bit 9
		    */
		    if ( ((unsigned char) temp_char) & 0x02 )
		      printf("Bird in CRTSYNC Mode\n\r");
		    else
		      printf("Bird not in CRTSYNC Mode\n\r");

        /*
		    check if sync modes enabled .. bit 8
		    */
		    if ( ((unsigned char) temp_char) & 0x01 )
		      printf("SYNC mode not enabled\n\r");
		    else
		      printf("SYNC mode enabled\n\r");

        if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    /*
		    check factory test mode ..bit 7
		    */
		    printf ("Factory Test Commands: ");
		    if (((unsigned char) temp_char) & 0x80)
		      printf("ENABLED\n\r");
		    else
		      printf("DISABLED\n\r");

        /*
		    check XOFF/XON ..bit 6
		    */
		    if (((unsigned char) temp_char) & 0x80)
		      printf("XOFF\n\r");
		    else
		      printf("XON\n\r");

        /*
		    check sleep/wake ..bit 5
		    */
		    if (((unsigned char) temp_char) & 0x20)
		      printf("Bird in Sleep Mode\n\r");
		    else
			    printf("Bird in Wake Up Mode\n\r");

		    /*
		    check output selection ..bits 4,3,2,1
		    */
		    switch (((unsigned char) temp_char & 0x1e) >> 1)
		    {
		      case 1:
			      printf ("Position output selected ");
			      break;
		      case 2:
			      printf ("Angle output selected ");
			      break;
		      case 3:
			      printf ("Matrix output selected ");
			      break;
		      case 4:
			      printf ("Position/Angle output selected ");
			      break;
		      case 5:
			      printf ("Position/Matrix output selected ");
			      break;
		      case 6:
			      printf ("Factory Test output selected ");
			      break;
		      case 7:
			      printf ("Quaternion output selected ");
			      break;
		      case 8:
			      printf ("Position/Quaternion output selected ");
			      break;
          default:
			      printf ("Illegal Output mode detected\n\r");
			      hitkeycontinue();
			      return(FALSE);
		    }

		    /*
		    check outputmode .. bit 0
		    */
		    if (((unsigned char) temp_char) & 0x1)
		      printf("in STREAM mode\n\r");
        else
			   printf("in POINT mode\n\r");
        break;
	    case 2:     /* Software Rev */
		    printf ("Software REV %d.%d\n\r",parameter[0],parameter[1]);
		    break;
      case 3:     /* CPU Crystal */
	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    /*
		    Store the Value in the Global
		    */
		    crystalfreq = temp_char;
		    printf ("CPU Crystal is %4.1f MHz\n\r",crystalfreq);
		    break;
	    case 4:     /* Maximum Range */
        if (interface == RS232)        /* Serial Interface Sends swapped bytes */
		      temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    printf ("Maximum Range is ");
		    if (temp_char == 1)
		      printf ("72 inches\n\r");
		    else
		      printf ("36 inches\n\r");
		    break;
	    case 5:     /* Filter Status */
	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
        else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    printf ("AC Narrow Notch filter is: ");
		    if (temp_char & 4)
		      printf ("OFF\n\r");
		    else
		      printf ("ON\n\r");

        printf ("AC Wide Notch filter is: ");
		    if (temp_char & 2)
		      printf ("OFF\n\r");
		    else
		      printf ("ON\n\r");

		    printf ("DC filter is: ");
		    if (temp_char & 1)
		      printf ("OFF\n\r");
		    else
		      printf ("ON\n\r");
        break;
	    case 6:     /* Filter Constant Table - Alpha Min */
		    for (i=0; i<7; i++)
		    {
	        if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	          temp_float = ((*(unsigned char *)&parameter[i*2]) +
				                  ((*(unsigned char *)&parameter[(i*2+1)]) << 8)) * WTF;
	        else                           /* ISA interface does not swap bytes */
	         temp_float = ((*(unsigned char *)&parameter[(i*2+1)]) +
				                  ((*(unsigned char *)&parameter[i*2]) << 8)) * WTF;

			    printf ("For the range %s, Filter constant is %6.4f\n\r",
				  dcfiltermsg[i],temp_float);
		    }
		    break;
      case 7:     /* Measurement Rate */
		    /*
		    Display the Rate
		    */
		    if (!getcrystalfreq())
		      return(FALSE);

	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
		      i = ((*(unsigned char *)&parameter[0]) & 0xff)
		            + (((*(unsigned char *)&parameter[1]) & 0xff) << 8) ;
	      else                           /* ISA interface does not swap bytes */
		      i = ((*(unsigned char *)&parameter[1]) & 0xff)
		            + (((*(unsigned char *)&parameter[0]) & 0xff) << 8) ;

		    measurementrate = (double)(i) / 256.0;
		    printf ("Measurement Rate: %6.2f\n\r",measurementrate);
        break;
		  case 8:     /* Disable/Enable Data Ready Output */
        if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
        else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    printf ("\n\rData Ready Output is ");
		    if (temp_char == TRUE)
		      printf("ENABLED");
		    else
		      printf("DISABLED");
		    break;
	    case 9:     /* Change Data Ready Character */
	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];
		    printf ("\n\rData Ready Output Character is %u (decimal), <%c> (ASCII)",
                                    (unsigned char) temp_char,(char) temp_char);
		    break;
	    case 10:     /* Error Code */
        if (interface == RS232)  /* Error code is the only byte output by the Bird */
		      /* 2nd passed parameter does not matter, when 3rd parameter = FALSE */
			    displayerror(parameter[0],parameter[1],FALSE);
	      else /* ISA - the error code is LSByte of the word output by the BIRD*/
	        /* 2nd passed parameter does not matter, when 3rd parameter = FALSE */
		      displayerror(parameter[1],parameter[1],FALSE);
        break;
	    case 11:    /* ON ERROR Mask */
	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    switch(temp_char & 0x3)
		    {
		      case 0:   /* FATAL errors are Blinked Forever */
			      printf ("\n\rFATAL Errors are Blinked Forever and Operation is Halted\n\r");
			      break;
		      case 1:   /* FATAL errors are Blinked Once */
			      printf ("\n\rFATAL Errors are Blinked Once and Operation is Resumed \n\r");
			      break;
		      case 2:   /* FATAL errors are Not Blinked  */
			      printf ("\n\rFATAL Errors are Not Blinked and Operation is Halted\n\r");
			      break;
		      case 3:   /* FATAL errors are Not Blinked Forever */
			      printf ("\n\rFATAL Errors are Not Blinked and Operation Continues\n\r");
			      break;
		    }
		    break;
	    case 12:    /* DC Filter Constant Table */
        /*
		    Display the DC Filter Table
		    */
		    for (i=0; i<7; i++)
		    {
	        if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	          temp_short = (unsigned short)((*(unsigned char *)&parameter[i*2]) +
				                          ((*(unsigned char *)&parameter[i*2+1]) << 8));
	        else                           /* ISA interface does not swap bytes */
	          temp_short = (unsigned short)((*(unsigned char *)&parameter[i*2+1]) +
				                            ((*(unsigned char *)&parameter[i*2]) << 8));

		      printf ("\n\rFor the range %s, current value is %u (decimal)\n\r",
			                                               dcfiltermsg[i],temp_short);

		    }
		    break;
		  case 13:    /* Filter Constant Table - Alpha Max */
		    for (i=0; i<7; i++)
		    {
	        if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	          temp_float = ((*(unsigned char *)&parameter[i*2]) +
				                  ((*(unsigned char *)&parameter[(i*2+1)]) << 8)) * WTF;
	        else                           /* ISA interface does not swap bytes */
	          temp_float = ((*(unsigned char *)&parameter[(i*2+1)]) +
				                      ((*(unsigned char *)&parameter[i*2]) << 8)) * WTF;
		      printf ("For the range %s, Filter constant is %6.4f\n\r",
			    dcfiltermsg[i],temp_float);
		    }
		    break;
	    case 14:    /* Glitch Checking */
	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    if (temp_char == TRUE)
		      printf("Sudden Changes are not output");
		    else
			    printf("Sudden Changes are output");
		    break;
	    case 15:    /* Model */
		    parameter[10] = 0; /* set the string termination */
		    printf ("\n\rModel is: %s",&parameter[0]);
		    break;
	    case 16:     /* Expanded Error Code */
		    displayerror(parameter[0],parameter[1],TRUE);
		    break;
	    case 17:    /* XYZ Reference Frame */
	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
	        temp_char = parameter[1];

		    if (temp_char == TRUE)
		      printf("User XYZ Reference Frame defined");
		    else
		      printf("User XYZ Reference Frame Not defined");
		    break;
		  case 18:        /* transmitter mode */
			  if(interface==RS232)
				  temp_char = parameter[0];
        else
          temp_char = parameter[1];

			  switch(temp_char & 0x7F)
				{
				  case 0:
					  printf ("Current transmitter mode is NON-PULSED - [OFF, XON, YON, ZON]\n\r");
					  if (temp_char>0x7F)
              printf( "... running in dual transmitter mode\n\r");
					  break;
				  case 1:
					  printf ("Current transmitter mode is PULSED - [OFF, XON, OFF, YON, OFF, ZON]\n\r");
					  if( temp_char>0x7F)
              printf ("... running in dual transmitter mode\n\r");
					  break;
				  case 2:
					  printf ("Current transmitter mode is 'Cool-Down' - [OFF, XON, short off, YON, short off, ZON]\n\r");
					  if (temp_char>0x7F)
              printf ("... running in dual transmitter mode\n\r");
					  break;
				  default:
					  printf ("Error - Unknown transmitter mode");
					  break;
				}
			  break;
		  case 19:        /* addressing mode */
			  printf("The current addressing mode is ");
			  if(interface==RS232)
				  temp_char = parameter[0];
        else
				  temp_char = parameter[1];

			  switch(temp_char)
				{
				  case 0:
					  printf ("NORMAL (14 FBB devices maximum)\n\r");
					  break;
				  case 1:
					  printf ("EXTENDED (30 FBB devices maximum)\n\r");
					  break;
				  case 3:
					  printf ("SUPER-EXTENDED (126 FBB devices maximum)\n\r");
					  break;
				  case 2:
				  default:
					  printf ("<ERROR>\n\r");
					  break;
				}
			  break;
		  case 20:        /* Line Frequency */
		    if (interface == RS232)        /* Serial Interface Sends swapped bytes */
        	temp_char = parameter[0];
        else                           /* ISA interface does not swap bytes */
        	temp_char = parameter[1];

			  printf ("Line Frequency is %3d Hz\n\r", temp_char);
      	break;
		  case 21:        /* FBB address  */
		    if (interface == RS232)        /* Serial Interface Sends swapped bytes */
        	temp_char = parameter[0];
        else                           /* ISA interface does not swap bytes */
        	temp_char = parameter[1];
        printf ("FBB Address is %3d\n\r", temp_char);
			  break;
		  case 22:      	/* Hemisphere */
			  temp_char = parameter[0];
			  temp_char2 = parameter[1];
      	switch(temp_char)
				{
				  case 0x00:
					  if (temp_char2==0x00)
              printf ("Hemisphere is currently set to FRONT\n\r");
            else
            	printf ("Hemisphere is currently set to REAR\n\r");
            break;
				  case 0x0C:
					  if (temp_char2==0x01)
              printf ("Hemisphere is currently set to UPPER\n\r");
            else
            	printf ("Hemisphere is currently set to LOWER\n\r");
            break;
				  case 0x06:
					  if (temp_char2==0x01)
              printf ("Hemisphere is currently set to LEFT\n\r");
            else
            	printf ("Hemisphere is currently set to RIGHT\n\r");
            break;
				  default:
					  printf ("Hemisphere currently unknown (error)\n\r");
					  break;
				}
		 	  break;
		  case 23:     		/* Angle Align 2 */
			  int_angle[0] = (parameter[0] & 0xFF) | ((parameter[1] << 8) & 0xFF00);
			  int_angle[1] = (parameter[2] & 0xFF) | ((parameter[3] << 8) & 0xFF00);
			  int_angle[2] = (parameter[4] & 0xFF) | ((parameter[5] << 8) & 0xFF00);

			  float_angle[0] = (float)(int_angle[0])/ANG_TO_INT;
			  float_angle[1] = (float)(int_angle[1])/ANG_TO_INT;
			  float_angle[2] = (float)(int_angle[2])/ANG_TO_INT;

			  printf("Angles are Azimuth: %8.2f,   Elevation: %8.2f,   Roll: %8.2f\n\r",
				                        float_angle[0], float_angle[1], float_angle[2]);
  			break;
		  case 24:      	/* Reference Frame 2 */
			  int_angle[0] = (parameter[0] & 0xFF) | ((parameter[1] << 8) & 0xFF00);
			  int_angle[1] = (parameter[2] & 0xFF) | ((parameter[3] << 8) & 0xFF00);
			  int_angle[2] = (parameter[4] & 0xFF) | ((parameter[5] << 8) & 0xFF00);

			  float_angle[0] = (float)(int_angle[0])/ANG_TO_INT;
			  float_angle[1] = (float)(int_angle[1])/ANG_TO_INT;
			  float_angle[2] = (float)(int_angle[2])/ANG_TO_INT;

			  printf("Angles are Azimuth: %8.2f,   Elevation: %8.2f,   Roll: %8.2f\n\r",
				                        float_angle[0], float_angle[1], float_angle[2]);
  			break;
		  case 25:        /* Bird Serial Number */
			  serial_number = (parameter[0] & 0xFF) | ((parameter[1] << 8) & 0xFF00);
			  printf("Bird Serial Number: %6d\n\r", serial_number);
			  break;
      case 26:        /* Xmtr Serial Number */
 			  serial_number = (parameter[0] & 0xFF) | ((parameter[1] << 8) & 0xFF00);
			  printf("Sensor Serial Number: %6d\n\r", serial_number);
        break;
      case 27:        /* Sensor Serial Number */
			  serial_number = (parameter[0] & 0xFF) | ((parameter[1] << 8) & 0xFF00);
			  printf("Xmtr Serial Number: %6d\n\r", serial_number);
        break;
	    case 28:        /* FBB Host Delay */
	      if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_short = (unsigned short)(((*(unsigned char *)&parameter[0]) +
				                       ((*(unsigned char *) &parameter[1]) << 8))) * 10;
	      else                           /* ISA interface does not swap bytes */
	        temp_short = (unsigned short)(((*(unsigned char *)&parameter[1]) +
				                       ((*(unsigned char *) &parameter[0]) << 8))) * 10;

		    printf("\n\rFBB Host Response Delay is %d microseconds",temp_short);
		    break;
	    case 29:        /* Group Data Mode */
        if (interface == RS232)        /* Serial Interface Sends swapped bytes */
	        temp_char = parameter[0];
	      else                           /* ISA interface does not swap bytes */
		      temp_char = parameter[1];

		    if (temp_char == TRUE)
		      printf("\n\rGroup Data Mode is Enabled");
		    else
		      printf("\n\rGroup Data Mode is Disabled");
		    break;
	    case 30:        /* Flock System Config */
		    displayflocksys(&parameter[0]);
		    break;
	    case 31:        /* FBB Auto Configuration - 1 Trans/N Rec */
		    showfbbconfig(&parameter[0]);
		    break;
	    case 32:        /* FBB Configuration */
		    showfbbconfig(&parameter[0]);
		    break;
	  }

	  hitkeycontinue();
	  return(TRUE);
  }
	else
	  return(ESC_SEL);
}

void displayflocksys(parameter)
unsigned char * parameter;
{
    int i;

    /*
       Display the Configuration for each Address
    */
    printf("\n\rFlock Configuration...");
    for (i=0;i<numfbbaddrs;i++)
    {
	/*
	   Allow the User to View the Data on a 25 line Screen
	*/
	if ((((i/21)*21)==i) && (i!=0)) hitkeycontinue();

	printf("\n\rFBB ADDR %d: ",i+1);

	if (parameter[i] & 0x80)
	{
	    if (parameter[i] & 0x10)
		printf("ERC, ");
	    else
		printf("6DFOB, ");
	}
	else
	{
	    printf("NOT ACCESSIBLE");
	    continue;
	}

	if (parameter[i] & 0x40)
	    printf("RUNNING, ");
	else
	    printf("NOT RUNNING, ");

	if ((parameter[i] & 0x30) == 0x20)
	    printf("RCVR");
	if ((parameter[i] & 0x30) == 0x00)
	    printf("NO RCVR");

	if ((parameter[i] & 0x11) == 0x01)
		 printf(", XMTR ");
	else
	{
	   if ((parameter[i] & 0x10) == 0x00)
	       printf(", NO XMTR");
	}

	if ((parameter[i] & 0x11) == 0x11)
	    printf(" ERT 0");

	if ((parameter[i] & 0x12) == 0x12)
	    printf(" ERT 1");

	if ((parameter[i] & 0x14) == 0x14)
	    printf(" ERT 2");

	if ((parameter[i] & 0x18) == 0x18)
	    printf(" ERT 3");

	if ((parameter[i] & 0x1f) == 0x10)
	    printf(" NO ERTs");
    }

	 hitkeycontinue();

    return;
}


/*
    bird_crtsync        - Implements the CRT SYNC command

    Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       TRUE if a command was executed
			FALSE if command could not be executed
			ESC_SEL if the user selected escape

    Remarks:
*/
int bird_crtsync()
{
    short i;
	 unsigned char birdcrtsyncmode;
    unsigned char birdcrtsyncdata[4];
    static char * crtsyncmenu[] = {"Select Sync mode:",
				   "All  Sync Off",
				   "CRT  Sync - CRT Vertical Retrace Greater than 72 Hz",
				   "CRT  Sync - CRT Vertical Retrace Less than 72 Hz",    
				   "Display CRT Pickup Info",
				   "Host Sync"
				   };     
				   
				   
    /*
	Find out what the user wants to do ...
    */
    switch (sendmenu(crtsyncmenu,5))
    {
	case 0:     /* CRT sync OFF */
	    /*
		Set the Sync Type
	    */
	    birdcrtsyncmode = 0;
		hostSyncFlag = false;

		 /*
		Send the Command
	    */
	if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
	{
	   if (bird_crtsync_serial(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#ifdef DOS
	else                 /* ELSE - ISA interface */
			     /* use commands from ISA interface commands file */
	{
	   if (bird_crtsync_isa(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#endif
	    printf("CRT sync OFF command sent to the Bird\n\r");

	    break;

	case 1:     /* CRT sync - > 72 Hz */
	    /*
		Set the Sync Type
	    */
		 birdcrtsyncmode = 1;
		hostSyncFlag = false;

	    /*
		Send the Command
	    */
	if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
	{
	   if (bird_crtsync_serial(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#ifdef DOS
	else                 /* ELSE - ISA interface */
			     /* use commands from ISA interface commands file */
	{
	   if (bird_crtsync_isa(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#endif
	    printf("CRT sync '1' command sent to the Bird\n\r");

	    break;

	case 2:     /* CRT sync - < 72 Hz */
	    /*
		Set the Sync Type
		 */
	    birdcrtsyncmode = 2;
		hostSyncFlag = false;

	    /*
		Send the Command
	    */
	if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
	{
	   if (bird_crtsync_serial(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#ifdef DOS
	else                 /* ELSE - ISA interface */
			     /* use commands from ISA interface commands file */
	{
	   if (bird_crtsync_isa(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#endif
	    printf("CRT sync '2' command sent to the Bird\n\r");
	    break;

	case 3:     /* Display Pickup Values*/

	/* clear Bird output buffer */
#ifdef DOS
	bird_clearoutputbuffer_isa();
#endif
	    /*
		Get the Crystal Frequency
	    */
	    if (!getcrystalfreq())
		return(FALSE);

	    birdcrtsyncmode = 255;
		hostSyncFlag = false;

	    /*
		Stay in a Loop displaying the Pickup Values
	    */
	    do
	    {

	if (interface == RS232)/* IF Serial Interface THEN ...*/
			   /* use commands from serial interface commands file */
	{
	   if (bird_crtsync_serial(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#ifdef DOS
	else                 /* ELSE - ISA interface */
			     /* use commands from ISA interface commands file */
	{
	   if (bird_crtsync_isa(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#endif
		/*
		    Display the Retrace Voltage
		*/
	if (interface == RS232)       /* Serial Interface swaps the bytes */
		   i = *(unsigned char *) &birdcrtsyncdata[0] +
		       ((*(unsigned char *) &birdcrtsyncdata[1]) << 8);
	else                          /* ISA interface does not swap the bytes */
		   i = *(unsigned char *) &birdcrtsyncdata[1] +
		       ((*(unsigned char *) &birdcrtsyncdata[0]) << 8);

		printf ("%6.4f  ", (float)((float)i * 5.0/32768.0));

		/*
		    Compute the Retrace Rate if the count is not = 0
		    ...then display
		*/
	if (interface == RS232)       /* Serial Interface swaps the bytes */
			i = *(unsigned char *)&birdcrtsyncdata[2] +
			 ((*(unsigned char *)&birdcrtsyncdata[3]) << 8);
	else                          /* ISA interface does not swap the bytes */
	       i = *(unsigned char *) &birdcrtsyncdata[3] +
		       ((*(unsigned char *) &birdcrtsyncdata[2]) << 8);

		if (i != 0)
		     printf ("      %6.2f\n\r",
			  (float)((125000.0 * crystalfreq)/(unsigned short)i)/2);
		else
		     printf ("       00.00\n\r");
	    }
	    while (!ckkbhit());   /* Stay in the loop until a key is hit */
	    clearkey();           /* clear the keyboard */

	    /*
		    Set the Sync Type to OFF
	    */
	    birdcrtsyncmode = 0;

	    /*
		Send the Command
	    */
	if (interface == RS232)/* IF Serial Interface THEN ...*/
					 /* use commands from serial interface commands file */
	{
	   if (bird_crtsync_serial(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#ifdef DOS
	else                 /* ELSE - ISA interface */
			     /* use commands from ISA interface commands file */
	{
	   if (bird_crtsync_isa(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
	      return(FALSE);
	}
#endif
	    break;   
	    
	    case 4:  
		birdcrtsyncmode = 8;  
		hostSyncFlag = true;
		    /*
			Send the Command
		    */
		if (interface == RS232)/* IF Serial Interface THEN ...*/
				   /* use commands from serial interface commands file */
			{
			if (bird_crtsync_serial(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
			return(FALSE);
			}
#ifdef DOS
		else                 /* ELSE - ISA interface */
				     /* use commands from ISA interface commands file */
			{
			if (bird_crtsync_isa(birdcrtsyncmode, birdcrtsyncdata) == FALSE)
			return(FALSE);
			}
#endif
		    printf("Host sync command sent to the Bird\n\r");  
		break;

	    case ESC_SEL:
			hostSyncFlag = false;
			return(ESC_SEL);                
    }
    hitkeycontinue();
    return(TRUE);
}

/*
    nextmastercmd       - Next Master Command

    Prototype in:       birdcmds.c

    Parameters Passed:  void

    Return Value:       TRUE if command sent OK
			FALSE if command could not be sent
			ESCSEL if the user selected ESC

    Remarks:
*/
int nextmastercmd()
{
    int nextmaster;
    char * nextmasterques = "\n\rEnter the NEXT Master address (1 - 14): ";

    printf ("%s",nextmasterques);
    while ((nextmaster = getnumber()) != ESC_SEL)
    {
	if ((nextmaster > 0) && (nextmaster < 15))
	{
	if (interface == RS232)/* IF Serial Interface THEN ...*/
			       /* use commands from serial interface commands file */
	{
	       if (bird_nextmaster_serial(nextmaster) == FALSE)
	   {
		      printf("** ERROR ** could not send the NEXTMASTER command\n\r");
		      hitkeycontinue();
	      return(FALSE);
	   }
	}
#ifdef DOS
	else                 /* ELSE - ISA interface */
				  /* use commands from ISA interface commands file */
	{
	       if (bird_nextmaster_isa(nextmaster) == FALSE)
	   {
		      printf("** ERROR ** could not send the NEXTMASTER command\n\r");
		      hitkeycontinue();
	      return(FALSE);
	   }
	}
#endif
		return(TRUE);
	}
	else
	{
	    printf("** ERROR ** invalid address\n\r");
	    printf ("%s",nextmasterques);
	}
    }
    return(ESC_SEL);
}


/*
    nextxmtrcmd         - Next Transmitter Command

	 Prototype in:       birdcmds.c

    Parameters Passed:  void

    Return Value:       TRUE if command sent OK
			FALSE if command could not be sent
			ESCSEL if the user selected ESC

    Remarks:
*/
int nextxmtrcmd()
{
    int nextxmtraddr;
    int nextxmtrnum = 0;
    char * nextxmtrques1 = "\n\rEnter the NEXT TRANSMITTER address (1-14): ";
    char * nextxmtrques2 = "\n\rEnter the NEXT TRANSMITTER number (0-3): ";

    /*
	Get the System Status because we will need to which device
	has a transmitter
    */
    if (!getsystemstatus())
	return(FALSE);

	 printf ("%s",nextxmtrques1);
    while ((nextxmtraddr = getnumber()) != ESC_SEL)
    {
	if ((nextxmtraddr > 0) && (nextxmtraddr < 15))
	{
	    if (fbbsystemstatus[nextxmtraddr] & 0x0f)
		   break;
	    else
	    {
		printf("** ERROR ** transmitter not available at that address\n\r");
		printf ("%s",nextxmtrques1);
	    }
	}
	else
	{
	    printf("** ERROR ** invalid address\n\r");
	    printf ("%s",nextxmtrques1);
	}
    }

    if (nextxmtraddr == ESC_SEL)
	return(ESC_SEL);

	 /*
	Only ask for the transmitter number if the device is an ERC
    */
    if (fbbsystemstatus[nextxmtraddr] & 0x10)
    {
	printf ("%s",nextxmtrques2);
	while ((nextxmtrnum = getnumber()) != ESC_SEL)
	{
	    if ((nextxmtrnum >= 0) && (nextxmtrnum <= 3))
	    {
		if (!(fbbsystemstatus[nextxmtraddr] & (0x1 << nextxmtrnum)))
		{
		    printf("** ERROR ** ERT selection not available at that address\n\r");
		    printf ("%s",nextxmtrques2);
		}
		else
		{
		    /*
			Else the Transmitter number OK so ready to load it
		    */
		    break;
		}
	    }
	    else
		 {
		printf("** ERROR ** invalid xmtr number\n\r");
		printf ("%s",nextxmtrques2);
	    }
	}
    }

    if (nextxmtrnum == ESC_SEL)
	return(ESC_SEL);


    if (interface == RS232)/* IF Serial Interface THEN ...*/
			      /* use commands from serial interface commands file */
    {
	   if (bird_nextxmtr_serial(nextxmtraddr,nextxmtrnum) == FALSE)
       {
	  printf("** ERROR ** could not send the NEXT XMTR command\n\r");
		  hitkeycontinue();
	  return(FALSE);
       }
    }
#ifdef DOS
    else                 /* ELSE - ISA interface */
			 /* use commands from ISA interface commands file */
    {
		if (bird_nextxmtr_isa(nextxmtraddr,nextxmtrnum) == FALSE)
		 {
	  printf("** ERROR ** could not send the NEXT XMTR command\n\r");
		  hitkeycontinue();
	  return(FALSE);
       }
    }
#endif

    printf("..NEXT XMTR command sent\n\r");
    hitkeycontinue();
    return(TRUE);
}


/*
    showfbbconfig       Display the FBB Configuration

    Prototype in:       cmdutil.h

    Parameters Passed:  void

    Return Value:       void

    Remarks:            Displays the FBB Configuration information pointed
			to by fbbconfig

*/
void showfbbconfig(fbbconfig)
unsigned char * fbbconfig;
{
    short i;
    short j;
    short active;

    switch (fbbconfig[0])
    {
	case 0:
	    printf("\n\rFBB Bird configured for Stand Alone Operation\n\r");
	    break;
	case 1:
	    printf("\n\rFBB Bird configured for 1 Transmitter/N Receiver Operation\n\r");
	    break;
	default:
	    printf("** ERROR ** invalid FBB Configuration Mode\n\r");
    }
    hitkeycontinue();

    printf("\n\rFBB Devices..");
	 for (i=1;i<=numfbbaddrs;i++)
	 {
	printf("\n\rDevice at FBB address %d is ", i);
	if (i < 15)
	{
	    j = *(unsigned char *)&fbbconfig[1] +
		((*(unsigned char *)&fbbconfig[2]) << 8);
	    active = ((0x1 << i) & j);
	}
	else
	{
	    j = *(unsigned char *)&fbbconfig[5] +
		((*(unsigned char *)&fbbconfig[6]) << 8);
	    active = ((0x1 << (i-15)) & j);
	}

	if (active)
	   printf("RUNNING");
	else
	   printf("NOT RUNNING");

	if (i == 20)    /* Don't let the info run off the screen */
	   hitkeycontinue();

	 }
	 hitkeycontinue();

    printf("\n\rFBB Dependents..");
    for (i=1;i<=14;i++)
    {
	printf("\n\rDevice at FBB address %d is ", i);
	j = *(unsigned char *)&fbbconfig[3] +
	    ((*(unsigned char *)&fbbconfig[4]) << 8);
	if ((0x1 << i) & j)
	   printf("DEPENDENT");
	else
	   printf("NOT DEPENDENT");
    }
}



		    /* return number of samples taken*/

int getsamples(samplesize,mean,stddev,pk_pk,maximum,minimum)
int samplesize; 
double mean[]; 
double stddev[];
double pk_pk[];
double maximum[];
double minimum[];
{
  short i;
  int index;
  unsigned char temprs232tofbbaddr;
  short birddata[14]; 
  unsigned char posorientcmd;
  unsigned char datasize;
  int wfc;
  double floatdata[6], sx[6], sx2[6];
  short outputmode = CONTINUOUS;
  short buttonmode = 0;
  short cmdsize=0;
  static unsigned char birdchangevaluecmd[] = {'P',0,0,0,0,0};  

  /* make sure not in FBB group mode - add later */
  /* no button mode */
  /* initialize mean[] and stddev[] */

  for (index=0; index<6; index++) 
  {
    mean[index]=0; stddev[index]=0; 
    sx[index]=0; sx2[index]=0;
    maximum[index]=-9999; minimum[index]=9999;
  }

  /*
  send the mode Command (ie. POSANGLES)
  */
  posorientcmd = 'Y';
  datasize = 6;
  if (send_cmd(&posorientcmd,1) != 1)
    return(0);
  
  /*
  enable data ready char, only to master
  */
  temprs232tofbbaddr = (unsigned char)rs232tofbbaddr;
  rs232tofbbaddr = 0; /* to master */
  birdchangevaluecmd[1] = 8;
  if (interface == RS232)
  {
    birdchangevaluecmd[2] = 1;
    cmdsize = 3;
  }
#ifdef DOS
  else                /* ISA BUS */
  {
    birdchangevaluecmd[2] = 0;
    birdchangevaluecmd[3] = 1;
    cmdsize = 4;
  }
#endif
	
  if (send_cmd(birdchangevaluecmd,cmdsize) != cmdsize) 
  {
    printf("\n\r * problem sending data ready char enable *");
    rs232tofbbaddr = temprs232tofbbaddr;
    return(0);
  }
  rs232tofbbaddr = temprs232tofbbaddr;

  /*
  wait 5 cycles for filters to settle
  */

  //printf("waiting for data ready char (1)\n\r");

  for (index=0; index<5; index++)
    do  /* wait for data ready char from master */ 
    {
      wfc = waitfordata();
    } while ( wfc != (int)(data_ready_char) );

  //printf("waiting for data ready char (2)\n\r");

  for (index=0; index<samplesize; index++) 
  {
    printf("\r %3d ",index+1);

    /* 
    wait for data ready char from master before taking record from bird
    */
    do
    {
      wfc = waitfordata(); /* timed out at low measurement speed (14-16 Hz) */  
    } while ( wfc != (int)(data_ready_char) );

    /*
    request a new point from bird
    */
    if (send_cmd((unsigned char *)"B",1) != 1) /* get another set of points */
    {
      /*
      disable data ready char from master, error exit
      */
      birdchangevaluecmd[1] = 8;
      if (interface == RS232)
      {
        birdchangevaluecmd[2] = 0;
	cmdsize = 3;
      }
#ifdef DOS
      else                /* ISA BUS */
      {
	birdchangevaluecmd[2] = 0;
	birdchangevaluecmd[3] = 0;
	cmdsize = 4;
      }
#endif
	
      if (send_cmd(birdchangevaluecmd,cmdsize) != cmdsize) 
      	printf("\n\r * problem sending data ready char disable *"); 
		    
      return(0);           /* return done if errors */
    }       

    /*
    get the data NOW
    */
    //printf("outputmode = %4x\n\r", outputmode);
    //hitkeycontinue();  
  
    if (!readbirddata(birddata,datasize,outputmode,buttonmode))
    {
      /*
      disable data ready char, error exit
      */
      temprs232tofbbaddr = (unsigned char)rs232tofbbaddr;
      rs232tofbbaddr = 0; /* to master */
      birdchangevaluecmd[1] = 8;
      if (interface == RS232)
      {
        birdchangevaluecmd[2] = 0;
	cmdsize = 3;
      }
#ifdef DOS
      else                /* ISA BUS */
      {
	birdchangevaluecmd[2] = 0;
	birdchangevaluecmd[3] = 0;
	cmdsize = 4;
      }
#endif
      if (send_cmd(birdchangevaluecmd,cmdsize) != cmdsize)
	printf("\n\r * problem sending data ready char disable *");
      rs232tofbbaddr = temprs232tofbbaddr;
      return(0);           /* return done if errors */
    }

    for (i=0;i<6;i++)
    {
      if (i<3)
        floatdata[i] = (double)(birddata[i] * posk);
      else
        floatdata[i] = (double)(birddata[i] * ANGK);
      sx[i]+=floatdata[i];
      sx2[i]+= (floatdata[i]*floatdata[i]);
      if (floatdata[i]<minimum[i])
        minimum[i]=floatdata[i];
      if (floatdata[i]>maximum[i])
        maximum[i]=floatdata[i];
    }
  }
 
  /* finish calculating the mean and Stddev */
  for (index=0; index<6; index++)
  {
    double temp;
    mean[index] = sx[index]/(double)samplesize;
    temp= sx2[index]/(double)samplesize - mean[index]*mean[index];
    stddev[index] = sqrt(fabs(temp));
    pk_pk[index]=maximum[index]-minimum[index];
  }

  /*
  disable data ready char from master, pior to normal exit
  */
  temprs232tofbbaddr = (unsigned char)rs232tofbbaddr;
  rs232tofbbaddr = 0; /* to master */
  birdchangevaluecmd[1] = 8;
  if (interface == RS232)
  {
    birdchangevaluecmd[2] = 0;
    cmdsize = 3;
  }
#ifdef DOS
  else                /* ISA BUS */
  {
    birdchangevaluecmd[2] = 0;
    birdchangevaluecmd[3] = 0;
    cmdsize = 4;
  }
#endif

  if (send_cmd(birdchangevaluecmd,cmdsize) != cmdsize)
  {
    printf("\n\r * problem sending data ready char disable *");
    rs232tofbbaddr = temprs232tofbbaddr;
    return(0);
  }
  rs232tofbbaddr = temprs232tofbbaddr;

  return(samplesize);
}


void printsamples(int samplesize, double mean[], double stddev[], 
		double pk_pk[], double maximum[], double minimum[]) 
{
 int index;
 
 printf("\r     X       Y       Z      Az      El     Roll\t\t%4d samples\n",samplesize);
 for (index=0; index<6; index++) printf("%7.2lf\t",mean[index]);
 printf("\tMean\n\r");
 for (index=0; index<6; index++) printf("%7.2lf\t",maximum[index]);
 printf("\tMax\n\r");
 for (index=0; index<6; index++) printf("%7.2lf\t",minimum[index]);
 printf("\tMin\n\r");
 for (index=0; index<6; index++) printf("%7.2lf\t",pk_pk[index]);
 printf("\tPeak to Peak\n\r");
 for (index=0; index<6; index++) printf("%7.2lf\t",stddev[index]);
 printf("\tStd Deviation\n\r");
 printf("\n\n");

 /* hitkeycontinue(); */
}

void clearbuff()     /* clear serial buffer  function */
{
  short rxchar;

  if (interface == RS232)
  {
     do
       rxchar = get_serial_char();
     while ( rxchar != NODATAAVAIL );
  }
#ifdef DOS
  else              /* ISA interface */
     /* clear Bird output buffer */
     bird_clearoutputbuffer_isa();
#endif
}



void getsamplesoverrange(int samplesize) {
 double                                 start, end, step, temp, present;
 unsigned char                  temprs232tofbbaddr;
 int                                    stepnumber, index;
 double                                 mean[6], stddev[6], pk_pk[6];
 double                                 maximum[6], minimum[6], noise;
 unsigned short                 i, el;
 unsigned short                 xmtr_time_cnt;
 double                                 xtime;
 short                                  cmdsize=0;
 static unsigned char   birdchangevaluecmd[] = {'P',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 unsigned short                 min_rate;

  /*
	Get the CPU crstal freq from master
  */
  clearbuff();

  temprs232tofbbaddr = (unsigned char)(rs232tofbbaddr);
  rs232tofbbaddr = 0; /* to master */
  if (!getcrystalfreq()) {
	  printf("\n\r * problem getting crystal frequency *");
	  return;
  }
  rs232tofbbaddr = temprs232tofbbaddr;
  printf("\n\r Crystal Frequency is: %4.1f\n",crystalfreq);
  /*
	  Get the slowest measurement rate from known crystalfreq
     (see Manual, Examine/Change Parameter 6 [Measurement rate])
     MIN measurement rate  = 1000 / (4 * XTIME + 0.3)
     where XTIME = XMTR_TIME_CNT_max * CLOCK/1000
	   CLOCK is a period of one computer time count in microseconds:
	   CLOCK = 8 / crystalfreq
	   XMTR_TIME_CNT_max = 65536 (16 bits data)
  */
  temp = (65536 / 1000) * (8.0 / crystalfreq);                                  /* calcualate XTIME */
  min_rate = (int)(1000 /(4 * temp + 0.3));    /* min measurement rate */
  printf("\n\r Choose starting and ending frequencies (%3d - 144Hz)",min_rate);
  start=getfloat("\n What starting frequency:",min_rate,144);
  end=getfloat(" What ending frequency:",min_rate,144);
  if (start==end) {
	printf("Start value and End value can not be the same.");
	hitkeycontinue();
	return;
  }
  if (start>end) {
    temp=start; start=end; end=temp;
  }
  do {
   step=getfloat(" What step frequency (positive number):",0,144);
  } while (step<=0);

  printf("\n\n\rMeasurement rate at START of scan in Measurments/sec %6.2f.",start);
  printf("\n\rMeasurement rate at END of scan %6.2f.",end);
  printf("\n\rScan step size in measurments/sec %6.2f",step);
    
  /* 
      get the average receiver position for display
  */
  printf("\n\n\r");

  getsamples(100,mean,stddev,pk_pk,maximum,minimum);
  
  printf("\rRECEIVER LOCATION\n\tX\tY\tZ\tAz\tEL\tROLL");
  printf("\n\r      %6.2lf  %6.2lf  %6.2lf %7.2lf %7.2lf %7.2lf",
	     mean[0],mean[1],mean[2],mean[3],mean[4],mean[5]);

  if (fabs(mean[4])<45.0) { 
     /* EL below 45 degrees, use average Euler angle statistics */
     el=0;
     printf("\n\n\rSpeed   Xtime    Xmtr_Time_Cnt    Avg Euler Pk-Pk\n");
  } else {
     el=1;
     printf("\n\n\r* NOTE *  because Euler elevation was larger then 45 degrees, only ");
	  printf("\n\relevation Peak to Peak will be displayed.");
	  printf("\n\n\rSpeed   Xtime    Xmtr_Time_Cnt     EL Pk-Pk\n");
  }

  stepnumber = (int) ( (end-start)/step );

  for (present=start,index=0; index<=stepnumber; index++) {
    
    /*
	Check to see if user is tire of waiting
    */
    if (ckkbhit()) {
	printf("\n\n\r ** Keyboard break ** \n");
	break;
    }

    /*
      set measurement rate
    */

      /*
	Set the Parameter number and the command size
      */
      birdchangevaluecmd[1] = 6;
		cmdsize = 4;

      /*
	convert to transmitter time counts
      */
      i = (unsigned)(((crystalfreq/8.0)*1000.0)*
		   (((1000.0/present)-0.3)/4.0));
      if (interface == RS232)    /* Serial Interface swap MSByte and LSByte */
      {
	 *(unsigned char *)&birdchangevaluecmd[2] = (unsigned char) (i & 0xff);
	 *(unsigned char *)&birdchangevaluecmd[3] = (unsigned char) ((i & 0xff00) >> 8);
	  }
      else                       /* ISA Interface does not swap bytes */
      {
	 *(unsigned char *)&birdchangevaluecmd[2] = (unsigned char) ((i & 0xff00) >> 8);
	 *(unsigned char *)&birdchangevaluecmd[3] = (unsigned char) (i & 0xff);
	  }
      xmtr_time_cnt = i;
      xtime = xmtr_time_cnt*(8.0/crystalfreq)/1000.0;
      
      /*
	 Send the new measurement speed Command to the Master unit
      */
      temprs232tofbbaddr = (unsigned char)rs232tofbbaddr;
		rs232tofbbaddr = 0; /* to master */

      if (send_cmd(birdchangevaluecmd,cmdsize) != cmdsize) {
	       printf("\n\r * problem setting new measurement rate *");
	       rs232tofbbaddr = temprs232tofbbaddr;
	       return;
      }
      rs232tofbbaddr = temprs232tofbbaddr;       

    if (getsamples(samplesize,mean,stddev,pk_pk,maximum,minimum)!=samplesize) 
	  return;

    if (el==0) noise = (pk_pk[3]+pk_pk[4]+pk_pk[5])/3.0;
    else noise = pk_pk[4];

    printf("\r%5.1lf   %6.3f   %10u         %5.2lf\n",present,xtime,xmtr_time_cnt,noise);
    present+=step;
    if (present>end) present=end;
  }
  hitkeycontinue();
}



/*
	 getbirdstatistics   - aquire data and take noise statistics

	 Prototype in:       birdcmds.h

    Parameters Passed:  void

    Return Value:       void

    Remarks:            Being developed.
*/

void getbirdstatistics(){

    int samplesize;
    int answer;
    double mean[6],stddev[6],pk_pk[6],maximum[6],minimum[6];    


    static char * birdstatmenu[] = {"Select Statistics option:",
				   "Return to main menu",
				   "Change sample number",
				   "Take POS/ANGLE samples",
				   "Take samples over a range"};

	 samplesize=500;

	 printf("\n\r** Reminder **");
    printf("\n\rIf you have a multiple receiver system and using one RS232 to");
    printf("\n\rthe master, then you must use the RS232 to FBB command to select");
    printf("\n\rthe receiver you want noise statistics from.");
    printf("\n\rTake receiver out of BUTTON mode and GROUP mode.");
    printf("\n\rTo get statistics at measurement rates above 110 Hz, the baud rate");
    printf("\n\rmust be at least 38400.\n");

    while (1) {   /* loop forever */

      printf("\n\rDefault sample number: %4d\n",samplesize);
       /*
	   Find out what the user wants to do ...
       */
      
      switch (sendmenu(birdstatmenu,4))
      {
	case 0:     /* return to main menu */
	   return;

	case 1:     /* specify sample size */
		do {
		  printf ("\n\rEnter the number of samples for statistics: ");
	     if ((answer = getnumber()) == ESC_SEL)  break;
		  if (answer<3)
		printf("\n\r number must be greater then 3 (or ESC key)");
	   } while (answer < 3) ;
	   samplesize=answer;
	   break;

	case 2:     /* take samples pos/angles */
	   printf("Sampling %d data records from ",samplesize);
	   if (rs232tofbbaddr<2) printf("Master Receiver..\n\r");
	   else printf("Receiver at address %d..\n\r",rs232tofbbaddr);
	   while (!ckkbhit()) 
	    if ( getsamples(samplesize,mean,stddev,pk_pk,maximum,minimum) == samplesize)
		printsamples(samplesize,mean,stddev,pk_pk,maximum,minimum);
	    else {
	      printf("Error taking samples, no statistics calculated");
	      clearkey();
	      break;
	    }
	   clearkey();
	   break;
	
	case 3:   /* take samples over a range (of cycle speeds) */
		printf("Sampling %d data records from ",samplesize);
	   if (rs232tofbbaddr<2) printf("Master Receiver..\n\r");
		else printf("Receiver at address %d..\n\r",rs232tofbbaddr);
	   getsamplesoverrange(samplesize);
      }
      printf("\n\n\n\r");
    } /* while loop */
}



void fbb_reset(void)
{
	printf("Resetting the Slaves through the FBB\n\r");     
	send_cmd((unsigned char *)"/",1);
    hitkeycontinue();
}

void z_commands(void)
{
	printf("Resetting the Master Bird\n\r");
	send_cmd((unsigned char *)"z",1);
	send_cmd((unsigned char *)"b",1);
	#ifdef TC		/* Borland Turbo C */
	  delay (2000);
	#endif
	hitkeycontinue();
}
