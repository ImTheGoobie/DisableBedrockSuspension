#define _WIN32_WINNT 0x0A00
#include <initguid.h>
#include <windows.h>
#include <appmodel.h>
#include <shobjidl.h>

void __stdcall WinMainCRTStartup(void) {
	CoInitialize(NULL);

	IPackageDebugSettings *dbg = NULL;
	CoCreateInstance(&CLSID_PackageDebugSettings, NULL, CLSCTX_INPROC_SERVER, &IID_IPackageDebugSettings, (void **)&dbg);

	PCWSTR fam = L"Microsoft.MinecraftUWP_8wekyb3d8bbwe";
	int count = 0, len = 0;

	if (GetPackagesByPackageFamily(fam, &count, NULL, &len, NULL) == ERROR_INSUFFICIENT_BUFFER) {
		PWSTR *names = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, count * sizeof(PWSTR));
		PWSTR buffer = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, len * sizeof(WCHAR));

		if (GetPackagesByPackageFamily(fam, &count, names, &len, buffer) == ERROR_SUCCESS) {
			for (int i = 0; i < count; ++i)
				dbg->lpVtbl->EnableDebugging(dbg, names[i], NULL, NULL);
		}

		HeapFree(GetProcessHeap(), 0, names);
		HeapFree(GetProcessHeap(), 0, buffer);
	}

	CoUninitialize();
	ExitProcess(0);
}
