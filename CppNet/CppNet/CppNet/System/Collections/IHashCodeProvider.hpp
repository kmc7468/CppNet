#ifndef CPPNET_SYSTEM_COLLECTIONS_IHASHCODEPROVIDER_HPP
#define CPPNET_SYSTEM_COLLECTIONS_IHASHCODEPROVIDER_HPP

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../Object.h"
#include "../Int32.h"

namespace CppNet::System::Collections
{
	interface IHashCodeProvider
	{
		virtual Int32 GetHashCode(const Object& obj) const = 0;
	};
}

#endif