#ifndef CPPNET_SYSTEM_COLLECTIONS_ICOMPARER_HPP
#define CPPNET_SYSTEM_COLLECTIONS_ICOMPARER_HPP

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../Int32.h"
#include "../Object.h"

namespace CppNet::System::Collections
{
	interface IComparer
	{
		virtual Int32 Compare(const Object& x, const Object& y) const = 0;
	};
}

#endif