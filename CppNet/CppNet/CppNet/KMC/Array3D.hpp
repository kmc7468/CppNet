#ifndef CPPNET_KMC_ARRAY3D_HPP
#define CPPNET_KMC_ARRAY3D_HPP

#include "../../Defines.h"

#include "../System/UInt64.h"
#include "../System/UInt32.h"
#include "../System/Object.h"

namespace CppNet::KMC
{
	template<typename T, size_t firstSize, size_t secondSize, size_t thirdSize>
	class Array3D final : public System::Object
	{
	public:
		class NodeB;
		class NodeA final
		{
			friend class Array3D<T, firstSize, secondSize, thirdSize>;

		private:
			T* value = nullptr;

			NodeA(T* value)
			{
				this->value = value;
			}

		public:
			NodeA(NodeA&& n)
			{
				value = n.value;
			}

			NodeA(const NodeA& n)
			{
				value = n.value;
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

				return NodeB((T*)(addr + (sizeof(T) * thirdSize * index)));
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

				return NodeB((T*)(addr + (sizeof(T) * thirdSize * index)));
			}

			NodeA& operator=(const NodeA&) = delete;
			NodeA& operator=(NodeA&&) = delete;

			NodeA& operator=(T** data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				for (size_t i = 0; i < secondSize; ++i)
					memcpy((T*)((UInt64)value + (i * thirdSize * sizeof(T))), data[i], sizeof(T) * thirdSize);

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
			const T& operator[](size_t index) const
			{
				if (index >= thirdSize)
					throw System::IndexOutOfRangeException();

				return value[index];
			}

			T& operator[](size_t index)
			{
				if (index >= thirdSize)
					throw System::IndexOutOfRangeException();

				return value[index];
			}

			NodeB& operator=(const NodeB&) = delete;
			NodeB& operator=(NodeB&&) = delete;

			NodeB& operator=(T* data)
			{
				if (data == nullptr)
					throw System::ArgumentNullException(nameof(data));

				memcpy(value, data, sizeof(T) * thirdSize);

				return *this;
			}
		};

	private:
		T* data = nullptr;

	public:
		Array3D()
		{
			data = new T[firstSize * secondSize * thirdSize];
		}

		Array3D(T& third_initValue)
			: Array3D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					for (size_t n = 0; n < thirdSize; ++n)
						(*this)[i][j][n] = third_initValue;
		}

		Array3D(T&& third_initValue)
			: Array3D()
		{
			for (size_t i = 0; i < firstSize; ++i)
				for (size_t j = 0; j < secondSize; ++j)
					for (size_t n = 0; n < thirdSize; ++n)
						(*this)[i][j][n] = third_initValue;
		}

		Array3D(const Array3D<T, firstSize, secondSize, thirdSize>& arr)
			: Array3D()
		{
			memcpy(data, arr.data, firstSize * secondSize * thirdSize * sizeof(T));
		}

		Array3D(Array3D<T, firstSize, secondSize, thirdSize>&& arr)
			: Array3D()
		{
			data = arr.data;

			arr.data = nullptr;
		}

		~Array3D()
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

			return NodeA((T*)(addr + (sizeof(T) * thirdSize * secondSize * index)));
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

			return NodeA((T*)(addr + (sizeof(T) * thirdSize * secondSize * index)));
		}
	};
}

#endif