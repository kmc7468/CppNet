#ifndef CPPNET_KMC_ARRAYND_HPP
#define CPPNET_KMC_ARRAYND_HPP

#include "../../Defines.h"
#include "../../Utility.h"

#include "../System/Object.h"
#include "../System/UInt64.h"
#include "../System/UInt32.h"
#include "../System/NullReferenceException.hpp"
#include "../System/IndexOutOfRangeException.hpp"

#include "../CTR/MultiPointer.hpp"

#include <vector>

namespace CppNet::KMC
{
	template<typename T, size_t... sizes>
	class ArrayND final : public System::Object
	{
	public:
#pragma region GetAllocSize
		// http://blog.naver.com/neurowhai/220872262256 를 참고하였습니다.
		// 감사합니다!

		template <size_t... _sizes>
		struct _AllocSize
		{
			enum : size_t { value = __AllocSize<sizeof...(_sizes), _sizes...>::value };
		};

		template <size_t left, size_t size, size_t... _sizes>
		struct __AllocSize
		{
			enum : size_t { value = size * __AllocSize<left - 1, _sizes...>::value };
		};

		template <size_t size, size_t... _sizes>
		struct __AllocSize<1, size, _sizes...>
		{
			enum : size_t { value = size };
		};
#pragma endregion
#pragma region NthSize
		// http://blog.naver.com/neurowhai/220872262256 를 참고하였습니다.
		// 감사합니다!

		template <size_t index, size_t size, size_t... SIZES>
		class GetNthSize
		{
		public:
			enum : size_t { value = GetNthSize<index - 1, SIZES...>::value };
		};

		template <size_t size, size_t... SIZES>
		class GetNthSize<0, size, SIZES...>
		{
		public:
			enum : size_t { value = size };
		};

		template <std::size_t index>
		using NthSize = GetNthSize<index, sizes...>;

#pragma endregion

	public:
		static constexpr size_t TotalSize = _AllocSize<sizes...>::value;
		static constexpr size_t AllocSize = TotalSize * sizeof(T);
		static constexpr size_t ND = sizeof...(sizes);
		static const std::vector<size_t> Arguments;

	private:
#pragma region Mul
		template<size_t index>
		struct Mul
		{
			enum : size_t
			{
				value = NthSize<index>::value * Mul<index + 1>::value
			};
		};

		template<>
		struct Mul<ND - 1>
		{
			enum : size_t
			{
				value = NthSize<ND - 1>::value
			};
		};
#pragma endregion

		T* data = nullptr;

	public:
#pragma region Node
		template<size_t index>
		class Node final
		{
			friend class ArrayND<T, sizes...>;
			friend class Node<index + 1>;
			friend class Node<index - 1>;

		private:
			T* val = nullptr;

			Node(T* val)
			{
				this->val = val;
			}

		public:
			Node(const Node<index>& n)
			{
				val = n.val;
			}

			Node(Node<index>&& n)
			{
				val = n.val;
			}

		public:
			const Node<index + 1> operator[](size_t inx) const
			{
				if (inx >= NthSize<index>::value)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 address = (System::UInt64)val;
#else
				System::UInt32 address = (System::UInt32)val;
#endif

				address += (inx * Mul<index + 2>::value);

				return Node<index + 1>((T*)address);
			}

			Node<index + 1> operator[](size_t inx)
			{
				if (inx >= NthSize<index>::value)
					throw System::IndexOutOfRangeException();

#ifdef BIT_64
				System::UInt64 address = (System::UInt64)val;
#else
				System::UInt32 address = (System::UInt32)val;
#endif

				address += (inx * Mul<index + 2>::value);

				return Node<index + 1>((T*)address);
			}

			Node<index>& operator=(const Node<index>&) = delete;
			Node<index>& operator=(Node<index>&&) = delete;

			Node<index>& operator=(typename CTR::MultiPointer<T, sizeof...(sizes)-index - 1>::Type dat)
			{
				const size_t temp = Arguments[index + 1];

				for (size_t i = 0; i < temp; ++i)
				{
					(*this)[i] = dat[i];
				}

				return *this;
			}
		};

		template<>
		class Node<ND - 2> final
		{
			friend class ArrayND<T, sizes...>;
			friend class Node<ND - 3>;

		private:
			T* val = nullptr;

			Node(T* val)
			{
				this->val = val;
			}

		public:
			Node(const Node<ND - 2>& n)
			{
				val = n.val;
			}

			Node(Node<ND - 2>&& n)
			{
				val = n.val;
			}

		public:
			inline const T& operator[](size_t index) const
			{
				if (index >= NthSize<ND - 2>::value)
					throw System::IndexOutOfRangeException();

				return val[index];
			}

			inline T& operator[](size_t index)
			{
				if (index >= NthSize<ND - 2>::value)
					throw System::IndexOutOfRangeException();

				return val[index];
			}

			Node<ND - 2>& operator=(const Node<ND - 2>&) = delete;
			Node<ND - 2>& operator=(Node<ND - 2>&&) = delete;

			Node<ND - 2>& operator=(typename CTR::MultiPointer<T, sizeof...(sizes)-(ND - 2) - 1>::Type dat)
			{
				memcpy(val, dat, NthSize<ND - 1>::value * sizeof(T));

				return *this;
			}
		};
#pragma endregion

	public:
		ArrayND()
		{
			data = new T[TotalSize];
		}

		ArrayND(T& initData)
			: ArrayND()
		{
			T* ptr = data;
			for (size_t i = 0; i < TotalSize; ++i)
			{
				*ptr = initData;
				ptr++;
			}
		}

		ArrayND(T&& initData)
			: ArrayND()
		{
			T* ptr = data;
			for (size_t i = 0; i < TotalSize; ++i)
			{
				*ptr = initData;
				ptr++;
			}
		}

		ArrayND(const ArrayND<T, sizes...>& arr)
			: ArrayND()
		{
			memcpy(data, arr.data, AllocSize);
		}

		ArrayND(ArrayND<T, sizes...>&& arr)
		{
			data = arr.data;
			arr.data = nullptr;
		}

		~ArrayND()
		{
			if (data)
				delete[] data;
		}

	public:
		const Node<0> operator[](size_t index) const
		{
			if (data == nullptr)
				throw System::NullReferenceException();
			else if (index >= Arguments[0])
				throw System::IndexOutOfRangeException();

#ifdef BIT_64
			System::UInt64 address = (System::UInt64)data;
#else
			System::UInt32 address = (System::UInt32)data;
#endif

			address += (index * Mul<1>::value);

			return Node<0>((T*)address);
		}

		Node<0> operator[](size_t index)
		{
			if (data == nullptr)
				throw System::NullReferenceException();
			else if (index >= Arguments[0])
				throw System::IndexOutOfRangeException();

#ifdef BIT_64
			System::UInt64 address = (System::UInt64)data;
#else
			System::UInt32 address = (System::UInt32)data;
#endif

			address += (index * Mul<1>::value);

			return Node<0>((T*)address);
		}

		ArrayND<T, sizes...>& operator=(const ArrayND<T, sizes...>& arr)
		{
			if (data == nullptr)
				data = new T[TotalSize];

			memcpy(data, arr.data, AllocSize);

			return *this;
		}

		ArrayND<T, sizes...>& operator=(ArrayND<T, sizes...>&& arr)
		{
			data = arr.data;
			arr.data = nullptr;

			return *this;
		}

		ArrayND<T, sizes...>& operator=(typename CTR::MultiPointer<T, sizeof...(sizes)>::Type dat)
		{
			if (data == nullptr)
				data = new T[TotalSize];

			const size_t temp = Arguments[0];

			for (size_t i = 0; i < temp; ++i)
			{
				(*this)[i] = dat[i];
			}

			return *this;
		}
	};
}

#include "ArrayND.inl"

#endif