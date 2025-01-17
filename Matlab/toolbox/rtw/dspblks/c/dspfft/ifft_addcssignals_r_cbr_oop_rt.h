/*
 * @(#)ifft_addcssignals_r_cbr_oop_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:21 2004
 *
 *		built from:	ifft_addcssignals_r_cbr_oop_rt.c
 */

#ifndef ifft_addcssignals_r_cbr_oop_rt_h
#define ifft_addcssignals_r_cbr_oop_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_Ifft_AddCSSignals_R_Cbr_Oop(
    creal32_T *y,
    const real32_T *u,
    const int_T   nChans,
    const int_T   nRows
    );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* ifft_addcssignals_r_cbr_oop_rt_h */
