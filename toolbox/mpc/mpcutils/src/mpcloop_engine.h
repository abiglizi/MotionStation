/* mpc_sfun.h: MPC Simulink/RTW S-Function - Macros
              
      Author: A. Bemporad
      Copyright 1986-2003 The MathWorks, Inc. 
      $Revision: 1.1.10.5 $  $Date: 2004/02/06 00:25:29 $   
*/


/* Debug messages */ 
/* 
  #ifndef DEBUG
  #define DEBUG
  #endif
*/

#define MPCLOOP

#include <stdlib.h>
#include <math.h>
/* #include "util.h" */
#include "dantzgmp.h"
#include "matrix.h" 
#include "mat_macros.h"
#include "mex.h"  /* In a MEX-file, to use mexPrintf instead of printf. */

/* Required for alloca to work*/
#if defined(__hpux) && ~defined __FAST_THREADS
#include <alloca.h>
#endif

/* Required for alloca to work*/
#if (defined(sun) || defined(__sun)) && \
    (defined(__SUNPRO_C) || defined(__SUNPRO_CC))
#include <alloca.h>
#endif

/* Required for alloca to work*/
#if defined(__WIN32__) || defined(WIN32) || defined(_WIN32) || \
    defined(_MSC_VER)
#include <malloc.h>
    #define alloca(x) _alloca(x)
#endif

/* Input arguments to MEX function */

#define MPCstruct_IN prhs[0]  

/* Output Arguments to MEX function */

#define	U_OUT	 plhs[0]
#define	Y_OUT	 plhs[1]
#define	XP_OUT	 plhs[2]
#define	XMPC_OUT plhs[3]


/* Parameter access macros */

/* Model parameters - Generated by the mpcloop.m initialization routine */


#define p_Ts(S)               mxGetField(S,0,"ts")
#define p_A(S)                mxGetField(S,0,"A")
#define p_Cm(S)               mxGetField(S,0,"Cm")
#define p_Dvm(S)              mxGetField(S,0,"Dvm")
#define p_Bu(S)               mxGetField(S,0,"Bu")
#define p_Bv(S)               mxGetField(S,0,"Bv")
#define p_PTYPE(S)            mxGetField(S,0,"PTYPE")
#define p_nu(S)               mxGetField(S,0,"nu")
#define p_nv(S)               mxGetField(S,0,"nv") /* total number of MDs, including the one due to offsets */
#define p_nym(S)              mxGetField(S,0,"nym")
#define p_ny(S)               mxGetField(S,0,"ny")
#define p_nx(S)               mxGetField(S,0,"nx")
#define p_degrees(S)          mxGetField(S,0,"degrees")
#define p_M(S)                mxGetField(S,0,"M")
#define p_MuKduINV(S)         mxGetField(S,0,"MuKduINV")
#define p_KduINV(S)           mxGetField(S,0,"KduINV")
#define p_Kx(S)               mxGetField(S,0,"Kx")
#define p_Ku1(S)              mxGetField(S,0,"Ku1")
#define p_Kut(S)              mxGetField(S,0,"Kut")
#define p_Kr(S)               mxGetField(S,0,"Kr")
#define p_Kv(S)               mxGetField(S,0,"Kv")
#define p_zmin(S)             mxGetField(S,0,"zmin")
#define p_rhsc0(S)            mxGetField(S,0,"rhsc0")
#define p_Mlim(S)             mxGetField(S,0,"Mlim")
#define p_Mx(S)               mxGetField(S,0,"Mx")
#define p_Mu1(S)              mxGetField(S,0,"Mu1")
#define p_Mv(S)               mxGetField(S,0,"Mv")
#define p_rhsa0(S)            mxGetField(S,0,"rhsa0")
#define p_TAB(S)              mxGetField(S,0,"TAB")
#define p_optimalseq(S)       mxGetField(S,0,"optimalseq")
#define p_utarget(S)          mxGetField(S,0,"utarget")
#define p_lastx(S)            mxGetField(S,0,"lastx")
#define p_lastu(S)            mxGetField(S,0,"lastu")
#define p_p(S)                mxGetField(S,0,"p")
#define p_Jm(S)               mxGetField(S,0,"Jm")
#define p_DUFree(S)           mxGetField(S,0,"DUFree") 
#define p_uoff(S)             mxGetField(S,0,"uoff") 
#define p_yoff(S)             mxGetField(S,0,"yoff") 
#define p_voff(S)             mxGetField(S,0,"voff") 
#define p_myoff(S)            mxGetField(S,0,"myoff") 
#define p_ref_preview(S)      mxGetField(S,0,"ref_preview") 
#define p_md_preview(S)       mxGetField(S,0,"md_preview") 
#define p_maxiter(S)          mxGetField(S,0,"maxiter") 
#define p_nxQP(S)             mxGetField(S,0,"nxQP") 

#define p_ref_signal(S)       mxGetField(S,0,"ref_signal") 
#define p_ref_from_ws(S)      mxGetField(S,0,"ref_from_ws") /* only for compatibility with MPC S-Function */
#define p_no_ref(S)           mxGetField(S,0,"no_ref")      /* only for compatibility with MPC S-Function */
#define p_md_signal(S)        mxGetField(S,0,"md_signal")
#define p_md_from_ws(S)       mxGetField(S,0,"md_from_ws")  /* only for compatibility with MPC S-Function */
#define p_no_md(S)            mxGetField(S,0,"no_md")       /* only for compatibility with MPC S-Function */
#define p_no_ym(S)            mxGetField(S,0,"no_ym")      /* only for compatibility with MPC S-Function */

/* #define p_lastt(S)            mxGetField(S,0,"lastt") */
/* #define p_v(S)                mxGetField(S,0,"v") */

#define p_Tf(S)               mxGetField(S,0,"Tf") 
#define p_myindex(S)          mxGetField(S,0,"myindex") 
#define p_xpoff(S)            mxGetField(S,0,"xpoff") 
#define p_dxpoff(S)           mxGetField(S,0,"dxpoff") 
#define p_xoff(S)             mxGetField(S,0,"xoff") 

#define p_Ap(S)               mxGetField(S,0,"Ap") 
#define p_Bup(S)              mxGetField(S,0,"Bup") 
#define p_Bvp(S)              mxGetField(S,0,"Bvp") 
#define p_Bdp(S)              mxGetField(S,0,"Bdp") 
#define p_Cp(S)               mxGetField(S,0,"Cp") 
#define p_Dvp(S)              mxGetField(S,0,"Dvp") 
#define p_Ddp(S)              mxGetField(S,0,"Ddp") 
#define p_nxp(S)              mxGetField(S,0,"nxp")
#define p_xp0(S)              mxGetField(S,0,"xp0") 
#define p_ndp(S)              mxGetField(S,0,"ndp")

#define p_ud_signal(S)        mxGetField(S,0,"ud_signal")
#define p_mn_signal(S)        mxGetField(S,0,"mn_signal")
#define p_un_signal(S)        mxGetField(S,0,"un_signal")

#define p_ypoff(S)            mxGetField(S,0,"ypoff") 
#define p_upoff(S)            mxGetField(S,0,"upoff") 
#define p_vpoff(S)            mxGetField(S,0,"vpoff") 

#define p_barhandle(S)        mxGetField(S,0,"barhandle") 
#define p_unconstr(S)         mxGetField(S,0,"unconstr") 
#define p_openloop(S)         mxGetField(S,0,"openloop") 
#define p_mv_signal(S)        mxGetField(S,0,"mv_signal") 
