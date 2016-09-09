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
			interface ICollection : public IEnumerable<T>
			{
				//NOTE: Count 프로퍼티와 확장 Count()가 충돌하므로 제외.

				virtual Boolean IsReadOnly() = 0;

				virtual void Add(const T& item)  = 0;

				virtual void Clear() = 0;

				//NOTE: Contains 중복

				template <size_t _Size>
				virtual void CopyTo(std::array<T, _Size> array, Int32 arrayIndex) = 0;

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