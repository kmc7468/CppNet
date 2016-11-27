#ifndef CPPNET_KMC_ARRAY1D_HPP
#define CPPNET_KMC_ARRAY1D_HPP

#include "../../Defines.h"
#include "../../Utility.h"

#include "../System/Object.h"
#include "../System/UInt64.h"
#include "../System/UInt32.h"
#include "../System/NullReferenceException.hpp"
#include "../System/IndexOutOfRangeException.hpp"
#include "../System/ArgumentNullException.hpp"

#include <memory.h>

namespace CppNet::KMC
{
	template<typename T, size_t size>
	class Array1D final : public System::Object
	{
	private:
		T* data = nullptr;

	public:
		Array1D()
		{
			data = new T[size];
		}

		Array1D(T& initValue)
			: Array1D()
		{
			for (size_t i = 0; i < size; ++i)
				data[i] = initValue;
		}

		Array1D(T&& initValue)
			: Array1D()
		{
			for (size_t i = 0; i < size; ++i)
				data[i] = initValue;
		}

		Array1D(const Array1D<T, size>& arr)
			: Array1D()
		{
			memcpy(data, arr.data, size);
		}

		Array1D(Array1D<T, size>&& arr)
		{
			data = arr.data;

			arr.data = nullptr;
		}

		~Array1D()
		{
			if (data)
				delete[] data;
		}

	public:
		const T& operator[](size_t index) const
		{
			if (data == nullptr)
				throw System::NullReferenceException();

			if (index >= firstSize)
				throw System::IndexOutOfRangeException();

#ifdef BIT_64
			System::UInt64 addr = (System::UInt64)data;
#else
			System::UInt32 addr = (System::UInt32)data;
#endif

			return NodeA((T*)(addr + (sizeof(T) * fourthSize * thirdSize * secondSize * index)));
		}
	
		T& operator[](size_t index)
		{
			if (data == nullptr)
				throw System::NullReferenceException();

			if (index >= firstSize)
				throw System::IndexOutOfRangeException();

#ifdef BIT_64
			System::UInt64 addr = (System::UInt64)data;
#else
			System::UInt32 addr = (System::UInt32)data;
#endif

			return NodeA((T*)(addr + (sizeof(T) * fourthSize * thirdSize * secondSize * index)));
		}
	};
}

#endif