#ifndef CPPNET_SYSTEM_COLLECTIONS_ISTRUCTURALCOMPARABLE_HPP
#define CPPNET_SYSTEM_COLLECTIONS_ISTRUCTURALCOMPARABLE_HPP

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../Int32.h"
#include "../Object.h"

#include "IComparer.hpp"

#include <memory>

namespace CppNet::System::Collections
{
	interface IStructuralComparable
	{
		virtual Int32 CompareTo(const Object& other, std::unique_ptr<IComparer> comparer) const = 0;
	};
}

#endif