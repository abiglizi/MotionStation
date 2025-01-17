/*
 * @(#)matmult_cc_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:30 2004
 *
 *		built from:	matmult_cc_rt.c
 */

#ifndef matmult_cc_rt_h
#define matmult_cc_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_MatMult_CC(
    creal32_T *y,
    const creal32_T *A,
    const creal32_T *B,
    const int dims[3]);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* matmult_cc_rt_h */
