#include "gc.h"

#include <array>
using namespace CppNet;

template<typename T, typename ...InitArgs>
gc_ptr<T> gc::newgc(InitArgs ...args)
{
	if (gc::allocs.size() == 0)
		gc::allocs.push_back(std::make_tuple<void*, size_t, size_t>(nullptr, 0, 0)); // 쓰레기 값

	if (gc::space_address == nullptr)
		gc::alloc_space();

	while (gc::use_bytes + sizeof(T) > gc::space_size)
	{
		gc::alloc_space();
	}

	T* p = new((void*)((size_t)space_address + use_bytes)) T(args...);

	void* vp = p;

	use_bytes += sizeof(T);

	std::tuple<void*, size_t, size_t> tup(vp, 0, 1);

	gc::allocs.push_back(tup);

	size_t s = gc::allocs.size() - 1;
	gc_ptr<T> g(s, 0);

	return g;
}

template<typename T, size_t size, typename... InitArgs>
std::array<gc_ptr<T>, size> gc::newgc(InitArgs... args)
{
	std::array<gc_ptr<T>, size> arr;

	for (size_t i = 0; i < size; i++)
	{
		if (gc::allocs.size() == 0)
			gc::allocs.push_back(std::make_tuple<void*, size_t, size_t>(nullptr, 0, 0)); // 쓰레기 값

		if (gc::space_address == nullptr)
			gc::alloc_space();

		while (gc::use_bytes + sizeof(T) > gc::space_size)
		{
			gc::alloc_space();
		}

		T* p = new((void*)((size_t)space_address + use_bytes)) T(args...);

		void* vp = p;

		if (i == 0)
		{
			std::tuple<void*, size_t, size_t> tup(vp, 0, size);

			gc::allocs.push_back(tup);
		}

		use_bytes += sizeof(T);

		size_t s = gc::allocs.size() - 1;
		gc_ptr<T> g(s, i);

		arr[i] = g;
	}

	return arr;
}