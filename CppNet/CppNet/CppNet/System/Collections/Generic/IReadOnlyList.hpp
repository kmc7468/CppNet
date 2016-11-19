#ifndef CPPNET_SYSTEM_COLLECTIONS_GENERIC_IREADONLYLIST_HPP
#define CPPNET_SYSTEM_COLLECTIONS_GENERIC_IREADONLYLIST_HPP

#include "../../../../Defines.h"
#include "../../../../Utility.h"

#include "IReadOnlyCollection.hpp"
#include "../../Int32.h"

namespace CppNet::System::Collections::Generic
{
	template<typename T>
	interface IReadOnlyList : public IReadOnlyCollection<T>
	{
		virtual const T& operator[](Int32 index) const = 0;
		virtual T& operator[](Int32 index) = 0;
	};
}

#endif