/*
 *  ALLPOLE_DF_ZD_A0SCALE_RT.C - DSP Allpole DF filter runtime helper function.
 *
 *  Copyright 1995-2003 The MathWorks, Inc.
 *  $Revision: 1.3.2.3 $  $Date: 2004/04/12 23:40:50 $
 */
#include "dsp_rt.h"

EXPORT_FCN void MWDSP_AllPole_DF_A0Scale_ZD(
                       const creal_T         *u,
                       creal_T               *y,
                       creal_T        * const mem_base,
                       int32_T                 *offset_mem,
                       const int_T            numDelays,
                       const int_T            sampsPerChan,
                       const int_T            numChans,
                       const real_T  * const a,
                       const boolean_T        one_fpf)
{
    int_T k;
    int_T indexD    = *offset_mem;
    int_T stateLen = numDelays +1;

    /* Loop over each input channel */
    for (k=0; k < numChans; k++) {   /* channel loop */
        int_T i        = sampsPerChan;
        /* Beginning of denominator coefficient buffer for this channel */
        const real_T *den = a;  
        real_T over_a0 = 1.0 / *den;  

        /* state memory for this channel */
        creal_T *filt_mem = mem_base + k*stateLen; 

        /* circular buffer offset relative to root in each channel */
        indexD    = *offset_mem;  
        
        while (i--) {   /* frame loop */
            creal_T  psumDEN = {0.0, 0.0};
            int_T j;
            creal_T *current_mem;
            
            psumDEN.re = (*u).re; 
            psumDEN.im = (*u++).im; 
            
            /* During frame-based processing and one-filter-per-frame */
            /* reset den for each sample of the same frame */
            if (one_fpf) den = a;
            else         over_a0 = 1.0 / *den;
            
            den++;
            /* Calculate partial sum for denominator and numerator */
            for (j=0; j<numDelays; j++) {
                current_mem = filt_mem +indexD;
                psumDEN.re -= *den *(*current_mem).re; 
                psumDEN.im -= *den *(*current_mem).im;  
                den++; indexD++;  
                if (indexD > numDelays) indexD = 0;  
            }
            
            /* Circular buffer magic: */
            /* update entire buffer by writing to only one element! */
            current_mem       = filt_mem +indexD;
            (*current_mem).re = over_a0 * psumDEN.re;
            (*current_mem).im = over_a0 * psumDEN.im;
             

            /* Compute the output value */
            (*y).re   = over_a0 * psumDEN.re;
            (*y++).im = over_a0 * psumDEN.im; 

        } /* frame loop */
    } /* channel loop */
    *offset_mem=indexD;
}

/* [EOF] */



