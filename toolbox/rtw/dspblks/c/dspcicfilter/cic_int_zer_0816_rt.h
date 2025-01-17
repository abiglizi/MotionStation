/*
 * @(#)cic_int_zer_0816_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:16 2004
 *
 *		built from:	cic_int_zer_0816_rt.c
 */

#ifndef cic_int_zer_0816_rt_h
#define cic_int_zer_0816_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_CICIntZer0816(
    int            R,
    int            N,
    int            nChans,
    int            nFrames,
    const int8_T  *inp,
    int16_T       *out,
    int32_T       *states,
    int            statesPerChanSize,
    const int32_T *stgInpWLs,
    int32_T        finalOutShiftVal,
    int            phase,
    int            ioStride);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* cic_int_zer_0816_rt_h */
