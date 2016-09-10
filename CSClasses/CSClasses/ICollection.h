#ifndef SYSTEM_COLLECTIONS_GENERIC_ICOLLECTION_H
#define SYSTEM_COLLECTIONS_GENERIC_ICOLLECTION_H

#include "System.h"
#include "IEnumerable.h"

#include <array>

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			interface IReadOnlyCollection : public IEnumerable<T>
			{
				virtual Int32 Count() const = 0;
			};

			template <typename T>
			interface ICollection : public IReadOnlyCollection<T>
			{
				virtual Boolean IsReadOnly() const = 0;

				virtual void Add(T& item) = 0;

				virtual void Clear() = 0;


				//template <size_t _Size>
				//virtual void CopyTo(std::array<T, _Size> array, Int32 arrayIndex) = 0;

				virtual Boolean Remove(const T& item) = 0;

				virtual Boolean Contains(const T& item) const = 0;
			};
		}
	}
}

#endif
