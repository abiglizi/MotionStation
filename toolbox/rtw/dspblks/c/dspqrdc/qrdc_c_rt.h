/*
 * @(#)qrdc_c_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:31 2004
 *
 *		built from:	qrdc_c_rt.c
 */

#ifndef qrdc_c_rt_h
#define qrdc_c_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_qrdcC(
    int_T		m,		/* rows in x */
    int_T		n,		/* columns in x */
    creal32_T	*x,		/* input matrix */				
    creal32_T	*qraux,	/* auxilliary vector */
    int_T		*jpvt,	/* pivot info */
    creal32_T	*work	/* work vector */
    );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* qrdc_c_rt_h */
