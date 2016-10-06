#ifndef CPPNET_GC_H
#define CPPNET_GC_H

#include <vector>

#include "../System/Object.h"
#include "gc_ptr.h"

#ifndef GC_MAXRAM 
#define GC_MAXRAM 104857600ULL // 100MB(1024KB)
#endif

namespace CppNet
{
	class gc : public System::Object
	{
		template<typename T>
		friend class gc_ptr;

	private:
		class mem_data
		{
		public:
			void* address = nullptr;
			size_t ref_count = 0;
			size_t alloc_size = 0;
		};

	private:
		static std::vector<mem_data*> allocs;

	public:
		template<typename T, typename... InitArgs>
		gc_ptr<T> newgc(InitArgs... args);
	};
}

#include "gc.inl"

#endif