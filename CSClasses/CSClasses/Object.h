

/*
	2016.09.07
	Created by kmc7468
*/

#ifndef SYSTEM_OBJECT_H
#define SYSTEM_OBJECT_H

#include "System.h"

namespace System
{
	class Object
	{
	public:
		virtual ~Object()
		{

		}
		
		virtual Boolean operator==(const Object& obj)
		{
			if (&obj == this) return true;
			else return false;
		}

		virtual Boolean operator!=(const Object& obj)
		{
			if (&obj == this) return false;
			else return true;
		}

		virtual inline Boolean Equals(Object& obj) const
		{
			return obj == *const_cast<Object*>(this);
		}

		static inline Boolean Equals(Object& obj, Object& obj2)
		{
			return obj == obj2;
		}

		static inline Boolean ReferenceEquals(Object& obj, Object& obj2)
		{
			if (&obj == &obj2) return true;
			else return false;
		}

		virtual inline String ToString() const
		{
			return L"";
		}
	};
}

#endif