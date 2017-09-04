// CheatEngine.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "vectors.h"
#include "MW3.h"

BOOL InitializedCheats = false;
BOOL dashLoaded = false;
BOOL Cheats = false;
DWORD (__cdecl *XamGetCurrentTitleID)() = (DWORD (__cdecl *)())ResolveFunction(Module_XAM, 0x1CF);
AuthenticationResponse RespData;
VOID Begin(){
	Thread((LPTHREAD_START_ROUTINE)cycleColors); //start on boot
	for(;;){
		if (XamGetCurrentTitleID() == DASHBOARD)
		{
			if (!dashLoaded)
			{
				Sleep(5000);
				if(AUTH::Authenticate()) { //check auth
					Cheats = true; 
					XNotify(L"CheatEngine - Oi Enjoy The Loot!");
				}else{
					Cheats = false;
				}
				dashLoaded = true;
			}			
		}
		else
		{
			if (Cheats)
			{
				switch(XamGetCurrentTitleID()){
					case COD_MW3:{
						if (!InitializedCheats && AUTH::Authenticate()){ //make sure we are still authed
							Sleep(5000);
							Thread((LPTHREAD_START_ROUTINE)MW3::Hook::MW3);					
							XNotify(L"CheatEngine - MW3 Loot!");
							InitializedCheats = true;
						}
						break;
					}
					default:{
						InitializedCheats = false;
						break;
					}
				}					
			}
		}
	}
}

BOOL WINAPI DllMain(HANDLE hInstDLL, DWORD fdwReason, LPVOID lpReserved) {
	switch (fdwReason) {
		case DLL_PROCESS_ATTACH:
			Thread((LPTHREAD_START_ROUTINE)Begin);
			break;
		case DLL_PROCESS_DETACH:
			break;
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
			break;
	} return TRUE;
}