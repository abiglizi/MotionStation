/*
 * @(#)unwrap_r_nrip_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:36 2004
 *
 *		built from:	unwrap_r_nrip_rt.c
 */

#ifndef unwrap_r_nrip_rt_h
#define unwrap_r_nrip_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_Unwrap_R_NRIP(      real32_T *y,
                         const real32_T cutoff,
                               int_T    inCols,
                               int_T    inRows
                        );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* unwrap_r_nrip_rt_h */
