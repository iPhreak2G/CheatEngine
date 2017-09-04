#include "stdafx.h"
#include "hv.h"

//#define UsingEncryption // remove this line if you don't want the server information to be encrypted
#define AUTHFLAG_RESPONSE 0x0F
#define AUTHFLAG_UPDATE 0x3F
VOID MountPaths()
{
	if ((XboxHardwareInfo->Flags & 0x20) == 0x20)
		if (CreateSymbolicLink("Cheats:\\", "\\Device\\Harddisk0\\Partition1", true) != ERROR_SUCCESS)
			return;
		else
			if (CreateSymbolicLink("Cheats:\\", "\\Device\\Mass0", true) != ERROR_SUCCESS)
				return;
}
BYTE CPUKey[16];
BYTE *GetFile(char *szPath, PDWORD pdwOutSize)
{
	FILE *f = fopen(szPath, "rb");

	if (!f) {
		*pdwOutSize = 0;
		return NULL;
	}

	fseek(f, 0, SEEK_END);
	*pdwOutSize = ftell(f);
	rewind(f);

	BYTE *pbReturnData = (BYTE*)malloc(*pdwOutSize);

	fread(pbReturnData, 1, *pdwOutSize, f);

	fclose(f);

	return pbReturnData;
}
VOID GetModuleHash(BYTE *outHash) {
	DWORD dataSize = 0xF000;
	BYTE *data = GetFile("Cheats:\\CheatEngine.xex", &dataSize);
	
	if (!data || dataSize == 0 || !FileExists("Cheats:\\CheatEngine.xex")) {
		return;
	}

	XECRYPT_SHA_STATE sha;
	XeCryptShaInit(&sha);
	XeCryptShaUpdate(&sha, data, dataSize);
	XeCryptShaFinal(&sha, outHash, 20);

	free(data);
}
BYTE GetCpuKey(BYTE cpureq[16]) {
	HV::Peek::HvPeekBytes(0x20, cpureq, 0x10);
	return cpureq[16];
}
namespace AUTH {
	BOOL Authenticate()
	{
		MountPaths(); //this needs to be fixed

		AuthenticationRequest Request;
		GetCpuKey(Request.CPUKey); //this needs to be fixed
		GetModuleHash(Request.XEXChecksum); //this needs to be fixed
		Request.XEXVersion = 49; // increment this every time you update the .xex/push update.
		ZeroMemory(&Request.Padding, 3);
		ZeroMemory(&Request.PacketChecksum, 0x10);

		unsigned char ServerIP[4] = { 74, 208, 216, 230 }; //cyanide vps
		//unsigned char ServerIP[4] = { 0xC0, 0xA8, 0x01, 0x04 }; //cyanide local
		unsigned char EncryptionKey[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#ifdef UsingEncryption
		XeCryptRc4((unsigned char*)EncryptionKey, 8, (unsigned char*)ServerIP, 4);
#endif

		BOOL Connected = false;
		SOCKET Sock;
		for (INT i = 0; i < 3; i++)
		{
			if ((Sock = Network_Connect(ServerIP, 9825)) != INVALID_SOCKET)
			{
				Connected = true;
				break;
			}
		}

		if (Connected)
		{
			NetDll_send(XNCALLER_SYSAPP, Sock, (char*)&Request, 0x34, 0);

			unsigned char authflag;
			NetDll_recv(XNCALLER_SYSAPP, Sock, (char*)&authflag, 1, 0);

			if (authflag == AUTHFLAG_RESPONSE)
			{
				AuthenticationResponse Response;
				NetDll_recv(XNCALLER_SYSAPP, Sock, (char*)&Response, 0x11, 0);

				unsigned char failed[0x11] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
				return memcmp(&Response, failed, 0x11) != 0;
			}
			else if (authflag == AUTHFLAG_UPDATE)
			{
				DWORD UpdateSize = 0;
				NetDll_recv(XNCALLER_SYSAPP, Sock, (char*)&UpdateSize, 4, 0);

				unsigned char* Update = new unsigned char[UpdateSize];
				if (UpdateSize == 0 || !Network_Receive(Sock, Update, UpdateSize))
				{
					XNotify(L"CheatEngine - Update Failed, Rebooting!"); // this doesn't NEED to be fixed but it's one of those aesthetic things that customers like looking at lol
					Sleep(5000);
					Network_Disconnect(Sock);
					HalReturnToFirmware(HalForceShutdownRoutine);
				}
				Network_Disconnect(Sock);

				HANDLE UpdateHandle;
				char UpdatePath[0xFF];
				sprintf_s(UpdatePath, "Cheats:\\CheatEngine.xex");

				if ((UpdateHandle = CreateFile(UpdatePath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0)) == INVALID_HANDLE_VALUE)
				{
					XNotify(L"CheatEngine - Update Failed, Rebooting!"); // this doesn't NEED to be fixed but it's one of those aesthetic things that customers like looking at lol
					Sleep(5000);
					HalReturnToFirmware(HalForceShutdownRoutine);
				}
				WriteFile(UpdateHandle, Update, UpdateSize, &UpdateSize, 0);
				CloseHandle(UpdateHandle);

				delete[] Update;

				XNotify(L"CheatEngine - Client Updated, Rebooting!"); // this doesn't NEED to be fixed but it's one of those aesthetic things that customers like looking at lol
				Sleep(5000);
				HalReturnToFirmware(HalForceShutdownRoutine);
			}
		}

		return false;
	}
}