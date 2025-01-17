#include <windows.h>
//
//  FUNCTION: DLLMain(HINSTANCE, DWORD, LPVOID)
//  PURPOSE:  Called when DLL is loaded by a process, and when new
//    threads are created by a process that has already loaded the
//    DLL.  Also called when threads of a process that has loaded the
//    DLL exit cleanly and when the process itself unloads the DLL.
//  PARAMETERS:
//    hDLLInst    - Instance handle of the DLL
//    fdwReason   - Process attach/detach or thread attach/detach
//    lpvReserved - Reserved and not used
//  RETURN VALUE:  (Used only when fdwReason == DLL_PROCESS_ATTACH)
//    TRUE  -  Used to signify that the DLL should remain loaded.
//    FALSE -  Used to signify that the DLL should be immediately unloaded.
//
BOOL WINAPI LibMain(HINSTANCE hDLLInst, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // The DLL is being loaded for the first time by a given process.
            // Perform per-process initialization here.  If the initialization
            // is successful, return TRUE; if unsuccessful, return FALSE.


            break;
        case DLL_PROCESS_DETACH:
            // The DLL is being unloaded by a given process.  Do any
            // per-process clean up here, such as undoing what was done in
            // DLL_PROCESS_ATTACH.  The return value is ignored.


            break;
        case DLL_THREAD_ATTACH:
            // A thread is being created in a process that has already loaded
            // this DLL.  Perform any per-thread initialization here.  The
            // return value is ignored.

            break;
        case DLL_THREAD_DETACH:
            // A thread is exiting cleanly in a process that has already
            // loaded this DLL.  Perform any per-thread clean up here.  The
            // return value is ignored.

            break;
    }
    return TRUE;
}
