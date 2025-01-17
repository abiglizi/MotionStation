/* $Revision: 1.2 $ */
#ifndef __LCC_ODBCINST_H
#define __LCC_ODBCINST_H
#ifndef ODBCVER
#define ODBCVER 0x0250					 
#endif
#define ODBC_ADD_DSN 1 
#define ODBC_CONFIG_DSN 2 
#define ODBC_REMOVE_DSN 3 
#if (ODBCVER >= 0x0250)
#define ODBC_ADD_SYS_DSN 4				 
#define ODBC_CONFIG_SYS_DSN	5		 
#define ODBC_REMOVE_SYS_DSN	6		 
#define	 ODBC_INSTALL_INQUIRY	1		
#define ODBC_INSTALL_COMPLETE	2
#define ODBC_INSTALL_DRIVER	1
#define ODBC_REMOVE_DRIVER		2
#define ODBC_CONFIG_DRIVER_MAX 100
#endif
#ifndef EXPORT
#define EXPORT
#endif
#ifndef RC_INVOKED
#define INSTAPI __stdcall
BOOL INSTAPI SQLInstallODBC(HWND,LPCSTR,LPCSTR,LPCSTR);
BOOL INSTAPI SQLManageDataSources(HWND);
BOOL INSTAPI SQLCreateDataSource(HWND,LPCSTR);
BOOL INSTAPI SQLGetTranslator(HWND,LPSTR,WORD,WORD *,LPSTR,WORD,WORD *,DWORD *);
BOOL INSTAPI SQLInstallDriver(LPCSTR,LPCSTR,LPSTR,WORD,WORD *);
BOOL INSTAPI SQLInstallDriverManager(LPSTR,WORD,WORD *);
BOOL INSTAPI SQLGetInstalledDrivers(LPSTR,WORD,WORD *);
BOOL INSTAPI SQLGetAvailableDrivers(LPCSTR,LPSTR,WORD,WORD *);
BOOL INSTAPI SQLConfigDataSource(HWND,WORD,LPCSTR,LPCSTR);
BOOL INSTAPI SQLRemoveDefaultDataSource(void);
BOOL INSTAPI SQLWriteDSNToIni(LPCSTR,LPCSTR);
BOOL INSTAPI SQLRemoveDSNFromIni(LPCSTR);
BOOL INSTAPI SQLValidDSN(LPCSTR);
BOOL INSTAPI SQLWritePrivateProfileString(LPCSTR,LPCSTR,LPCSTR,LPCSTR);
int INSTAPI SQLGetPrivateProfileString(LPCSTR,LPCSTR,LPCSTR,LPCSTR);
BOOL INSTAPI SQLRemoveDriverManager(LPDWORD);
BOOL INSTAPI SQLInstallTranslator(LPCSTR,LPCSTR, LPCSTR, LPSTR ,WORD,WORD *,WORD,LPDWORD);
BOOL INSTAPI SQLRemoveTranslator(LPCSTR, LPDWORD);
BOOL INSTAPI SQLRemoveDriver(LPCSTR,BOOL,LPDWORD);
BOOL INSTAPI SQLConfigDriver(HWND,WORD,LPCSTR,LPCSTR,LPSTR,WORD,WORD *);
BOOL INSTAPI ConfigDSN(HWND,WORD,LPCSTR,LPCSTR);
BOOL INSTAPI ConfigTranslator(HWND,DWORD *);
#if (ODBCVER >= 0x0250)
BOOL INSTAPI ConfigDriver(HWND,WORD,LPCSTR,LPCSTR,LPSTR,WORD,WORD *);
#endif
#endif 
#endif 
