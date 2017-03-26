#pragma once

#include <windows.h>

typedef struct
{
	LPVOID _M_start;
	LPVOID _M_finish;
	LPVOID padding1;
	LPVOID padding2;
	LPVOID _M_end_of_storage;
	LPVOID padding3;
} bcb6_std_vector, *pbcb6_std_vector;

#define bcb6_std_vector_ctor(v)            ((v)->_M_end_of_storage = (v)->_M_finish = (v)->_M_start = NULL)
#define bcb6_std_vector_size(v, elemType)  (size_t)((elemType *)(v)->_M_finish - (elemType *)(v)->_M_start)
#define bcb6_std_vector_begin(v, elemType) ((elemType *)(v)->_M_start)
#define bcb6_std_vector_end(v, elemType)   ((elemType *)(v)->_M_finish)
#define bcb6_std_vector_empty(v)           ((v)->_M_finish == (v)->_M_start)

EXTERN_C void __fastcall bcb6_std_vector_resize(bcb6_std_vector *v, size_t size);
EXTERN_C void __fastcall bcb6_std_vector_push_back(bcb6_std_vector *v, char c);