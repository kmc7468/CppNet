#ifndef SYSTEM_COLLECTIONS_GENERIC_H
#define SYSTEM_COLLECTIONS_GENERIC_H

#include "System.h"

#include "ICollection.h"
#include "IEnumerable.h"
#include "IList.h"

#include <vector>
#include <map>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template<class T>
			using List = std::vector<T>;

			template<class TKey, class TValue>
			using Dictionary = std::map<TKey, TValue>;
		}
	}
}

#endif