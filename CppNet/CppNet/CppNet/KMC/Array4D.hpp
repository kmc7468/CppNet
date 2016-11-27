#ifndef CPPNET_KMC_ARRAY4D_HPP
#define CPPNET_KMC_ARRAY4D_HPP

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
	template<typename T, size_t firstSize, size_t secondSize, size_t thirdSize, size_t fourthSize>
	class Array4D final : public System::Object
	{
	public:
		class NodeB;
		class NodeC;
		class NodeA final
		{
			friend class Array4D<T, firstSize, secondSize, thirdSize, fourthSize>;

		private:
			T* value = nullptr;

			NodeA(T* value)
			{
				this->value = value;
			}

		public:
			NodeA(const NodeA& n)
			{
				this->value = n.value;
			}

			NodeA(NodeA&& n)
			{
				this->value = n.value;
			}

		public:
			const NodeB operator[](size_t index) const
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeB((T*)(addr + (sizeof(T) * fourthSize * thirdSize * index)));
			}

			NodeB operator[](size_t index)
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeB((T*)(addr + (sizeof(T) * fourthSize * thirdSize * index)));
			}

			NodeA& operator=(const NodeA&) = delete;
			NodeA& operator=(NodeA&&) = delete;

			NodeA& operator=(T*** data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				for (size_t i = 0; i < secondSize; ++i)
					for (size_t j = 0; j < thirdSize; ++j)
						(*this)[i][j] = data[i][j];

				return *this;
			}
		};
		class NodeB final
		{
			friend class NodeA;

		private:
			T* value = nullptr;

			NodeB(T* value)
			{
				this->value = value;
			}

		public:
			NodeB(NodeB&& n)
			{
				value = n.value;
			}

			NodeB(const NodeB& n)
			{
				value = n.value;
			}

		public:
			const NodeC operator[](size_t index) const
			{
				if (index >= thirdSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeC((T*)(addr + (sizeof(T) * fourthSize * index)));
			}

			NodeC operator[](size_t index)
			{
				if (index >= thirdSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeC((T*)(addr + (sizeof(T) * fourthSize * index)));
			}

			NodeB& operator=(const NodeB&) = delete;
			NodeB& operator=(NodeB&&) = delete;

			NodeB& operator=(T** data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				for (size_t i = 0; i < thirdSize; ++i)
					memcpy((T*)((UInt64)value + (i * fourthSize * sizeof(T))), data[i], sizeof(T) * fourthSize);

				return *this;
			}
		};
		class NodeC final
		{
			friend class NodeB;

		private:
			T* value = nullptr;

			NodeC(T* value)
			{
				this->value = value;
			}

		public:
			NodeC(const NodeC& n)
			{
				value = n.value;
			}

			NodeC(NodeC&& n)
			{
				value = n.value;
			}

		public:
			const T& operator[](size_t index) const
			{
				if (index >= fourthSize)
					throw System::IndexOutOfRangeException();

				return value[index];
			}

			T& operator[](size_t index)
			{
				if (index >= fourthSize)
					throw System::IndexOutOfRangeException();

				return value[index];
			}

			NodeC& operator=(const NodeC&) = delete;
			NodeC& operator=(NodeC&&) = delete;

			NodeC& operator=(T* data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				memcpy(value, data, sizeof(T) * fourthSize);

				return *this;
			}
		};

	private:
		T* data = nullptr;

	public:
		Array4D()
		{
			data = new T[firstSize * secondSize * thirdSize * fourthSize];
		}

		Array4D(T& fourth_initValue)
			: Array4D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					for (size_t n = 0; n < thirdSize; ++n)
						for (size_t a = 0; a < fourthSize; ++a)
							(*this)[i][j][n][a] = fourth_initValue;
		}

		Array4D(T&& fourth_initValue)
			: Array4D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					for (size_t n = 0; n < thirdSize; ++n)
						for (size_t a = 0; a < fourthSize; ++a)
							(*this)[i][j][n][a] = fourth_initValue;
		}

		Array4D(const Array4D<T, firstSize, secondSize, thirdSize, fourthSize>& arr)
			: Array4D()
		{
			memcpy(data, arr.data, firstSize * secondSize * thirdSize * fourthSize * sizeof(T));
		}

		Array4D(Array4D<T, firstSize, secondSize, thirdSize, fourthSize>&& arr)
		{
			data = arr.data;

			arr.data = nullptr;
		}

		~Array4D()
		{
			if (data)
				delete[] data;
		}

	public:
		const NodeA operator[](size_t index) const
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

		NodeA operator[](size_t index)
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