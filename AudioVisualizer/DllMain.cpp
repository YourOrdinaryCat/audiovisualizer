#include "pch.h"

#include "Tracing.h"


BOOL WINAPI DllMain(
	HINSTANCE /*hinstDLL*/,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID /*lpReserved*/)  // reserved
{
	// Perform actions based on the reason for calling.
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
#ifdef _TRACE_
		Trace::Initialize();
#endif
		break;

	case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;

	case DLL_PROCESS_DETACH:
		// Perform any necessary cleanup.
#ifdef _TRACE_
		Trace::ShutDown();
#endif
		break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}