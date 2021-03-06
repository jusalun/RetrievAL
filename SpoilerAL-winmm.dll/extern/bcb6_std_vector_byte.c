#include <windows.h>
#define USING_NAMESPACE_BCB6_STD
#include "bcb6_std_vector.h"
#include "bcb6_std_allocator.h"

void __fastcall vector_byte_reserve(vector_byte *v, size_t n)
{
	size_t capacity = vector_capacity(v);
	if (n > capacity)
	{
		size_t size = vector_size(v);
		BYTE *p = (BYTE *)allocator_reallocate(vector_begin(v), capacity, n);
		vector_begin(v) = p;
		vector_end(v) = p + size;
		vector_end_of_storage(v) = p + n;
	}
}

void __fastcall vector_byte_resize(vector_byte *v, size_t n)
{
	BYTE *p = vector_begin(v) + n;
	if (p <= vector_end_of_storage(v))
	{
		if (p > vector_end(v))
			memset(vector_end(v), 0, p - vector_end(v));
		vector_end(v) = p;
	}
	else
	{
		n = p - vector_end(v);
		size_t size = vector_size(v);
		size_t capacity = size + max(size, n);
		p = (BYTE *)allocator_reallocate(vector_begin(v), vector_capacity(v), capacity);
		memset(p + size, 0, n);
		vector_begin(v) = p;
		vector_end(v) = p + size + n;
		vector_end_of_storage(v) = p + capacity;
	}
}

void __fastcall vector_byte_resize_nofill(vector_byte *v, size_t n)
{
	BYTE *p = vector_begin(v) + n;
	if (p <= vector_end_of_storage(v))
	{
		vector_end(v) = p;
	}
	else
	{
		n = p - vector_end(v);
		size_t size = vector_size(v);
		size_t capacity = size + max(size, n);
		p = (BYTE *)allocator_reallocate(vector_begin(v), vector_capacity(v), capacity);
		vector_begin(v) = p;
		vector_end(v) = p + size + n;
		vector_end_of_storage(v) = p + capacity;
	}
}

void __fastcall vector_byte_push_back(vector_byte *v, BYTE value)
{
	if (vector_end(v) == vector_end_of_storage(v))
	{
		size_t size, capacity;
		if (capacity = size = vector_size(v))
			capacity += capacity;
		else
			capacity++;
		BYTE *p = (BYTE *)allocator_reallocate(vector_begin(v), vector_capacity(v), capacity);
		vector_begin(v) = p;
		vector_end(v) = p + size;
		vector_end_of_storage(v) = p + capacity;
	}
	*(vector_end(v)++) = value;
}
