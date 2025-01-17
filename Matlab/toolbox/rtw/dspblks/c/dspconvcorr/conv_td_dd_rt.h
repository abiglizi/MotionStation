/*
 * @(#)conv_td_dd_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:16 2004
 *
 *		built from:	conv_td_dd_rt.c
 */

#ifndef conv_td_dd_rt_h
#define conv_td_dd_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_Conv_TD_DD(
    const real_T  *inPtrA,
    int_T         nRowsA,
    boolean_T     multiChanA,
    const real_T  *inPtrB,
    int_T         nRowsB,
    boolean_T     multiChanB,
    real_T        *outPtr,
    int_T         nRowsY,
    int_T         nChansY
);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* conv_td_dd_rt_h */
