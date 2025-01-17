/* $Revision: 1.8 $ $Date: 2002/04/26 23:44:41 $ */
/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.1     Fri Dec  7 02:42:02 2001 (UTC)              */
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
/*  TEXAS INSTRUMENTS INC.                                                  */
/*                                                                          */
/*  NAME                                                                    */
/*      Complex FFT (Radix 4)                                               */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      06-Dec-2001                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C callable and can the called as                    */
/*                                                                          */
/*      void DSP_r4fft(int n, short *restrict x, const short *restrict w);  */
/*                                                                          */
/*      n    --- FFT size (power of 4)                  (input)             */
/*      x[]  --- input and output sequences (dim-n)     (input/output)      */
/*      w[]  --- FFT coefficients (dim-n)               (input)             */
/*                                                                          */
/*      If the routine is not to be used as a C callable function,          */
/*      then all instructions relating to stack should be removed.          */
/*      Refer to comments of individual instructions. You will also         */
/*      need to initialize values for all the values passed as these        */
/*      are assumed to be in registers as defined by the calling            */
/*      convention of the compiler, (refer to the C compiler reference      */
/*      guide.)                                                             */
/*                                                                          */
/*  C CODE                                                                  */
/*                                                                          */
/*      This is the C equivalent of the Assembly Code without the           */
/*      assumptions listed below. Note that the assembly code is hand       */
/*      optimized and assumptions apply.                                    */
/*                                                                          */
/*      SOURCE:Burrus, Parks p .113                                         */
/*                                                                          */
/*  void DSP_r4fft(int n, short *restrict x, const short *restrict w)       */
/*  {                                                                       */
/*      int             n1, n2, ie, ia1, ia2, ia3, i0, i1, i2, i3, j, k;    */
/*      short           t, r1, r2, s1, s2, co1, co2, co3, si1, si2, si3;    */
/*                                                                          */
/*      n2 = n;                                                             */
/*      ie = 1;                                                             */
/*      for (k = n; k > 1; k >>= 2)                                         */
/*      {                                                                   */
/*          n1 = n2;                                                        */
/*          n2 >>= 2;                                                       */
/*          ia1 = 0;                                                        */
/*          for (j = 0; j < n2; j++)                                        */
/*          {                                                               */
/*              ia2 = ia1 + ia1;                                            */
/*              ia3 = ia2 + ia1;                                            */
/*              co1 = w[ia1 * 2 + 1];                                       */
/*              si1 = w[ia1 * 2];                                           */
/*              co2 = w[ia2 * 2 + 1];                                       */
/*              si2 = w[ia2 * 2];                                           */
/*              co3 = w[ia3 * 2 + 1];                                       */
/*              si3 = w[ia3 * 2];                                           */
/*              ia1 = ia1 + ie;                                             */
/*              for (i0 = j; i0 < n; i0 += n1)                              */
/*              {                                                           */
/*                  i1 = i0 + n2;                                           */
/*                  i2 = i1 + n2;                                           */
/*                  i3 = i2 + n2;                                           */
/*                  r1 = x[2 * i0] + x[2 * i2];                             */
/*                  r2 = x[2 * i0] - x[2 * i2];                             */
/*                  t = x[2 * i1] + x[2 * i3];                              */
/*                  x[2 * i0] = r1 + t;                                     */
/*                  r1 = r1 - t;                                            */
/*                  s1 = x[2 * i0 + 1] + x[2 * i2 + 1];                     */
/*                  s2 = x[2 * i0 + 1] - x[2 * i2 + 1];                     */
/*                  t = x[2 * i1 + 1] + x[2 * i3 + 1];                      */
/*                  x[2 * i0 + 1] = s1 + t;                                 */
/*                  s1 = s1 - t;                                            */
/*                  x[2 * i2] = (r1 * co2 + s1 * si2) >> 15;                */
/*                  x[2 * i2 + 1] = (s1 * co2-r1 * si2)>>15;                */
/*                  t = x[2 * i1 + 1] - x[2 * i3 + 1];                      */
/*                  r1 = r2 + t;                                            */
/*                  r2 = r2 - t;                                            */
/*                  t = x[2 * i1] - x[2 * i3];                              */
/*                  s1 = s2 - t;                                            */
/*                  s2 = s2 + t;                                            */
/*                  x[2 * i1] = (r1 * co1 + s1 * si1)  >>15;                */
/*                  x[2 * i1 + 1] = (s1 * co1-r1 * si1)>>15;                */
/*                  x[2 * i3] = (r2 * co3 + s2 * si3)  >>15;                */
/*                  x[2 * i3 + 1] = (s2 * co3-r2 * si3)>>15;                */
/*              }                                                           */
/*          }                                                               */
/*          ie <<= 2;                                                       */
/*      }                                                                   */
/*  }                                                                       */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*                                                                          */
/*      This routine is used to compute FFT of a complex sequece            */
/*      of size n, a power of 4, with "decimation-in-frequency              */
/*      decomposition" method. The output is in digit-reversed              */
/*      order. Each complex value is with interleaved 16-bit real           */
/*      and imaginary parts.                                                */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      1. Loading input x as well as coefficient w in word.                */
/*      2. Both loops j and i0 shown in the C code are placed in the        */
/*         INNERLOOP of the assembly code.                                  */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      4 <= n <= 65536                                                     */
/*      x is aligned on a 4*N Byte (N*word) boundary                        */
/*      w is aligned on an odd word boundary                                */
/*      x data is stored in the order real[0], image[0], real[1], ...       */
/*      w coef is stored in the order k*sin[0*delta], k*cos[0*delta],       */
/*             k*sin[1*delta], ...  where delta = 2*PI/N, k = 32767         */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      x must be aligned on a 4*N Byte (N*word) boundary for circular      */
/*      buffering.  w should be aligned on an odd word boundary to          */
/*      minimize memory bank hits.  There are N/4 memory bank hits total    */
/*                                                                          */
/*  CYCLES                                                                  */
/*      LOGBASE4(N) * (10 * N/4 + 29) + 36 + N/4                            */
/*      (This includes all function-call overhead, as well as stack         */
/*      save and restore overhead.)                                         */
/*                                                                          */
/*  CODESIZE                                                                */
/*      736 bytes                                                           */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_R4FFT_H_
#define DSP_R4FFT_H_ 1

void DSP_r4fft(int n, short *restrict x, const short *restrict w);

#endif
/* ======================================================================== */
/*  End of file:  dsp_r4fft.h                                               */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
