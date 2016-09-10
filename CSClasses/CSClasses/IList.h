#ifndef SYSTEM_COLLECTIONS_GENERIC_ILIST_H
#define SYSTEM_COLLECTIONS_GENERIC_ILIST_H

#include "System.h"
#include "ICollection.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			interface IList : public ICollection<T>
			{
				virtual T& operator[](Int32 index) = 0;

				virtual Int32 IndexOf(const T& item) = 0;

				virtual void Insert(Int32 index, T& item) = 0;

				virtual void RemoveAt(Int32 index) = 0;
			};
		}
	}
}

#endif