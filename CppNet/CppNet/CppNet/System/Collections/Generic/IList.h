#ifndef SYSTEM_COLLECTIONS_GENERIC_ILIST_H
#define SYSTEM_COLLECTIONS_GENERIC_ILIST_H

#include "../../../../Defines.h"

#include "../../Int32.h"

#include "IReadOnlyList.hpp"

namespace CppNet
{
	namespace System
	{
		namespace Collections
		{
			namespace Generic
			{
				template <typename T>
				interface IList : public IReadOnlyList<T>
				{
					virtual const T& operator[](Int32 index) const = 0;
					virtual T& operator[](Int32 index) = 0;

					virtual Int32 IndexOf(const T& item) const = 0;

					virtual void Insert(Int32 index, T& item) = 0;

					virtual void RemoveAt(Int32 index) = 0;
				};
			}
		}
	}
}

#endif