/*
 * @(#)pad_copy_io_trunc_cols_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:30 2004
 *
 *		built from:	pad_copy_io_trunc_cols_rt.c
 */

#ifndef pad_copy_io_trunc_cols_rt_h
#define pad_copy_io_trunc_cols_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_PadCopyOnlyTruncAlongCols(
    const byte_T *u,       /* pointer to input array  (any data type, any complexity) */
    byte_T       *y,       /* pointer to output array (any data type, any complexity) */
    int_T bytesPerInpCol,  /* number of bytes in each column of input array */
    int_T bytesPerOutCol,  /* number of bytes in each column of output array */
    int_T numOutCols       /* number of columns in the output array  */
    );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* pad_copy_io_trunc_cols_rt_h */