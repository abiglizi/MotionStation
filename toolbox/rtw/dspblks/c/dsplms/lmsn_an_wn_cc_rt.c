/**********************/  
/* 
 * lmsn_an_wn_cc_rt.c - Signal Processing Blockset Normalized LMS adaptive filter run-time function 
 * 
 * Specifications: 
 * 
 * - Complex (single precision) Input Signal
 * - Complex (single precision) Desired Signal
 * - All outputs complex (single precision)
 * - Adapt input port - NO
 * - Weight output port - NO
 * 
 *  Copyright 1995-2003 The MathWorks, Inc.
 *  $Revision: 1.1.6.1 $Date: 2003/12/06 15:57:17 $ 
 */  
#include "dsp_rt.h" 
#include "dsplms_rt.h" 


EXPORT_FCN   void MWDSP_lmsn_an_wn_CC(   const creal32_T *inSigU, 
                                const creal32_T *deSigU, 
                                const real32_T   muU,
                                uint32_T      *buffStartIdx, 
                                creal32_T       *inBuff, 
                                creal32_T       *wgtBuff,
                                const int_T    FilterLength, 
                                const real32_T   LkgFactor, 
                                const int_T    FrmLen, 
                                const int_T    bytesPerInpElmt,
                                creal32_T       *outY,
                                creal32_T       *errY,
                                real32_T       *enrgInBuff)
{

int_T i,j;
creal32_T *initWgtICptr = wgtBuff;

memset(outY,0,bytesPerInpElmt*FrmLen);

for (i=0; i<FrmLen; i++) 
{
       wgtBuff = initWgtICptr ;
 /* Step-1: Copy the current sample at the END of the circular buffer and update BuffStartIdx */ 
       /* get the energy of the signal in updated buffer (though calculated before update) */ 
       *enrgInBuff -=  CMAGSQp(inBuff + *buffStartIdx) - CMAGSQp(inSigU + i);
       *(inBuff+ (*buffStartIdx)) = *(inSigU + i);
       if (++(*buffStartIdx) == (uint32_T)FilterLength) *buffStartIdx=0;

 /* Step-2: multiply wgtBuff_vector (not yet updated) and inBuff_vector */  
       for (j=buffStartIdx[0]; j < FilterLength; j++) 
       {  /* note: wgtBuff's starting point is 0 and inBuff's starting point is BuffStartIdx */  
          outY->re += (wgtBuff->re)*((inBuff + j)->re) - (wgtBuff->im)*((inBuff + j)->im);
          outY->im += (wgtBuff->re)*((inBuff + j)->im) + (wgtBuff->im)*((inBuff + j)->re);wgtBuff++;
       }  
       for (j=0; j < (int_T)buffStartIdx[0]; j++) 
       {  /* note: wgtBuff's starting point is 0 and inBuff's starting point is BuffStartIdx */  
          outY->re += (wgtBuff->re)*((inBuff + j)->re) - (wgtBuff->im)*((inBuff + j)->im);
          outY->im += (wgtBuff->re)*((inBuff + j)->im) + (wgtBuff->im)*((inBuff + j)->re);wgtBuff++;          
       }

  /* Step-3: get error for the current sample */  
       errY->re = deSigU->re - outY->re;
       errY->im = (deSigU++)->im - (outY++)->im;  /* errY++ not here */  

  /* Step-4:Update wgtIC for next input sample */  
       wgtBuff = initWgtICptr;
       for (j=buffStartIdx[0]; j < FilterLength; j++) 
       {  /* note: wgtBuff's starting point is 0 and inBuff's starting point is BuffStartIdx */   
          real32_T reQuotient = ((inBuff + j)->re)/ (*enrgInBuff + FLT_EPSILON);
          real32_T imQuotient = ((inBuff + j)->im)/ (*enrgInBuff + FLT_EPSILON);
          wgtBuff->re = ( (errY->re)*reQuotient + (errY->im)*imQuotient)*muU + LkgFactor*(wgtBuff->re);
          wgtBuff->im = (-(errY->re)*imQuotient + (errY->im)*reQuotient)*muU + LkgFactor*(wgtBuff->im);wgtBuff++;          
       } 
       for (j=0; j < (int_T)buffStartIdx[0]; j++) 
       {    
          real32_T reQuotient = ((inBuff + j)->re)/ (*enrgInBuff + FLT_EPSILON);
          real32_T imQuotient = ((inBuff + j)->im)/ (*enrgInBuff + FLT_EPSILON);
          wgtBuff->re = ( (errY->re)*reQuotient + (errY->im)*imQuotient)*muU + LkgFactor*(wgtBuff->re);
          wgtBuff->im = (-(errY->re)*imQuotient + (errY->im)*reQuotient)*muU + LkgFactor*(wgtBuff->im);wgtBuff++;         
       }
       errY++;
}
}

/* [EOF] lmsn_an_wn_cc_rt.c */   

