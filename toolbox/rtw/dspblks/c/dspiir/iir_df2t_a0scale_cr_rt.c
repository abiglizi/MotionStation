/* $Revision: 1.2.2.2 $ */
/*
 *  IIR_DF2T_A0SCALE_CR_RT.C - DSP filter block runtime helper function
 *
 *  Copyright 1995-2003 The MathWorks, Inc.
 *  $Revision:
 */
#include "dsp_rt.h"

EXPORT_FCN void MWDSP_IIR_DF2T_A0Scale_CR(const creal32_T         *u,
                               creal32_T               *y,
                               creal32_T * const       mem_base,
                               const int_T             numDelays,
                               const int_T             sampsPerChan,
                               const int_T             numChans,
                               const real32_T * const  tnum,
                               const int_T             ordNUM,
                               const real32_T * const  tden,
                               const int_T             ordDEN,
                               const boolean_T         one_fpf)
{
    int_T j, k, lenMIN;
    lenMIN = MIN(ordNUM, ordDEN); /* for common state update loop */

    /* Loop over each input channel: */
    for (k=0; k < numChans; k++) {
        int_T            i = sampsPerChan;
        const real32_T  *num = tnum;
        const real32_T  *den = tden; 
        real32_T invA0;
        invA0 = 1 / *den;
        while (i--) {
            creal32_T in          = *u++;    /* Get next channel input sample */
            creal32_T *filt_mem   = mem_base + k * numDelays; /* state memory for this channel */
            creal32_T *next_mem   = filt_mem + 1;
            creal32_T out;        
            
            if (one_fpf)
            {
                num = tnum;
                den = tden;
            }
            else invA0 = 1 / *den;

            
            /* Compute the output value
             * y[n] = x[n]*b0 + D0[n]
             */
            (y)->re   = out.re = invA0 * (in.re * (*num)    + filt_mem->re);
            (y++)->im = out.im = invA0 * (in.im * (*num++)  + filt_mem->im);
            den++;
            
            /* Update states having both numerator and denominator coeffs
             *   D0[n+1] = D1[n] + x[n]*b1 - y[n]*a1
             *   D1[n+1] = D2[n] + x[n]*b2 - y[n]*a2
             *   ...
             */
            for (j=0; j < lenMIN; j++) {
                filt_mem->re     = next_mem->re     + in.re * (*num)   - out.re * (*den);
                (filt_mem++)->im = (next_mem++)->im + in.im * (*num++) - out.im * (*den++);
            }
            /* Update the rest of the states.  Note that
             * at most one of these two statements will execute
             */
            for (   ; j < ordNUM; j++) {
                filt_mem->re     = next_mem->re     + in.re  * (*num);
                (filt_mem++)->im = (next_mem++)->im + in.im  * (*num++);
            }
            for (   ; j < ordDEN; j++) {
                filt_mem->re     = next_mem->re     - out.re * (*den);
                (filt_mem++)->im = (next_mem++)->im - out.im * (*den++);
            }
        } /* frame loop */
    } /* channel loop */
}

/* [EOF] iir_df2t_a0scale_cr_rt.c */

