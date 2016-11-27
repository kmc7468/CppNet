#ifndef CPPNET_KMC_ARRAY2D_HPP
#define CPPNET_KMC_ARRAY2D_HPP

#include "../../Defines.h"

#include "../System/Object.h"
#include "../System/UInt64.h"
#include "../System/UInt32.h"
#include "../System/NullReferenceException.hpp"
#include "../System/IndexOutOfRangeException.hpp"

#include <memory.h>

namespace CppNet::KMC
{
	template<typename T, size_t firstSize, size_t secondSize>
	class Array2D final : public System::Object
	{
	public:
		class Node final
		{
			friend class Array2D<T, firstSize, secondSize>;

		private:
			T* value = nullptr;

			Node(T* value)
			{
				this->value = value;
			}

		public:
			Node(Node&& n)
			{
				value = n.value;
			}

			Node(const Node& n)
			{
				value = n.value;
			}

		public:
			const T& operator[](size_t index) const
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

				return value[index];
			}

			T& operator[](size_t index)
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

				return value[index];
			}

			Node& operator=(const Node&) = delete;
			Node& operator=(Node&&) = delete;

			Node& operator=(T* data)
			{
				memcpy(value, data, sizeof(T) * secondSize);
			}
		};

	private:
		T* data = nullptr;

	public:
		Array2D()
		{
			data = new T[firstSize * secondSize];
		}

		Array2D(T& second_initValue)
			: Array2D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					(*this)[i][j] = second_initValue;
		}

		Array2D(T&& second_initValue)
			: Array2D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					(*this)[i][j] = second_initValue;
		}

		Array2D(const Array2D<T, firstSize, secondSize>& arr)
			: Array2D()
		{
			memcpy(data, arr.data, firstSize * secondSize * sizeof(T));
		}

		Array2D(Array2D<T, firstSize, secondSize>&& arr)
		{
			data = arr.data;

			arr.data = nullptr;
		}

		~Array2D()
		{
			if (data)
				free(data);
		}

	public:
		const Node operator[](size_t index) const
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

			return Node((T*)(addr + (sizeof(T) * secondSize * index)));
		}

		Node operator[](size_t index)
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

			return Node((T*)(addr + (sizeof(T) * secondSize * index)));
		}
	};
}

#endif