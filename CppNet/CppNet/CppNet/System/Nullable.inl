#include "Nullable.h"

#include "InvalidOperationException.h"

namespace CppNet
{
	namespace System
	{
		template<typename T>
		Nullable<T>::Nullable()
		{
			value = new T(T{});
		}

		template<typename T>
		Nullable<T>::Nullable(std::nullptr_t t)
		{
			value = new T(T{});
		}

		template<typename T>
		Nullable<T>::Nullable(const T& value)
		{
			this->value = new T(value);
			hasvalue = true;
		}

		template<typename T>
		Nullable<T>::Nullable(const Nullable<T>& n)
		{
			value = new T(*(n.value));
			hasvalue = n.hasvalue;
		}

		template<typename T>
		Nullable<T>::Nullable(Nullable<T>&& n)
		{
			value = new T(std::move(*(n.value)));
			hasvalue = std::move(n.hasvalue);
		}

		template<typename T>
		Nullable<T>::~Nullable()
		{
			if (value)
				delete value;
		}

		template<typename T>
		Boolean Nullable<T>::HasValue() const
		{
			return hasvalue;
		}

		template<typename T>
		const T& Nullable<T>::Value() const
		{
			if (!hasvalue)
				throw InvalidOperationException();
			// FIXME 언어

			return *value;
		}

		template<typename T>
		T& Nullable<T>::Value()
		{
			if (!hasvalue)
				throw InvalidOperationException();
			// FIXME 언어

			return *value;
		}

		template<typename T>
		const T& Nullable<T>::GetValueOrDefault() const
		{
			return *value;
		}

		template<typename T>
		T& Nullable<T>::GetValueOrDefault()
		{
			return *value;
		}

		template<typename T>
		const T& Nullable<T>::GetValueOrDefault(const T& def) const
		{
			if (hasvalue)
				return *value;
			else
				return T(def);
		}

		template<typename T>
		T& Nullable<T>::GetValueOrDefault(const T& def)
		{
			if (hasvalue)
				return *value;
			else
				return T(def);
		}

		template<typename T>
		Nullable<T>& Nullable<T>::operator=(const T& value)
		{
			hasvalue = true;

			*(this->value) = value;

			return *this;
		}

		template<typename T>
		Nullable<T>& Nullable<T>::operator=(T&& value)
		{
			hasvalue = true;

			*(this->value) = std::move(value);

			return *this;
		}

		template<typename T>
		Nullable<T>& Nullable<T>::operator=(std::nullptr_t t)
		{
			hasvalue = false;

			*(this->value) = T{};

			return *this;
		}

		template<typename T>
		Nullable<T> Nullable<T>::DeepCopy() const
		{
			return *this;
		}

		template<typename T>
		Nullable<T> Nullable<T>::ShallowCopy() const
		{
			Nullable<T> t;

			t.value = value;
			t.hasvalue = hasvalue;

			return t;
		}
	}
}