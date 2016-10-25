#include "Nullable.h"

namespace System
{
	template<typename T>
	Nullable<T>::Nullable(const T& val)
		: value(val)
	{
		hasValue = true;
	}

	template<typename T>
	Boolean Nullable<T>::HasValue() const
	{
		return hasValue;
	}

	template<typename T>
	const T& Nullable<T>::Value() const
	{
		if (!hasValue)
			throw InvalidOperationException();
		// FIXME Lang

		return value;
	}

	template<typename T>
	T& Nullable<T>::Value()
	{
		if (!hasValue)
			throw InvalidOperationException();
		// FIXME Lang

		return value;
	}

	template<typename T>
	const T& Nullable<T>::GetValueOrDefault() const
	{
		return value;
	}

	template<typename T>
	T& Nullable<T>::GetValueOrDefault()
	{
		return value;
	}

	template<typename T>
	const T& Nullable<T>::GetValueOrDefault(const T& def_value) const
	{
		return hasValue ? value : def_value;
	}

	template<typename T>
	T& Nullable<T>::GetValueOrDefault(T& def_value)
	{
		return hasValue ? value : def_value;
	}

	template<typename T>
	Boolean Nullable<T>::Equals(Object& obj) const
	{
		return Boolean();
	}
}