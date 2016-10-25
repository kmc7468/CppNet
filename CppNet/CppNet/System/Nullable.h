#ifndef SYSTEM_NULLABLE_H
#define SYSTEM_NULLABLE_H

#include "Object.h"

namespace System
{
	template<typename T>
	class Nullable : public Object
	{
	private:
		Boolean hasValue = false;
		T value{};

	public:
		Nullable(const T& val);
		~Nullable() = default;

		Boolean HasValue() const;

		const T& Value() const;
		T& Value();

		const T& GetValueOrDefault() const;
		T& GetValueOrDefault();

		const T& GetValueOrDefault(const T& def_value) const;
		T& GetValueOrDefault(T& def_value);

		Boolean Equals(Object& obj) const override;
	};
}

#include "Nullable.inl"

#endif