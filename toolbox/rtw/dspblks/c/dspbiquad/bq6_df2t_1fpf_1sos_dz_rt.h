/*
 * @(#)bq6_df2t_1fpf_1sos_dz_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:13 2004
 *
 *		built from:	bq6_df2t_1fpf_1sos_dz_rt.c
 */

#ifndef bq6_df2t_1fpf_1sos_dz_rt_h
#define bq6_df2t_1fpf_1sos_dz_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_BQ6_DF2T_1fpf_1sos_DZ (const real_T *u,
                                  creal_T *y,
                                  creal_T *state,
                                  const creal_T *coeffs,
                                  const creal_T  a0inv,
                                  const int_T sampsPerChan,
                                  const int_T numChans);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* bq6_df2t_1fpf_1sos_dz_rt_h */
