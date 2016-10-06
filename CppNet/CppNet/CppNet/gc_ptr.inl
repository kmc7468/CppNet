#include "gc_ptr.h"

#include "gc.h"

#include <algorithm>
using namespace CppNet;

template<class T>
gc_ptr<T>::gc_ptr(size_t index)
{
	gc::data.at(index)->ref_count++;

	this->index = index;
}

template<class T>
gc_ptr<T>::gc_ptr(gc_ptr<T>&& gc)
{
	gc::data.at(index)->ref_count++;

	index = std::move(gc.index);
}

template<class T>
gc_ptr<T>::gc_ptr(const gc_ptr<T>& gc)
{
	gc::data.at(index)->ref_count++;

	index = gc.index;
}

template<class T>
gc_ptr<T>::~gc_ptr()
{
	gc::data.at(index)->ref_count--;
}

template<class T>
T* gc_ptr<T>::operator->() const
{
	return gc::allocs[index]->address;
}

template<class T>
T& gc_ptr<T>::operator*() const
{
	return *(gc::allocs[index]->address);
}