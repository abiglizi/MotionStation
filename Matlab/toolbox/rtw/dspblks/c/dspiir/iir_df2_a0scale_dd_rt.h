/*
 * @(#)iir_df2_a0scale_dd_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:27 2004
 *
 *		built from:	iir_df2_a0scale_dd_rt.c
 */

#ifndef iir_df2_a0scale_dd_rt_h
#define iir_df2_a0scale_dd_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_IIR_DF2_A0Scale_DD( const real_T           *u,
                               real_T                 *y,
                               real_T         * const mem_base,
                               int32_T                 *mem_offset,
                               const int_T            numDelays,
                               const int_T            sampsPerChan,
                               const int_T            numChans,
                               const real_T   * const b, 
                               const int_T            ordNUM,
                               const real_T   * const a,
                               const int_T            ordDEN, 
                               const boolean_T        one_fpf);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* iir_df2_a0scale_dd_rt_h */
