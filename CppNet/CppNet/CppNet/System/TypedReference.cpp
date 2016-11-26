#include "TypedReference.h"

#include "NotSupportedException.h"

namespace CppNet::System
{
	Boolean TypedReference::Equals(const Object& obj) const
	{
		throw NotSupportedException();
	}
}