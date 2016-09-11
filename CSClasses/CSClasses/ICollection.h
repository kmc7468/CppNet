#ifndef SYSTEM_COLLECTIONS_GENERIC_ICOLLECTION_H
#define SYSTEM_COLLECTIONS_GENERIC_ICOLLECTION_H

#include "SystemType.h"
#include "IEnumerable.h"

#include <array>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			interface ICollection : public IEnumerable<T>
			{

				virtual Boolean IsReadOnly() = 0;

				virtual void Add(const T& item)  = 0;

				virtual void Clear() = 0;


				//template <size_t _Size>
				//virtual void CopyTo(std::array<T, _Size> array, Int32 arrayIndex) = 0;

				virtual Boolean Remove(const T& item) = 0;

			};

			template <typename T>
			interface IReadOnlyCollection : public IEnumerable<T>
			{
			};
		}
	}
}

#endif
