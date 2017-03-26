.486
.model flat

includelib kernel32.lib

extrn @TSSGCtrl_IsRemoteProcess@4:proc
extrn __imp__GetCurrentProcess@0:dword
extrn @bcb6_std_string_dtor@4:proc

public _TSSDoubleToggle_Read_Compare1

.code

align 16

_TSSDoubleToggle_Read_Compare1 proc near

	TSSGCtrl_Compare equ 0051C470H

	push    TSSGCtrl_Compare
	mov     ecx, dword ptr [ebp - 0ECH]
	call    @TSSGCtrl_IsRemoteProcess@4
	test    al, al
	jnz     L1
	call    dword ptr [__imp__GetCurrentProcess@0]
	mov     dword ptr [esp + 16], eax
L1:
	lea     ecx, [ebp - 0ECH]
	jmp     @bcb6_std_string_dtor@4

_TSSDoubleToggle_Read_Compare1 endp

end