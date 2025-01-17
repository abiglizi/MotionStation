/*
 * @(#)allpole_df_zz_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:11 2004
 *
 *		built from:	allpole_df_zz_rt.c
 */

#ifndef allpole_df_zz_rt_h
#define allpole_df_zz_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_AllPole_DF_ZZ(
                       const creal_T        *u,
                       creal_T              *y,
                       creal_T       * const mem_base,
                       int32_T                *offset_mem,
                       const int_T           numDelays,
                       const int_T           sampsPerChan,
                       const int_T           numChans,
                       const creal_T  * const a,
                       const boolean_T       one_fpf);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* allpole_df_zz_rt_h */
