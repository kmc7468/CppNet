#ifndef CPPNET_SYSTEM_COLLECTIONS_GENERIC_IREADONLYCOLLECTION_HPP
#define CPPNET_SYSTEM_COLLECTIONS_GENERIC_IREADONLYCOLLECTION_HPP

#include "../../../../Defines.h"
#include "../../../../Utility.h"

#include "IEnumerable.h"

#include "../../Int32.h"

namespace CppNet::System::Collections::Generic
{
	template<typename T>
	interface IReadOnlyCollection : public IEnumerable<T>
	{
		virtual Int32 Count() const = 0;
	};
}

#endif