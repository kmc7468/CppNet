#ifndef SYSTEM_COLLECTIONS_ICOLLECTION_H
#define SYSTEM_COLLECTIONS_ICOLLECTION_H

#include "Int32.h"
#include "Boolean.h"
#include "Object.h"

#include "_IEnumerable.h"

#include <array>

namespace System
{
	namespace Collections
	{
		interface ICollection : public IEnumerable
		{
			virtual Int32 Count() const = 0;

			virtual Boolean IsSynchronized() const = 0;

			virtual Object SyncRoot() const = 0;

			//template <typename T, size_t _Size>
			//virtual void CopyTo(std::array<T, _Size> array, Int32 index) = 0;


		};
	}
}

#endif