/* $Revision: 1.8 $ $Date: 2002/04/26 23:44:25 $ */
/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.4     Fri Mar 29 20:07:39 2002 (UTC)              */
/*      Snapshot date:  18-Apr-2002                                         */
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
/*   TEXAS INSTRUMENTS, INC.                                                */
/*                                                                          */
/*  NAME                                                                    */
/*      DSP_dotp_sqr                                                        */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      29-Mar-2002                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable, and can be called as:                   */
/*                                                                          */
/*      int DSP_dotp_sqr                                                    */
/*      (                                                                   */
/*          int G,            // Sum-of-y-squared initial value //          */
/*          const short  *x,  // First input array.             //          */
/*          const short  *y,  // Second input array.            //          */
/*          int *restrict r,  // Accumulation of x[] * y[].     //          */
/*          int nx            // Length of the input vector.    //          */
/*      );                                                                  */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This routine computes the dot product of x[] and y[] arrays,        */
/*      adding it to the value in the location pointed to by 'r'.           */
/*                                                                          */
/*      Additionally, it computes the sum of the squares of the terms       */
/*      in the y[] array, adding it to the argument G.  The final value     */
/*      of G is given as the return value of the function.  This value      */
/*      is used by the VSELP vocoder.                                       */
/*                                                                          */
/*      The following C code is an implementation of the algorithm          */
/*      without restrictions.  Optimized implementations may add            */
/*      restrictions as noted under the heading "ASSUMPTIONS."              */
/*                                                                          */
/*      int DSP_dotp_sqr                                                    */
/*      (                                                                   */
/*          int G,            // Sum-of-y-squared initial value //          */
/*          const short  *x,  // First input array.             //          */
/*          const short  *y,  // Second input array.            //          */
/*          int *restrict r,  // Accumulation of x[] * y[].     //          */
/*          int nx            // Length of the input vector.    //          */
/*      )                                                                   */
/*      {                                                                   */
/*          int i;                                                          */
/*                                                                          */
/*          for (i = 0; i < nx; i++)                                        */
/*          {                                                               */
/*              *r += x[i] * y[i];                                          */
/*              G  += y[i] * y[i];                                          */
/*          }                                                               */
/*                                                                          */
/*          return G;                                                       */
/*      }                                                                   */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      nx >= 12, nx % 4 == 0.                                              */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      Unrolled 4 times to maximize multiplier utilization.                */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      No bank conflicts occur under any conditions.                       */
/*      This code is ENDIAN NEUTRAL.                                        */
/*                                                                          */
/*  CYCLES                                                                  */
/*      nx + 20                                                             */
/*                                                                          */
/*  CODESIZE                                                                */
/*      192 bytes.                                                          */
/*                                                                          */
/*  SOURCE                                                                  */
/*      DSPLIB.                                                             */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_DOTP_SQR_H_
#define DSP_DOTP_SQR_H_ 1

int DSP_dotp_sqr
(
    int G,            /* Sum-of-y-squared initial value */
    const short  *x,  /* First input array.             */
    const short  *y,  /* Second input array.            */
    int *restrict r,  /* Accumulation of x[] * y[].     */
    int nx            /* Length of the input vector.    */
);

#endif
/* ======================================================================== */
/*  End of file:  dsp_dotp_sqr.h                                            */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
