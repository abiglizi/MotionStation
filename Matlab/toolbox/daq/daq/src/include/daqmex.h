

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Mar 24 02:14:02 2004
 */
/* Compiler settings for \build\matlab\toolbox\daq\daq\src\include\daqmex.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __daqmex_h__
#define __daqmex_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPropRoot_FWD_DEFINED__
#define __IPropRoot_FWD_DEFINED__
typedef interface IPropRoot IPropRoot;
#endif 	/* __IPropRoot_FWD_DEFINED__ */


#ifndef __IDaqEnum_FWD_DEFINED__
#define __IDaqEnum_FWD_DEFINED__
typedef interface IDaqEnum IDaqEnum;
#endif 	/* __IDaqEnum_FWD_DEFINED__ */


#ifndef __IDaqMappedEnum_FWD_DEFINED__
#define __IDaqMappedEnum_FWD_DEFINED__
typedef interface IDaqMappedEnum IDaqMappedEnum;
#endif 	/* __IDaqMappedEnum_FWD_DEFINED__ */


#ifndef __IProp_FWD_DEFINED__
#define __IProp_FWD_DEFINED__
typedef interface IProp IProp;
#endif 	/* __IProp_FWD_DEFINED__ */


#ifndef __IPropValue_FWD_DEFINED__
#define __IPropValue_FWD_DEFINED__
typedef interface IPropValue IPropValue;
#endif 	/* __IPropValue_FWD_DEFINED__ */


#ifndef __IPropContainer_FWD_DEFINED__
#define __IPropContainer_FWD_DEFINED__
typedef interface IPropContainer IPropContainer;
#endif 	/* __IPropContainer_FWD_DEFINED__ */


#ifndef __IChannelList_FWD_DEFINED__
#define __IChannelList_FWD_DEFINED__
typedef interface IChannelList IChannelList;
#endif 	/* __IChannelList_FWD_DEFINED__ */


#ifndef __IChannel_FWD_DEFINED__
#define __IChannel_FWD_DEFINED__
typedef interface IChannel IChannel;
#endif 	/* __IChannel_FWD_DEFINED__ */


#ifndef __IDaqEngine_FWD_DEFINED__
#define __IDaqEngine_FWD_DEFINED__
typedef interface IDaqEngine IDaqEngine;
#endif 	/* __IDaqEngine_FWD_DEFINED__ */


#ifndef __ImwAdaptor_FWD_DEFINED__
#define __ImwAdaptor_FWD_DEFINED__
typedef interface ImwAdaptor ImwAdaptor;
#endif 	/* __ImwAdaptor_FWD_DEFINED__ */


#ifndef __ImwDevice_FWD_DEFINED__
#define __ImwDevice_FWD_DEFINED__
typedef interface ImwDevice ImwDevice;
#endif 	/* __ImwDevice_FWD_DEFINED__ */


#ifndef __ImwInput_FWD_DEFINED__
#define __ImwInput_FWD_DEFINED__
typedef interface ImwInput ImwInput;
#endif 	/* __ImwInput_FWD_DEFINED__ */


#ifndef __ImwOutput_FWD_DEFINED__
#define __ImwOutput_FWD_DEFINED__
typedef interface ImwOutput ImwOutput;
#endif 	/* __ImwOutput_FWD_DEFINED__ */


#ifndef __ImwDIO_FWD_DEFINED__
#define __ImwDIO_FWD_DEFINED__
typedef interface ImwDIO ImwDIO;
#endif 	/* __ImwDIO_FWD_DEFINED__ */


#ifndef __ImwAdaptor_FWD_DEFINED__
#define __ImwAdaptor_FWD_DEFINED__
typedef interface ImwAdaptor ImwAdaptor;
#endif 	/* __ImwAdaptor_FWD_DEFINED__ */


#ifndef __ImwDevice_FWD_DEFINED__
#define __ImwDevice_FWD_DEFINED__
typedef interface ImwDevice ImwDevice;
#endif 	/* __ImwDevice_FWD_DEFINED__ */


#ifndef __ImwInput_FWD_DEFINED__
#define __ImwInput_FWD_DEFINED__
typedef interface ImwInput ImwInput;
#endif 	/* __ImwInput_FWD_DEFINED__ */


#ifndef __ImwOutput_FWD_DEFINED__
#define __ImwOutput_FWD_DEFINED__
typedef interface ImwOutput ImwOutput;
#endif 	/* __ImwOutput_FWD_DEFINED__ */


#ifndef __ImwDIO_FWD_DEFINED__
#define __ImwDIO_FWD_DEFINED__
typedef interface ImwDIO ImwDIO;
#endif 	/* __ImwDIO_FWD_DEFINED__ */


#ifndef __Prop_FWD_DEFINED__
#define __Prop_FWD_DEFINED__

#ifdef __cplusplus
typedef class Prop Prop;
#else
typedef struct Prop Prop;
#endif /* __cplusplus */

#endif 	/* __Prop_FWD_DEFINED__ */


#ifndef __DaqEngine_FWD_DEFINED__
#define __DaqEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class DaqEngine DaqEngine;
#else
typedef struct DaqEngine DaqEngine;
#endif /* __cplusplus */

#endif 	/* __DaqEngine_FWD_DEFINED__ */


#ifndef __PropContainer_FWD_DEFINED__
#define __PropContainer_FWD_DEFINED__

#ifdef __cplusplus
typedef class PropContainer PropContainer;
#else
typedef struct PropContainer PropContainer;
#endif /* __cplusplus */

#endif 	/* __PropContainer_FWD_DEFINED__ */


#ifndef __DaqMappedEnum_FWD_DEFINED__
#define __DaqMappedEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class DaqMappedEnum DaqMappedEnum;
#else
typedef struct DaqMappedEnum DaqMappedEnum;
#endif /* __cplusplus */

#endif 	/* __DaqMappedEnum_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_daqmex_0000 */
/* [local] */ 

//Copyright 1998-2003 The MathWorks, Inc.
// built from  daqmex.idl $Revision: 1.4.4.4 $  $Date: 2003/12/04 18:39:14 $
typedef struct tagBUFFER
    {
    long Size;
    long ValidPoints;
    /* [size_is][ref] */ unsigned char *ptr;
    DWORD dwAdaptorData;
    unsigned long Flags;
    unsigned long Reserved;
    hyper StartPoint;
    double StartTime;
    double EndTime;
    } 	BUFFER_ST;

typedef /* [v1_enum] */ 
enum tagNESTABLEPROPTYPES
    {	NPAICHANNEL	= 0,
	NPAOCHANNEL	= NPAICHANNEL + 1,
	NPDIGITALLINE	= NPAOCHANNEL + 1
    } 	NESTABLEPROPTYPES;

#if 0
typedef struct tagNESTABLEPROP
    {
    long StructSize;
    long Index;
    NESTABLEPROPTYPES Type;
    long HwChan;
    BSTR Name;
    /* [size_is] */ BYTE extra[ 1 ];
    } 	NESTABLEPROP;

#endif
typedef struct tagNESTABLEPROP
{
    long StructSize;
    long Index;
    NESTABLEPROPTYPES Type;
    long HwChan;
    BSTR Name;
} NESTABLEPROP;
#ifdef __cplusplus
typedef const VARIANT &VARIANTREF;
#else
typedef const VARIANT *VARIANTREF;

#endif


extern RPC_IF_HANDLE __MIDL_itf_daqmex_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_daqmex_0000_v0_0_s_ifspec;

#ifndef __IPropRoot_INTERFACE_DEFINED__
#define __IPropRoot_INTERFACE_DEFINED__

/* interface IPropRoot */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IPropRoot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BEEFABE-E54A-11d3-A551-00902757EA8D")
    IPropRoot : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [string][in] */ LPCOLESTR newVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ long *Type) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_User( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_User( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsHidden( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_IsHidden( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsReadOnly( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_IsReadOnly( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_IsReadonlyRunning( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_IsReadonlyRunning( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRange( 
            /* [out] */ VARIANT *min,
            /* [out] */ VARIANT *max) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetRange( 
            /* [in] */ VARIANT *min,
            /* [in] */ VARIANT *max) = 0;
        
        virtual /* [local][restricted][hidden][helpstring] */ long STDMETHODCALLTYPE _GetObject( void) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultValue( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultValue( 
            /* [in] */ VARIANTREF newVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsValidValue( 
            /* [in] */ VARIANTREF value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropRootVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropRoot * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropRoot * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropRoot * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IPropRoot * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IPropRoot * This,
            /* [string][in] */ LPCOLESTR newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IPropRoot * This,
            /* [out] */ long *Type);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            IPropRoot * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_User )( 
            IPropRoot * This,
            /* [in] */ long newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHidden )( 
            IPropRoot * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHidden )( 
            IPropRoot * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IPropRoot * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadOnly )( 
            IPropRoot * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadonlyRunning )( 
            IPropRoot * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadonlyRunning )( 
            IPropRoot * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRange )( 
            IPropRoot * This,
            /* [out] */ VARIANT *min,
            /* [out] */ VARIANT *max);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IPropRoot * This,
            /* [in] */ VARIANT *min,
            /* [in] */ VARIANT *max);
        
        /* [local][restricted][hidden][helpstring] */ long ( STDMETHODCALLTYPE *_GetObject )( 
            IPropRoot * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultValue )( 
            IPropRoot * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultValue )( 
            IPropRoot * This,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsValidValue )( 
            IPropRoot * This,
            /* [in] */ VARIANTREF value);
        
        END_INTERFACE
    } IPropRootVtbl;

    interface IPropRoot
    {
        CONST_VTBL struct IPropRootVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropRoot_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropRoot_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropRoot_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropRoot_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IPropRoot_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IPropRoot_GetType(This,Type)	\
    (This)->lpVtbl -> GetType(This,Type)

#define IPropRoot_get_User(This,pVal)	\
    (This)->lpVtbl -> get_User(This,pVal)

#define IPropRoot_put_User(This,newVal)	\
    (This)->lpVtbl -> put_User(This,newVal)

#define IPropRoot_get_IsHidden(This,pVal)	\
    (This)->lpVtbl -> get_IsHidden(This,pVal)

#define IPropRoot_put_IsHidden(This,newVal)	\
    (This)->lpVtbl -> put_IsHidden(This,newVal)

#define IPropRoot_get_IsReadOnly(This,pVal)	\
    (This)->lpVtbl -> get_IsReadOnly(This,pVal)

#define IPropRoot_put_IsReadOnly(This,newVal)	\
    (This)->lpVtbl -> put_IsReadOnly(This,newVal)

#define IPropRoot_get_IsReadonlyRunning(This,pVal)	\
    (This)->lpVtbl -> get_IsReadonlyRunning(This,pVal)

#define IPropRoot_put_IsReadonlyRunning(This,newVal)	\
    (This)->lpVtbl -> put_IsReadonlyRunning(This,newVal)

#define IPropRoot_GetRange(This,min,max)	\
    (This)->lpVtbl -> GetRange(This,min,max)

#define IPropRoot_SetRange(This,min,max)	\
    (This)->lpVtbl -> SetRange(This,min,max)

#define IPropRoot__GetObject(This)	\
    (This)->lpVtbl -> _GetObject(This)

#define IPropRoot_get_DefaultValue(This,pVal)	\
    (This)->lpVtbl -> get_DefaultValue(This,pVal)

#define IPropRoot_put_DefaultValue(This,newVal)	\
    (This)->lpVtbl -> put_DefaultValue(This,newVal)

#define IPropRoot_IsValidValue(This,value)	\
    (This)->lpVtbl -> IsValidValue(This,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropRoot_get_Name_Proxy( 
    IPropRoot * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IPropRoot_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropRoot_put_Name_Proxy( 
    IPropRoot * This,
    /* [string][in] */ LPCOLESTR newVal);


void __RPC_STUB IPropRoot_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropRoot_GetType_Proxy( 
    IPropRoot * This,
    /* [out] */ long *Type);


void __RPC_STUB IPropRoot_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropRoot_get_User_Proxy( 
    IPropRoot * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IPropRoot_get_User_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropRoot_put_User_Proxy( 
    IPropRoot * This,
    /* [in] */ long newVal);


void __RPC_STUB IPropRoot_put_User_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropRoot_get_IsHidden_Proxy( 
    IPropRoot * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IPropRoot_get_IsHidden_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropRoot_put_IsHidden_Proxy( 
    IPropRoot * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IPropRoot_put_IsHidden_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropRoot_get_IsReadOnly_Proxy( 
    IPropRoot * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IPropRoot_get_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropRoot_put_IsReadOnly_Proxy( 
    IPropRoot * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IPropRoot_put_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropRoot_get_IsReadonlyRunning_Proxy( 
    IPropRoot * This,
    /* [retval][out] */ BOOL *pVal);


void __RPC_STUB IPropRoot_get_IsReadonlyRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropRoot_put_IsReadonlyRunning_Proxy( 
    IPropRoot * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IPropRoot_put_IsReadonlyRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropRoot_GetRange_Proxy( 
    IPropRoot * This,
    /* [out] */ VARIANT *min,
    /* [out] */ VARIANT *max);


void __RPC_STUB IPropRoot_GetRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropRoot_SetRange_Proxy( 
    IPropRoot * This,
    /* [in] */ VARIANT *min,
    /* [in] */ VARIANT *max);


void __RPC_STUB IPropRoot_SetRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local][restricted][hidden][helpstring] */ long STDMETHODCALLTYPE IPropRoot__GetObject_Proxy( 
    IPropRoot * This);


void __RPC_STUB IPropRoot__GetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropRoot_get_DefaultValue_Proxy( 
    IPropRoot * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IPropRoot_get_DefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropRoot_put_DefaultValue_Proxy( 
    IPropRoot * This,
    /* [in] */ VARIANTREF newVal);


void __RPC_STUB IPropRoot_put_DefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropRoot_IsValidValue_Proxy( 
    IPropRoot * This,
    /* [in] */ VARIANTREF value);


void __RPC_STUB IPropRoot_IsValidValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPropRoot_INTERFACE_DEFINED__ */


#ifndef __IDaqEnum_INTERFACE_DEFINED__
#define __IDaqEnum_INTERFACE_DEFINED__

/* interface IDaqEnum */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDaqEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3F93B7F-93C7-11d3-A526-00902757EA8D")
    IDaqEnum : public IPropRoot
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddEnumValues( 
            /* [in] */ VARIANTREF values) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ClearEnumValues( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveEnumValue( 
            /* [in] */ VARIANTREF values) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumValues( 
            /* [out] */ IEnumVARIANT **EnumVARIANT) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDaqEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDaqEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDaqEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDaqEnum * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IDaqEnum * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IDaqEnum * This,
            /* [string][in] */ LPCOLESTR newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IDaqEnum * This,
            /* [out] */ long *Type);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            IDaqEnum * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_User )( 
            IDaqEnum * This,
            /* [in] */ long newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHidden )( 
            IDaqEnum * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHidden )( 
            IDaqEnum * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IDaqEnum * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadOnly )( 
            IDaqEnum * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadonlyRunning )( 
            IDaqEnum * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadonlyRunning )( 
            IDaqEnum * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRange )( 
            IDaqEnum * This,
            /* [out] */ VARIANT *min,
            /* [out] */ VARIANT *max);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IDaqEnum * This,
            /* [in] */ VARIANT *min,
            /* [in] */ VARIANT *max);
        
        /* [local][restricted][hidden][helpstring] */ long ( STDMETHODCALLTYPE *_GetObject )( 
            IDaqEnum * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultValue )( 
            IDaqEnum * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultValue )( 
            IDaqEnum * This,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsValidValue )( 
            IDaqEnum * This,
            /* [in] */ VARIANTREF value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddEnumValues )( 
            IDaqEnum * This,
            /* [in] */ VARIANTREF values);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ClearEnumValues )( 
            IDaqEnum * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveEnumValue )( 
            IDaqEnum * This,
            /* [in] */ VARIANTREF values);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            IDaqEnum * This,
            /* [out] */ IEnumVARIANT **EnumVARIANT);
        
        END_INTERFACE
    } IDaqEnumVtbl;

    interface IDaqEnum
    {
        CONST_VTBL struct IDaqEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDaqEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDaqEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDaqEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDaqEnum_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IDaqEnum_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IDaqEnum_GetType(This,Type)	\
    (This)->lpVtbl -> GetType(This,Type)

#define IDaqEnum_get_User(This,pVal)	\
    (This)->lpVtbl -> get_User(This,pVal)

#define IDaqEnum_put_User(This,newVal)	\
    (This)->lpVtbl -> put_User(This,newVal)

#define IDaqEnum_get_IsHidden(This,pVal)	\
    (This)->lpVtbl -> get_IsHidden(This,pVal)

#define IDaqEnum_put_IsHidden(This,newVal)	\
    (This)->lpVtbl -> put_IsHidden(This,newVal)

#define IDaqEnum_get_IsReadOnly(This,pVal)	\
    (This)->lpVtbl -> get_IsReadOnly(This,pVal)

#define IDaqEnum_put_IsReadOnly(This,newVal)	\
    (This)->lpVtbl -> put_IsReadOnly(This,newVal)

#define IDaqEnum_get_IsReadonlyRunning(This,pVal)	\
    (This)->lpVtbl -> get_IsReadonlyRunning(This,pVal)

#define IDaqEnum_put_IsReadonlyRunning(This,newVal)	\
    (This)->lpVtbl -> put_IsReadonlyRunning(This,newVal)

#define IDaqEnum_GetRange(This,min,max)	\
    (This)->lpVtbl -> GetRange(This,min,max)

#define IDaqEnum_SetRange(This,min,max)	\
    (This)->lpVtbl -> SetRange(This,min,max)

#define IDaqEnum__GetObject(This)	\
    (This)->lpVtbl -> _GetObject(This)

#define IDaqEnum_get_DefaultValue(This,pVal)	\
    (This)->lpVtbl -> get_DefaultValue(This,pVal)

#define IDaqEnum_put_DefaultValue(This,newVal)	\
    (This)->lpVtbl -> put_DefaultValue(This,newVal)

#define IDaqEnum_IsValidValue(This,value)	\
    (This)->lpVtbl -> IsValidValue(This,value)


#define IDaqEnum_AddEnumValues(This,values)	\
    (This)->lpVtbl -> AddEnumValues(This,values)

#define IDaqEnum_ClearEnumValues(This)	\
    (This)->lpVtbl -> ClearEnumValues(This)

#define IDaqEnum_RemoveEnumValue(This,values)	\
    (This)->lpVtbl -> RemoveEnumValue(This,values)

#define IDaqEnum_EnumValues(This,EnumVARIANT)	\
    (This)->lpVtbl -> EnumValues(This,EnumVARIANT)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEnum_AddEnumValues_Proxy( 
    IDaqEnum * This,
    /* [in] */ VARIANTREF values);


void __RPC_STUB IDaqEnum_AddEnumValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEnum_ClearEnumValues_Proxy( 
    IDaqEnum * This);


void __RPC_STUB IDaqEnum_ClearEnumValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEnum_RemoveEnumValue_Proxy( 
    IDaqEnum * This,
    /* [in] */ VARIANTREF values);


void __RPC_STUB IDaqEnum_RemoveEnumValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEnum_EnumValues_Proxy( 
    IDaqEnum * This,
    /* [out] */ IEnumVARIANT **EnumVARIANT);


void __RPC_STUB IDaqEnum_EnumValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDaqEnum_INTERFACE_DEFINED__ */


#ifndef __IDaqMappedEnum_INTERFACE_DEFINED__
#define __IDaqMappedEnum_INTERFACE_DEFINED__

/* interface IDaqMappedEnum */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDaqMappedEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3F93B80-93C7-11d3-A526-00902757EA8D")
    IDaqMappedEnum : public IDaqEnum
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddMappedEnumValue( 
            long Value,
            /* [string][in] */ LPCOLESTR StringValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindString( 
            /* [in] */ long Value,
            /* [out] */ BSTR *StringValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindValue( 
            /* [string][in] */ LPCOLESTR StringValue,
            /* [out] */ long *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDaqMappedEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDaqMappedEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDaqMappedEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDaqMappedEnum * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IDaqMappedEnum * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IDaqMappedEnum * This,
            /* [string][in] */ LPCOLESTR newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IDaqMappedEnum * This,
            /* [out] */ long *Type);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            IDaqMappedEnum * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_User )( 
            IDaqMappedEnum * This,
            /* [in] */ long newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHidden )( 
            IDaqMappedEnum * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHidden )( 
            IDaqMappedEnum * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IDaqMappedEnum * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadOnly )( 
            IDaqMappedEnum * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadonlyRunning )( 
            IDaqMappedEnum * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadonlyRunning )( 
            IDaqMappedEnum * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRange )( 
            IDaqMappedEnum * This,
            /* [out] */ VARIANT *min,
            /* [out] */ VARIANT *max);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IDaqMappedEnum * This,
            /* [in] */ VARIANT *min,
            /* [in] */ VARIANT *max);
        
        /* [local][restricted][hidden][helpstring] */ long ( STDMETHODCALLTYPE *_GetObject )( 
            IDaqMappedEnum * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultValue )( 
            IDaqMappedEnum * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultValue )( 
            IDaqMappedEnum * This,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsValidValue )( 
            IDaqMappedEnum * This,
            /* [in] */ VARIANTREF value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddEnumValues )( 
            IDaqMappedEnum * This,
            /* [in] */ VARIANTREF values);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ClearEnumValues )( 
            IDaqMappedEnum * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveEnumValue )( 
            IDaqMappedEnum * This,
            /* [in] */ VARIANTREF values);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            IDaqMappedEnum * This,
            /* [out] */ IEnumVARIANT **EnumVARIANT);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddMappedEnumValue )( 
            IDaqMappedEnum * This,
            long Value,
            /* [string][in] */ LPCOLESTR StringValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindString )( 
            IDaqMappedEnum * This,
            /* [in] */ long Value,
            /* [out] */ BSTR *StringValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindValue )( 
            IDaqMappedEnum * This,
            /* [string][in] */ LPCOLESTR StringValue,
            /* [out] */ long *value);
        
        END_INTERFACE
    } IDaqMappedEnumVtbl;

    interface IDaqMappedEnum
    {
        CONST_VTBL struct IDaqMappedEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDaqMappedEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDaqMappedEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDaqMappedEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDaqMappedEnum_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IDaqMappedEnum_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IDaqMappedEnum_GetType(This,Type)	\
    (This)->lpVtbl -> GetType(This,Type)

#define IDaqMappedEnum_get_User(This,pVal)	\
    (This)->lpVtbl -> get_User(This,pVal)

#define IDaqMappedEnum_put_User(This,newVal)	\
    (This)->lpVtbl -> put_User(This,newVal)

#define IDaqMappedEnum_get_IsHidden(This,pVal)	\
    (This)->lpVtbl -> get_IsHidden(This,pVal)

#define IDaqMappedEnum_put_IsHidden(This,newVal)	\
    (This)->lpVtbl -> put_IsHidden(This,newVal)

#define IDaqMappedEnum_get_IsReadOnly(This,pVal)	\
    (This)->lpVtbl -> get_IsReadOnly(This,pVal)

#define IDaqMappedEnum_put_IsReadOnly(This,newVal)	\
    (This)->lpVtbl -> put_IsReadOnly(This,newVal)

#define IDaqMappedEnum_get_IsReadonlyRunning(This,pVal)	\
    (This)->lpVtbl -> get_IsReadonlyRunning(This,pVal)

#define IDaqMappedEnum_put_IsReadonlyRunning(This,newVal)	\
    (This)->lpVtbl -> put_IsReadonlyRunning(This,newVal)

#define IDaqMappedEnum_GetRange(This,min,max)	\
    (This)->lpVtbl -> GetRange(This,min,max)

#define IDaqMappedEnum_SetRange(This,min,max)	\
    (This)->lpVtbl -> SetRange(This,min,max)

#define IDaqMappedEnum__GetObject(This)	\
    (This)->lpVtbl -> _GetObject(This)

#define IDaqMappedEnum_get_DefaultValue(This,pVal)	\
    (This)->lpVtbl -> get_DefaultValue(This,pVal)

#define IDaqMappedEnum_put_DefaultValue(This,newVal)	\
    (This)->lpVtbl -> put_DefaultValue(This,newVal)

#define IDaqMappedEnum_IsValidValue(This,value)	\
    (This)->lpVtbl -> IsValidValue(This,value)


#define IDaqMappedEnum_AddEnumValues(This,values)	\
    (This)->lpVtbl -> AddEnumValues(This,values)

#define IDaqMappedEnum_ClearEnumValues(This)	\
    (This)->lpVtbl -> ClearEnumValues(This)

#define IDaqMappedEnum_RemoveEnumValue(This,values)	\
    (This)->lpVtbl -> RemoveEnumValue(This,values)

#define IDaqMappedEnum_EnumValues(This,EnumVARIANT)	\
    (This)->lpVtbl -> EnumValues(This,EnumVARIANT)


#define IDaqMappedEnum_AddMappedEnumValue(This,Value,StringValue)	\
    (This)->lpVtbl -> AddMappedEnumValue(This,Value,StringValue)

#define IDaqMappedEnum_FindString(This,Value,StringValue)	\
    (This)->lpVtbl -> FindString(This,Value,StringValue)

#define IDaqMappedEnum_FindValue(This,StringValue,value)	\
    (This)->lpVtbl -> FindValue(This,StringValue,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqMappedEnum_AddMappedEnumValue_Proxy( 
    IDaqMappedEnum * This,
    long Value,
    /* [string][in] */ LPCOLESTR StringValue);


void __RPC_STUB IDaqMappedEnum_AddMappedEnumValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqMappedEnum_FindString_Proxy( 
    IDaqMappedEnum * This,
    /* [in] */ long Value,
    /* [out] */ BSTR *StringValue);


void __RPC_STUB IDaqMappedEnum_FindString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqMappedEnum_FindValue_Proxy( 
    IDaqMappedEnum * This,
    /* [string][in] */ LPCOLESTR StringValue,
    /* [out] */ long *value);


void __RPC_STUB IDaqMappedEnum_FindValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDaqMappedEnum_INTERFACE_DEFINED__ */


#ifndef __IProp_INTERFACE_DEFINED__
#define __IProp_INTERFACE_DEFINED__

/* interface IProp */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IProp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0BFA2913-D48E-11D1-90BE-00600841F9FF")
    IProp : public IDaqMappedEnum
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANTREF newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProp * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProp * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProp * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IProp * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IProp * This,
            /* [string][in] */ LPCOLESTR newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IProp * This,
            /* [out] */ long *Type);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            IProp * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_User )( 
            IProp * This,
            /* [in] */ long newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHidden )( 
            IProp * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHidden )( 
            IProp * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IProp * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadOnly )( 
            IProp * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadonlyRunning )( 
            IProp * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsReadonlyRunning )( 
            IProp * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRange )( 
            IProp * This,
            /* [out] */ VARIANT *min,
            /* [out] */ VARIANT *max);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IProp * This,
            /* [in] */ VARIANT *min,
            /* [in] */ VARIANT *max);
        
        /* [local][restricted][hidden][helpstring] */ long ( STDMETHODCALLTYPE *_GetObject )( 
            IProp * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultValue )( 
            IProp * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultValue )( 
            IProp * This,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsValidValue )( 
            IProp * This,
            /* [in] */ VARIANTREF value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddEnumValues )( 
            IProp * This,
            /* [in] */ VARIANTREF values);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ClearEnumValues )( 
            IProp * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveEnumValue )( 
            IProp * This,
            /* [in] */ VARIANTREF values);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumValues )( 
            IProp * This,
            /* [out] */ IEnumVARIANT **EnumVARIANT);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddMappedEnumValue )( 
            IProp * This,
            long Value,
            /* [string][in] */ LPCOLESTR StringValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindString )( 
            IProp * This,
            /* [in] */ long Value,
            /* [out] */ BSTR *StringValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindValue )( 
            IProp * This,
            /* [string][in] */ LPCOLESTR StringValue,
            /* [out] */ long *value);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IProp * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IProp * This,
            /* [in] */ VARIANTREF newVal);
        
        END_INTERFACE
    } IPropVtbl;

    interface IProp
    {
        CONST_VTBL struct IPropVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProp_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IProp_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IProp_GetType(This,Type)	\
    (This)->lpVtbl -> GetType(This,Type)

#define IProp_get_User(This,pVal)	\
    (This)->lpVtbl -> get_User(This,pVal)

#define IProp_put_User(This,newVal)	\
    (This)->lpVtbl -> put_User(This,newVal)

#define IProp_get_IsHidden(This,pVal)	\
    (This)->lpVtbl -> get_IsHidden(This,pVal)

#define IProp_put_IsHidden(This,newVal)	\
    (This)->lpVtbl -> put_IsHidden(This,newVal)

#define IProp_get_IsReadOnly(This,pVal)	\
    (This)->lpVtbl -> get_IsReadOnly(This,pVal)

#define IProp_put_IsReadOnly(This,newVal)	\
    (This)->lpVtbl -> put_IsReadOnly(This,newVal)

#define IProp_get_IsReadonlyRunning(This,pVal)	\
    (This)->lpVtbl -> get_IsReadonlyRunning(This,pVal)

#define IProp_put_IsReadonlyRunning(This,newVal)	\
    (This)->lpVtbl -> put_IsReadonlyRunning(This,newVal)

#define IProp_GetRange(This,min,max)	\
    (This)->lpVtbl -> GetRange(This,min,max)

#define IProp_SetRange(This,min,max)	\
    (This)->lpVtbl -> SetRange(This,min,max)

#define IProp__GetObject(This)	\
    (This)->lpVtbl -> _GetObject(This)

#define IProp_get_DefaultValue(This,pVal)	\
    (This)->lpVtbl -> get_DefaultValue(This,pVal)

#define IProp_put_DefaultValue(This,newVal)	\
    (This)->lpVtbl -> put_DefaultValue(This,newVal)

#define IProp_IsValidValue(This,value)	\
    (This)->lpVtbl -> IsValidValue(This,value)


#define IProp_AddEnumValues(This,values)	\
    (This)->lpVtbl -> AddEnumValues(This,values)

#define IProp_ClearEnumValues(This)	\
    (This)->lpVtbl -> ClearEnumValues(This)

#define IProp_RemoveEnumValue(This,values)	\
    (This)->lpVtbl -> RemoveEnumValue(This,values)

#define IProp_EnumValues(This,EnumVARIANT)	\
    (This)->lpVtbl -> EnumValues(This,EnumVARIANT)


#define IProp_AddMappedEnumValue(This,Value,StringValue)	\
    (This)->lpVtbl -> AddMappedEnumValue(This,Value,StringValue)

#define IProp_FindString(This,Value,StringValue)	\
    (This)->lpVtbl -> FindString(This,Value,StringValue)

#define IProp_FindValue(This,StringValue,value)	\
    (This)->lpVtbl -> FindValue(This,StringValue,value)


#define IProp_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define IProp_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IProp_get_Value_Proxy( 
    IProp * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IProp_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IProp_put_Value_Proxy( 
    IProp * This,
    /* [in] */ VARIANTREF newVal);


void __RPC_STUB IProp_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProp_INTERFACE_DEFINED__ */


#ifndef __IPropValue_INTERFACE_DEFINED__
#define __IPropValue_INTERFACE_DEFINED__

/* interface IPropValue */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IPropValue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A27FFA5-5CEF-11d4-A591-00902757EA8D")
    IPropValue : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANTREF newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropValueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropValue * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropValue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropValue * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IPropValue * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IPropValue * This,
            /* [in] */ VARIANTREF newVal);
        
        END_INTERFACE
    } IPropValueVtbl;

    interface IPropValue
    {
        CONST_VTBL struct IPropValueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropValue_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropValue_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropValue_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropValue_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define IPropValue_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropValue_get_Value_Proxy( 
    IPropValue * This,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IPropValue_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropValue_put_Value_Proxy( 
    IPropValue * This,
    /* [in] */ VARIANTREF newVal);


void __RPC_STUB IPropValue_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPropValue_INTERFACE_DEFINED__ */


#ifndef __IPropContainer_INTERFACE_DEFINED__
#define __IPropContainer_INTERFACE_DEFINED__

/* interface IPropContainer */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IPropContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E79D1B45-DF5F-11D1-90C1-00600841F9FF")
    IPropContainer : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_MemberValue( 
            /* [string][in] */ LPCOLESTR MemberName,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_MemberValue( 
            /* [string][in] */ LPCOLESTR MemberName,
            /* [in] */ VARIANTREF newVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMemberInterface( 
            /* [unique][string][in] */ LPCOLESTR MemberName,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][retval][out] */ void **Interface) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateProperty( 
            /* [string][in] */ LPCOLESTR Name,
            /* [in] */ VARIANT *InitialValue,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][out] */ void **NewProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumMembers( 
            /* [out] */ IEnumUnknown **ppIEnumUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropContainer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropContainer * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MemberValue )( 
            IPropContainer * This,
            /* [string][in] */ LPCOLESTR MemberName,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MemberValue )( 
            IPropContainer * This,
            /* [string][in] */ LPCOLESTR MemberName,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMemberInterface )( 
            IPropContainer * This,
            /* [unique][string][in] */ LPCOLESTR MemberName,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][retval][out] */ void **Interface);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProperty )( 
            IPropContainer * This,
            /* [string][in] */ LPCOLESTR Name,
            /* [in] */ VARIANT *InitialValue,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][out] */ void **NewProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumMembers )( 
            IPropContainer * This,
            /* [out] */ IEnumUnknown **ppIEnumUnk);
        
        END_INTERFACE
    } IPropContainerVtbl;

    interface IPropContainer
    {
        CONST_VTBL struct IPropContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropContainer_get_MemberValue(This,MemberName,pVal)	\
    (This)->lpVtbl -> get_MemberValue(This,MemberName,pVal)

#define IPropContainer_put_MemberValue(This,MemberName,newVal)	\
    (This)->lpVtbl -> put_MemberValue(This,MemberName,newVal)

#define IPropContainer_GetMemberInterface(This,MemberName,RequesedIID,Interface)	\
    (This)->lpVtbl -> GetMemberInterface(This,MemberName,RequesedIID,Interface)

#define IPropContainer_CreateProperty(This,Name,InitialValue,RequesedIID,NewProp)	\
    (This)->lpVtbl -> CreateProperty(This,Name,InitialValue,RequesedIID,NewProp)

#define IPropContainer_EnumMembers(This,ppIEnumUnk)	\
    (This)->lpVtbl -> EnumMembers(This,ppIEnumUnk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPropContainer_get_MemberValue_Proxy( 
    IPropContainer * This,
    /* [string][in] */ LPCOLESTR MemberName,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IPropContainer_get_MemberValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPropContainer_put_MemberValue_Proxy( 
    IPropContainer * This,
    /* [string][in] */ LPCOLESTR MemberName,
    /* [in] */ VARIANTREF newVal);


void __RPC_STUB IPropContainer_put_MemberValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropContainer_GetMemberInterface_Proxy( 
    IPropContainer * This,
    /* [unique][string][in] */ LPCOLESTR MemberName,
    /* [in] */ REFIID RequesedIID,
    /* [iid_is][retval][out] */ void **Interface);


void __RPC_STUB IPropContainer_GetMemberInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropContainer_CreateProperty_Proxy( 
    IPropContainer * This,
    /* [string][in] */ LPCOLESTR Name,
    /* [in] */ VARIANT *InitialValue,
    /* [in] */ REFIID RequesedIID,
    /* [iid_is][out] */ void **NewProp);


void __RPC_STUB IPropContainer_CreateProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPropContainer_EnumMembers_Proxy( 
    IPropContainer * This,
    /* [out] */ IEnumUnknown **ppIEnumUnk);


void __RPC_STUB IPropContainer_EnumMembers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPropContainer_INTERFACE_DEFINED__ */


#ifndef __IChannelList_INTERFACE_DEFINED__
#define __IChannelList_INTERFACE_DEFINED__

/* interface IChannelList */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IChannelList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BEEFAC1-E54A-11d3-A551-00902757EA8D")
    IChannelList : public IPropContainer
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetChannelContainer( 
            long index,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **Cont) = 0;
        
        virtual /* [local][helpstring] */ HRESULT STDMETHODCALLTYPE GetChannelStructLocal( 
            long index,
            /* [ref][out] */ NESTABLEPROP **Channel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetChannelStruct( 
            long index,
            /* [out] */ NESTABLEPROP **Channel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNumberOfChannels( 
            /* [out] */ long *Number) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateChannel( 
            long HwChannel,
            /* [out] */ IPropContainer **Cont) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteChannel( 
            long index) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteAllChannels( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChannelListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChannelList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChannelList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChannelList * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MemberValue )( 
            IChannelList * This,
            /* [string][in] */ LPCOLESTR MemberName,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MemberValue )( 
            IChannelList * This,
            /* [string][in] */ LPCOLESTR MemberName,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMemberInterface )( 
            IChannelList * This,
            /* [unique][string][in] */ LPCOLESTR MemberName,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][retval][out] */ void **Interface);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProperty )( 
            IChannelList * This,
            /* [string][in] */ LPCOLESTR Name,
            /* [in] */ VARIANT *InitialValue,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][out] */ void **NewProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumMembers )( 
            IChannelList * This,
            /* [out] */ IEnumUnknown **ppIEnumUnk);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetChannelContainer )( 
            IChannelList * This,
            long index,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **Cont);
        
        /* [local][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetChannelStructLocal )( 
            IChannelList * This,
            long index,
            /* [ref][out] */ NESTABLEPROP **Channel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetChannelStruct )( 
            IChannelList * This,
            long index,
            /* [out] */ NESTABLEPROP **Channel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNumberOfChannels )( 
            IChannelList * This,
            /* [out] */ long *Number);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateChannel )( 
            IChannelList * This,
            long HwChannel,
            /* [out] */ IPropContainer **Cont);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteChannel )( 
            IChannelList * This,
            long index);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteAllChannels )( 
            IChannelList * This);
        
        END_INTERFACE
    } IChannelListVtbl;

    interface IChannelList
    {
        CONST_VTBL struct IChannelListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChannelList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChannelList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChannelList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChannelList_get_MemberValue(This,MemberName,pVal)	\
    (This)->lpVtbl -> get_MemberValue(This,MemberName,pVal)

#define IChannelList_put_MemberValue(This,MemberName,newVal)	\
    (This)->lpVtbl -> put_MemberValue(This,MemberName,newVal)

#define IChannelList_GetMemberInterface(This,MemberName,RequesedIID,Interface)	\
    (This)->lpVtbl -> GetMemberInterface(This,MemberName,RequesedIID,Interface)

#define IChannelList_CreateProperty(This,Name,InitialValue,RequesedIID,NewProp)	\
    (This)->lpVtbl -> CreateProperty(This,Name,InitialValue,RequesedIID,NewProp)

#define IChannelList_EnumMembers(This,ppIEnumUnk)	\
    (This)->lpVtbl -> EnumMembers(This,ppIEnumUnk)


#define IChannelList_GetChannelContainer(This,index,riid,Cont)	\
    (This)->lpVtbl -> GetChannelContainer(This,index,riid,Cont)

#define IChannelList_GetChannelStructLocal(This,index,Channel)	\
    (This)->lpVtbl -> GetChannelStructLocal(This,index,Channel)

#define IChannelList_GetChannelStruct(This,index,Channel)	\
    (This)->lpVtbl -> GetChannelStruct(This,index,Channel)

#define IChannelList_GetNumberOfChannels(This,Number)	\
    (This)->lpVtbl -> GetNumberOfChannels(This,Number)

#define IChannelList_CreateChannel(This,HwChannel,Cont)	\
    (This)->lpVtbl -> CreateChannel(This,HwChannel,Cont)

#define IChannelList_DeleteChannel(This,index)	\
    (This)->lpVtbl -> DeleteChannel(This,index)

#define IChannelList_DeleteAllChannels(This)	\
    (This)->lpVtbl -> DeleteAllChannels(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannelList_GetChannelContainer_Proxy( 
    IChannelList * This,
    long index,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **Cont);


void __RPC_STUB IChannelList_GetChannelContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local][helpstring] */ HRESULT STDMETHODCALLTYPE IChannelList_GetChannelStructLocal_Proxy( 
    IChannelList * This,
    long index,
    /* [ref][out] */ NESTABLEPROP **Channel);


void __RPC_STUB IChannelList_GetChannelStructLocal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannelList_GetChannelStruct_Proxy( 
    IChannelList * This,
    long index,
    /* [out] */ NESTABLEPROP **Channel);


void __RPC_STUB IChannelList_GetChannelStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannelList_GetNumberOfChannels_Proxy( 
    IChannelList * This,
    /* [out] */ long *Number);


void __RPC_STUB IChannelList_GetNumberOfChannels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannelList_CreateChannel_Proxy( 
    IChannelList * This,
    long HwChannel,
    /* [out] */ IPropContainer **Cont);


void __RPC_STUB IChannelList_CreateChannel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannelList_DeleteChannel_Proxy( 
    IChannelList * This,
    long index);


void __RPC_STUB IChannelList_DeleteChannel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannelList_DeleteAllChannels_Proxy( 
    IChannelList * This);


void __RPC_STUB IChannelList_DeleteAllChannels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChannelList_INTERFACE_DEFINED__ */


#ifndef __IChannel_INTERFACE_DEFINED__
#define __IChannel_INTERFACE_DEFINED__

/* interface IChannel */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BEEFAC0-E54A-11d3-A551-00902757EA8D")
    IChannel : public IPropContainer
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_PropValue( 
            /* [in] */ REFIID riid,
            /* [iid_is][in] */ IPropRoot *Member,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_PropValue( 
            /* [in] */ REFIID riid,
            /* [iid_is][in] */ IPropRoot *Member,
            /* [in] */ VARIANTREF newVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UnitsToBinary( 
            /* [in] */ double UnitsVal,
            /* [out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BinaryToUnits( 
            /* [in] */ VARIANTREF BinaryVal,
            /* [out] */ double *UnitsVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChannelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChannel * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChannel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChannel * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MemberValue )( 
            IChannel * This,
            /* [string][in] */ LPCOLESTR MemberName,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MemberValue )( 
            IChannel * This,
            /* [string][in] */ LPCOLESTR MemberName,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMemberInterface )( 
            IChannel * This,
            /* [unique][string][in] */ LPCOLESTR MemberName,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][retval][out] */ void **Interface);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateProperty )( 
            IChannel * This,
            /* [string][in] */ LPCOLESTR Name,
            /* [in] */ VARIANT *InitialValue,
            /* [in] */ REFIID RequesedIID,
            /* [iid_is][out] */ void **NewProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumMembers )( 
            IChannel * This,
            /* [out] */ IEnumUnknown **ppIEnumUnk);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PropValue )( 
            IChannel * This,
            /* [in] */ REFIID riid,
            /* [iid_is][in] */ IPropRoot *Member,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PropValue )( 
            IChannel * This,
            /* [in] */ REFIID riid,
            /* [iid_is][in] */ IPropRoot *Member,
            /* [in] */ VARIANTREF newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnitsToBinary )( 
            IChannel * This,
            /* [in] */ double UnitsVal,
            /* [out] */ VARIANT *pVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BinaryToUnits )( 
            IChannel * This,
            /* [in] */ VARIANTREF BinaryVal,
            /* [out] */ double *UnitsVal);
        
        END_INTERFACE
    } IChannelVtbl;

    interface IChannel
    {
        CONST_VTBL struct IChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChannel_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChannel_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChannel_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChannel_get_MemberValue(This,MemberName,pVal)	\
    (This)->lpVtbl -> get_MemberValue(This,MemberName,pVal)

#define IChannel_put_MemberValue(This,MemberName,newVal)	\
    (This)->lpVtbl -> put_MemberValue(This,MemberName,newVal)

#define IChannel_GetMemberInterface(This,MemberName,RequesedIID,Interface)	\
    (This)->lpVtbl -> GetMemberInterface(This,MemberName,RequesedIID,Interface)

#define IChannel_CreateProperty(This,Name,InitialValue,RequesedIID,NewProp)	\
    (This)->lpVtbl -> CreateProperty(This,Name,InitialValue,RequesedIID,NewProp)

#define IChannel_EnumMembers(This,ppIEnumUnk)	\
    (This)->lpVtbl -> EnumMembers(This,ppIEnumUnk)


#define IChannel_get_PropValue(This,riid,Member,pVal)	\
    (This)->lpVtbl -> get_PropValue(This,riid,Member,pVal)

#define IChannel_put_PropValue(This,riid,Member,newVal)	\
    (This)->lpVtbl -> put_PropValue(This,riid,Member,newVal)

#define IChannel_UnitsToBinary(This,UnitsVal,pVal)	\
    (This)->lpVtbl -> UnitsToBinary(This,UnitsVal,pVal)

#define IChannel_BinaryToUnits(This,BinaryVal,UnitsVal)	\
    (This)->lpVtbl -> BinaryToUnits(This,BinaryVal,UnitsVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IChannel_get_PropValue_Proxy( 
    IChannel * This,
    /* [in] */ REFIID riid,
    /* [iid_is][in] */ IPropRoot *Member,
    /* [retval][out] */ VARIANT *pVal);


void __RPC_STUB IChannel_get_PropValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IChannel_put_PropValue_Proxy( 
    IChannel * This,
    /* [in] */ REFIID riid,
    /* [iid_is][in] */ IPropRoot *Member,
    /* [in] */ VARIANTREF newVal);


void __RPC_STUB IChannel_put_PropValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannel_UnitsToBinary_Proxy( 
    IChannel * This,
    /* [in] */ double UnitsVal,
    /* [out] */ VARIANT *pVal);


void __RPC_STUB IChannel_UnitsToBinary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChannel_BinaryToUnits_Proxy( 
    IChannel * This,
    /* [in] */ VARIANTREF BinaryVal,
    /* [out] */ double *UnitsVal);


void __RPC_STUB IChannel_BinaryToUnits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChannel_INTERFACE_DEFINED__ */


#ifndef __IDaqEngine_INTERFACE_DEFINED__
#define __IDaqEngine_INTERFACE_DEFINED__

/* interface IDaqEngine */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDaqEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BEEFABF-E54A-11d3-A551-00902757EA8D")
    IDaqEngine : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTime( 
            /* [out] */ double *Time) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WarningMessage( 
            /* [in] */ BSTR Message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DaqEvent( 
            DWORD event,
            double time,
            hyper sample,
            /* [unique][in] */ BSTR Message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetBufferingConfig( 
            /* [out] */ long *BufferSizeSamples,
            /* [out] */ long *NumBuffers) = 0;
        
        virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE PutBuffer( 
            /* [unique][in] */ BUFFER_ST *Buffer) = 0;
        
        virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE GetBuffer( 
            long Timeout,
            /* [unique][out] */ BUFFER_ST **Buffer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PutInputData( 
            /* [in] */ long Timeout,
            /* [in] */ BUFFER_ST *Buffer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOutputData( 
            /* [in] */ long Timeout,
            /* [out] */ BUFFER_ST *Buffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDaqEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDaqEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDaqEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDaqEngine * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTime )( 
            IDaqEngine * This,
            /* [out] */ double *Time);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WarningMessage )( 
            IDaqEngine * This,
            /* [in] */ BSTR Message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DaqEvent )( 
            IDaqEngine * This,
            DWORD event,
            double time,
            hyper sample,
            /* [unique][in] */ BSTR Message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetBufferingConfig )( 
            IDaqEngine * This,
            /* [out] */ long *BufferSizeSamples,
            /* [out] */ long *NumBuffers);
        
        /* [helpstring][local] */ HRESULT ( STDMETHODCALLTYPE *PutBuffer )( 
            IDaqEngine * This,
            /* [unique][in] */ BUFFER_ST *Buffer);
        
        /* [helpstring][local] */ HRESULT ( STDMETHODCALLTYPE *GetBuffer )( 
            IDaqEngine * This,
            long Timeout,
            /* [unique][out] */ BUFFER_ST **Buffer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PutInputData )( 
            IDaqEngine * This,
            /* [in] */ long Timeout,
            /* [in] */ BUFFER_ST *Buffer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetOutputData )( 
            IDaqEngine * This,
            /* [in] */ long Timeout,
            /* [out] */ BUFFER_ST *Buffer);
        
        END_INTERFACE
    } IDaqEngineVtbl;

    interface IDaqEngine
    {
        CONST_VTBL struct IDaqEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDaqEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDaqEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDaqEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDaqEngine_GetTime(This,Time)	\
    (This)->lpVtbl -> GetTime(This,Time)

#define IDaqEngine_WarningMessage(This,Message)	\
    (This)->lpVtbl -> WarningMessage(This,Message)

#define IDaqEngine_DaqEvent(This,event,time,sample,Message)	\
    (This)->lpVtbl -> DaqEvent(This,event,time,sample,Message)

#define IDaqEngine_GetBufferingConfig(This,BufferSizeSamples,NumBuffers)	\
    (This)->lpVtbl -> GetBufferingConfig(This,BufferSizeSamples,NumBuffers)

#define IDaqEngine_PutBuffer(This,Buffer)	\
    (This)->lpVtbl -> PutBuffer(This,Buffer)

#define IDaqEngine_GetBuffer(This,Timeout,Buffer)	\
    (This)->lpVtbl -> GetBuffer(This,Timeout,Buffer)

#define IDaqEngine_PutInputData(This,Timeout,Buffer)	\
    (This)->lpVtbl -> PutInputData(This,Timeout,Buffer)

#define IDaqEngine_GetOutputData(This,Timeout,Buffer)	\
    (This)->lpVtbl -> GetOutputData(This,Timeout,Buffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEngine_GetTime_Proxy( 
    IDaqEngine * This,
    /* [out] */ double *Time);


void __RPC_STUB IDaqEngine_GetTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEngine_WarningMessage_Proxy( 
    IDaqEngine * This,
    /* [in] */ BSTR Message);


void __RPC_STUB IDaqEngine_WarningMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEngine_DaqEvent_Proxy( 
    IDaqEngine * This,
    DWORD event,
    double time,
    hyper sample,
    /* [unique][in] */ BSTR Message);


void __RPC_STUB IDaqEngine_DaqEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEngine_GetBufferingConfig_Proxy( 
    IDaqEngine * This,
    /* [out] */ long *BufferSizeSamples,
    /* [out] */ long *NumBuffers);


void __RPC_STUB IDaqEngine_GetBufferingConfig_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][local] */ HRESULT STDMETHODCALLTYPE IDaqEngine_PutBuffer_Proxy( 
    IDaqEngine * This,
    /* [unique][in] */ BUFFER_ST *Buffer);


void __RPC_STUB IDaqEngine_PutBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][local] */ HRESULT STDMETHODCALLTYPE IDaqEngine_GetBuffer_Proxy( 
    IDaqEngine * This,
    long Timeout,
    /* [unique][out] */ BUFFER_ST **Buffer);


void __RPC_STUB IDaqEngine_GetBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEngine_PutInputData_Proxy( 
    IDaqEngine * This,
    /* [in] */ long Timeout,
    /* [in] */ BUFFER_ST *Buffer);


void __RPC_STUB IDaqEngine_PutInputData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDaqEngine_GetOutputData_Proxy( 
    IDaqEngine * This,
    /* [in] */ long Timeout,
    /* [out] */ BUFFER_ST *Buffer);


void __RPC_STUB IDaqEngine_GetOutputData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDaqEngine_INTERFACE_DEFINED__ */


#ifndef __ImwAdaptor_INTERFACE_DEFINED__
#define __ImwAdaptor_INTERFACE_DEFINED__

/* interface ImwAdaptor */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ImwAdaptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69CA3484-95F5-11d3-A527-00902757EA8D")
    ImwAdaptor : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AdaptorInfo( 
            /* [in] */ IPropContainer *Container) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenDevice( 
            /* [in] */ REFIID DevIID,
            /* [in] */ long nParams,
            /* [size_is][in] */ VARIANT *Param,
            /* [in] */ REFIID EngineIID,
            /* [iid_is][in] */ IUnknown *pEngine,
            /* [iid_is][out] */ void **ppIDevice) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE TranslateError( 
            HRESULT eCode,
            /* [out] */ BSTR *retVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ImwAdaptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImwAdaptor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImwAdaptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImwAdaptor * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AdaptorInfo )( 
            ImwAdaptor * This,
            /* [in] */ IPropContainer *Container);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OpenDevice )( 
            ImwAdaptor * This,
            /* [in] */ REFIID DevIID,
            /* [in] */ long nParams,
            /* [size_is][in] */ VARIANT *Param,
            /* [in] */ REFIID EngineIID,
            /* [iid_is][in] */ IUnknown *pEngine,
            /* [iid_is][out] */ void **ppIDevice);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *TranslateError )( 
            ImwAdaptor * This,
            HRESULT eCode,
            /* [out] */ BSTR *retVal);
        
        END_INTERFACE
    } ImwAdaptorVtbl;

    interface ImwAdaptor
    {
        CONST_VTBL struct ImwAdaptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImwAdaptor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ImwAdaptor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ImwAdaptor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ImwAdaptor_AdaptorInfo(This,Container)	\
    (This)->lpVtbl -> AdaptorInfo(This,Container)

#define ImwAdaptor_OpenDevice(This,DevIID,nParams,Param,EngineIID,pEngine,ppIDevice)	\
    (This)->lpVtbl -> OpenDevice(This,DevIID,nParams,Param,EngineIID,pEngine,ppIDevice)

#define ImwAdaptor_TranslateError(This,eCode,retVal)	\
    (This)->lpVtbl -> TranslateError(This,eCode,retVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwAdaptor_AdaptorInfo_Proxy( 
    ImwAdaptor * This,
    /* [in] */ IPropContainer *Container);


void __RPC_STUB ImwAdaptor_AdaptorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwAdaptor_OpenDevice_Proxy( 
    ImwAdaptor * This,
    /* [in] */ REFIID DevIID,
    /* [in] */ long nParams,
    /* [size_is][in] */ VARIANT *Param,
    /* [in] */ REFIID EngineIID,
    /* [iid_is][in] */ IUnknown *pEngine,
    /* [iid_is][out] */ void **ppIDevice);


void __RPC_STUB ImwAdaptor_OpenDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwAdaptor_TranslateError_Proxy( 
    ImwAdaptor * This,
    HRESULT eCode,
    /* [out] */ BSTR *retVal);


void __RPC_STUB ImwAdaptor_TranslateError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ImwAdaptor_INTERFACE_DEFINED__ */


#ifndef __ImwDevice_INTERFACE_DEFINED__
#define __ImwDevice_INTERFACE_DEFINED__

/* interface ImwDevice */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ImwDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42680178-65FA-11d3-A51B-00902757EA8D")
    ImwDevice : public IUnknown
    {
    public:
        virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE AllocBufferData( 
            /* [out][in] */ BUFFER_ST *pBuffer) = 0;
        
        virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE FreeBufferData( 
            /* [out][in] */ BUFFER_ST *pBuffer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetChannelProperty( 
            /* [in] */ long user,
            /* [in] */ NESTABLEPROP *pChan,
            /* [out][in] */ VARIANT *NewValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [in] */ long user,
            /* [out][in] */ VARIANT *NewValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ hyper *samplesProcessed,
            /* [out] */ BOOL *running) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ChildChange( 
            /* [in] */ DWORD typeofchange,
            /* [out][in] */ NESTABLEPROP *pChan) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ImwDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImwDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImwDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImwDevice * This);
        
        /* [helpstring][local] */ HRESULT ( STDMETHODCALLTYPE *AllocBufferData )( 
            ImwDevice * This,
            /* [out][in] */ BUFFER_ST *pBuffer);
        
        /* [helpstring][local] */ HRESULT ( STDMETHODCALLTYPE *FreeBufferData )( 
            ImwDevice * This,
            /* [out][in] */ BUFFER_ST *pBuffer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetChannelProperty )( 
            ImwDevice * This,
            /* [in] */ long user,
            /* [in] */ NESTABLEPROP *pChan,
            /* [out][in] */ VARIANT *NewValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            ImwDevice * This,
            /* [in] */ long user,
            /* [out][in] */ VARIANT *NewValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            ImwDevice * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            ImwDevice * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            ImwDevice * This,
            /* [out] */ hyper *samplesProcessed,
            /* [out] */ BOOL *running);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ChildChange )( 
            ImwDevice * This,
            /* [in] */ DWORD typeofchange,
            /* [out][in] */ NESTABLEPROP *pChan);
        
        END_INTERFACE
    } ImwDeviceVtbl;

    interface ImwDevice
    {
        CONST_VTBL struct ImwDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImwDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ImwDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ImwDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ImwDevice_AllocBufferData(This,pBuffer)	\
    (This)->lpVtbl -> AllocBufferData(This,pBuffer)

#define ImwDevice_FreeBufferData(This,pBuffer)	\
    (This)->lpVtbl -> FreeBufferData(This,pBuffer)

#define ImwDevice_SetChannelProperty(This,user,pChan,NewValue)	\
    (This)->lpVtbl -> SetChannelProperty(This,user,pChan,NewValue)

#define ImwDevice_SetProperty(This,user,NewValue)	\
    (This)->lpVtbl -> SetProperty(This,user,NewValue)

#define ImwDevice_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define ImwDevice_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#define ImwDevice_GetStatus(This,samplesProcessed,running)	\
    (This)->lpVtbl -> GetStatus(This,samplesProcessed,running)

#define ImwDevice_ChildChange(This,typeofchange,pChan)	\
    (This)->lpVtbl -> ChildChange(This,typeofchange,pChan)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][local] */ HRESULT STDMETHODCALLTYPE ImwDevice_AllocBufferData_Proxy( 
    ImwDevice * This,
    /* [out][in] */ BUFFER_ST *pBuffer);


void __RPC_STUB ImwDevice_AllocBufferData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][local] */ HRESULT STDMETHODCALLTYPE ImwDevice_FreeBufferData_Proxy( 
    ImwDevice * This,
    /* [out][in] */ BUFFER_ST *pBuffer);


void __RPC_STUB ImwDevice_FreeBufferData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDevice_SetChannelProperty_Proxy( 
    ImwDevice * This,
    /* [in] */ long user,
    /* [in] */ NESTABLEPROP *pChan,
    /* [out][in] */ VARIANT *NewValue);


void __RPC_STUB ImwDevice_SetChannelProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDevice_SetProperty_Proxy( 
    ImwDevice * This,
    /* [in] */ long user,
    /* [out][in] */ VARIANT *NewValue);


void __RPC_STUB ImwDevice_SetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDevice_Start_Proxy( 
    ImwDevice * This);


void __RPC_STUB ImwDevice_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDevice_Stop_Proxy( 
    ImwDevice * This);


void __RPC_STUB ImwDevice_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDevice_GetStatus_Proxy( 
    ImwDevice * This,
    /* [out] */ hyper *samplesProcessed,
    /* [out] */ BOOL *running);


void __RPC_STUB ImwDevice_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDevice_ChildChange_Proxy( 
    ImwDevice * This,
    /* [in] */ DWORD typeofchange,
    /* [out][in] */ NESTABLEPROP *pChan);


void __RPC_STUB ImwDevice_ChildChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ImwDevice_INTERFACE_DEFINED__ */


#ifndef __ImwInput_INTERFACE_DEFINED__
#define __ImwInput_INTERFACE_DEFINED__

/* interface ImwInput */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ImwInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42680175-65FA-11d3-A51B-00902757EA8D")
    ImwInput : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSingleValues( 
            /* [out] */ VARIANT *Values) = 0;
        
        virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE PeekData( 
            /* [out][in] */ BUFFER_ST *pBuffer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Trigger( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ImwInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImwInput * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImwInput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImwInput * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSingleValues )( 
            ImwInput * This,
            /* [out] */ VARIANT *Values);
        
        /* [helpstring][local] */ HRESULT ( STDMETHODCALLTYPE *PeekData )( 
            ImwInput * This,
            /* [out][in] */ BUFFER_ST *pBuffer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Trigger )( 
            ImwInput * This);
        
        END_INTERFACE
    } ImwInputVtbl;

    interface ImwInput
    {
        CONST_VTBL struct ImwInputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImwInput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ImwInput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ImwInput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ImwInput_GetSingleValues(This,Values)	\
    (This)->lpVtbl -> GetSingleValues(This,Values)

#define ImwInput_PeekData(This,pBuffer)	\
    (This)->lpVtbl -> PeekData(This,pBuffer)

#define ImwInput_Trigger(This)	\
    (This)->lpVtbl -> Trigger(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwInput_GetSingleValues_Proxy( 
    ImwInput * This,
    /* [out] */ VARIANT *Values);


void __RPC_STUB ImwInput_GetSingleValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][local] */ HRESULT STDMETHODCALLTYPE ImwInput_PeekData_Proxy( 
    ImwInput * This,
    /* [out][in] */ BUFFER_ST *pBuffer);


void __RPC_STUB ImwInput_PeekData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwInput_Trigger_Proxy( 
    ImwInput * This);


void __RPC_STUB ImwInput_Trigger_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ImwInput_INTERFACE_DEFINED__ */


#ifndef __ImwOutput_INTERFACE_DEFINED__
#define __ImwOutput_INTERFACE_DEFINED__

/* interface ImwOutput */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ImwOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42680176-65FA-11d3-A51B-00902757EA8D")
    ImwOutput : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PutSingleValues( 
            /* [in] */ VARIANT *Values) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Trigger( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ImwOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImwOutput * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImwOutput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImwOutput * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PutSingleValues )( 
            ImwOutput * This,
            /* [in] */ VARIANT *Values);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Trigger )( 
            ImwOutput * This);
        
        END_INTERFACE
    } ImwOutputVtbl;

    interface ImwOutput
    {
        CONST_VTBL struct ImwOutputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImwOutput_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ImwOutput_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ImwOutput_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ImwOutput_PutSingleValues(This,Values)	\
    (This)->lpVtbl -> PutSingleValues(This,Values)

#define ImwOutput_Trigger(This)	\
    (This)->lpVtbl -> Trigger(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwOutput_PutSingleValues_Proxy( 
    ImwOutput * This,
    /* [in] */ VARIANT *Values);


void __RPC_STUB ImwOutput_PutSingleValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwOutput_Trigger_Proxy( 
    ImwOutput * This);


void __RPC_STUB ImwOutput_Trigger_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ImwOutput_INTERFACE_DEFINED__ */


#ifndef __ImwDIO_INTERFACE_DEFINED__
#define __ImwDIO_INTERFACE_DEFINED__

/* interface ImwDIO */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ImwDIO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42680177-65FA-11d3-A51B-00902757EA8D")
    ImwDIO : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadValues( 
            /* [in] */ long NumberOfPorts,
            /* [size_is][in] */ long *PortList,
            /* [size_is][out] */ unsigned long *Data) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteValues( 
            /* [in] */ long NumberOfPorts,
            /* [size_is][in] */ long *PortList,
            /* [size_is][in] */ unsigned long *Data,
            /* [size_is][in] */ unsigned long *Mask) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPortDirection( 
            /* [in] */ long Port,
            /* [in] */ unsigned long DirectionValues) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ImwDIOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImwDIO * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImwDIO * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImwDIO * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadValues )( 
            ImwDIO * This,
            /* [in] */ long NumberOfPorts,
            /* [size_is][in] */ long *PortList,
            /* [size_is][out] */ unsigned long *Data);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *WriteValues )( 
            ImwDIO * This,
            /* [in] */ long NumberOfPorts,
            /* [size_is][in] */ long *PortList,
            /* [size_is][in] */ unsigned long *Data,
            /* [size_is][in] */ unsigned long *Mask);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPortDirection )( 
            ImwDIO * This,
            /* [in] */ long Port,
            /* [in] */ unsigned long DirectionValues);
        
        END_INTERFACE
    } ImwDIOVtbl;

    interface ImwDIO
    {
        CONST_VTBL struct ImwDIOVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImwDIO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ImwDIO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ImwDIO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ImwDIO_ReadValues(This,NumberOfPorts,PortList,Data)	\
    (This)->lpVtbl -> ReadValues(This,NumberOfPorts,PortList,Data)

#define ImwDIO_WriteValues(This,NumberOfPorts,PortList,Data,Mask)	\
    (This)->lpVtbl -> WriteValues(This,NumberOfPorts,PortList,Data,Mask)

#define ImwDIO_SetPortDirection(This,Port,DirectionValues)	\
    (This)->lpVtbl -> SetPortDirection(This,Port,DirectionValues)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDIO_ReadValues_Proxy( 
    ImwDIO * This,
    /* [in] */ long NumberOfPorts,
    /* [size_is][in] */ long *PortList,
    /* [size_is][out] */ unsigned long *Data);


void __RPC_STUB ImwDIO_ReadValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDIO_WriteValues_Proxy( 
    ImwDIO * This,
    /* [in] */ long NumberOfPorts,
    /* [size_is][in] */ long *PortList,
    /* [size_is][in] */ unsigned long *Data,
    /* [size_is][in] */ unsigned long *Mask);


void __RPC_STUB ImwDIO_WriteValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ImwDIO_SetPortDirection_Proxy( 
    ImwDIO * This,
    /* [in] */ long Port,
    /* [in] */ unsigned long DirectionValues);


void __RPC_STUB ImwDIO_SetPortDirection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ImwDIO_INTERFACE_DEFINED__ */



#ifndef __DAQMEXLib_LIBRARY_DEFINED__
#define __DAQMEXLib_LIBRARY_DEFINED__

/* library DAQMEXLib */
/* [helpstring][version][uuid] */ 







EXTERN_C const IID LIBID_DAQMEXLib;

EXTERN_C const CLSID CLSID_Prop;

#ifdef __cplusplus

class DECLSPEC_UUID("0BFA2914-D48E-11D1-90BE-00600841F9FF")
Prop;
#endif

EXTERN_C const CLSID CLSID_DaqEngine;

#ifdef __cplusplus

class DECLSPEC_UUID("E79D1B43-DF5F-11D1-90C1-00600841F9FF")
DaqEngine;
#endif

EXTERN_C const CLSID CLSID_PropContainer;

#ifdef __cplusplus

class DECLSPEC_UUID("E79D1B46-DF5F-11D1-90C1-00600841F9FF")
PropContainer;
#endif

EXTERN_C const CLSID CLSID_DaqMappedEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("61D9F511-B6E9-11D3-A538-00902757EA8D")
DaqMappedEnum;
#endif
#endif /* __DAQMEXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


