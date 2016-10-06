#ifndef CPPNET_GC_H
#define CPPNET_GC_H

#include <vector>

#include "../System/Object.h"
#include "gc_ptr.h"

namespace CppNet
{
	class gc : public System::Object
	{
		template<typename T>
		friend class gc_ptr;

	private:
		static std::vector<void*> allocs;
		static std::vector<size_t> refcounts;
	};
}

#endif