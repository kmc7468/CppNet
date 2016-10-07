#ifndef CPPNET_GC_H
#define CPPNET_GC_H

#include "../Defines.h"

#include <vector>

#include "../System/Object.h"
#include "gc_ptr.h"

#ifndef GC_MAXRAM 
#define GC_MAXRAM 104857600ULL // 100MB(102400KB)
#endif

#ifndef GC_ALLOCRAM
#define GC_ALLOCRAM 1024ULL // 1KB(1024Byte)
#endif

#ifndef GC_STARTRAM
#define GC_STARTRAM 2048ULL // 2KB(2048Byte)
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
		static gc_ptr<T> newgc(InitArgs... args);
#ifdef CppNet_Unsafe
		template<typename T>
		static void deletegc(const gc_ptr<T>& gc);
#endif
		template<typename T, size_t size, typename... InitArgs>
		static std::array<gc_ptr<T>, size> newgc(InitArgs... args);
#ifdef CppNet_Unsafe
		template<typename T, size_t size>
		static void deletegc(std::array<gc_ptr<T>, size> arr);
#endif
		
	private:
		static void* space_address;
		static size_t space_size;
		static size_t use_bytes;

		static void alloc_space();
	};
}

#include "gc.inl"

#endif