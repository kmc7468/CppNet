#ifndef CPPNET_GC_PTR_H
#define CPPNET_GC_PTR_H

#include "../System/Object.h"

namespace CppNet
{
	template<typename T>
	class gc_ptr : public System::Object
	{
	private:
		T* address = nullptr;
		size_t* ref_count = nullptr;
	};
}

#endif