/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.7     Sun Mar 17 11:19:38 2002 (UTC)              */
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
/*    TEXAS INSTRUMENTS, INC.                                               */
/*                                                                          */
/*    NAME                                                                  */
/*          DSP_fltoq15                                                     */
/*                                                                          */
/*    REVISION DATE                                                         */
/*        27-Jul-2001                                                       */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      void DSP_fltoq15(float x[], short r[], short nx)                    */
/*                                                                          */
/*      x[nx] : Pointer to values of type float                             */
/*      r[nx] : Contains Q15 values from x[nx]                              */
/*      nx    : Number of elements in arrays                                */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      Convert the IEEE floating point numbers stored in vector x[] into   */
/*      Q.15 format numbers stored in vector r[]. Results are truncated     */
/*      towards zero. Values that exceed the size limit will be saturated   */
/*      to 0x7fff if value is positive and 0x8000 if value is negative.     */
/*      All values too small to be correctly represented will be truncated  */
/*      to 0.                                                               */
/*                                                                          */
/*      The 16-bit Q.15 format is defined as follows:                       */
/*                                                                          */
/*          1 11111                                                         */
/*          5 432109876543210                                               */
/*          S.XXXXXXXXXXXXXXX                                               */
/*                                                                          */
/*          range: 1.000000000000000 = -1.0               <-> -32768        */
/*                 0.111111111111111 =  0.999969482421875 <->  32767        */
/*                                                                          */
/*      IEEE floating point format is defined as follows:                   */
/*                                                                          */
/*          31 30....23  22.....0                                           */
/*           S EXPONENT  MANTISSA                                           */
/*                                                                          */
/*      The value is obtained as: (-1)^S * 1.MANTISSA * 2^(EXPONENT-127)    */
/*                                                                          */
/*    C CODE                                                                */
/*        void DSP_fltoq15(float x[], short r[], short nx)                  */
/*        {                                                                 */
/*            int i, a;                                                     */
/*                                                                          */
/*            for(i = 0; i < nx; i++)                                       */
/*            {                                                             */
/*                a = 32768 * x[i];                                         */
/*                                                                          */
/*                // saturate to 16-bit //                                  */
/*                if (a>32767)  a =  32767;                                 */
/*                if (a<-32768) a = -32768;                                 */
/*                                                                          */
/*                r[i] = (short) a;                                         */
/*            }                                                             */
/*        }                                                                 */
/*                                                                          */
/*    ASSUMPTIONS                                                           */
/*        1.  nx >= 2                                                       */
/*        2.  nx is a multiple of 2                                         */
/*                                                                          */
/*    NOTES                                                                 */
/*        This code is interrupt-tolerant but not interruptible.            */
/*        This implementation is ENDIAN NEUTRAL.                            */
/*                                                                          */
/*    TECHNIQUE                                                             */
/*        Loop is unrolled twice.                                           */
/*                                                                          */
/*    CYCLES                                                                */
/*        3 * nx/2 + 14                                                     */
/*                                                                          */
/*    CODESIZE                                                              */
/*        224 bytes                                                         */
/*                                                                          */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_FLTOQ15_H_
#define DSP_FLTOQ15_H_ 1

void DSP_fltoq15(float x[], short r[], short nx);

#endif
/* ======================================================================== */
/*  End of file:  dsp_fltoq15.h                                             */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
