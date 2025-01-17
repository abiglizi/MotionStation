/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.6     Fri Mar 29 15:42:31 2002 (UTC)              */
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
/*      iir -- Infinite Impulse Response Filter/ ARMA filter, Hand ASM      */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      29-Mar-2002                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*          void DSP_iir                                                    */
/*          (                                                               */
/*              short *restrict r1,      // Output array (used)      //     */
/*              const short     *x,      // Input array              //     */
/*              short *restrict r2,      // Output array (stored)    //     */
/*              const short     *h2,     // Filter Coeffs. AR part   //     */
/*              const short     *h1,     // Filter Coeffs. FIR part  //     */
/*              int             nr       // Number of output samples //     */
/*          );                                                              */
/*                                                                          */
/*      The iir routine performs an impulse response filter computation     */
/*      on the input data in "x" and the past outputs in "r1".  It          */
/*      stores the output for "nr" output samples in "r2".                  */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The IIR performs an auto regressive moving average (ARMA)           */
/*      filter with 4 auto-regressive coefficients in "h2" and 5 moving     */
/*      average filter coefficients FIR in "h1" for "nr" output             */
/*      samples.  The output vector is stored in two locations. This        */
/*      routine is used as a high pass filter in the VSELP vocoder.         */
/*      All data is assumed to be 16 bit.                                   */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      Reads to the output array to get the previous output samples        */
/*      for AR filtering are avoided by maintaining copies of the           */
/*      samples in the register file.  The accumulator for the "AR"         */
/*      part and the "FIR" part are de-coupled to break data                */
/*      dependencies.  Inner loop that iterates through the filter          */
/*      coefficients is completely unrolled.                                */
/*                                                                          */
/*      C64x multiply instructions such as DOTP2 are used for the FIR       */
/*      portion of the computation, and the lower latency MPY               */
/*      instructions are used for the IIR portion.                          */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      "nr" is greater than or equal to 8.                                 */
/*                                                                          */
/*      Input data array "x" contains "nr + 4" input samples to produce     */
/*      "nr" output samples.                                                */
/*                                                                          */
/*      Output array "r1" contains "nr + 4" locations, "r2" contains        */
/*      "nr" locations for storing "nr" output samples. The output          */
/*      samples are stored with an offset of 4 into the "r1" array.         */
/*                                                                          */
/*  CYCLES                                                                  */
/*      cycles = 4 * nr + 21                                                */
/*                                                                          */
/*  CODESIZE                                                                */
/*      268 bytes                                                           */
/*                                                                          */
/*  SOURCE                                                                  */
/*      DSPLIB for C62x                                                     */
/*                                                                          */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_IIR_H_
#define DSP_IIR_H_ 1

void DSP_iir
(
    short *restrict r1,      /* Output array (used)      */
    const short     *x,      /* Input array              */
    short *restrict r2,      /* Output array (stored)    */
    const short     *h2,     /* Filter Coeffs. AR part   */
    const short     *h1,     /* Filter Coeffs. FIR part  */
    int             nr       /* Number of output samples */
);

#endif
/* ======================================================================== */
/*  End of file:  dsp_iir.h                                                 */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
