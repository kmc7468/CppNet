#include "gc.h"

#include <array>
using namespace CppNet;

template<typename T, typename ...InitArgs>
gc_ptr<T> gc::newgc(InitArgs ...args)
{
	if (gc::allocs.size() == 0)
		gc::allocs.push_back(new gc::mem_data()); // 쓰레기 값

	if (gc::space_address == nullptr)
		gc::alloc_space();

	while (gc::use_bytes + sizeof(T) > gc::space_size)
	{
		gc::alloc_space();
	}

	T* p = new((void*)((size_t)space_address + use_bytes)) T(args...);

	void* vp = p;

	use_bytes += sizeof(T);

	gc::mem_data* d = new gc::mem_data;
	d->alloc_size = 1;
	d->address = vp;

	gc::allocs.push_back(d);

	gc_ptr<T> g(gc::allocs.size() - 1, 0);

	return g;
}

template<typename T, size_t size, typename... InitArgs>
std::array<gc_ptr<T>, size> gc::newgc(InitArgs... args)
{
	std::array<gc_ptr<T>, size> arr;

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = newgc<T>(args...);
	}

	return arr;
}