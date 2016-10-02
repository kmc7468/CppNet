#include "Object.h"

namespace System
{
	Boolean Object::operator==(const Object& obj) const
	{
		if (&obj == this) return true;
		else return false;
	}

	Boolean Object::operator!=(const Object& obj) const
	{
		if (&obj == this) return false;
		else return true;
	}
}