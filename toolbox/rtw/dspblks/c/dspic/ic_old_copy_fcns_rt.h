/*
 * @(#)ic_old_copy_fcns_rt.h    generated by: makeheader 4.21  Tue Mar 30 16:43:25 2004
 *
 *		built from:	ic_old_copy_fcns_rt.c
 */

#ifndef ic_old_copy_fcns_rt_h
#define ic_old_copy_fcns_rt_h

#ifdef __cplusplus
    extern "C" {
#endif

EXPORT_FCN void MWDSP_CopyScalarICs( byte_T       *dstBuff, 
                                 const byte_T *ICBuff, 
                                 int_T         numElems, 
                                 const int_T   bytesPerElem );

EXPORT_FCN void MWDSP_DelayCopyScalarICs(byte_T *buffer,
                              byte_T *ICPtr,
                              const int_T nChansXdWorkRows,
                              const int_T  bytesPerElement
                              );

EXPORT_FCN void MWDSP_DelayCopyVectorICs(byte_T *buffer,
                              byte_T *ICPtr,
                              int_T nChans,
                              const int_T dWorkRows,
                              const int_T bytesPerElement
                              );

EXPORT_FCN void MWDSP_DelayCopy3DSampMatrixICs(byte_T *buffer,
                                    byte_T *ICPtr,
                                    int_T nChans,
                                    const int_T dWorkRows,
                                    const int_T bytesPerElement,
                                    const int_T dataPortWidth
                                    );

EXPORT_FCN void MWDSP_DelayCopy3DFrameMatrixICs(byte_T *buffer,
                                     byte_T *ICPtr,
                                     int_T nChans,
                                     const int_T dWorkRows,
                                     const int_T bytesPerElement
                                     );

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* ic_old_copy_fcns_rt_h */
