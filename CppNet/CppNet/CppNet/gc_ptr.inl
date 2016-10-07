#include "gc_ptr.h"

#include "gc.h"

#include <algorithm>
using namespace CppNet;

template<class T>
gc_ptr<T>::gc_ptr(size_t index, size_t arr_num)
{
	gc::allocs.at(index)->ref_count++;

	this->index = index;
	this->arr_num = arr_num;
}

template<class T>
gc_ptr<T>::gc_ptr(gc_ptr<T>&& gc)
{
	gc::allocs.at(index)->ref_count++;

	index = std::move(gc.index);
	arr_num = std::move(gc.arr_num);
}

template<class T>
gc_ptr<T>::gc_ptr(const gc_ptr<T>& gc)
{
	gc::allocs.at(index)->ref_count++;

	index = gc.index;
	arr_num = gc.arr_num;
}

template<class T>
gc_ptr<T>::~gc_ptr()
{
	gc::allocs.at(index)->ref_count--;
}

template<class T>
T* gc_ptr<T>::operator->() const
{
	return ((T*)(gc::allocs[index]->address)) + arr_num;
}

template<class T>
T& gc_ptr<T>::operator*() const
{
	return *(((T*)(gc::allocs[index]->address)) + arr_num);
}

template<class T>
gc_ptr<T>& gc_ptr<T>::operator=(const gc_ptr<T>& gc)
{
	this->arr_num = gc.arr_num;
	this->index = gc.index;
	
	return *this;
}

template<class T>
inline gc_ptr<T>& CppNet::gc_ptr<T>::operator=(gc_ptr<T>&& gc)
{
	this->arr_num = std::move(gc.arr_num);
	this->index = std::move(gc.index);

	return *this;
}