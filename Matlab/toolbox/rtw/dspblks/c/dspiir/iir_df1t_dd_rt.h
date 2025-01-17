/*
 * @(#)iir_df1t_dd_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:26 2004
 *
 *		built from:	iir_df1t_dd_rt.c
 */

#ifndef iir_df1t_dd_rt_h
#define iir_df1t_dd_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_IIR_DF1T_DD( const real_T         *u,
                         real_T               *y,
                         real_T * const       mem_base,
                         const int_T          numDelays,
                         const int_T          sampsPerChan,
                         const int_T          numChans,
                         const real_T * const tnum,
                         const int_T          ordNUM,
                         const real_T * const tden,
                         const int_T          ordDEN,
                         const boolean_T      one_fpf);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* iir_df1t_dd_rt_h */
