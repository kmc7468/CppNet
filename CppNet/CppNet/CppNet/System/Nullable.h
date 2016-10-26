#ifndef CPPNET_SYSTEM_NULLABLE_H
#define CPPNET_SYSTEM_NULLABLE_H

#include "Object.h"
#include "../ICopy.h"

namespace CppNet
{
	namespace System
	{
		template<typename T>
		class Nullable final : public Object, public ICopy<Nullable<T>>
		{
		private:
			T* value = nullptr;
			Boolean hasvalue = false;
			
		public:
			Nullable();
			Nullable(std::nullptr_t t);
			Nullable(const T& value);
			Nullable(const Nullable<T>& n);
			Nullable(Nullable<T>&& n);
			~Nullable();

			Boolean HasValue() const;
			const T& Value() const;
			T& Value();

			const T& GetValueOrDefault() const;
			T& GetValueOrDefault();

			const T& GetValueOrDefault(const T& def) const;
			T& GetValueOrDefault(const T& def);

			Nullable<T>& operator=(const T& value);
			Nullable<T>& operator=(T&& value);

			Nullable<T>& operator=(std::nullptr_t t);

		public:
			Nullable<T> DeepCopy() const override;
			Nullable<T> ShallowCopy() const override;
		};
	}
}

#include "Nullable.inl"

#endif