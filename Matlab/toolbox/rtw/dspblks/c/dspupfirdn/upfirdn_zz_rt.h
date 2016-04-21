/*
 * @(#)upfirdn_zz_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:37 2004
 *
 *		built from:	upfirdn_zz_rt.c
 */

#ifndef upfirdn_zz_rt_h
#define upfirdn_zz_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_UpFIRDn_ZZ(   const creal_T *u,            /* input port*/
                               creal_T *y,            /* output port*/
                               creal_T *tap0,         /* points to input buffer start address per channel */
                               creal_T *sums,         /* points to output of each interp phase per channel */
                               creal_T *outBuf,       /* points to output buffer start address per channel */
                         const creal_T * const filter,/* FIR coeff */
                               int32_T  *tapIdx,        /* points to input buffer location to read in u */
                               int32_T  *outIdx,        /* points to output buffer data for transfer to y */
                         const int_T  numChans,       /* number of channels */
                         const int_T  inFrameSize,    /* input frame size */
                         const int_T  iFactor,        /* interpolation factor */
                         const int_T  dFactor,        /* decimation factor */
                         const int_T  subOrder,       /* order of each iFactor*dFactor polyphase subfilter */
                         const int_T  memSize,        /* input buffer size per channel */
                         const int_T  outLen,         /* output buffer size per channel */
                         const int_T  n0,             /* inputs to each interpolation phase is separated by n0 samples */
                         const int_T  n1              /* outputs of each interpolation phase is separated by n1 samples */
                         );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* upfirdn_zz_rt_h */