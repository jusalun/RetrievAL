#pragma once

#include "TSSGSubject.h"

#pragma pack(push, 1)
typedef struct _TSSSplit
{
	TSSGSubject     super;
	unsigned long   drawType;
	unsigned long   indentType;
	unsigned char   width;
	unsigned char   height;
	BYTE            padSplit[2];
	long            indent;
	bcb6_std_string strParam;
} TSSSplit;
#pragma pack(pop)

