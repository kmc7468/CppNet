#include "Object.h"

namespace System
{
	Object::~Object() { }

	Boolean Object::operator==(const Object& obj)
	{
		if (&obj == this) return true;
		else return false;
	}

	Boolean Object::operator!=(const Object& obj)
	{
		if (&obj == this) return false;
		else return true;
	}

	Boolean Object::Equals(Object& obj) const
	{
		return obj == *const_cast<Object*>(this);
	}

	Boolean Object::Equals(Object& obj, Object& obj2)
	{
		return obj == obj2;
	}

	Boolean Object::ReferenceEquals(Object& obj, Object& obj2)
	{
		if (&obj == &obj2) return true;
		else return false;
	}

	String Object::ToString() const
	{
		return L"";
	}
}