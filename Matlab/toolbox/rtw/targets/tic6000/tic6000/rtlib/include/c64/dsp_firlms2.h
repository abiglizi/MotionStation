/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.8     Sun Mar 17 11:19:34 2002 (UTC)              */
/*      Snapshot date:  17-Apr-2002                                         */
/*                                                                          */
/*  This library contains proprietary intellectual property of Texas        */
/*  Instruments, Inc.  The library and its source code are protected by     */
/*  various copyrights, and portions may also be protected by patents or    */
/*  other legal protections.                                                */
/*                                                                          */
/*  This software is licensed for use with Texas Instruments TMS320         */
/*  family DSPs.  This license was provided to you prior to installing      */
/*  the software.  You may review this license by consulting the file       */
/*  TI_license.PDF which accompanies the files in this library.             */
/* ------------------------------------------------------------------------ */
/*          Copyright (C) 2002 Texas Instruments, Incorporated.             */
/*                          All Rights Reserved.                            */
/* ======================================================================== */
/* ======================================================================= */
/* NAME                                                                    */
/*     DSP_firlms2 -- Least Mean Square Adaptive Filter                    */
/*                Hand Coded Assembly Implementation                       */
/*                                                                         */
/* REVISION DATE                                                           */
/*     13-Mar-2002                                                         */
/*                                                                         */
/* USAGE                                                                   */
/*                                                                         */
/*     This routine has the following C prototype:                         */
/*                                                                         */
/*         long DSP_firlms2                                                */
/*         (                                                               */
/*             short       *restrict h,  // Filter Coefficients            */
/*             const short *restrict x,  // Input Data                     */
/*             short                 b,  // Error from previous FIR        */
/*             int                   nh  // Number of Coefficients         */
/*         )                                                               */
/*                                                                         */
/*     The DSP_firlms2 routine accepts a list of 'nh' input data and 'nh'  */
/*     adaptive filter coefficients and updates the coefficients by        */
/*     adding weighted error times the inputs to the original              */
/*     coefficients. This assumes single sample input followed by the      */
/*     last nh-1 inputs and nh coefficients.                               */
/*                                                                         */
/* DESCRIPTION                                                             */
/*                                                                         */
/*     The algorithm is simple and Natural C implementation is as follows: */
/*                                                                         */
/*         long DSP_firlms2                                                */
/*         (                                                               */
/*             short       *restrict h,  // Filter Coefficients            */
/*             const short *restrict x,  // Input Data                     */
/*             short                 b,  // Error from previous FIR        */
/*             int                   nh  // Number of Coefficients         */
/*         )                                                               */
/*         {                                                               */
/*             int  i;                                                     */
/*             long r=0;                                                   */
/*                                                                         */
/*             for(i = 0; i < nh; i++)                                     */
/*             {                                                           */
/*               * Update the filter coefficients *                        */
/*                                                                         */
/*                 h[i] += (x[i] * b) >> 15;                               */
/*                                                                         */
/*               * Calculate the filter output    *                        */
/*                                                                         */
/*                 r    += x[i + 1] * h[i];                                */
/*             }                                                           */
/*             return r;                                                   */
/*         }                                                               */
/*                                                                         */
/* TECHNIQUES                                                              */
/*     - The loop is unrolled 4 times                                      */
/*     - MPY2, PACKH2 and ADD2 are used to update the filter coefficients  */
/*     - DOTP2 is used to calculate filter output                          */
/*                                                                         */
/* ASSUMPTIONS                                                             */
/*     - Assumes 16-bit input data, error and filter coefficients.         */
/*     - nh > = 4 and is a multiple of 4                                   */
/*                                                                         */
/*  MEMORY NOTE                                                            */
/*                                                                         */
/*  NOTES                                                                  */
/*     - Little Endian                                                     */
/*     - No Bank Conflict                                                  */
/*     - interrupt tolerant but not interruptible                          */
/*                                                                         */
/*  CYCLES                                                                 */
/*      3 * nh/4 + 17                                                      */
/*                                                                         */
/*  CODESIZE                                                               */
/*      144 bytes                                                          */
/*                                                                         */
/* ----------------------------------------------------------------------- */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================= */
#ifndef DSP_FIRLMS2_H_
#define DSP_FIRLMS2_H_ 1

long DSP_firlms2
(
    short       *restrict h,  // Filter Coefficients
    const short *restrict x,  // Input Data
    short                 b,  // Error from previous FIR
    int                   nh  // Number of Coefficients
);

#endif
/* ======================================================================== */
/*  End of file:  dsp_firlms2.h                                             */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
