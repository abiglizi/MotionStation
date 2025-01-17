/*
 * @(#)2chsbank_df_rr_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:23 2004
 *
 *		built from:	2chsbank_df_rr_rt.c
 */

#ifndef 2chsbank_df_rr_rt_h
#define 2chsbank_df_rr_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_2ChSBank_DF_RR(
    const real32_T        *inputToLongFilt, 
    const real32_T        *inputToShortFilt, 
          real32_T        *out,
          real32_T        *longFiltTapBuf,
          real32_T        *shortFiltTapBuf,              
    const real32_T *const  longFilt,  
    const real32_T *const  shortFilt,          
          int32_T           *longFiltTapIdx, 
          int32_T           *shortFiltTapIdx, 
    const int_T            numChans,
    const int_T            inFrameSize,          
    const int_T            polyphaseLongFiltLen,
    const int_T            polyphaseShortFiltLen
);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* 2chsbank_df_rr_rt_h */
