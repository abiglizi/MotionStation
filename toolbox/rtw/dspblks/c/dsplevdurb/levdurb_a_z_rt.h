/*
 * @(#)levdurb_a_z_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:28 2004
 *
 *		built from:	levdurb_a_z_rt.c
 */

#ifndef levdurb_a_z_rt_h
#define levdurb_a_z_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_LevDurb_A_Z(
    const creal_T *u,   /* *u   Input pointer */ 
          creal_T *y_A, /* *y_A   A output pointer */ 
    const int_T    N    /* N    Input array length */ 
    );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* levdurb_a_z_rt_h */