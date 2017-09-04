#include "stdafx.h"

#define GetPointer(X) *(PDWORD)(X)
#define CSleep(X) Sleep(X * 1000)
VOID Thread(LPTHREAD_START_ROUTINE th);
HRESULT CreateSymbolicLink(char* szDrive, char* szDeviceName, BOOL System);
// Hooking
VOID PatchInJump(PDWORD Address, DWORD Destination, BOOL Linked);
VOID HookFunctionStart(PDWORD Address, PDWORD SaveStub, DWORD Destination);
DWORD PatchModuleImport(PCHAR Module, PCHAR ImportedModuleName, DWORD Ordinal, DWORD PatchAddress);
DWORD PatchModuleImport(PLDR_DATA_TABLE_ENTRY Module, PCHAR ImportedModuleName, DWORD Ordinal, DWORD PatchAddress);

// File Stuff
BOOL FileExists(PCHAR Path);
BOOL ReadFileAlt(PCHAR Path, LPVOID Buffer, DWORD dwBytesToRead);
BOOL WriteFileAlt(PCHAR Path, LPCVOID Buffer, DWORD dwBytesToWrite);

// Misc
DWORD ResolveFunction(PCHAR ModuleName, DWORD Ordinal);
VOID XNotify(CONST PWCHAR pwszStringParam);
typedef enum _XBOX_GAMES : DWORD {	
	DASHBOARD = 0xFFFE07D1,
	COD_ADVANCED_WARFARE = 0x41560914,
	COD_GHOSTS = 0x415608fc,
    COD_BLACK_OPS_2 = 0x415608C3,
	COD_BLACK_OPS_3 = 0x4156091D,
	COD_MW3 = 0x415608CB,
	COD_BO1 = 0x41560855,
	COD_MW2 = 0x41560817,
	COD_WAW = 0x4156081C,
	COD_MW = 0x415607E6
} XBOX_GAMES;