#ifndef CPPNET_KMC_ARRAY5D_HPP
#define CPPNET_KMC_ARRAY5D_HPP

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
	template<typename T, size_t firstSize, size_t secondSize, size_t thirdSize, size_t fourthSize, size_t fifthSize>
	class Array5D final : public System::Object
	{
	public:
		class NodeB;
		class NodeC;
		class NodeD;
		class NodeA final
		{
			friend class Array5D<T, firstSize, secondSize, thirdSize, fourthSize, fifthSize>;

		private:
			T* value = nullptr;

			NodeA(T* value)
			{
				this->value = value;
			}

		public:
			NodeA(const NodeA& n)
			{
				this->value = value;
			}

			NodeA(NodeA&& n)
			{
				this->value = value;
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

				return NodeB((T*)(addr + (sizeof(T) * fifthSize * fourthSize * thirdSize * index)));
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

				return NodeB((T*)(addr + (sizeof(T) * fifthSize * fourthSize * thirdSize * index)));
			}

			NodeA& operator=(const NodeA&) = delete;
			NodeA& operator=(NodeA&&) = delete;

			NodeA& operator=(T**** data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				for (size_t i = 0; i < secondSize; ++i)
					for (size_t j = 0; j < thirdSize; ++j)
						for (size_t n = 0; n < fourthSize; ++n)
							(*this)[i][j][n] = data[i][j][n];

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
			NodeB(const NodeB& n)
			{
				this->value = value;
			}

			NodeB(NodeB&& n)
			{
				this->value = value;
			}

		public:
			const NodeC operator[](size_t index) const
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeC((T*)(addr + (sizeof(T) * fifthSize * fourthSize * index)));
			}

			NodeC operator[](size_t index)
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeC((T*)(addr + (sizeof(T) * fifthSize * fourthSize * index)));
			}

			NodeB& operator=(const NodeB&) = delete;
			NodeB& operator=(NodeB&&) = delete;

			NodeB& operator=(T*** data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				for (size_t i = 0; i < thirdSize; ++i)
					for (size_t j = 0; j < fourthSize; ++j)
						(*this)[i][j] = data[i][j];

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
				this->value = value;
			}

			NodeC(NodeC&& n)
			{
				this->value = value;
			}

		public:
			const NodeD operator[](size_t index) const
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeD((T*)(addr + (sizeof(T) * fifthSize * index)));
			}

			NodeD operator[](size_t index)
			{
				if (index >= secondSize)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 addr = (System::UInt64)value;
#else
				System::UInt32 addr = (System::UInt32)value;
#endif

				return NodeD((T*)(addr + (sizeof(T) * fifthSize * index)));
			}

			NodeC& operator=(const NodeC&) = delete;
			NodeC& operator=(NodeC&&) = delete;

			NodeC& operator=(T** data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				for (size_t i = 0; i < fourthSize; ++i)
					memcpy((T*)((UInt64)value + (i * fourthSize * sizeof(T))), data[i], sizeof(T) * fourthSize);

				return *this;
			}
		};
		class NodeD final
		{
			friend class NodeC;

		private:
			T* value = nullptr;

			NodeD(T* value)
			{
				this->value = value;
			}

		public:
			NodeD(const NodeD& n)
			{
				value = n.value;
			}

			NodeD(NodeD&& n)
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

			NodeD& operator=(const NodeD&) = delete;
			NodeD& operator=(NodeD&&) = delete;

			NodeD& operator=(T* data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				memcpy(value, data, sizeof(T) * fifthSize);

				return *this;
			}
		};

	private:
		T* data = nullptr;

	public:
		Array5D()
		{
			data = new T[firstSize * secondSize * thirdSize * fourthSize * fifthSize];
		}

		Array5D(T& fifth_initValue)
			: Array5D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					for (size_t n = 0; n < thirdSize; ++n)
						for (size_t a = 0; a < fourthSize; ++a)
							for (size_t b = 0; b < fifthSize; ++b)
								(*this)[i][j][n][a][b] = fifth_initValue;
		}

		Array5D(T&& fifth_initValue)
			: Array5D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					for (size_t n = 0; n < thirdSize; ++n)
						for (size_t a = 0; a < fourthSize; ++a)
							for (size_t b = 0; b < fifthSize; ++b)
								(*this)[i][j][n][a][b] = fifth_initValue;
		}

		Array5D(const Array5D<T, firstSize, secondSize, thirdSize, fourthSize, fifthSize>& arr)
			: Array5D()
		{
			memcpy(data, arr.data, firstSize * secondSize * thirdSize * fourthSize * fifthSize);
		}

		Array5D(Array5D<T, firstSize, secondSize, thirdSize, fourthSize, fifthSize>&& arr)
		{
			data = arr.data;

			arr.data = nullptr;
		}

		~Array5D()
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

			return NodeA((T*)(addr + (sizeof(T) * fifthSize * fourthSize * thirdSize * secondSize * index)));
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

			return NodeA((T*)(addr + (sizeof(T) * fifthSize * fourthSize * thirdSize * secondSize * index)));
		}
	};
}

#endif