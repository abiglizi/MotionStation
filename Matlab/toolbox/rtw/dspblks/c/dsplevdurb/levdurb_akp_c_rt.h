/*
 * @(#)levdurb_akp_c_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:29 2004
 *
 *		built from:	levdurb_akp_c_rt.c
 */

#ifndef levdurb_akp_c_rt_h
#define levdurb_akp_c_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_LevDurb_AKP_C(
    const creal32_T *u,   /* *u   Input pointer */ 
          creal32_T *y_A, /* *y_A A output pointer */ 
          creal32_T *y_K, /* *y_K K output pointer */ 
          real32_T  *y_P, /* *y_P P output pointer  */ 
    const int_T      N    /* N    Input array length */ 
    );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* levdurb_akp_c_rt_h */