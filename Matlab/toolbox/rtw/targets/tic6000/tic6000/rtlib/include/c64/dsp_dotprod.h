/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.13    Fri Mar 29 15:27:32 2002 (UTC)              */
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
/*                                                                          */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  NAME                                                                    */
/*      DSP_dotprod                                                         */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      29-Mar-2002                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable, and has the following C prototype:      */
/*                                                                          */
/*      int DSP_dotprod                                                     */
/*      (                                                                   */
/*          const short *m,       // Pointer to first vector  //            */
/*          const short *n,       // Pointer to second vector //            */
/*          int          count    // Length of vectors.       //            */
/*      );                                                                  */
/*                                                                          */
/*      This routine returns the dot product as its return value.           */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The "DSP_dotprod" function implements a dot product of two input    */
/*      vectors, returning the scalar result.  Each element of the          */
/*      first array is multiplied with the corresponding element of the     */
/*      second array, and the products are summed.  The sum is returned.    */
/*                                                                          */
/*      int DSP_dotprod                                                     */
/*      (                                                                   */
/*          const short *m,       // Pointer to first vector  //            */
/*          const short *n,       // Pointer to second vector //            */
/*          int          count    // Length of vectors.       //            */
/*      )                                                                   */
/*      {                                                                   */
/*          int i, sum = 0;                                                 */
/*                                                                          */
/*          for (i = 0; i < count; i++)                                     */
/*              sum += m[i] * n[i];                                         */
/*                                                                          */
/*          return sum;                                                     */
/*      }                                                                   */
/*                                                                          */
/*      The above C code is a general implementation without                */
/*      restrictions.  The assembly code has some restrictions, as          */
/*      noted below.                                                        */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The code is unrolled 4 times to enable full memory and multiplier   */
/*      bandwidth to be utilized.                                           */
/*                                                                          */
/*      Interrupts are masked by branch delay slots only.                   */
/*                                                                          */
/*      Prolog collapsing has been performed to reduce codesize.            */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      The input length is a multiple of 4 and greater than 0.             */
/*                                                                          */
/*      The input data and coeeficients are stored on double word           */
/*      aligned boundaries.                                                 */
/*                                                                          */
/*      This code is not interruptible.  Interrupts are masked by           */
/*      branch delay slots during the entire duration of this               */
/*      function.                                                           */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      To avoid bank conflicts, The input arrays 'm' and 'n' must          */
/*      be offset by 4 half-words (8 bytes).                                */
/*                                                                          */
/*      The code is ENDIAN NEUTRAL.                                         */
/*                                                                          */
/*  CODESIZE                                                                */
/*      108 bytes                                                           */
/*                                                                          */
/*  CYCLES                                                                  */
/*      cycles = count/4 + 15                                               */
/*      For count = 720, cycles = 195.                                      */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_DOTPROD_H_
#define DSP_DOTPROD_H_ 1

int DSP_dotprod
(
    const short *m,       /* Pointer to first vector  */
    const short *n,       /* Pointer to second vector */
    int          count    /* Length of vectors.       */
);

#endif
/* ======================================================================== */
/*  End of file:  dsp_dotprod.h                                             */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
