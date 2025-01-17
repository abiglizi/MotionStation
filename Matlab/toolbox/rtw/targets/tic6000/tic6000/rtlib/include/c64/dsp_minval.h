/* ======================================================================== */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  DSPLIB  DSP Signal Processing Library                                   */
/*                                                                          */
/*      Release:        Version 1.02                                        */
/*      CVS Revision:   1.6     Fri Mar 29 20:27:51 2002 (UTC)              */
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
/*                                                                          */
/*  TEXAS INSTRUMENTS, INC.                                                 */
/*                                                                          */
/*  NAME                                                                    */
/*      DSP_minval                                                          */
/*                                                                          */
/*  REVISION DATE                                                           */
/*      07-May-2001                                                         */
/*                                                                          */
/*  USAGE                                                                   */
/*      This routine is C-callable and can be called as:                    */
/*                                                                          */
/*          short DSP_minval(const short *x, int nx);                       */
/*                                                                          */
/*          x  = address to array of values                                 */
/*          nx = number of values in array                                  */
/*                                                                          */
/*                                                                          */
/*  DESCRIPTION                                                             */
/*      This routine finds the minimum value of a vector and returns        */
/*      the value.                                                          */
/*                                                                          */
/*          short DSP_minval(const short *x, int nx)                        */
/*          {                                                               */
/*              int  i, min;                                                */
/*              min = 32767;                                                */
/*              for (i = 0; i < nx; i++)                                    */
/*                  if (x[i] < min)                                         */
/*                       min = x[i];                                        */
/*              return min;                                                 */
/*          }                                                               */
/*                                                                          */
/*  ASSUMPTIONS                                                             */
/*      Nx is a multiple of 4.                                              */
/*      Nx is greater than or equal to 20.                                  */
/*                                                                          */
/*  MEMORY NOTE                                                             */
/*      This code is ENDIAN NEUTRAL.                                        */
/*                                                                          */
/*  NOTES                                                                   */
/*      This code is interrupt tolerant but not interruptible.              */
/*                                                                          */
/*  CODESIZE                                                                */
/*      112 bytes                                                           */
/*                                                                          */
/*  CYCLES                                                                  */
/*      nx / 4 + 10                                                         */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
#ifndef DSP_MINVAL_H_
#define DSP_MINVAL_H_ 1

short DSP_minval(const short *x, int nx);

#endif
/* ======================================================================== */
/*  End of file:  dsp_minval.h                                              */
/* ------------------------------------------------------------------------ */
/*            Copyright (c) 2002 Texas Instruments, Incorporated.           */
/*                           All Rights Reserved.                           */
/* ======================================================================== */
