#include "gc.h"

#include "../System/UInt64.h"
using namespace CppNet;
using namespace System;

std::vector<std::tuple<void*, size_t, size_t>> gc::allocs = std::vector<std::tuple<void*, size_t, size_t>>();
void* gc::space_address = nullptr;
size_t gc::space_size = 0;
size_t gc::use_bytes = 0;

void gc::alloc_space()
{
	if (GC_MAXRAM < GC_ALLOCRAM + use_bytes)
		throw std::bad_alloc();

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

			size_t index = 0;
			for (auto a : gc::allocs)
			{
				if (index == 0) { index++; continue; }

				void* temp01 = std::get<0>(a);
				size_t temp02 = std::get<1>(a), temp03 = std::get<2>(a);

				temp01 = (void*)((size_t)temp01 - sub);

				std::tuple<void*, size_t, size_t> tup = std::make_tuple(temp01, temp02, temp03);

				gc::allocs.at(index) = tup;

				index++;
			}
		}
		else if (old_i < new_i) // new의 주소가 더 높음
		{
			UInt64 sub = new_i - old_i;

			size_t index = 0;
			for (auto a : gc::allocs)
			{
				if (index == 0) { index++; continue; }

				void* temp01 = std::get<0>(a);
				size_t temp02 = std::get<1>(a), temp03 = std::get<2>(a);

				temp01 = (void*)((size_t)temp01 + sub);

				std::tuple<void*, size_t, size_t> tup = std::make_tuple(temp01, temp02, temp03);
			
				gc::allocs.at(index) = tup;

				index++;
			}
		}
	}
}