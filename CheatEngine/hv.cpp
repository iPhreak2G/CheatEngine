#include "stdafx.h"
#include "hv.h"

namespace HV {
	QWORD HvxExpansionInstall(DWORD PhysicalAddress, DWORD CodeSize) { //NO STATIC
		__asm {
			li			r0, 0x70
				sc
				blr
		}
	}
	QWORD HvxExpansionCall(DWORD ExpansionId, QWORD Param1 = 0, QWORD Param2 = 0, QWORD Param3 = 0, QWORD Param4 = 0) { //NO STATIC
		__asm {
			li			r0, 0x71
				sc
				blr
		}
	}

	HRESULT InitializeHvPoke() {
		VOID* pPhysExp = XPhysicalAlloc(0x1000, MAXULONG_PTR, 0, PAGE_READWRITE);
		DWORD physExpAdd = (DWORD)MmGetPhysicalAddress(pPhysExp);

		ZeroMemory(pPhysExp, 0x1000);
		memcpy(pPhysExp, HvPokeExp, sizeof(HvPokeExp));

		HRESULT result = (HRESULT)HvxExpansionInstall(physExpAdd, 0x1000);

		XPhysicalFree(pPhysExp);

		return result;
	}

	QWORD HvGetFuseLine(BYTE fuseIndex) {
		if (fuseIndex > 11) return 0;
		return Peek::HvPeekQWORD(0x8000020000020000 + (fuseIndex * 0x200));
	}
	namespace Peek {
		BYTE    HvPeekBYTE(QWORD Address) {
			return (BYTE)HvxExpansionCall(HvPokeExpID, PEEK_BYTE, Address);
		}
		WORD    HvPeekWORD(QWORD Address) {
			return (WORD)HvxExpansionCall(HvPokeExpID, PEEK_WORD, Address);
		}
		DWORD   HvPeekDWORD(QWORD Address) {
			return (DWORD)HvxExpansionCall(HvPokeExpID, PEEK_DWORD, Address);
		}
		QWORD   HvPeekQWORD(QWORD Address) {
			return HvxExpansionCall(HvPokeExpID, PEEK_QWORD, Address);
		}
		HRESULT HvPeekBytes(QWORD Address, PVOID Buffer, DWORD Size) {
			VOID* data = XPhysicalAlloc(Size, MAXULONG_PTR, 0, PAGE_READWRITE);
			ZeroMemory(data, Size);

			HRESULT result = (HRESULT)HvxExpansionCall(HvPokeExpID,
				PEEK_BYTES, Address, (QWORD)MmGetPhysicalAddress(data), Size);

			if (result == S_OK) memcpy(Buffer, data, Size);

			XPhysicalFree(data);
			return result;
		}
	}
	namespace Poke {
		HRESULT HvPokeBYTE(QWORD Address, BYTE Value) {
			return (HRESULT)HvxExpansionCall(HvPokeExpID, POKE_BYTE, Address, Value);
		}
		HRESULT HvPokeWORD(QWORD Address, WORD Value) {
			return (HRESULT)HvxExpansionCall(HvPokeExpID, POKE_WORD, Address, Value);
		}
		HRESULT HvPokeDWORD(QWORD Address, DWORD Value) {
			return (HRESULT)HvxExpansionCall(HvPokeExpID, POKE_DWORD, Address, Value);
		}
		HRESULT HvPokeQWORD(QWORD Address, QWORD Value) {
			return (HRESULT)HvxExpansionCall(HvPokeExpID, POKE_QWORD, Address, Value);
		}
		HRESULT HvPokeBytes(QWORD Address, CONST VOID* Buffer, DWORD Size) {
			VOID* data = XPhysicalAlloc(Size, MAXULONG_PTR, 0, PAGE_READWRITE);
			memcpy(data, Buffer, Size);

			HRESULT result = (HRESULT)HvxExpansionCall(HvPokeExpID,
				POKE_BYTES, Address, (QWORD)MmGetPhysicalAddress(data), Size);

			XPhysicalFree(data);
			return result;
		}
	}
}
#pragma warning(pop)