/* $Revision: 1.2 $ */
#define DEFINE_SHLGUID(name, l, w1, w2) DEFINE_GUID(name, l, w1, w2, 0xC0,0,0,0,0,0,0,0x46)
DEFINE_SHLGUID(CLSID_ShellDesktop,      0x00021400L, 0, 0);
DEFINE_SHLGUID(CLSID_ShellLink, 	0x00021401L, 0, 0);
DEFINE_SHLGUID(IID_IContextMenu,    	0x000214E4L, 0, 0);
DEFINE_SHLGUID(IID_IShellFolder,    	0x000214E6L, 0, 0);
DEFINE_SHLGUID(IID_IShellExtInit,   	0x000214E8L, 0, 0);
DEFINE_SHLGUID(IID_IShellPropSheetExt,  0x000214E9L, 0, 0);
DEFINE_SHLGUID(IID_IExtractIcon,   	0x000214EBL, 0, 0);
DEFINE_SHLGUID(IID_IShellLink,		0x000214EEL, 0, 0);
DEFINE_SHLGUID(IID_IShellCopyHook,	0x000214EFL, 0, 0);
DEFINE_SHLGUID(IID_IFileViewer,		0x000214F0L, 0, 0);
DEFINE_SHLGUID(IID_IEnumIDList,     	0x000214F2L, 0, 0);
DEFINE_SHLGUID(IID_IFileViewerSite, 	0x000214F3L, 0, 0);

