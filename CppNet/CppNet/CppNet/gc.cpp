#include "gc.h"
using namespace CppNet;

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
		space_address = realloc(space_address, space_size + GC_ALLOCRAM);

		if (space_address == NULL)
		{
			throw std::bad_alloc();
		}

		space_size += GC_ALLOCRAM;
	}
}