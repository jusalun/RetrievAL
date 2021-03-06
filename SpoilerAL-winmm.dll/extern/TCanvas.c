#include "TCanvas.h"

extern const DWORD F005E0D50;
extern const DWORD F0055E418;
extern const DWORD F005E0EA8;

__declspec(naked) void __fastcall TCanvas_FillRect(LPVOID this, const RECT *rect)
{
	__asm
	{
		mov     eax, ecx
		mov     ecx, 0055E1D4H
		jmp     ecx
	}
}

__declspec(naked) void __fastcall TCanvas_Lock(LPVOID this)
{
	__asm
	{
		mov     edx, 0055E284H
		mov     eax, ecx
		jmp     edx
	}
}

__declspec(naked) void __fastcall TCanvas_Unlock(LPVOID this)
{
	__asm
	{
		mov     edx, 0055E620H
		mov     eax, ecx
		jmp     edx
	}
}

__declspec(naked) HDC __fastcall TCanvas_GetHandle(LPVOID this)
{
	__asm
	{
		mov     edx, 0055E74CH
		mov     eax, ecx
		jmp     edx
	}
}

__declspec(naked) void __fastcall TCanvas_TextOut(LPVOID *this, int X, int Y, LPCSTR Text)
{
	__asm
	{
		#define this (esp +  4)
		#define X    (esp +  8)
		#define Y    (esp + 12)
		#define Text (esp + 16)

		mov     edx, dword ptr [Text]
		push    eax
		mov     eax, esp
		call    dword ptr [F005E0D50]
		mov     ecx, dword ptr [eax]
		push    ecx
		mov     ecx, dword ptr [Y + 4]
		mov     edx, dword ptr [X + 4]
		mov     eax, dword ptr [this + 4]
		call    dword ptr [F0055E418]
		mov     edx, 2
		mov     eax, esp
		call    dword ptr [F005E0EA8]
		pop     eax
		ret     16

		#undef this
		#undef X
		#undef Y
		#undef Text
	}
}
