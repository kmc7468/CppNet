#ifndef CPPNET_GC_PTR_H
#define CPPNET_GC_PTR_H

#include <memory>

#include "../System/Object.h"
#include "../System/UInt64.h"

namespace CppNet
{
	template<class T>
	class gc_ptr : public System::Object
	{
	public:
		gc_ptr(size_t index);
		gc_ptr(gc_ptr<T>&& gc);
		gc_ptr(const gc_ptr<T>& gc);
		~gc_ptr();

	private:
		size_t index = 0;
		// 여기서 index는 식별 코드이다.

	public:
		T* operator->() const;
		T& operator*() const;
	};
}

#include "gc_ptr.inl"

#endif