/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.7     Mon Mar 11 23:38:08 2002 (UTC)              */
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
/*      DSP_minerror -- Minimum Energy Error Search                         */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      11-Feb-2002                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*      int DSP_minerror                                                    */
/*      (                                                                   */
/*          const short *restrict GSP0_TABLE,                               */
/*          const short *restrict errCoefs,                                 */
/*          int         *restrict max_index                                 */
/*      );                                                                  */
/*                                                                          */
/*      GSP0_TABLE[256*9] :  Pointer to GSP0 terms array.                   */
/*                           Must be double-word aligned.                   */
/*      errCoefs[9]       :  Array of error coefficients.                   */
/*      max_index         :  Index to GSP0_TABLE[max_index], the first      */
/*                           element of the 9-element vector that resulted  */
/*                           in the maximum dot product.                    */
/*      return int        :  Maximum dot product result.                    */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      Performs a dot product on 256 pairs of 9 element vectors and        */
/*      searches for the pair of vectors which produces the maximum dot     */
/*      product result. This is a large part of the VSELP vocoder codebook  */
/*      search.                                                             */
/*                                                                          */
/*  C CODE                                                                  */
/*      This is the C equivalent of the assembly code without restrictions  */
/*      Note that the assembly code is hand optimized and restrictions may  */
/*      apply.                                                              */
/*                                                                          */
/*      int DSP_minerror                                                    */
/*      (                                                                   */
/*          const short *restrict GSP0_TABLE,                               */
/*          const short *restrict errCoefs,                                 */
/*          int         *restrict max_index                                 */
/*      )                                                                   */
/*      {                                                                   */
/*          int val, maxVal = -50;                                          */
/*          int i, j;                                                       */
/*                                                                          */
/*          for (i = 0; i < GSP0_NUM; i++)                                  */
/*          {                                                               */
/*              for (val = 0, j = 0; j < GSP0_TERMS; j++)                   */
/*                  val += GSP0_TABLE[i*GSP0_TERMS+j] * errCoefs[j];        */
/*                                                                          */
/*              if (val > maxVal)                                           */
/*              {                                                           */
/*                  maxVal = val;                                           */
/*                  *max_index = i*GSP0_TERMS;                              */
/*              }                                                           */
/*          }                                                               */
/*                                                                          */
/*          return (maxVal);                                                */
/*      }                                                                   */
/*                                                                          */
/*  TECHNIQUES                                                              */
/*      Load double word instruction is used to simultaneously              */
/*      load four values in a single clock cycle.                           */
/*      The jloop is totally unrolled                                       */
/*      The iloop is unrolled 4 times                                       */
/*      A flag is used to set the exit program location                     */
/*      The MV is used to move the data                                     */
/*      The loop is software pipelined.                                     */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      Array GSP0_TABLE[] must be double-word aligned.                     */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      No memory bank hits under any conditions.                           */
/*                                                                          */
/*  NOTES                                                                   */
/*      This code is LITTLE ENDIAN.                                         */
/*      This code is interrupt-tolerant but not interruptible.              */
/*                                                                          */
/*  CYCLES                                                                  */
/*     256/4 * 9 + 17 = 593                                                 */
/*                                                                          */
/*  CODESIZE                                                                */
/*      352 bytes                                                           */
/*                                                                          */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_MINERROR_H_
#define DSP_MINERROR_H_ 1

int DSP_minerror
(
    const short *restrict GSP0_TABLE,
    const short *restrict errCoefs,
    int         *restrict max_index
);

#endif
/* ======================================================================== */
/*  End of file:  dsp_minerror.h                                            */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
