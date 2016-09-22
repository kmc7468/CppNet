

/*
	2016.09.07
	Created by kmc7468
*/

#ifndef SYSTEM_OBJECT_H
#define SYSTEM_OBJECT_H

#include "Boolean.h"
#include "System/String.h"

namespace System
{
	class Object
	{
	public:
		virtual ~Object() = default;

	public:
		virtual Boolean operator==(const Object& obj);
		virtual Boolean operator!=(const Object& obj);

	public:
		virtual inline Boolean Equals(Object& obj) const;
		static inline Boolean Equals(Object& obj, Object& obj2);

		static inline Boolean ReferenceEquals(Object& obj, Object& obj2);

		virtual inline String ToString() const;
	};
}

#include "Object.inl"

#endif