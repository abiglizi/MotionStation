/*
 * @(#)allpole_lat_cc_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:11 2004
 *
 *		built from:	allpole_lat_cc_rt.c
 */

#ifndef allpole_lat_cc_rt_h
#define allpole_lat_cc_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_AllPole_Lat_CC(const creal32_T         *u,
                          creal32_T               *y,
                          creal32_T               *mem_first,
                          const int_T             sampsPerChan,
                          const int_T             numChans,
                          const creal32_T * const K_first,
                          const int_T             ordK,
                          const boolean_T         one_fpf);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* allpole_lat_cc_rt_h */
