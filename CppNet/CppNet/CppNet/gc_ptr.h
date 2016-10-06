#ifndef CPPNET_GC_PTR_H
#define CPPNET_GC_PTR_H

#include <memory>

#include "../System/Object.h"
#include "../System/UInt64.h"

namespace CppNet
{
	template<typename T>
	class gc_ptr : public System::Object
	{
	public:
		gc_ptr(void** address);
		gc_ptr(gc_ptr<T>&& gc);
		gc_ptr(const gc_ptr<T>& gc);
		~gc_ptr();

	private:
		void** address;
		/* NOTE
		address 포인터는 gc 클래스에 있는 std::vector<void*>에 저장된 포인터를 가르키게 됨
		*/

	public:
		T** operator->() const;
		T& operator*() const;
	};
}

#include "gc_ptr.inl"

#endif