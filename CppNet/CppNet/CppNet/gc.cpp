#include "gc.h"

#include "../System/UInt64.h"
using namespace CppNet;
using namespace System;

std::vector<gc::mem_data*> gc::allocs = std::vector<gc::mem_data*>();
void* gc::space_address = nullptr;
size_t gc::space_size = 0;
size_t gc::use_bytes = 0;

void gc::alloc_space()
{
	if (space_address == nullptr)
	{
		space_address = malloc(GC_STARTRAM);
		
		if (space_address == NULL)
		{
			throw std::bad_alloc();
		}

		space_size = GC_STARTRAM;
	}
	else
	{
		void* old = gc::space_address;

		space_address = realloc(space_address, space_size + GC_ALLOCRAM);

		if (space_address == NULL)
		{
			throw std::bad_alloc();
		}

		space_size += GC_ALLOCRAM;

		UInt64 old_i = (UInt64)old;
		UInt64 new_i = (UInt64)gc::space_address;

		if (old_i > new_i) // old의 주소가 더 높음
		{
			UInt64 sub = old_i - new_i;

			for (size_t i = 0; i < gc::allocs.size(); i++)
			{
			}
		}
		else if (old_i < new_i) // new의 주소가 더 높음
		{
			UInt64 sub = new_i - old_i;
		}
	}
}