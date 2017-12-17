#pragma function(atan2)

__declspec(naked) double __cdecl atan2(double y, double x)
{
	__asm
	{
		fld     qword ptr [esp + 4]     ; Load real from stack
		fld     qword ptr [esp + 12]    ; Load real from stack
		fpatan                          ; Take the arctangent
		ret
	}
}