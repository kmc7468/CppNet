#include "gc.h"
using namespace CppNet;

template<typename T, typename ...InitArgs>
gc_ptr<T> gc::newgc(InitArgs ...args)
{
	if (gc::allocs.size() == 0)
		gc::allocs.push_back(new gc::mem_data()); // 쓰레기 값

	void* vp = new(space_address + use_bytes) T(std::forward(args...));

	use_bytes += sizeof(T);

	gc::mem_data* d = new gc::mem_data;
	d->alloc_size = 1;
	d->address = vp;

	gc::allocs.push_back(d);

	gc_ptr<T> g(gc::allocs.at(gc::allocs.size() - 1));

	return g;
}

#ifdef CppNet_Unsafe
template<typename T>
void gc::deletegc(const gc_ptr<T>& gc)
{
	gc.index = 0;
}
#endif

template<typename T, size_t size, typename... InitArgs>
std::array<gc_ptr<T>, size> gc::newgc(InitArgs... args)
{

}

#ifdef CppNet_Unsafe
template<typename T, size_t size>
void gc::deletegc(std::array<gc_ptr<T>, size> arr)
{

}
#endif