#ifndef CPPNET_SYSTEM_COLLECTIONS_ISTRUCTURALEQUATABLE_HPP
#define CPPNET_SYSTEM_COLLECTIONS_ISTRUCTURALEQUATABLE_HPP

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "IEqualityComparer.hpp"
#include "../Object.h"
#include "../Boolean.h"
#include "../Int32.h"

namespace CppNet::System::Collections
{
	interface IStructuralEquatable
	{
		virtual Boolean Equals(const Object& other, std::unique_ptr<IEqualityComparer> comparer) const = 0;
		virtual Int32 GetHashCode(std::unique_ptr<IEqualityComparer> comparer) const = 0;
	};
}

#endif