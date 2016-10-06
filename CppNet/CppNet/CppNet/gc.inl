#include "gc.h"
using namespace CppNet;

template<typename T, typename ...InitArgs>
inline gc_ptr<T> gc::newgc(InitArgs ...args)
{
	void* vp = new T(args...);

	gc::allocs.push_back(vp);
	
	gc::mem_data* d = new gc::mem_data;
	d->alloc_size = 1;

	gc::data.push_back(d);

	gc_ptr<T> g(gc::allocs.at(gc::allocs.size() - 1));

	return g;
}