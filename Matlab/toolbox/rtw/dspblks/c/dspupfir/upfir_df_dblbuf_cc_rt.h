/*
 * @(#)upfir_df_dblbuf_cc_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:36 2004
 *
 *		built from:	upfir_df_dblbuf_cc_rt.c
 */

#ifndef upfir_df_dblbuf_cc_rt_h
#define upfir_df_dblbuf_cc_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_UpFIR_DF_DblBuf_CC(
    const creal32_T   *u,
          creal32_T   *out,
          creal32_T   *tap0,
    const creal32_T   *filter,
          int32_T     *tapIdx,
          boolean_T *wrtBuf,
    const int_T     numChans,
    const int_T     inFrameSize,
    const int_T     iFactor,
    const int_T     polyphaseFiltLen,
    const int_T     eachOutBufSize
);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* upfir_df_dblbuf_cc_rt_h */
