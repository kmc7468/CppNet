#include "gc_ptr.h"

#include "gc.h"
using namespace CppNet;

template<typename T>
gc_ptr<T>::gc_ptr(void** address)
{
	gc::refcounts[std::find(gc::allocs.begin(), gc::allocs.end(), *address)] += 1;

	this->address = address;
}

template<typename T>
gc_ptr<T>::gc_ptr(gc_ptr<T>&& gc)
{
	gc::refcounts[std::find(gc::allocs.begin(), gc::allocs.end(), *address)] += 1;

	address = std::move(gc.address);
}

template<typename T>
gc_ptr<T>::gc_ptr(const gc_ptr<T>& gc)
{
	gc::refcounts[std::find(gc::allocs.begin(), gc::allocs.end(), *address)] += 1;

	address = gc.address;
}

template<typename T>
gc_ptr<T>::~gc_ptr()
{
	gc::refcounts[std::find(gc::allocs.begin(), gc::allocs.end(), *address)] -= 1;
}

template<typename T>
T** gc_ptr<T>::operator->() const
{
	return (T**)address;
}

template<typename T>
T& gc_ptr<T>::operator*() const
{
	return **((T**)address);
}