/* $Revision: 1.8 $ $Date: 2002/04/26 23:45:12 $ */
/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.6     Wed Apr 17 15:48:16 2002 (UTC)              */
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
/*    TEXAS INSTRUMENTS, INC.                                               */
/*                                                                          */
/*    NAME                                                                  */
/*          DSP_fir_cplx                                                    */
/*                                                                          */
/*    REVISION DATE                                                         */
/*        09-Apr-2002                                                       */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void DSP_fir_cplx                                                   */
/*      (                                                                   */
/*          const short *restrict x,                                        */
/*          const short *restrict h,                                        */
/*          short *restrict r,                                              */
/*          int nh,                                                         */
/*          int nr                                                          */
/*     )                                                                    */
/*                                                                          */
/*     x[2*(nr+nh-1)] : Input array. x must point to x[2*(nh-1)].           */
/*     h[2*nh]        : Coefficient array (in normal order).                */
/*     r[2*nr]        : Output array.                                       */
/*     nh             : Number of complex coefficients.                     */
/*                      Must be even.                                       */
/*     nr             : Number of complex output samples.                   */
/*                      nh * nr must be >= 4.                               */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This complex FIR computes nr complex output samples using nh        */
/*      complex coefficients. It operates on 16-bit data with a 32-bit      */
/*      accumulate. Each array consists of an even and odd term with even   */
/*      terms representing the real part of the element and the odd terms   */
/*      the imaginary part. The pointer to input array x must point to the  */
/*      (nh)th complex sample, i.e. element 2*(nh-1), upon entry to the     */
/*      function. The coefficients are expected in normal order.            */
/*                                                                          */
/*  C CODE                                                                  */
/*      void DSP_fir_cplx                                                   */
/*      (                                                                   */
/*          const short *restrict x,                                        */
/*          const short *restrict h,                                        */
/*          short *restrict r,                                              */
/*          int nh,                                                         */
/*          int nr                                                          */
/*      )                                                                   */
/*      {                                                                   */
/*          short i,j;                                                      */
/*          int imag, real;                                                 */
/*                                                                          */
/*          for (i = 0; i < 2*nr; i += 2)                                   */
/*          {                                                               */
/*              imag = 0;                                                   */
/*              real = 0;                                                   */
/*              for (j = 0; j < 2*nh; j += 2)                               */
/*              {                                                           */
/*                  real += h[j] * x[i-j]   - h[j+1] * x[i+1-j];            */
/*                  imag += h[j] * x[i+1-j] + h[j+1] * x[i-j];              */
/*              }                                                           */
/*              r[i]   = (real >> 15);                                      */
/*              r[i+1] = (imag >> 15);                                      */
/*          }                                                               */
/*      }                                                                   */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      The inner loop is unrolled twice.                                   */
/*      The outer loop is conditionally executed in parallel with the       */
/*      inner loop.                                                         */
/*      Both the inner and outer loops are software pipelined.              */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      nh must be even.                                                    */
/*      nr * nh >=4.                                                        */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      No memory bank hits under any conditions.                           */
/*                                                                          */
/*  NOTE                                                                    */
/*      Little Endian                                                       */
/*                                                                          */
/*  CYCLES                                                                  */
/*      2* nh * nr + 20                                                     */
/*                                                                          */
/*  CODESIZE                                                                */
/*     384 bytes                                                            */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_FIR_CPLX_H_
#define DSP_FIR_CPLX_H_ 1

void DSP_fir_cplx
(
    const short *restrict x,
    const short *restrict h,
    short *restrict r,
    int nh,
    int nr
       );

#endif
/* ======================================================================== */
/*  End of file:  dsp_fir_cplx.h                                            */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
