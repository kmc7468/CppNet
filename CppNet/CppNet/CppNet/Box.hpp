#ifndef CPPNET_BOX_HPP
#define CPPNET_BOX_HPP

#include "System/NullReferenceException.hpp"

namespace CppNet
{
	// From
	// https://gist.github.com/kiwiyou/d30cff6f5952aa1c2a6db39b4609124d
	// Thank you!

	template<typename T>
	class Box final
	{
	private:
		T* data = nullptr;
		size_t* ref_count = nullptr;

	public:
		Box()
		{
			data = new T{};
			ref_count = new size_t(1);
		}

		Box(std::nullptr_t null)
		{
			ref_count = new size_t(1);
		}

		Box(const Box<T>& box)
		{
			data = box.data;
			ref_count = box.ref_count;
			++(*ref_count);
		}

		Box(Box<T>&& box)
		{
			data = box.data;
			ref_count = box.ref_count;

			box.data = nullptr;
			box.ref_count = nullptr;
		}

		Box(const T& value)
		{
			data = new T(value);
			ref_count = new size_t(1);
		}

		Box(T&& value)
		{
			data = new T(value);
			ref_count = new size_t(1);
		}

		~Box()
		{
			if (*ref_count == 1)
			{
				if (data)
					delete data;
				delete ref_count;
			}
			else
			{
				--(*ref_count);
				data = nullptr;
			}
		}

	public:
		const T& operator*() const
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		T& operator*()
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		const T* const operator->() const
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		T* operator->()
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		Box<T>& operator=(const T& value)
		{
			if (!data)
			{
				data = new T(value);
				ref_count = new size_t(1);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& operator=(T&& value)
		{
			if (!data)
			{
				data = new T(value);
				ref_count = new size_t(1);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& operator=(std::nullptr_t null)
		{
			if (data)
			{
				data = nullptr;
			}

			return *this;
		}

	public:
		const T& Get() const
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		T& Get()
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		const T* const Data() const
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		T* Data()
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		Box<T>& Set(const T& value)
		{
			if (!data)
			{
				data = new T(value);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& Set(T&& value)
		{
			if (!data)
			{
				data = new T(value);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& Set(std::nullptr_t null)
		{
			if (data)
			{
				data = nullptr;
			}

			return *this;
		}
	};
}

#endif