/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.4     Thu Sep  6 18:22:36 2001 (UTC)              */
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
/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  NAME                                                                    */
/*      DSP_fir_r8: FIR Filter (radix 8)                                    */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      10-Aug-2001                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void DSP_fir_r8                                                     */
/*      (                                                                   */
/*          const short *restrict x,  // Input array [nr+nh-1 elements] //  */
/*          const short *restrict h,  // Coeff array [nh elements]      //  */
/*          short       *restrict r,  // Output array [nr elements]     //  */
/*          int nh,                   // Number of coefficients.        //  */
/*          int nr                    // Number of output samples.      //  */
/*      )                                                                   */
/*                                                                          */
/*  ARGUMENTS PASSED                                                        */
/*      *x    ->      A4                                                    */
/*      *h    ->      B4                                                    */
/*      *r    ->      A6                                                    */
/*      nh    ->      B6                                                    */
/*      nr    ->      A8                                                    */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      Computes a real FIR filter (direct-form) using coefficients         */
/*      stored in vector h.  The real data input is stored in vector x.     */
/*      The filter output result is stored in vector r.  Input data and     */
/*      filter taps are 16-bit, with intermediate values kept at 32-bit     */
/*      precision.  Filter taps are expected in Q15 format.                 */
/*                                                                          */
/*      The following is a natural C implementation with no restrictions.   */
/*      This version has restrictions as noted in the ASSUMPTIONS below.    */
/*                                                                          */
/*      void DSP_fir_r8                                                     */
/*      (                                                                   */
/*          const short *restrict x,                                        */
/*          const short *restrict h,                                        */
/*          short       *restrict r,                                        */
/*          int nh,                                                         */
/*          int nr                                                          */
/*      )                                                                   */
/*      {                                                                   */
/*          int i, j, sum;                                                  */
/*                                                                          */
/*          for (j = 0; j < nr; j++)                                        */
/*          {                                                               */
/*              sum = 0;                                                    */
/*              for (i = 0; i < nh; i++)                                    */
/*                  sum += x[i + j] * h[i];                                 */
/*              r[j] = sum >> 15;                                           */
/*          }                                                               */
/*      }                                                                   */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      Number of taps:    'nh' >= 8, multiple of 8                         */
/*      Number of samples: 'nr' >= 4, multiple of 4                         */
/*      Array 'r' is word aligned.                                          */
/*                                                                          */
/*  NOTES                                                                   */
/*      This function blocks interrupts for its entire duration.  It is     */
/*      interrupt tolerant, but not interruptible.                          */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      No memory bank hits under any conditions.                           */
/*      This code is a LITTLE ENDIAN implementation.                        */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      1.  Load double word instruction is used to simultaneously load     */
/*          four values in a single clock cycle.                            */
/*                                                                          */
/*      2.  The inner loop is unrolled four times and will always           */
/*          compute a multiple of 4 of nr.                                  */
/*                                                                          */
/*      3.  The outer loop is conditionally exected in parallel with the    */
/*          inner loop.  This allows for a zero overhead outer loop.        */
/*                                                                          */
/*  CYCLES                                                                  */
/*      nh * nr/4 + 17                                                      */
/*                                                                          */
/*      For nh = 32 and nr = 36, cycles = 305.                              */
/*                                                                          */
/*  CODESIZE                                                                */
/*      336 bytes.                                                          */
/*                                                                          */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_FIR_R8_H_
#define DSP_FIR_R8_H_ 1

void DSP_fir_r8
(
    const short *restrict x,  /* Input array [nr+nh-1 elements] */
    const short *restrict h,  /* Coeff array [nh elements]      */
    short       *restrict r,  /* Output array [nr elements]     */
    int nh,                   /* Number of coefficients.        */
    int nr                    /* Number of output samples.      */
);

#endif
/* ======================================================================== */
/*  End of file:  dsp_fir_r8.h                                              */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
