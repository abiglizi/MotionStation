/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.6     Fri Mar 29 20:48:34 2002 (UTC)              */
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
/*  NAME                                                                    */
/*      DSP_bexp -- Block exponent of a vector                              */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      12-Jul-2001                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine has the following C prototype:                         */
/*                                                                          */
/*          int DSP_bexp                                                    */
/*          (                                                               */
/*              const int *x,     // Input Data         //                  */
/*              unsigned   nx     // Number of elements //                  */
/*          );                                                              */
/*                                                                          */
/*      The DSP_bexp routine accepts a list of 'num' input points and       */
/*      performs the determination of the block exponent.  It returns       */
/*      the minimum number of "redundant sign bits" observed on the         */
/*      block of data.                                                      */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      The DSP_bexp function, performs a determination of the block        */
/*      exponent of the vector of elements and returns the maximum          */
/*      exponent.  This information can then be used to re-normalize        */
/*      the vector.  This operation is useful when auto-scaling is          */
/*      required as in a FFT.  The DSP_bexp operation returns the minimum   */
/*      norm of the vector.  The minimum norm corresponds to the            */
/*      maximum exponent.                                                   */
/*                                                                          */
/*  C CODE                                                                  */
/*      The following is a general C code description of the algorithm      */
/*      without restrictions.  This implementation may have restrictions    */
/*      as noted under 'ASSUMPTIONS' below.                                 */
/*                                                                          */
/*      int DSP_bexp(const int *x, short nx)                                */
/*      {                                                                   */
/*          int i;                                                          */
/*          int mask, mag;                                                  */
/*                                                                          */
/*          mask = 0;                                                       */
/*                                                                          */
/*          // ---------------------------------------------------- //      */
/*          //  Merge the absolute values of all the elements       //      */
/*          //  together.  The leftmost bit-change on this mask     //      */
/*          //  gives us the magnitude we desire.                   //      */
/*          // ---------------------------------------------------- //      */
/*          for (i = 0; i < nx; i++)                                        */
/*              mask |= x[i] ^ (x[i] >> 31);                                */
/*                                                                          */
/*          // ---------------------------------------------------- //      */
/*          //  Find the magnitude of the mask.                     //      */
/*          // ---------------------------------------------------- //      */
/*          for (mag = 0; (1 << mag) < mask; mag++)                         */
/*              ;                                                           */
/*                                                                          */
/*          return 31 - mag;                                                */
/*      }                                                                   */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      nx >= 8.                                                            */
/*      nx % 8 == 0.                                                        */
/*                                                                          */
/*      The array 'x' is double-word aligned.                               */
/*                                                                          */
/*  NOTES                                                                   */
/*      This code is interrupt tolerant, but not interruptible.  It masks   */
/*      interrupts for its entire duration with branch delay slots.         */
/*                                                                          */
/*      This code is ENDIAN NEUTRAL.                                        */
/*                                                                          */
/*  SOURCE                                                                  */
/*      DSPLIB.                                                             */
/*                                                                          */
/*  CYCLES                                                                  */
/*      cycles = nx/2 + 21, including 6 cycle function call overhead.       */
/*      For nx = 32, cycles = 37.                                           */
/*                                                                          */
/*  CODESIZE                                                                */
/*      216 bytes.                                                          */
/*                                                                          */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_BEXP_H_
#define DSP_BEXP_H_ 1

int DSP_bexp
(
    const int *x,     /* Input Data         */
    unsigned   nx     /* Number of elements */
);

#endif
/* ======================================================================== */
/*  End of file:  dsp_bexp.h                                                */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
