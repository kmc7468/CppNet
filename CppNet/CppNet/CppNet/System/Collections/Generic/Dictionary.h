#ifndef CPPNET_SYSTEM_COLLECTIONS_GENERIC_DICTIONARY_H
#define CPPNET_SYSTEM_COLLECTIONS_GENERIC_DICTIONARY_H

#include <map>

namespace CppNet::System::Collections::Generic
{
	template<typename TKey, typename TValue>
	using Dictionary = std::map<TKey, TValue>;
}

#endif