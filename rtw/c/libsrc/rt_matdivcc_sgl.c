/* Copyright 1994-2003 The MathWorks, Inc.
 *
 * File: rt_matdivcc_dbl.c     $Revision: 1.2.4.2 $
 *
 * Abstract:
 *      Real-Time Workshop support routine which performs
 *      matrix inversion: inv(In1)*In2 using LU factorization.
 *
 */

#include <string.h>   /* needed for memcpy */
#include "rtlibsrc.h"

/* Function: rt_MatDivCC_Sgl ===================================================
 * Abstract: 
 *           Calculate inv(In1)*In2 using LU factorization.
 */
#ifdef CREAL_T
void rt_MatDivCC_Sgl(creal32_T   *Out,
                     creal32_T   *In1,
                     creal32_T   *In2,
                     creal32_T   *lu,
                     int32_T   *piv,
                     creal32_T   *x,
                     const int dims[3])
{
  int N = dims[0];
  int N2 = N * N;
  int P = dims[2];
  int NP = N * P;
  const boolean_T unit_upper = FALSE;
  const boolean_T unit_lower = TRUE;

  (void)memcpy(lu, In1, N2*sizeof(real32_T)*2);

  rt_lu_cplx_sgl(lu, N, piv);

  rt_ForwardSubstitutionCC_Sgl(lu, In2, x, N, P, piv,unit_lower);

  rt_BackwardSubstitutionCC_Sgl(lu + N2 -1, x + NP -1, Out, N, P, unit_upper);
}
#endif
/* [EOF] rt_matdivcc_dbl.c */
