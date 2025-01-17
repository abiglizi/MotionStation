/*
    asctech.h       - Ascension Technology Header

    Modification History

	10/18/90    jf - released
	11/7/90     jf - added DEFAULTCRYSTALFREQ
	9/17/91     jf - added POSK36 and POSK72
	4/7/92      jf - added POSK144
	1/26/93     jf - added data modes
2/23/96  vk..ANG_TO_INT, MEAS_RATE_TO_INT definition added
*/




#ifdef MAIN            
	int             enhancedModeFlag;    
	int             addressMode;  
	int             hostSyncFlag;
#else
	extern int      enhancedModeFlag;    
	extern int      addressMode; 
	extern int      hostSyncFlag; 
#endif            
	    
	    
#define NORMAL                          0
#define EXTENDED                        1   
#define SUPER_EXTENDED                  3         
	    
	    
#ifndef ASCTECH
#define ASCTECH    

#define true    1
#define false   0

#define TRUE    1
#define FALSE   0
#define ON      1
#define OFF     0

/*
    Number Conversions
*/
#define DTR (float)(3.141593/180.0)                 /* degrees to radians */
#define FTW (float)32768.0                          /* float to word integer */
#define WTF (float)(1.0/32768.0)                    /* float to word integer */
#define ANGK (float)(180.0/32768.0)                 /* integer to degrees */
#define ANG_TO_INT (float)(32767.0/180.0)           /* degrees to integer */
#define MEAS_RATE_TO_INT (float)(65536.0/256.0)     /* measurement rate to integer */
#define POSK36 (float)(36.0/32768.0)                /* integer to inches */
#define POSK72 (float)(72.0/32768.0)                /* integer to inches */
#define POSK144 (float)(144.0/32768.0)              /* integer to inches ER Controller */

/*
    Output Mode defintions
*/
#define POINT 0
#define CONTINUOUS 1
#define STREAM  2

/*
    Data Mode Definitions
*/
#define POS         1
#define ANGLE       2
#define MATRIX      3
#define QUATER      4
#define POSANGLE    5
#define POSMATRIX   6
#define POSQUATER   7

/*
    Bird Timing definitions
*/
#define DEFAULTCRYSTALFREQ (float) 20.00        /* CPU Clock Frequency */
#define DEFAULTCLOCKVALUE (float) 0.40          /* 8/DEFAULTCRYSTALFREQ */


#endif /* ASCTECH */
