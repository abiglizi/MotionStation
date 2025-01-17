/*
 * @(#)bq6_df2t_1fpf_nsos_rr_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:14 2004
 *
 *		built from:	bq6_df2t_1fpf_nsos_rr_rt.c
 */

#ifndef bq6_df2t_1fpf_nsos_rr_rt_h
#define bq6_df2t_1fpf_nsos_rr_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_BQ6_DF2T_1fpf_Nsos_RR (const real32_T *u,
                                  real32_T *y,
                                  real32_T *state,
                                  const real32_T *coeffs,
                                  const real32_T *a0invs,
                                  const int_T sampsPerChan,
                                  const int_T numChans,
                                  const int_T numSections);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* bq6_df2t_1fpf_nsos_rr_rt_h */
