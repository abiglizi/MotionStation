/* $Revision: 1.2 $ */
#ifndef	__LCC__MAPIDEFS_H
#define	__LCC__MAPIDEFS_H
#if	defined (WIN32) && !defined (_WIN32)
#define	_WIN32
#endif
#include	<windows.h>
#include	<ole2.h>
#include	<rpc.h>
#include	<winerror.h>
#include	<objbase.h>
#include	<stddef.h>
#ifndef	MAPI_DIM
#define	MAPI_DIM 1
#endif
#ifndef	STDMAPIINITCALLTYPE
#if	!defined (_MAC) && defined (_WIN32)
#define	STDMAPIINITCALLTYPE __cdecl
#else
#define	STDMAPIINITCALLTYPE STDMETHODCALLTYPE
#endif
#define	STDINITMETHODIMP HRESULT STDMAPIINITCALLTYPE
#define	STDINITMETHODIMP_(type) type STDMAPIINITCALLTYPE
#endif
#define	MAPI_NT_SERVICE ((ULONG) 0x00010000) 
#if	!defined (MIDL_PASS) 
typedef	WORD WCHAR;
#ifdef	UNICODE
typedef	WCHAR TCHAR;
#else
typedef	char TCHAR;
#endif
#endif	
typedef	ULONG FAR * LPULONG;
#ifndef	__LHANDLE
#define	__LHANDLE
typedef	unsigned long LHANDLE, FAR * LPLHANDLE;
#endif
#ifndef	BEGIN_INTERFACE
#define	BEGIN_INTERFACE
#endif
#define	MAPI_MODIFY ((ULONG) 0x00000001)
#define	MAPI_ACCESS_MODIFY ((ULONG) 0x00000001)
#define	MAPI_ACCESS_READ ((ULONG) 0x00000002)
#define	MAPI_ACCESS_DELETE ((ULONG) 0x00000004)
#define	MAPI_ACCESS_CREATE_HIERARCHY ((ULONG) 0x00000008)
#define	MAPI_ACCESS_CREATE_CONTENTS ((ULONG) 0x00000010)
#define	MAPI_ACCESS_CREATE_ASSOCIATED ((ULONG) 0x00000020)
#define	MAPI_UNICODE ((ULONG) 0x80000000)
#ifdef	UNICODE
#define	fMapiUnicode MAPI_UNICODE
#else
#define	fMapiUnicode 0
#endif
#define	hrSuccess 0
#ifndef	MAPI_ORIG 
#define	MAPI_ORIG 0 
#define	MAPI_TO 1 
#define	MAPI_CC 2 
#define	MAPI_BCC 3 
#define	MAPI_P1 0x10000000 
#define	MAPI_SUBMITTED 0x80000000 
#endif
#define	MAPI_SHORTTERM 0x80
#define	MAPI_NOTRECIP 0x40
#define	MAPI_THISSESSION 0x20
#define	MAPI_NOW 0x10
#define	MAPI_NOTRESERVED 0x08
#define	MAPI_COMPOUND 0x80
typedef	struct {
	BYTE abFlags[4];
	BYTE ab[MAPI_DIM];
}	ENTRYID, FAR *LPENTRYID;
#define	CbNewENTRYID(_cb) (offsetof(ENTRYID,ab) + (_cb))
#define	CbENTRYID(_cb) (offsetof(ENTRYID,ab) + (_cb))
#define	SizedENTRYID(_cb, _name) struct _ENTRYID_ ## _name { \
	BYTE abFlags[4]; \
	BYTE ab[_cb]; \
}	_name
typedef	struct _MAPIUID {
	BYTE ab[16];
}	MAPIUID, FAR * LPMAPIUID;
#define	IsEqualMAPIUID(lpuid1, lpuid2) (!memcmp(lpuid1, lpuid2, sizeof(MAPIUID)))
#define	MAPI_ONE_OFF_UID { 0x81, 0x2b, 0x1f, 0xa4, 0xbe, 0xa3, 0x10, 0x19, \
	0x9d, 0x6e, 0x00, 0xdd, 0x01, 0x0f, 0x54, 0x02 }
#define	MAPI_ONE_OFF_UNICODE 0x8000
#define	MAPI_ONE_OFF_NO_RICH_INFO 0x0001
#define	MAPI_STORE ((ULONG) 0x00000001) 
#define	MAPI_ADDRBOOK ((ULONG) 0x00000002) 
#define	MAPI_FOLDER ((ULONG) 0x00000003) 
#define	MAPI_ABCONT ((ULONG) 0x00000004) 
#define	MAPI_MESSAGE ((ULONG) 0x00000005) 
#define	MAPI_MAILUSER ((ULONG) 0x00000006) 
#define	MAPI_ATTACH ((ULONG) 0x00000007) 
#define	MAPI_DISTLIST ((ULONG) 0x00000008) 
#define	MAPI_PROFSECT ((ULONG) 0x00000009) 
#define	MAPI_STATUS ((ULONG) 0x0000000A) 
#define	MAPI_SESSION ((ULONG) 0x0000000B) 
#define	MAPI_FORMINFO ((ULONG) 0x0000000C) 
#ifndef	cchProfileNameMax
#define	cchProfileNameMax 64
#define	cchProfilePassMax 64
#endif
#define	MV_FLAG 0x1000 
#define	PT_UNSPECIFIED ((ULONG) 0) 
#define	PT_NULL ((ULONG) 1) 
#define	PT_I2 ((ULONG) 2) 
#define	PT_LONG ((ULONG) 3) 
#define	PT_R4 ((ULONG) 4) 
#define	PT_DOUBLE ((ULONG) 5) 
#define	PT_CURRENCY ((ULONG) 6) 
#define	PT_APPTIME ((ULONG) 7) 
#define	PT_ERROR ((ULONG) 10) 
#define	PT_BOOLEAN ((ULONG) 11) 
#define	PT_OBJECT ((ULONG) 13) 
#define	PT_I8 ((ULONG) 20) 
#define	PT_STRING8 ((ULONG) 30) 
#define	PT_UNICODE ((ULONG) 31) 
#define	PT_SYSTIME ((ULONG) 64) 
#define	PT_CLSID ((ULONG) 72) 
#define	PT_BINARY ((ULONG) 258) 
#define	PT_SHORT PT_I2
#define	PT_I4 PT_LONG
#define	PT_FLOAT PT_R4
#define	PT_R8 PT_DOUBLE
#define	PT_LONGLONG PT_I8
#ifdef	UNICODE
#define	PT_TSTRING PT_UNICODE
#define	PT_MV_TSTRING (MV_FLAG|PT_UNICODE)
#define	LPSZ lpszW
#define	LPPSZ lppszW
#define	MVSZ MVszW
#else
#define	PT_TSTRING PT_STRING8
#define	PT_MV_TSTRING (MV_FLAG|PT_STRING8)
#define	LPSZ lpszA
#define	LPPSZ lppszA
#define	MVSZ MVszA
#endif
#define	PROP_TYPE_MASK ((ULONG)0x0000FFFF) 
#define	PROP_TYPE(ulPropTag) (((ULONG)(ulPropTag))&PROP_TYPE_MASK)
#define	PROP_ID(ulPropTag) (((ULONG)(ulPropTag))>>16)
#define	PROP_TAG(ulPropType,ulPropID) ((((ULONG)(ulPropID))<<16)|((ULONG)(ulPropType)))
#define	PROP_ID_NULL 0
#define	PROP_ID_INVALID 0xFFFF
#define	PR_NULL PROP_TAG( PT_NULL, PROP_ID_NULL)
#define	CHANGE_PROP_TYPE(ulPropTag, ulPropType) \
	(((ULONG)0xFFFF0000 & ulPropTag) | ulPropType)
#define	PT_MV_I2 (MV_FLAG|PT_I2)
#define	PT_MV_LONG (MV_FLAG|PT_LONG)
#define	PT_MV_R4 (MV_FLAG|PT_R4)
#define	PT_MV_DOUBLE (MV_FLAG|PT_DOUBLE)
#define	PT_MV_CURRENCY (MV_FLAG|PT_CURRENCY)
#define	PT_MV_APPTIME (MV_FLAG|PT_APPTIME)
#define	PT_MV_SYSTIME (MV_FLAG|PT_SYSTIME)
#define	PT_MV_STRING8 (MV_FLAG|PT_STRING8)
#define	PT_MV_BINARY (MV_FLAG|PT_BINARY)
#define	PT_MV_UNICODE (MV_FLAG|PT_UNICODE)
#define	PT_MV_CLSID (MV_FLAG|PT_CLSID)
#define	PT_MV_I8 (MV_FLAG|PT_I8)
#define	PT_MV_SHORT PT_MV_I2
#define	PT_MV_I4 PT_MV_LONG
#define	PT_MV_FLOAT PT_MV_R4
#define	PT_MV_R8 PT_MV_DOUBLE
#define	PT_MV_LONGLONG PT_MV_I8
#define	MV_INSTANCE 0x2000
#define	MVI_FLAG (MV_FLAG | MV_INSTANCE)
#define	MVI_PROP(tag) ((tag) | MVI_FLAG)
typedef	struct _SPropTagArray {
	ULONG cValues;
	ULONG aulPropTag[MAPI_DIM];
}	SPropTagArray, FAR * LPSPropTagArray;
#define	CbNewSPropTagArray(_ctag) (offsetof(SPropTagArray,aulPropTag) + (_ctag)*sizeof(ULONG))
#define	CbSPropTagArray(_lparray) \
	(offsetof(SPropTagArray,aulPropTag) + \
	(UINT)((_lparray)->cValues)*sizeof(ULONG))
#define	SizedSPropTagArray(_ctag, _name) \
struct	_SPropTagArray_ ## _name \
{	\
	ULONG cValues; \
	ULONG aulPropTag[_ctag]; \
}	_name
typedef	struct _SPropValue SPropValue;
typedef	CY CURRENCY;
typedef	struct _SBinary
{
	ULONG cb;
	LPBYTE lpb;
}	SBinary, FAR *LPSBinary;

typedef	struct _SShortArray
{
	ULONG cValues;
	short int FAR *lpi;
}	SShortArray;

typedef	struct _SGuidArray
{
	ULONG cValues;
	GUID FAR *lpguid;
}	SGuidArray;

typedef	struct _SRealArray
{
	ULONG cValues;
	float FAR *lpflt;
}	SRealArray;

typedef	struct _SLongArray
{
	ULONG cValues;
	LONG FAR *lpl;
}	SLongArray;

typedef	struct _SLargeIntegerArray
{
	ULONG cValues;
	LARGE_INTEGER FAR *lpli;
}	SLargeIntegerArray;

typedef	struct _SDateTimeArray
{
	ULONG cValues;
	FILETIME FAR *lpft;
}	SDateTimeArray;

typedef	struct _SAppTimeArray
{
	ULONG cValues;
	double FAR *lpat;
}	SAppTimeArray;

typedef	struct _SCurrencyArray
{
	ULONG cValues;
	CURRENCY FAR *lpcur;
}	SCurrencyArray;

typedef	struct _SBinaryArray
{
	ULONG cValues;
	SBinary FAR *lpbin;
}	SBinaryArray;

typedef	struct _SDoubleArray
{
	ULONG cValues;
	double FAR *lpdbl;
}	SDoubleArray;

typedef	struct _SWStringArray
{
	ULONG cValues;
	LPWSTR FAR *lppszW;
}	SWStringArray;

typedef	struct _SLPSTRArray
{
	ULONG cValues;
	LPSTR FAR *lppszA;
}	SLPSTRArray;

typedef	union _PV
{
	short int i; 
	LONG l; 
	ULONG ul; 
	float flt; 
	double dbl; 
	unsigned short int b; 
	CURRENCY cur; 
	double at; 
	FILETIME ft; 
	LPSTR lpszA; 
	SBinary bin; 
	LPWSTR lpszW; 
	LPGUID lpguid; 
	LARGE_INTEGER li; 
	SShortArray MVi; 
	SLongArray MVl; 
	SRealArray MVflt; 
	SDoubleArray MVdbl; 
	SCurrencyArray MVcur; 
	SAppTimeArray MVat; 
	SDateTimeArray MVft; 
	SBinaryArray MVbin; 
	SLPSTRArray MVszA; 
	SWStringArray MVszW; 
	SGuidArray MVguid; 
	SLargeIntegerArray MVli; 
	SCODE err; 
	LONG x; 
}	__UPV;

typedef	struct _SPropValue
{
	ULONG ulPropTag;
	ULONG dwAlignPad;
	union _PV Value;
}	SPropValue, FAR * LPSPropValue;






typedef	struct _SPropProblem
{
	ULONG ulIndex;
	ULONG ulPropTag;
	SCODE scode;
}	SPropProblem, FAR * LPSPropProblem;

typedef	struct _SPropProblemArray
{
	ULONG cProblem;
	SPropProblem aProblem[MAPI_DIM];
}	SPropProblemArray, FAR * LPSPropProblemArray;

#define	CbNewSPropProblemArray(_cprob) \
	(offsetof(SPropProblemArray,aProblem) + (_cprob)*sizeof(SPropProblem))
#define	CbSPropProblemArray(_lparray) \
	(offsetof(SPropProblemArray,aProblem) + \
	(UINT) ((_lparray)->cProblem*sizeof(SPropProblem)))
#define	SizedSPropProblemArray(_cprob, _name) \
struct	_SPropProblemArray_ ## _name \
{	\
	ULONG cProblem; \
	SPropProblem aProblem[_cprob]; \
}	_name

/*
	* ENTRYLIST
	*/

typedef	SBinaryArray ENTRYLIST, FAR *LPENTRYLIST;

/*
	* FLATENTRYLIST
	* MTSID
	* FLATMTSIDLIST
	*/

typedef	struct {
	ULONG cb;
	BYTE abEntry[MAPI_DIM];
}	FLATENTRY, FAR *LPFLATENTRY;

typedef	struct {
	ULONG cEntries;
	ULONG cbEntries;
	BYTE abEntries[MAPI_DIM];
}	FLATENTRYLIST, FAR *LPFLATENTRYLIST;

typedef	struct {
	ULONG cb;
	BYTE ab[MAPI_DIM];
}	MTSID, FAR *LPMTSID;

typedef	struct {
	ULONG cMTSIDs;
	ULONG cbMTSIDs;
	BYTE abMTSIDs[MAPI_DIM];
}	FLATMTSIDLIST, FAR *LPFLATMTSIDLIST;

#define	CbNewFLATENTRY(_cb) (offsetof(FLATENTRY,abEntry) + (_cb))
#define	CbFLATENTRY(_lpentry) (offsetof(FLATENTRY,abEntry) + (_lpentry)->cb)
#define	CbNewFLATENTRYLIST(_cb) (offsetof(FLATENTRYLIST,abEntries) + (_cb))
#define	CbFLATENTRYLIST(_lplist) (offsetof(FLATENTRYLIST,abEntries) + (_lplist)->cbEntries)
#define	CbNewMTSID(_cb) (offsetof(MTSID,ab) + (_cb))
#define	CbMTSID(_lpentry) (offsetof(MTSID,ab) + (_lpentry)->cb)
#define	CbNewFLATMTSIDLIST(_cb) (offsetof(FLATMTSIDLIST,abMTSIDs) + (_cb))
#define	CbFLATMTSIDLIST(_lplist) (offsetof(FLATMTSIDLIST,abMTSIDs) + (_lplist)->cbMTSIDs)





typedef	struct _ADRENTRY
{
	ULONG ulReserved1; 
	ULONG cValues;
	LPSPropValue rgPropVals;
}	ADRENTRY, FAR * LPADRENTRY;

typedef	struct _ADRLIST
{
	ULONG cEntries;
	ADRENTRY aEntries[MAPI_DIM];
}	ADRLIST, FAR * LPADRLIST;

#define	CbNewADRLIST(_centries) \
	(offsetof(ADRLIST,aEntries) + (_centries)*sizeof(ADRENTRY))
#define	CbADRLIST(_lpadrlist) \
	(offsetof(ADRLIST,aEntries) + (UINT)(_lpadrlist)->cEntries*sizeof(ADRENTRY))
#define	SizedADRLIST(_centries, _name) \
struct	_ADRLIST_ ## _name \
{	\
	ULONG cEntries; \
	ADRENTRY aEntries[_centries]; \
}	_name




typedef	struct _SRow
{
	ULONG ulAdrEntryPad; 
	ULONG cValues; 
	LPSPropValue lpProps; 
}	SRow, FAR * LPSRow;

typedef	struct _SRowSet
{
	ULONG cRows; 
	SRow aRow[MAPI_DIM]; 
}	SRowSet, FAR * LPSRowSet;

#define	CbNewSRowSet(_crow) (offsetof(SRowSet,aRow) + (_crow)*sizeof(SRow))
#define	CbSRowSet(_lprowset) (offsetof(SRowSet,aRow) + \
	(UINT)((_lprowset)->cRows*sizeof(SRow)))
#define	SizedSRowSet(_crow, _name) \
struct	_SRowSet_ ## _name \
{	\
	ULONG cRows; \
	SRow aRow[_crow]; \
}	_name



typedef	SCODE (STDMETHODCALLTYPE ALLOCATEBUFFER)(
	ULONG cbSize,
	LPVOID FAR * lppBuffer
);

typedef	SCODE (STDMETHODCALLTYPE ALLOCATEMORE)(
	ULONG cbSize,
	LPVOID lpObject,
	LPVOID FAR * lppBuffer
);

typedef	ULONG (STDAPICALLTYPE FREEBUFFER)(
	LPVOID lpBuffer
);

typedef	ALLOCATEBUFFER FAR *LPALLOCATEBUFFER;
typedef	ALLOCATEMORE FAR * LPALLOCATEMORE;
typedef	FREEBUFFER FAR * LPFREEBUFFER;



#if	defined(MAPI_IF) && (!defined(__cplusplus) || defined(CINTERFACE))
#define	DECLARE_MAPI_INTERFACE(iface) \
	typedef struct iface##Vtbl iface##Vtbl, FAR * iface; \
	struct iface##Vtbl
#define	DECLARE_MAPI_INTERFACE_(iface, baseiface) \
	DECLARE_MAPI_INTERFACE(iface)
#define	DECLARE_MAPI_INTERFACE_PTR(iface, piface) \
	typedef struct iface##Vtbl iface##Vtbl, FAR * iface, FAR * FAR * piface;
#else
#define	DECLARE_MAPI_INTERFACE(iface) \
	DECLARE_INTERFACE(iface)
#define	DECLARE_MAPI_INTERFACE_(iface, baseiface) \
	DECLARE_INTERFACE_(iface, baseiface)
#ifdef	__cplusplus
#define	DECLARE_MAPI_INTERFACE_PTR(iface, piface) \
	interface iface; typedef iface FAR * piface
#else
#define	DECLARE_MAPI_INTERFACE_PTR(iface, piface) \
	typedef interface iface iface, FAR * piface
#endif
#endif

#define	MAPIMETHOD(method) MAPIMETHOD_(HRESULT, method)
#define	MAPIMETHOD_(type, method) STDMETHOD_(type, method)
#define	MAPIMETHOD_DECLARE(type, method, prefix) \
	STDMETHODIMP_(type) prefix##method
#define	MAPIMETHOD_TYPEDEF(type, method, prefix) \
	typedef type (STDMETHODCALLTYPE prefix##method##_METHOD)

#define	MAPI_IUNKNOWN_METHODS(IPURE) \
	MAPIMETHOD(QueryInterface) \
	(THIS_ REFIID riid, LPVOID FAR * ppvObj) IPURE; \
	MAPIMETHOD_(ULONG,AddRef) (THIS) IPURE; \
	MAPIMETHOD_(ULONG,Release) (THIS) IPURE; \

#undef	IMPL
#define	IMPL



typedef	const IID FAR * LPCIID;

DECLARE_MAPI_INTERFACE_PTR(IMsgStore,	LPMDB);
DECLARE_MAPI_INTERFACE_PTR(IMAPIFolder,	LPMAPIFOLDER);
DECLARE_MAPI_INTERFACE_PTR(IMessage,	LPMESSAGE);
DECLARE_MAPI_INTERFACE_PTR(IAttach,	LPATTACH);
DECLARE_MAPI_INTERFACE_PTR(IAddrBook,	LPADRBOOK);
DECLARE_MAPI_INTERFACE_PTR(IABContainer,	LPABCONT);
DECLARE_MAPI_INTERFACE_PTR(IMailUser,	LPMAILUSER);
DECLARE_MAPI_INTERFACE_PTR(IDistList,	LPDISTLIST);
DECLARE_MAPI_INTERFACE_PTR(IMAPIStatus,	LPMAPISTATUS);
DECLARE_MAPI_INTERFACE_PTR(IMAPITable,	LPMAPITABLE);
DECLARE_MAPI_INTERFACE_PTR(IProfSect,	LPPROFSECT);
DECLARE_MAPI_INTERFACE_PTR(IMAPIProp,	LPMAPIPROP);
DECLARE_MAPI_INTERFACE_PTR(IMAPIContainer,	LPMAPICONTAINER);
DECLARE_MAPI_INTERFACE_PTR(IMAPIAdviseSink,	LPMAPIADVISESINK);
DECLARE_MAPI_INTERFACE_PTR(IMAPIProgress,	LPMAPIPROGRESS);
DECLARE_MAPI_INTERFACE_PTR(IProviderAdmin,	LPPROVIDERADMIN);



typedef	struct _MAPIERROR
{
	ULONG ulVersion;
	LPTSTR lpszError;
	LPTSTR lpszComponent;
	ULONG ulLowLevelError;
	ULONG ulContext;

}	MAPIERROR, FAR * LPMAPIERROR;




/*
	* Notification event types. The event types can be combined in a bitmask
	* for filtering. Each one has a parameter structure associated with it:
	*
	* fnevCriticalError ERROR_NOTIFICATION
	* fnevNewMail NEWMAIL_NOTIFICATION
	* fnevObjectCreated OBJECT_NOTIFICATION
	* fnevObjectDeleted OBJECT_NOTIFICATION
	* fnevObjectModified OBJECT_NOTIFICATION
	* fnevObjectCopied OBJECT_NOTIFICATION
	* fnevSearchComplete OBJECT_NOTIFICATION
	* fnevTableModified TABLE_NOTIFICATION
	* fnevStatusObjectModified ?
	*
	* fnevExtended EXTENDED_NOTIFICATION
	*/

#define	fnevCriticalError ((ULONG) 0x00000001)
#define	fnevNewMail ((ULONG) 0x00000002)
#define	fnevObjectCreated ((ULONG) 0x00000004)
#define	fnevObjectDeleted ((ULONG) 0x00000008)
#define	fnevObjectModified ((ULONG) 0x00000010)
#define	fnevObjectMoved ((ULONG) 0x00000020)
#define	fnevObjectCopied ((ULONG) 0x00000040)
#define	fnevSearchComplete ((ULONG) 0x00000080)
#define	fnevTableModified ((ULONG) 0x00000100)
#define	fnevStatusObjectModified ((ULONG) 0x00000200)
#define	fnevReservedForMapi ((ULONG) 0x40000000)
#define	fnevExtended ((ULONG) 0x80000000)



#define	TABLE_CHANGED 1
#define	TABLE_ERROR 2
#define	TABLE_ROW_ADDED 3
#define	TABLE_ROW_DELETED 4
#define	TABLE_ROW_MODIFIED 5
#define	TABLE_SORT_DONE 6
#define	TABLE_RESTRICT_DONE 7
#define	TABLE_SETCOL_DONE 8
#define	TABLE_RELOAD 9



typedef	struct _ERROR_NOTIFICATION
{
	ULONG cbEntryID;
	LPENTRYID lpEntryID;
	SCODE scode;
	ULONG ulFlags; 
	LPMAPIERROR lpMAPIError; 
}	ERROR_NOTIFICATION;

typedef	struct _NEWMAIL_NOTIFICATION
{
	ULONG cbEntryID;
	LPENTRYID lpEntryID; 
	ULONG cbParentID;
	LPENTRYID lpParentID; 
	ULONG ulFlags; 
	LPTSTR lpszMessageClass; 
	ULONG ulMessageFlags; 
}	NEWMAIL_NOTIFICATION;

typedef	struct _OBJECT_NOTIFICATION
{
	ULONG cbEntryID;
	LPENTRYID lpEntryID; 
	ULONG ulObjType; 
	ULONG cbParentID;
	LPENTRYID lpParentID; 
	ULONG cbOldID;
	LPENTRYID lpOldID; 
	ULONG cbOldParentID;
	LPENTRYID lpOldParentID; 
	LPSPropTagArray lpPropTagArray;
}	OBJECT_NOTIFICATION;

typedef	struct _TABLE_NOTIFICATION
{
	ULONG ulTableEvent; 
	HRESULT hResult; 
	SPropValue propIndex; 
	SPropValue propPrior; 
	SRow row; 
	ULONG ulPad; 
}	TABLE_NOTIFICATION;

typedef	struct _EXTENDED_NOTIFICATION
{
	ULONG ulEvent; 
	ULONG cb; 
	LPBYTE pbEventParameters; 
}	EXTENDED_NOTIFICATION;

typedef	struct
{
	ULONG cbEntryID;
	LPENTRYID lpEntryID;
	ULONG cValues;
	LPSPropValue lpPropVals;
}	STATUS_OBJECT_NOTIFICATION;

typedef	struct _NOTIFICATION
{
	ULONG ulEventType; 
	ULONG ulAlignPad; 
	union
	{
	ERROR_NOTIFICATION err;
	NEWMAIL_NOTIFICATION newmail;
	OBJECT_NOTIFICATION obj;
	TABLE_NOTIFICATION tab;
	EXTENDED_NOTIFICATION ext;
	STATUS_OBJECT_NOTIFICATION statobj;
	} info;
}	NOTIFICATION, FAR * LPNOTIFICATION;




#define	MAPI_IMAPIADVISESINK_METHODS(IPURE) \
	MAPIMETHOD_(ULONG, OnNotify) \
	(THIS_ ULONG cNotif, \
	LPNOTIFICATION lpNotifications) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPIAdviseSink
DECLARE_MAPI_INTERFACE_(IMAPIAdviseSink,	IUnknown)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIADVISESINK_METHODS(PURE)
};



typedef	long (STDAPICALLTYPE NOTIFCALLBACK) (
	LPVOID lpvContext,
	ULONG cNotification,
	LPNOTIFICATION lpNotifications);
typedef	NOTIFCALLBACK FAR * LPNOTIFCALLBACK;

/*
	* Message name for the 16-bit MAPI notififcation engine.
	* This can be used in 16-bit applications to force processing
	* of notification callbacks.
	*/

#define	szMAPINotificationMsg "MAPI Notify window message"






#define	MAPI_TOP_LEVEL ((ULONG) 0x00000001)

#define	MAPI_IMAPIPROGRESS_METHODS(IPURE) \
	MAPIMETHOD(Progress) \
	(THIS_ ULONG ulValue, \
	ULONG ulCount, \
	ULONG ulTotal) IPURE; \
	MAPIMETHOD(GetFlags) \
	(THIS_ ULONG FAR * lpulFlags) IPURE; \
	MAPIMETHOD(GetMax) \
	(THIS_ ULONG FAR * lpulMax) IPURE; \
	MAPIMETHOD(GetMin) \
	(THIS_ ULONG FAR * lpulMin) IPURE; \
	MAPIMETHOD(SetLimits) \
	(THIS_ LPULONG lpulMin, \
	LPULONG lpulMax, \
	LPULONG lpulFlags) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPIProgress
DECLARE_MAPI_INTERFACE_(IMAPIProgress,	IUnknown)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROGRESS_METHODS(PURE)
};







/*
	* Version:
	*/
#define	MAPI_ERROR_VERSION 0x00000000L









#define	KEEP_OPEN_READONLY ((ULONG) 0x00000001)
#define	KEEP_OPEN_READWRITE ((ULONG) 0x00000002)
#define	FORCE_SAVE ((ULONG) 0x00000004)




#define	MAPI_CREATE ((ULONG) 0x00000002)
#define	STREAM_APPEND ((ULONG) 0x00000004)







#define	MAPI_MOVE ((ULONG) 0x00000001)
#define	MAPI_NOREPLACE ((ULONG) 0x00000002)
#define	MAPI_DECLINE_OK ((ULONG) 0x00000004)

#ifndef	MAPI_DIALOG 
#define	MAPI_DIALOG ((ULONG) 0x00000008)
#endif

#ifndef	MAPI_USE_DEFAULT 
#define	MAPI_USE_DEFAULT 0x00000040 
#endif





#define	MAPI_NO_STRINGS ((ULONG) 0x00000001)
#define	MAPI_NO_IDS ((ULONG) 0x00000002)


#define	MNID_ID 0
#define	MNID_STRING 1
typedef	struct _MAPINAMEID
{
	LPGUID lpguid;
	ULONG ulKind;
	union {
	LONG lID;
	LPWSTR lpwstrName;
	} Kind;

}	MAPINAMEID, FAR * LPMAPINAMEID;

#define	MAPI_IMAPIPROP_METHODS(IPURE) \
	MAPIMETHOD(GetLastError) \
	(THIS_ HRESULT hResult, \
	ULONG ulFlags, \
	LPMAPIERROR FAR * lppMAPIError) IPURE; \
	MAPIMETHOD(SaveChanges) \
	(THIS_ ULONG ulFlags) IPURE; \
	MAPIMETHOD(GetProps) \
	(THIS_ LPSPropTagArray lpPropTagArray, \
	ULONG ulFlags, \
	ULONG FAR * lpcValues, \
	LPSPropValue FAR * lppPropArray) IPURE; \
	MAPIMETHOD(GetPropList) \
	(THIS_ ULONG ulFlags, \
	LPSPropTagArray FAR * lppPropTagArray) IPURE; \
	MAPIMETHOD(OpenProperty) \
	(THIS_ ULONG ulPropTag, \
	LPCIID lpiid, \
	ULONG ulInterfaceOptions, \
	ULONG ulFlags, \
	LPUNKNOWN FAR * lppUnk) IPURE; \
	MAPIMETHOD(SetProps) \
	(THIS_ ULONG cValues, \
	LPSPropValue lpPropArray, \
	LPSPropProblemArray FAR * lppProblems) IPURE; \
	MAPIMETHOD(DeleteProps) \
	(THIS_ LPSPropTagArray lpPropTagArray, \
	LPSPropProblemArray FAR * lppProblems) IPURE; \
	MAPIMETHOD(CopyTo) \
	(THIS_ ULONG ciidExclude, \
	LPCIID rgiidExclude, \
	LPSPropTagArray lpExcludeProps, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	LPCIID lpInterface, \
	LPVOID lpDestObj, \
	ULONG ulFlags, \
	LPSPropProblemArray FAR * lppProblems) IPURE; \
	MAPIMETHOD(CopyProps) \
	(THIS_ LPSPropTagArray lpIncludeProps, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	LPCIID lpInterface, \
	LPVOID lpDestObj, \
	ULONG ulFlags, \
	LPSPropProblemArray FAR * lppProblems) IPURE; \
	MAPIMETHOD(GetNamesFromIDs) \
	(THIS_ LPSPropTagArray FAR * lppPropTags, \
	LPGUID lpPropSetGuid, \
	ULONG ulFlags, \
	ULONG FAR * lpcPropNames, \
	LPMAPINAMEID FAR * FAR * lpppPropNames) IPURE; \
	MAPIMETHOD(GetIDsFromNames) \
	(THIS_ ULONG cPropNames, \
	LPMAPINAMEID FAR * lppPropNames, \
	ULONG ulFlags, \
	LPSPropTagArray FAR * lppPropTags) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPIProp
DECLARE_MAPI_INTERFACE_(IMAPIProp,	IUnknown)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
};





#define	TBLSTAT_COMPLETE ((ULONG) 0)
#define	TBLSTAT_QCHANGED ((ULONG) 7)
#define	TBLSTAT_SORTING ((ULONG) 9)
#define	TBLSTAT_SORT_ERROR ((ULONG) 10)
#define	TBLSTAT_SETTING_COLS ((ULONG) 11)
#define	TBLSTAT_SETCOL_ERROR ((ULONG) 13)
#define	TBLSTAT_RESTRICTING ((ULONG) 14)
#define	TBLSTAT_RESTRICT_ERROR ((ULONG) 15)




#define	TBLTYPE_SNAPSHOT ((ULONG) 0)
#define	TBLTYPE_KEYSET ((ULONG) 1)
#define	TBLTYPE_DYNAMIC ((ULONG) 2)






#define	TABLE_SORT_ASCEND ((ULONG) 0x00000000)
#define	TABLE_SORT_DESCEND ((ULONG) 0x00000001)
#define	TABLE_SORT_COMBINE ((ULONG) 0x00000002)




typedef	struct _SSortOrder
{
	ULONG ulPropTag; 
	ULONG ulOrder; 
}	SSortOrder, FAR * LPSSortOrder;

typedef	struct _SSortOrderSet
{
	ULONG cSorts; 
	ULONG cCategories; 
	ULONG cExpanded; 
	
	SSortOrder aSort[MAPI_DIM]; 
}	SSortOrderSet, FAR * LPSSortOrderSet;

#define	CbNewSSortOrderSet(_csort) \
	(offsetof(SSortOrderSet,aSort) + (_csort)*sizeof(SSortOrder))
#define	CbSSortOrderSet(_lpset) \
	(offsetof(SSortOrderSet,aSort) + \
	(UINT)((_lpset)->cSorts*sizeof(SSortOrder)))
#define	SizedSSortOrderSet(_csort, _name) \
struct	_SSortOrderSet_ ## _name \
{	\
	ULONG cSorts; \
	ULONG cCategories; \
	ULONG cExpanded; \
	SSortOrder aSort[_csort]; \
}	_name

typedef	ULONG BOOKMARK;

#define	BOOKMARK_BEGINNING ((BOOKMARK) 0) 
#define	BOOKMARK_CURRENT ((BOOKMARK) 1) 
#define	BOOKMARK_END ((BOOKMARK) 2) 



#define	FL_FULLSTRING ((ULONG) 0x00000000)
#define	FL_SUBSTRING ((ULONG) 0x00000001)
#define	FL_PREFIX ((ULONG) 0x00000002)

#define	FL_IGNORECASE ((ULONG) 0x00010000)
#define	FL_IGNORENONSPACE ((ULONG) 0x00020000)
#define	FL_LOOSE ((ULONG) 0x00040000)



typedef	struct _SRestriction FAR * LPSRestriction;



#define	RES_AND ((ULONG) 0x00000000)
#define	RES_OR ((ULONG) 0x00000001)
#define	RES_NOT ((ULONG) 0x00000002)
#define	RES_CONTENT ((ULONG) 0x00000003)
#define	RES_PROPERTY ((ULONG) 0x00000004)
#define	RES_COMPAREPROPS ((ULONG) 0x00000005)
#define	RES_BITMASK ((ULONG) 0x00000006)
#define	RES_SIZE ((ULONG) 0x00000007)
#define	RES_EXIST ((ULONG) 0x00000008)
#define	RES_SUBRESTRICTION ((ULONG) 0x00000009)
#define	RES_COMMENT ((ULONG) 0x0000000A)



#define	RELOP_LT ((ULONG) 0) 
#define	RELOP_LE ((ULONG) 1) 
#define	RELOP_GT ((ULONG) 2) 
#define	RELOP_GE ((ULONG) 3) 
#define	RELOP_EQ ((ULONG) 4) 
#define	RELOP_NE ((ULONG) 5) 
#define	RELOP_RE ((ULONG) 6) 



#define	BMR_EQZ ((ULONG) 0) 
#define	BMR_NEZ ((ULONG) 1) 






typedef	struct _SAndRestriction
{
	ULONG cRes;
	LPSRestriction lpRes;
}	SAndRestriction;

typedef	struct _SOrRestriction
{
	ULONG cRes;
	LPSRestriction lpRes;
}	SOrRestriction;

typedef	struct _SNotRestriction
{
	ULONG ulReserved;
	LPSRestriction lpRes;
}	SNotRestriction;

typedef	struct _SContentRestriction
{
	ULONG ulFuzzyLevel;
	ULONG ulPropTag;
	LPSPropValue lpProp;
}	SContentRestriction;

typedef	struct _SBitMaskRestriction
{
	ULONG relBMR;
	ULONG ulPropTag;
	ULONG ulMask;
}	SBitMaskRestriction;

typedef	struct _SPropertyRestriction
{
	ULONG relop;
	ULONG ulPropTag;
	LPSPropValue lpProp;
}	SPropertyRestriction;

typedef	struct _SComparePropsRestriction
{
	ULONG relop;
	ULONG ulPropTag1;
	ULONG ulPropTag2;
}	SComparePropsRestriction;

typedef	struct _SSizeRestriction
{
	ULONG relop;
	ULONG ulPropTag;
	ULONG cb;
}	SSizeRestriction;

typedef	struct _SExistRestriction
{
	ULONG ulReserved1;
	ULONG ulPropTag;
	ULONG ulReserved2;
}	SExistRestriction;

typedef	struct _SSubRestriction
{
	ULONG ulSubObject;
	LPSRestriction lpRes;
}	SSubRestriction;

typedef	struct _SCommentRestriction
{
	ULONG cValues; 
	LPSRestriction lpRes;
	LPSPropValue lpProp;
}	SCommentRestriction;

typedef	struct _SRestriction
{
	ULONG rt; 
	union
	{
	SComparePropsRestriction resCompareProps; 
	SAndRestriction resAnd;
	SOrRestriction resOr;
	SNotRestriction resNot;
	SContentRestriction resContent;
	SPropertyRestriction resProperty;
	SBitMaskRestriction resBitMask;
	SSizeRestriction resSize;
	SExistRestriction resExist;
	SSubRestriction resSub;
	SCommentRestriction resComment;
	} res;
}	SRestriction;

#define	TBL_ALL_COLUMNS ((ULONG) 0x00000001)
#define	TBL_LEAF_ROW ((ULONG) 1)
#define	TBL_EMPTY_CATEGORY ((ULONG) 2)
#define	TBL_EXPANDED_CATEGORY ((ULONG) 3)
#define	TBL_COLLAPSED_CATEGORY ((ULONG) 4)
#define	TBL_NOWAIT ((ULONG) 0x00000001)
#define	TBL_ASYNC ((ULONG) 0x00000001)
#define	TBL_BATCH ((ULONG) 0x00000002)
#define	DIR_BACKWARD ((ULONG) 0x00000001)
#define	TBL_NOADVANCE ((ULONG) 0x00000001)
#define	MAPI_IMAPITABLE_METHODS(IPURE) \
	MAPIMETHOD(GetLastError) \
	(THIS_ HRESULT hResult, \
	ULONG ulFlags, \
	LPMAPIERROR FAR * lppMAPIError) IPURE; \
	MAPIMETHOD(Advise) \
	(THIS_ ULONG ulEventMask, \
	LPMAPIADVISESINK lpAdviseSink, \
	ULONG FAR * lpulConnection) IPURE; \
	MAPIMETHOD(Unadvise) \
	(THIS_ ULONG ulConnection) IPURE; \
	MAPIMETHOD(GetStatus) \
	(THIS_ ULONG FAR * lpulTableStatus, \
	ULONG FAR * lpulTableType) IPURE; \
	MAPIMETHOD(SetColumns) \
	(THIS_ LPSPropTagArray lpPropTagArray, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(QueryColumns) \
	(THIS_ ULONG ulFlags, \
	LPSPropTagArray FAR * lpPropTagArray) IPURE; \
	MAPIMETHOD(GetRowCount) \
	(THIS_ ULONG ulFlags, \
	ULONG FAR * lpulCount) IPURE; \
	MAPIMETHOD(SeekRow) \
	(THIS_ BOOKMARK bkOrigin, \
	LONG lRowCount, \
	LONG FAR * lplRowsSought) IPURE; \
	MAPIMETHOD(SeekRowApprox) \
	(THIS_ ULONG ulNumerator, \
	ULONG ulDenominator) IPURE; \
	MAPIMETHOD(QueryPosition) \
	(THIS_ ULONG FAR * lpulRow, \
	ULONG FAR * lpulNumerator, \
	ULONG FAR * lpulDenominator) IPURE; \
	MAPIMETHOD(FindRow) \
	(THIS_ LPSRestriction lpRestriction, \
	BOOKMARK bkOrigin, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(Restrict) \
	(THIS_ LPSRestriction lpRestriction, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(CreateBookmark) \
	(THIS_ BOOKMARK FAR * lpbkPosition) IPURE; \
	MAPIMETHOD(FreeBookmark) \
	(THIS_ BOOKMARK bkPosition) IPURE; \
	MAPIMETHOD(SortTable) \
	(THIS_ LPSSortOrderSet lpSortCriteria, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(QuerySortOrder) \
	(THIS_ LPSSortOrderSet FAR * lppSortCriteria) IPURE; \
	MAPIMETHOD(QueryRows) \
	(THIS_ LONG lRowCount, \
	ULONG ulFlags, \
	LPSRowSet FAR * lppRows) IPURE; \
	MAPIMETHOD(Abort) (THIS) IPURE; \
	MAPIMETHOD(ExpandRow) \
	(THIS_ ULONG cbInstanceKey, \
	LPBYTE pbInstanceKey, \
	ULONG ulRowCount, \
	ULONG ulFlags, \
	LPSRowSet FAR * lppRows, \
	ULONG FAR * lpulMoreRows) IPURE; \
	MAPIMETHOD(CollapseRow) \
	(THIS_ ULONG cbInstanceKey, \
	LPBYTE pbInstanceKey, \
	ULONG ulFlags, \
	ULONG FAR * lpulRowCount) IPURE; \
	MAPIMETHOD(WaitForCompletion) \
	(THIS_ ULONG ulFlags, \
	ULONG ulTimeout, \
	ULONG FAR * lpulTableStatus) IPURE; \
	MAPIMETHOD(GetCollapseState) \
	(THIS_ ULONG ulFlags, \
	ULONG cbInstanceKey, \
	LPBYTE lpbInstanceKey, \
	ULONG FAR * lpcbCollapseState, \
	LPBYTE FAR * lppbCollapseState) IPURE; \
	MAPIMETHOD(SetCollapseState) \
	(THIS_ ULONG ulFlags, \
	ULONG cbCollapseState, \
	LPBYTE pbCollapseState, \
	BOOKMARK FAR * lpbkLocation) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPITable
DECLARE_MAPI_INTERFACE_(IMAPITable,	IUnknown)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPITABLE_METHODS(PURE)
};
#define	PS_PROFILE_PROPERTIES_INIT \
{	0x98, 0x15, 0xAC, 0x08, 0xAA, 0xB0, 0x10, 0x1A, \
	0x8C, 0x93, 0x08, 0x00, 0x2B, 0x2A, 0x56, 0xC2 }
#define	MAPI_IPROFSECT_METHODS(IPURE)
#undef	INTERFACE
#define	INTERFACE IProfSect
DECLARE_MAPI_INTERFACE_(IProfSect,	IMAPIProp)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IPROFSECT_METHODS(PURE)
};
#define	MAPI_STORE_PROVIDER ((ULONG) 33) 
#define	MAPI_AB ((ULONG) 34) 
#define	MAPI_AB_PROVIDER ((ULONG) 35) 
#define	MAPI_TRANSPORT_PROVIDER ((ULONG) 36) 
#define	MAPI_SPOOLER ((ULONG) 37) 
#define	MAPI_PROFILE_PROVIDER ((ULONG) 38) 
#define	MAPI_SUBSYSTEM ((ULONG) 39) 
#define	MAPI_HOOK_PROVIDER ((ULONG) 40) 
#define	STATUS_VALIDATE_STATE ((ULONG) 0x00000001)
#define	STATUS_SETTINGS_DIALOG ((ULONG) 0x00000002)
#define	STATUS_CHANGE_PASSWORD ((ULONG) 0x00000004)
#define	STATUS_FLUSH_QUEUES ((ULONG) 0x00000008)
#define	STATUS_DEFAULT_OUTBOUND ((ULONG) 0x00000001)
#define	STATUS_DEFAULT_STORE ((ULONG) 0x00000002)
#define	STATUS_PRIMARY_IDENTITY ((ULONG) 0x00000004)
#define	STATUS_SIMPLE_STORE ((ULONG) 0x00000008)
#define	STATUS_XP_PREFER_LAST ((ULONG) 0x00000010)
#define	STATUS_NO_PRIMARY_IDENTITY ((ULONG) 0x00000020)
#define	STATUS_NO_DEFAULT_STORE ((ULONG) 0x00000040)
#define	STATUS_TEMP_SECTION ((ULONG) 0x00000080)
#define	STATUS_OWN_STORE ((ULONG) 0x00000100)
#define	STATUS_NEED_IPM_TREE ((ULONG) 0x00000800)
#define	STATUS_PRIMARY_STORE ((ULONG) 0x00001000)
#define	STATUS_SECONDARY_STORE ((ULONG) 0x00002000)
#define	STATUS_AVAILABLE ((ULONG) 0x00000001)
#define	STATUS_OFFLINE ((ULONG) 0x00000002)
#define	STATUS_FAILURE ((ULONG) 0x00000004)
#define	STATUS_INBOUND_ENABLED ((ULONG) 0x00010000)
#define	STATUS_INBOUND_ACTIVE ((ULONG) 0x00020000)
#define	STATUS_INBOUND_FLUSH ((ULONG) 0x00040000)
#define	STATUS_OUTBOUND_ENABLED ((ULONG) 0x00100000)
#define	STATUS_OUTBOUND_ACTIVE ((ULONG) 0x00200000)
#define	STATUS_OUTBOUND_FLUSH ((ULONG) 0x00400000)
#define	STATUS_REMOTE_ACCESS ((ULONG) 0x00800000)
#define	SUPPRESS_UI ((ULONG) 0x00000001)
#define	REFRESH_XP_HEADER_CACHE ((ULONG) 0x00010000)
#define	PROCESS_XP_HEADER_CACHE ((ULONG) 0x00020000)
#define	FORCE_XP_CONNECT ((ULONG) 0x00040000)
#define	FORCE_XP_DISCONNECT ((ULONG) 0x00080000)
#define	CONFIG_CHANGED ((ULONG) 0x00100000)
#define	ABORT_XP_HEADER_OPERATION ((ULONG) 0x00200000)
#define	SHOW_XP_SESSION_UI ((ULONG) 0x00400000)
#define	UI_READONLY ((ULONG) 0x00000001)
#define	FLUSH_UPLOAD ((ULONG) 0x00000002)
#define	FLUSH_DOWNLOAD ((ULONG) 0x00000004)
#define	FLUSH_FORCE ((ULONG) 0x00000008)
#define	FLUSH_NO_UI ((ULONG) 0x00000010)
#define	FLUSH_ASYNC_OK ((ULONG) 0x00000020)
#define	MAPI_IMAPISTATUS_METHODS(IPURE) \
	MAPIMETHOD(ValidateState) \
	(THIS_ ULONG ulUIParam, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(SettingsDialog) \
	(THIS_ ULONG ulUIParam, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(ChangePassword) \
	(THIS_ LPTSTR lpOldPass, \
	LPTSTR lpNewPass, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(FlushQueues) \
	(THIS_ ULONG ulUIParam, \
	ULONG cbTargetTransport, \
	LPENTRYID lpTargetTransport, \
	ULONG ulFlags) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPIStatus
DECLARE_MAPI_INTERFACE_(IMAPIStatus,	IMAPIProp)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMAPISTATUS_METHODS(PURE)
};
#define	MAPI_BEST_ACCESS ((ULONG) 0x00000010)
#define	CONVENIENT_DEPTH ((ULONG) 0x00000001)
#define	SEARCH_RUNNING ((ULONG) 0x00000001)
#define	SEARCH_REBUILD ((ULONG) 0x00000002)
#define	SEARCH_RECURSIVE ((ULONG) 0x00000004)
#define	SEARCH_FOREGROUND ((ULONG) 0x00000008)
#define	STOP_SEARCH ((ULONG) 0x00000001)
#define	RESTART_SEARCH ((ULONG) 0x00000002)
#define	RECURSIVE_SEARCH ((ULONG) 0x00000004)
#define	SHALLOW_SEARCH ((ULONG) 0x00000008)
#define	FOREGROUND_SEARCH ((ULONG) 0x00000010)
#define	BACKGROUND_SEARCH ((ULONG) 0x00000020)
#define	MAPI_IMAPICONTAINER_METHODS(IPURE) \
	MAPIMETHOD(GetContentsTable) \
	(THIS_ ULONG ulFlags, \
	LPMAPITABLE FAR * lppTable) IPURE; \
	MAPIMETHOD(GetHierarchyTable) \
	(THIS_ ULONG ulFlags, \
	LPMAPITABLE FAR * lppTable) IPURE; \
	MAPIMETHOD(OpenEntry) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	LPCIID lpInterface, \
	ULONG ulFlags, \
	ULONG FAR * lpulObjType, \
	LPUNKNOWN FAR * lppUnk) IPURE; \
	MAPIMETHOD(SetSearchCriteria) \
	(THIS_ LPSRestriction lpRestriction, \
	LPENTRYLIST lpContainerList, \
	ULONG ulSearchFlags) IPURE; \
	MAPIMETHOD(GetSearchCriteria) \
	(THIS_ ULONG ulFlags, \
	LPSRestriction FAR * lppRestriction, \
	LPENTRYLIST FAR * lppContainerList, \
	ULONG FAR * lpulSearchState)IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPIContainer
DECLARE_MAPI_INTERFACE_(IMAPIContainer,	IMAPIProp)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMAPICONTAINER_METHODS(PURE)
};
typedef	struct _flaglist {
	ULONG cFlags;
	ULONG ulFlag[MAPI_DIM];
}	FlagList, FAR * LPFlagList;
#define	AB_RECIPIENTS ((ULONG) 0x00000001)
#define	AB_SUBCONTAINERS ((ULONG) 0x00000002)
#define	AB_MODIFIABLE ((ULONG) 0x00000004)
#define	AB_UNMODIFIABLE ((ULONG) 0x00000008)
#define	AB_FIND_ON_OPEN ((ULONG) 0x00000010)
#define	AB_NOT_DEFAULT ((ULONG) 0x00000020)
#define	CREATE_CHECK_DUP_STRICT ((ULONG) 0x00000001)
#define	CREATE_CHECK_DUP_LOOSE ((ULONG) 0x00000002)
#define	CREATE_REPLACE ((ULONG) 0x00000004)
#define	MAPI_UNRESOLVED ((ULONG) 0x00000000)
#define	MAPI_AMBIGUOUS ((ULONG) 0x00000001)
#define	MAPI_RESOLVED ((ULONG) 0x00000002)
#define	MAPI_IABCONTAINER_METHODS(IPURE) \
	MAPIMETHOD(CreateEntry) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	ULONG ulCreateFlags, \
	LPMAPIPROP FAR * lppMAPIPropEntry) IPURE; \
	MAPIMETHOD(CopyEntries) \
	(THIS_ LPENTRYLIST lpEntries, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(DeleteEntries) \
	(THIS_ LPENTRYLIST lpEntries, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(ResolveNames) \
	(THIS_ LPSPropTagArray lpPropTagArray, \
	ULONG ulFlags, \
	LPADRLIST lpAdrList, \
	LPFlagList lpFlagList) IPURE; \

#undef	INTERFACE
#define	INTERFACE IABContainer
DECLARE_MAPI_INTERFACE_(IABContainer,	IMAPIContainer)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMAPICONTAINER_METHODS(PURE)
	MAPI_IABCONTAINER_METHODS(PURE)
};
#define	MAPI_SEND_NO_RICH_INFO ((ULONG) 0x00010000)
#define	MAPI_DIAG(_code) ((LONG) _code)
#define	MAPI_DIAG_NO_DIAGNOSTIC MAPI_DIAG( -1 )
#define	MAPI_DIAG_OR_NAME_UNRECOGNIZED MAPI_DIAG( 0 )
#define	MAPI_DIAG_OR_NAME_AMBIGUOUS MAPI_DIAG( 1 )
#define	MAPI_DIAG_MTS_CONGESTED MAPI_DIAG( 2 )
#define	MAPI_DIAG_LOOP_DETECTED MAPI_DIAG( 3 )
#define	MAPI_DIAG_RECIPIENT_UNAVAILABLE MAPI_DIAG( 4 )
#define	MAPI_DIAG_MAXIMUM_TIME_EXPIRED MAPI_DIAG( 5 )
#define	MAPI_DIAG_EITS_UNSUPPORTED MAPI_DIAG( 6 )
#define	MAPI_DIAG_CONTENT_TOO_LONG MAPI_DIAG( 7 )
#define	MAPI_DIAG_IMPRACTICAL_TO_CONVERT MAPI_DIAG( 8 )
#define	MAPI_DIAG_PROHIBITED_TO_CONVERT MAPI_DIAG( 9 )
#define	MAPI_DIAG_CONVERSION_UNSUBSCRIBED MAPI_DIAG( 10 )
#define	MAPI_DIAG_PARAMETERS_INVALID MAPI_DIAG( 11 )
#define	MAPI_DIAG_CONTENT_SYNTAX_IN_ERROR MAPI_DIAG( 12 )
#define	MAPI_DIAG_LENGTH_CONSTRAINT_VIOLATD MAPI_DIAG( 13 )
#define	MAPI_DIAG_NUMBER_CONSTRAINT_VIOLATD MAPI_DIAG( 14 )
#define	MAPI_DIAG_CONTENT_TYPE_UNSUPPORTED MAPI_DIAG( 15 )
#define	MAPI_DIAG_TOO_MANY_RECIPIENTS MAPI_DIAG( 16 )
#define	MAPI_DIAG_NO_BILATERAL_AGREEMENT MAPI_DIAG( 17 )
#define	MAPI_DIAG_CRITICAL_FUNC_UNSUPPORTED MAPI_DIAG( 18 )
#define	MAPI_DIAG_CONVERSION_LOSS_PROHIB MAPI_DIAG( 19 )
#define	MAPI_DIAG_LINE_TOO_LONG MAPI_DIAG( 20 )
#define	MAPI_DIAG_PAGE_TOO_LONG MAPI_DIAG( 21 )
#define	MAPI_DIAG_PICTORIAL_SYMBOL_LOST MAPI_DIAG( 22 )
#define	MAPI_DIAG_PUNCTUATION_SYMBOL_LOST MAPI_DIAG( 23 )
#define	MAPI_DIAG_ALPHABETIC_CHARACTER_LOST MAPI_DIAG( 24 )
#define	MAPI_DIAG_MULTIPLE_INFO_LOSSES MAPI_DIAG( 25 )
#define	MAPI_DIAG_REASSIGNMENT_PROHIBITED MAPI_DIAG( 26 )
#define	MAPI_DIAG_REDIRECTION_LOOP_DETECTED MAPI_DIAG( 27 )
#define	MAPI_DIAG_EXPANSION_PROHIBITED MAPI_DIAG( 28 )
#define	MAPI_DIAG_SUBMISSION_PROHIBITED MAPI_DIAG( 29 )
#define	MAPI_DIAG_EXPANSION_FAILED MAPI_DIAG( 30 )
#define	MAPI_DIAG_RENDITION_UNSUPPORTED MAPI_DIAG( 31 )
#define	MAPI_DIAG_MAIL_ADDRESS_INCORRECT MAPI_DIAG( 32 )
#define	MAPI_DIAG_MAIL_OFFICE_INCOR_OR_INVD MAPI_DIAG( 33 )
#define	MAPI_DIAG_MAIL_ADDRESS_INCOMPLETE MAPI_DIAG( 34 )
#define	MAPI_DIAG_MAIL_RECIPIENT_UNKNOWN MAPI_DIAG( 35 )
#define	MAPI_DIAG_MAIL_RECIPIENT_DECEASED MAPI_DIAG( 36 )
#define	MAPI_DIAG_MAIL_ORGANIZATION_EXPIRED MAPI_DIAG( 37 )
#define	MAPI_DIAG_MAIL_REFUSED MAPI_DIAG( 38 )
#define	MAPI_DIAG_MAIL_UNCLAIMED MAPI_DIAG( 39 )
#define	MAPI_DIAG_MAIL_RECIPIENT_MOVED MAPI_DIAG( 40 )
#define	MAPI_DIAG_MAIL_RECIPIENT_TRAVELLING MAPI_DIAG( 41 )
#define	MAPI_DIAG_MAIL_RECIPIENT_DEPARTED MAPI_DIAG( 42 )
#define	MAPI_DIAG_MAIL_NEW_ADDRESS_UNKNOWN MAPI_DIAG( 43 )
#define	MAPI_DIAG_MAIL_FORWARDING_UNWANTED MAPI_DIAG( 44 )
#define	MAPI_DIAG_MAIL_FORWARDING_PROHIB MAPI_DIAG( 45 )
#define	MAPI_DIAG_SECURE_MESSAGING_ERROR MAPI_DIAG( 46 )
#define	MAPI_DIAG_DOWNGRADING_IMPOSSIBLE MAPI_DIAG( 47 )
#define	MAPI_MH_DP_PUBLIC_UA ((ULONG) 0)
#define	MAPI_MH_DP_PRIVATE_UA ((ULONG) 1)
#define	MAPI_MH_DP_MS ((ULONG) 2)
#define	MAPI_MH_DP_ML ((ULONG) 3)
#define	MAPI_MH_DP_PDAU ((ULONG) 4)
#define	MAPI_MH_DP_PDS_PATRON ((ULONG) 5)
#define	MAPI_MH_DP_OTHER_AU ((ULONG) 6)
#define	MAPI_IMAILUSER_METHODS(IPURE)
#undef	INTERFACE
#define	INTERFACE IMailUser
DECLARE_MAPI_INTERFACE_(IMailUser,	IMAPIProp)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMAILUSER_METHODS(PURE)
};
#define	MAPI_IDISTLIST_METHODS(IPURE) \
	MAPIMETHOD(CreateEntry) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	ULONG ulCreateFlags, \
	LPMAPIPROP FAR * lppMAPIPropEntry) IPURE; \
	MAPIMETHOD(CopyEntries) \
	(THIS_ LPENTRYLIST lpEntries, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(DeleteEntries) \
	(THIS_ LPENTRYLIST lpEntries, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(ResolveNames) \
	(THIS_ LPSPropTagArray lpPropTagArray, \
	ULONG ulFlags, \
	LPADRLIST lpAdrList, \
	LPFlagList lpFlagList) IPURE; \

#undef	INTERFACE
#define	INTERFACE IDistList
DECLARE_MAPI_INTERFACE_(IDistList,	IMAPIContainer)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMAPICONTAINER_METHODS(PURE)
	MAPI_IDISTLIST_METHODS(PURE)
};
#define	FOLDER_ROOT ((ULONG) 0x00000000)
#define	FOLDER_GENERIC ((ULONG) 0x00000001)
#define	FOLDER_SEARCH ((ULONG) 0x00000002)
#define	MESSAGE_MOVE ((ULONG) 0x00000001)
#define	MESSAGE_DIALOG ((ULONG) 0x00000002)
#define	OPEN_IF_EXISTS ((ULONG) 0x00000001)
#define	DEL_MESSAGES ((ULONG) 0x00000001)
#define	FOLDER_DIALOG ((ULONG) 0x00000002)
#define	DEL_FOLDERS ((ULONG) 0x00000004)
#define	DEL_ASSOCIATED ((ULONG) 0x00000008)
#define	FOLDER_MOVE ((ULONG) 0x00000001)
#define	COPY_SUBFOLDERS ((ULONG) 0x00000010)
#define	MSGSTATUS_HIGHLIGHTED ((ULONG) 0x00000001)
#define	MSGSTATUS_TAGGED ((ULONG) 0x00000002)
#define	MSGSTATUS_HIDDEN ((ULONG) 0x00000004)
#define	MSGSTATUS_DELMARKED ((ULONG) 0x00000008)
#define	MSGSTATUS_REMOTE_DOWNLOAD ((ULONG) 0x00001000)
#define	MSGSTATUS_REMOTE_DELETE ((ULONG) 0x00002000)
#define	RECURSIVE_SORT ((ULONG) 0x00000002)
#define	FLDSTATUS_HIGHLIGHTED ((ULONG) 0x00000001)
#define	FLDSTATUS_TAGGED ((ULONG) 0x00000002)
#define	FLDSTATUS_HIDDEN ((ULONG) 0x00000004)
#define	FLDSTATUS_DELMARKED ((ULONG) 0x00000008)
#define	MAPI_IMAPIFOLDER_METHODS(IPURE) \
	MAPIMETHOD(CreateMessage) \
	(THIS_ LPCIID lpInterface, \
	ULONG ulFlags, \
	LPMESSAGE FAR * lppMessage) IPURE; \
	MAPIMETHOD(CopyMessages) \
	(THIS_ LPENTRYLIST lpMsgList, \
	LPCIID lpInterface, \
	LPVOID lpDestFolder, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(DeleteMessages) \
	(THIS_ LPENTRYLIST lpMsgList, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(CreateFolder) \
	(THIS_ ULONG ulFolderType, \
	LPTSTR lpszFolderName, \
	LPTSTR lpszFolderComment, \
	LPCIID lpInterface, \
	ULONG ulFlags, \
	LPMAPIFOLDER FAR * lppFolder) IPURE; \
	MAPIMETHOD(CopyFolder) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	LPCIID lpInterface, \
	LPVOID lpDestFolder, \
	LPTSTR lpszNewFolderName, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(DeleteFolder) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(SetReadFlags) \
	(THIS_ LPENTRYLIST lpMsgList, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(GetMessageStatus) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	ULONG ulFlags, \
	ULONG FAR * lpulMessageStatus) IPURE; \
	MAPIMETHOD(SetMessageStatus) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	ULONG ulNewStatus, \
	ULONG ulNewStatusMask, \
	ULONG FAR * lpulOldStatus) IPURE; \
	MAPIMETHOD(SaveContentsSort) \
	(THIS_ LPSSortOrderSet lpSortCriteria, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(EmptyFolder) \
	(THIS_ ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPIFolder
DECLARE_MAPI_INTERFACE_(IMAPIFolder,	IMAPIContainer)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMAPICONTAINER_METHODS(PURE)
	MAPI_IMAPIFOLDER_METHODS(PURE)
};
#define	STORE_ENTRYID_UNIQUE ((ULONG) 0x00000001)
#define	STORE_READONLY ((ULONG) 0x00000002)
#define	STORE_SEARCH_OK ((ULONG) 0x00000004)
#define	STORE_MODIFY_OK ((ULONG) 0x00000008)
#define	STORE_CREATE_OK ((ULONG) 0x00000010)
#define	STORE_ATTACH_OK ((ULONG) 0x00000020)
#define	STORE_OLE_OK ((ULONG) 0x00000040)
#define	STORE_SUBMIT_OK ((ULONG) 0x00000080)
#define	STORE_NOTIFY_OK ((ULONG) 0x00000100)
#define	STORE_MV_PROPS_OK ((ULONG) 0x00000200)
#define	STORE_CATEGORIZE_OK ((ULONG) 0x00000400)
#define	STORE_RTF_OK ((ULONG) 0x00000800)
#define	STORE_RESTRICTION_OK ((ULONG) 0x00001000)
#define	STORE_SORT_OK ((ULONG) 0x00002000)
#define	STORE_PUBLIC_FOLDERS ((ULONG) 0x00004000)
#define	STORE_UNCOMPRESSED_RTF ((ULONG) 0x00008000)
#define	STORE_HAS_SEARCHES ((ULONG) 0x01000000)
#define	LOGOFF_NO_WAIT ((ULONG) 0x00000001)
#define	LOGOFF_ORDERLY ((ULONG) 0x00000002)
#define	LOGOFF_PURGE ((ULONG) 0x00000004)
#define	LOGOFF_ABORT ((ULONG) 0x00000008)
#define	LOGOFF_QUIET ((ULONG) 0x00000010)
#define	LOGOFF_COMPLETE ((ULONG) 0x00010000)
#define	LOGOFF_INBOUND ((ULONG) 0x00020000)
#define	LOGOFF_OUTBOUND ((ULONG) 0x00040000)
#define	LOGOFF_OUTBOUND_QUEUE ((ULONG) 0x00080000)
#define	MSG_LOCKED ((ULONG) 0x00000001)
#define	MSG_UNLOCKED ((ULONG) 0x00000000)
#define	FOLDER_IPM_SUBTREE_VALID ((ULONG) 0x00000001)
#define	FOLDER_IPM_INBOX_VALID ((ULONG) 0x00000002)
#define	FOLDER_IPM_OUTBOX_VALID ((ULONG) 0x00000004)
#define	FOLDER_IPM_WASTEBASKET_VALID ((ULONG) 0x00000008)
#define	FOLDER_IPM_SENTMAIL_VALID ((ULONG) 0x00000010)
#define	FOLDER_VIEWS_VALID ((ULONG) 0x00000020)
#define	FOLDER_COMMON_VIEWS_VALID ((ULONG) 0x00000040)
#define	FOLDER_FINDER_VALID ((ULONG) 0x00000080)
#define	MAPI_IMSGSTORE_METHODS(IPURE) \
	MAPIMETHOD(Advise) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	ULONG ulEventMask, \
	LPMAPIADVISESINK lpAdviseSink, \
	ULONG FAR * lpulConnection) IPURE; \
	MAPIMETHOD(Unadvise) \
	(THIS_ ULONG ulConnection) IPURE; \
	MAPIMETHOD(CompareEntryIDs) \
	(THIS_ ULONG cbEntryID1, \
	LPENTRYID lpEntryID1, \
	ULONG cbEntryID2, \
	LPENTRYID lpEntryID2, \
	ULONG ulFlags, \
	ULONG FAR * lpulResult) IPURE; \
	MAPIMETHOD(OpenEntry) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	LPCIID lpInterface, \
	ULONG ulFlags, \
	ULONG FAR * lpulObjType, \
	LPUNKNOWN FAR * lppUnk) IPURE; \
	MAPIMETHOD(SetReceiveFolder) \
	(THIS_ LPTSTR lpszMessageClass, \
	ULONG ulFlags, \
	ULONG cbEntryID, \
	LPENTRYID lpEntryID) IPURE; \
	MAPIMETHOD(GetReceiveFolder) \
	(THIS_ LPTSTR lpszMessageClass, \
	ULONG ulFlags, \
	ULONG FAR * lpcbEntryID, \
	LPENTRYID FAR * lppEntryID, \
	LPTSTR FAR * lppszExplicitClass) IPURE; \
	MAPIMETHOD(GetReceiveFolderTable) \
	(THIS_ ULONG ulFlags, \
	LPMAPITABLE FAR * lppTable) IPURE; \
	MAPIMETHOD(StoreLogoff) \
	(THIS_ ULONG FAR * lpulFlags) IPURE; \
	MAPIMETHOD(AbortSubmit) \
	(THIS_ ULONG cbEntryID, \
	LPENTRYID lpEntryID, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(GetOutgoingQueue) \
	(THIS_ ULONG ulFlags, \
	LPMAPITABLE FAR * lppTable) IPURE; \
	MAPIMETHOD(SetLockState) \
	(THIS_ LPMESSAGE lpMessage, \
	ULONG ulLockState) IPURE; \
	MAPIMETHOD(FinishedMsg) \
	(THIS_ ULONG ulFlags, \
	ULONG cbEntryID, \
	LPENTRYID lpEntryID) IPURE; \
	MAPIMETHOD(NotifyNewMail) \
	(THIS_ LPNOTIFICATION lpNotification) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMsgStore
DECLARE_MAPI_INTERFACE_(IMsgStore,	IMAPIProp)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMSGSTORE_METHODS(PURE)
};
#define	FORCE_SUBMIT ((ULONG) 0x00000001)
#define	MSGFLAG_READ ((ULONG) 0x00000001)
#define	MSGFLAG_UNMODIFIED ((ULONG) 0x00000002)
#define	MSGFLAG_SUBMIT ((ULONG) 0x00000004)
#define	MSGFLAG_UNSENT ((ULONG) 0x00000008)
#define	MSGFLAG_HASATTACH ((ULONG) 0x00000010)
#define	MSGFLAG_FROMME ((ULONG) 0x00000020)
#define	MSGFLAG_ASSOCIATED ((ULONG) 0x00000040)
#define	MSGFLAG_RESEND ((ULONG) 0x00000080)
#define	MSGFLAG_RN_PENDING ((ULONG) 0x00000100)
#define	MSGFLAG_NRN_PENDING ((ULONG) 0x00000200)
#define	SUBMITFLAG_LOCKED ((ULONG) 0x00000001)
#define	SUBMITFLAG_PREPROCESS ((ULONG) 0x00000002)
#define	MODRECIP_ADD ((ULONG) 0x00000002)
#define	MODRECIP_MODIFY ((ULONG) 0x00000004)
#define	MODRECIP_REMOVE ((ULONG) 0x00000008)
#define	SUPPRESS_RECEIPT ((ULONG) 0x00000001)
#define	CLEAR_READ_FLAG ((ULONG) 0x00000004)
#define	GENERATE_RECEIPT_ONLY ((ULONG) 0x00000010)
#define	CLEAR_RN_PENDING ((ULONG) 0x00000020)
#define	CLEAR_NRN_PENDING ((ULONG) 0x00000040)
#define	ATTACH_DIALOG ((ULONG) 0x00000001)
#define	SECURITY_SIGNED ((ULONG) 0x00000001)
#define	SECURITY_ENCRYPTED ((ULONG) 0x00000002)
#define	PRIO_URGENT ((long) 1)
#define	PRIO_NORMAL ((long) 0)
#define	PRIO_NONURGENT ((long) -1)
#define	SENSITIVITY_NONE ((ULONG) 0x00000000)
#define	SENSITIVITY_PERSONAL ((ULONG) 0x00000001)
#define	SENSITIVITY_PRIVATE ((ULONG) 0x00000002)
#define	SENSITIVITY_COMPANY_CONFIDENTIAL ((ULONG) 0x00000003)
#define	IMPORTANCE_LOW ((long) 0)
#define	IMPORTANCE_NORMAL ((long) 1)
#define	IMPORTANCE_HIGH ((long) 2)
#define	MAPI_IMESSAGE_METHODS(IPURE) \
	MAPIMETHOD(GetAttachmentTable) \
	(THIS_ ULONG ulFlags, \
	LPMAPITABLE FAR * lppTable) IPURE; \
	MAPIMETHOD(OpenAttach) \
	(THIS_ ULONG ulAttachmentNum, \
	LPCIID lpInterface, \
	ULONG ulFlags, \
	LPATTACH FAR * lppAttach) IPURE; \
	MAPIMETHOD(CreateAttach) \
	(THIS_ LPCIID lpInterface, \
	ULONG ulFlags, \
	ULONG FAR * lpulAttachmentNum, \
	LPATTACH FAR * lppAttach) IPURE; \
	MAPIMETHOD(DeleteAttach) \
	(THIS_ ULONG ulAttachmentNum, \
	ULONG ulUIParam, \
	LPMAPIPROGRESS lpProgress, \
	ULONG ulFlags) IPURE; \
	MAPIMETHOD(GetRecipientTable) \
	(THIS_ ULONG ulFlags, \
	LPMAPITABLE FAR * lppTable) IPURE; \
	MAPIMETHOD(ModifyRecipients) \
	(THIS_ ULONG ulFlags, \
	LPADRLIST lpMods) IPURE; \
	MAPIMETHOD(SubmitMessage) \
	(THIS_ ULONG ulFlags) IPURE; \
	MAPIMETHOD(SetReadFlag) \
	(THIS_ ULONG ulFlags) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMessage
DECLARE_MAPI_INTERFACE_(IMessage,	IMAPIProp)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IMESSAGE_METHODS(PURE)
};
#define	NO_ATTACHMENT ((ULONG) 0x00000000)
#define	ATTACH_BY_VALUE ((ULONG) 0x00000001)
#define	ATTACH_BY_REFERENCE ((ULONG) 0x00000002)
#define	ATTACH_BY_REF_RESOLVE ((ULONG) 0x00000003)
#define	ATTACH_BY_REF_ONLY ((ULONG) 0x00000004)
#define	ATTACH_EMBEDDED_MSG ((ULONG) 0x00000005)
#define	ATTACH_OLE ((ULONG) 0x00000006)
#define	MAPI_IATTACH_METHODS(IPURE)
#undef	INTERFACE
#define	INTERFACE IAttach
DECLARE_MAPI_INTERFACE_(IAttach,	IMAPIProp)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPIPROP_METHODS(PURE)
	MAPI_IATTACH_METHODS(PURE)
};
#define	GET_ADRPARM_VERSION(ulFlags) (((ULONG)ulFlags) & 0xF0000000)
#define	SET_ADRPARM_VERSION(ulFlags, ulVersion) (((ULONG)ulVersion) | (((ULONG)ulFlags) & 0x0FFFFFFF))
#define	ADRPARM_HELP_CTX ((ULONG) 0x00000000)
#define	DIALOG_MODAL ((ULONG) 0x00000001)
#define	DIALOG_SDI ((ULONG) 0x00000002)
#define	DIALOG_OPTIONS ((ULONG) 0x00000004)
#define	ADDRESS_ONE ((ULONG) 0x00000008)
#define	AB_SELECTONLY ((ULONG) 0x00000010)
#define	AB_RESOLVE ((ULONG) 0x00000020)
#define	DT_MAILUSER ((ULONG) 0x00000000)
#define	DT_DISTLIST ((ULONG) 0x00000001)
#define	DT_FORUM ((ULONG) 0x00000002)
#define	DT_AGENT ((ULONG) 0x00000003)
#define	DT_ORGANIZATION ((ULONG) 0x00000004)
#define	DT_PRIVATE_DISTLIST ((ULONG) 0x00000005)
#define	DT_REMOTE_MAILUSER ((ULONG) 0x00000006)
#define	DT_MODIFIABLE ((ULONG) 0x00010000)
#define	DT_GLOBAL ((ULONG) 0x00020000)
#define	DT_LOCAL ((ULONG) 0x00030000)
#define	DT_WAN ((ULONG) 0x00040000)
#define	DT_NOT_SPECIFIC ((ULONG) 0x00050000)
#define	DT_FOLDER ((ULONG) 0x01000000)
#define	DT_FOLDER_LINK ((ULONG) 0x02000000)
#define	DT_FOLDER_SPECIAL ((ULONG) 0x04000000)
typedef	BOOL (STDMETHODCALLTYPE ACCELERATEABSDI)(ULONG ulUIParam, LPVOID lpvmsg);
typedef	ACCELERATEABSDI FAR * LPFNABSDI;
typedef	void (STDMETHODCALLTYPE DISMISSMODELESS)(ULONG ulUIParam, LPVOID lpvContext);
typedef	DISMISSMODELESS FAR * LPFNDISMISS;
typedef	SCODE (STDMETHODCALLTYPE FAR * LPFNBUTTON)(
	ULONG ulUIParam,
	LPVOID lpvContext,
	ULONG cbEntryID,
	LPENTRYID lpSelection,
	ULONG ulFlags
);
typedef	struct _ADRPARM
{
	ULONG cbABContEntryID;
	LPENTRYID lpABContEntryID;
	ULONG ulFlags;
	LPVOID lpReserved;
	ULONG ulHelpContext;
	LPTSTR lpszHelpFileName;
	LPFNABSDI lpfnABSDI;
	LPFNDISMISS lpfnDismiss;
	LPVOID lpvDismissContext;
	LPTSTR lpszCaption;
	LPTSTR lpszNewEntryTitle;
	LPTSTR lpszDestWellsTitle;
	ULONG cDestFields;
	ULONG nDestFieldFocus;
	LPTSTR FAR * lppszDestTitles;
	ULONG FAR * lpulDestComps;
	LPSRestriction lpContRestriction;
	LPSRestriction lpHierRestriction;
}	ADRPARM, FAR * LPADRPARM;
#define	MAPI_DEFERRED_ERRORS ((ULONG) 0x00000008)
#define	MAPI_ASSOCIATED ((ULONG) 0x00000040)
#define	MDB_NO_DIALOG ((ULONG) 0x00000001)
#define	MDB_WRITE ((ULONG) 0x00000004)
#define	MDB_TEMPORARY ((ULONG) 0x00000020)
#define	MDB_NO_MAIL ((ULONG) 0x00000080)
#define	AB_NO_DIALOG ((ULONG) 0x00000001)
#define	MAPI_ENABLED ((ULONG) 0x00000000)
#define	MAPI_DISABLED ((ULONG) 0x00000001)
#define	MAPI_IMAPICONTROL_METHODS(IPURE) \
	MAPIMETHOD(GetLastError) \
	(THIS_ HRESULT hResult, \
	ULONG ulFlags, \
	LPMAPIERROR FAR * lppMAPIError) IPURE; \
	MAPIMETHOD(Activate) \
	(THIS_ ULONG ulFlags, \
	ULONG ulUIParam) IPURE; \
	MAPIMETHOD(GetState) \
	(THIS_ ULONG ulFlags, \
	ULONG FAR * lpulState) IPURE; \

#undef	INTERFACE
#define	INTERFACE IMAPIControl
DECLARE_MAPI_INTERFACE_(IMAPIControl,	IUnknown)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IMAPICONTROL_METHODS(PURE)
};

DECLARE_MAPI_INTERFACE_PTR(IMAPIControl,	LPMAPICONTROL);
#define	DT_MULTILINE ((ULONG) 0x00000001)
#define	DT_EDITABLE ((ULONG) 0x00000002)
#define	DT_REQUIRED ((ULONG) 0x00000004)
#define	DT_SET_IMMEDIATE ((ULONG) 0x00000008)
#define	DT_PASSWORD_EDIT ((ULONG) 0x00000010)
#define	DT_ACCEPT_DBCS ((ULONG) 0x00000020)
#define	DT_SET_SELECTION ((ULONG) 0x00000040)
#define	DTCT_LABEL ((ULONG) 0x00000000)
#define	DTCT_EDIT ((ULONG) 0x00000001)
#define	DTCT_LBX ((ULONG) 0x00000002)
#define	DTCT_COMBOBOX ((ULONG) 0x00000003)
#define	DTCT_DDLBX ((ULONG) 0x00000004)
#define	DTCT_CHECKBOX ((ULONG) 0x00000005)
#define	DTCT_GROUPBOX ((ULONG) 0x00000006)
#define	DTCT_BUTTON ((ULONG) 0x00000007)
#define	DTCT_PAGE ((ULONG) 0x00000008)
#define	DTCT_RADIOBUTTON ((ULONG) 0x00000009)
#define	DTCT_MVLISTBOX ((ULONG) 0x0000000B)
#define	DTCT_MVDDLBX ((ULONG) 0x0000000C)
typedef	struct _DTBLLABEL
{
	ULONG ulbLpszLabelName;
	ULONG ulFlags;
}	DTBLLABEL, FAR * LPDTBLLABEL;
#define	SizedDtblLabel(n,u) \
struct	_DTBLLABEL_ ## u \
{	\
	DTBLLABEL dtbllabel; \
	TCHAR lpszLabelName[n]; \
}	u
typedef	struct _DTBLEDIT
{
	ULONG ulbLpszCharsAllowed;
	ULONG ulFlags;
	ULONG ulNumCharsAllowed;
	ULONG ulPropTag;
}	DTBLEDIT, FAR * LPDTBLEDIT;
#define	SizedDtblEdit(n,u) \
struct	_DTBLEDIT_ ## u \
{	\
	DTBLEDIT dtbledit; \
	TCHAR lpszCharsAllowed[n]; \
}	u
#define	MAPI_NO_HBAR ((ULONG) 0x00000001)
#define	MAPI_NO_VBAR ((ULONG) 0x00000002)
typedef	struct _DTBLLBX
{
	ULONG ulFlags;
	ULONG ulPRSetProperty;
	ULONG ulPRTableName;
}	DTBLLBX, FAR * LPDTBLLBX;
typedef	struct _DTBLCOMBOBOX
{
	ULONG ulbLpszCharsAllowed;
	ULONG ulFlags;
	ULONG ulNumCharsAllowed;
	ULONG ulPRPropertyName;
	ULONG ulPRTableName;
}	DTBLCOMBOBOX, FAR * LPDTBLCOMBOBOX;
#define	SizedDtblComboBox(n,u) \
struct	_DTBLCOMBOBOX_ ## u \
{	\
	DTBLCOMBOBOX dtblcombobox; \
	TCHAR lpszCharsAllowed[n]; \
}	u
typedef	struct _DTBLDDLBX
{
	ULONG ulFlags;
	ULONG ulPRDisplayProperty;
	ULONG ulPRSetProperty;
	ULONG ulPRTableName;
}	DTBLDDLBX, FAR * LPDTBLDDLBX;
typedef	struct _DTBLCHECKBOX
{
	ULONG ulbLpszLabel;
	ULONG ulFlags;
	ULONG ulPRPropertyName;
}	DTBLCHECKBOX, FAR * LPDTBLCHECKBOX;
#define	SizedDtblCheckBox(n,u) \
struct	_DTBLCHECKBOX_ ## u \
{	\
	DTBLCHECKBOX dtblcheckbox; \
	TCHAR lpszLabel[n]; \
}	u
typedef	struct _DTBLGROUPBOX
{
	ULONG ulbLpszLabel;
	ULONG ulFlags;
}	DTBLGROUPBOX, FAR * LPDTBLGROUPBOX;
#define	SizedDtblGroupBox(n,u) \
struct	_DTBLGROUPBOX_ ## u \
{	\
	DTBLGROUPBOX dtblgroupbox; \
	TCHAR lpszLabel[n]; \
}	u
typedef	struct _DTBLBUTTON {
	ULONG ulbLpszLabel;
	ULONG ulFlags;
	ULONG ulPRControl;
}	DTBLBUTTON, FAR * LPDTBLBUTTON;
#define	SizedDtblButton(n,u) \
struct	_DTBLBUTTON_ ## u \
{	\
	DTBLBUTTON dtblbutton; \
	TCHAR lpszLabel[n]; \
}	u


/*	Valid ulFlags:
	* MAPI_UNICODE
	*/
typedef	struct _DTBLPAGE
{
	ULONG ulbLpszLabel;
	ULONG ulFlags;
	ULONG ulbLpszComponent;
	ULONG ulContext;
}	DTBLPAGE, FAR * LPDTBLPAGE;
#define	SizedDtblPage(n,n1,u) \
struct	_DTBLPAGE_ ## u { \
	DTBLPAGE dtblpage; \
	TCHAR lpszLabel[n]; \
	TCHAR lpszComponent[n1]; \
}	u
typedef	struct _DTBLRADIOBUTTON {
	ULONG ulbLpszLabel;
	ULONG ulFlags;
	ULONG ulcButtons;
	ULONG ulPropTag;
	long lReturnValue;
}	DTBLRADIOBUTTON, FAR * LPDTBLRADIOBUTTON;
#define	SizedDtblRadioButton(n,u) \
struct	_DTBLRADIOBUTTON_ ## u \
{	\
	DTBLRADIOBUTTON dtblradiobutton; \
	TCHAR lpszLabel[n]; \
}	u
typedef	struct _DTBLMVLISTBOX
{
	ULONG ulFlags;
	ULONG ulMVPropTag;
}	DTBLMVLISTBOX, FAR * LPDTBLMVLISTBOX;
typedef	struct _DTBLMVDDLBX
{
	ULONG ulFlags;
	ULONG ulMVPropTag;
}	DTBLMVDDLBX, FAR * LPDTBLMVDDLBX;
#define	UI_SERVICE 0x00000002
#define	SERVICE_UI_ALWAYS 0x00000002 
#define	SERVICE_UI_ALLOWED 0x00000010
#define	UI_CURRENT_PROVIDER_FIRST 0x00000004
#define	MAPI_IPROVIDERADMIN_METHODS(IPURE) \
	MAPIMETHOD(GetLastError) \
	(THIS_ HRESULT hResult, \
	ULONG ulFlags, \
	LPMAPIERROR FAR * lppMAPIError) IPURE; \
	MAPIMETHOD(GetProviderTable) \
	(THIS_ ULONG ulFlags, \
	LPMAPITABLE FAR * lppTable) IPURE; \
	MAPIMETHOD(CreateProvider) \
	(THIS_ LPTSTR lpszProvider, \
	ULONG cValues, \
	LPSPropValue lpProps, \
	ULONG ulUIParam, \
	ULONG ulFlags, \
	MAPIUID FAR * lpUID) IPURE; \
	MAPIMETHOD(DeleteProvider) \
	(THIS_ LPMAPIUID lpUID) IPURE; \
	MAPIMETHOD(OpenProfileSection) \
	(THIS_ LPMAPIUID lpUID, \
	LPCIID lpInterface, \
	ULONG ulFlags, \
	LPPROFSECT FAR * lppProfSect) IPURE; \


#undef	INTERFACE
#define	INTERFACE IProviderAdmin
DECLARE_MAPI_INTERFACE_(IProviderAdmin,	IUnknown)
{
	BEGIN_INTERFACE
	MAPI_IUNKNOWN_METHODS(PURE)
	MAPI_IPROVIDERADMIN_METHODS(PURE)
};
#endif	
