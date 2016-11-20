#ifndef CPPNET_SYSTEM_COLLECTIONS_GENERIC_LIST_H
#define CPPNET_SYSTEM_COLLECTIONS_GENERIC_LIST_H

#include <vector>

namespace CppNet::System::Collections::Generic
{
	template<typename T>
	using List = std::vector<T>;
}

#endif