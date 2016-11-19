#ifndef CPPNET_SYSTEM_COLLECTIONS_IEQUALITYCOMPARER_HPP
#define CPPNET_SYSTEM_COLLECTIONS_IEQUALITYCOMPARER_HPP

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../Object.h"
#include "../Int32.h"
#include "../Boolean.h"

namespace CppNet::System::Collections
{
	interface IEqualityComparer
	{
		virtual Boolean Equals(const Object& x, const Object& y) const = 0;
		virtual Int32 GetHashCode(const Object& obj) const = 0;
	};
}

#endif