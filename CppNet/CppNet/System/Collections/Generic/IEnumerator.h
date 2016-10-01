#ifndef SYSTEM_COLLECTIONS_GENERIC_IENUMERATOR_H
#define SYSTEM_COLLECTIONS_GENERIC_IENUMERATOR_H

#include "../../System.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			interface IEnumerator : public Object
			{
				virtual T& Current() = 0;

				virtual Boolean MoveNext() = 0;

				virtual void Reset() = 0;
			};
		}
	}
}

#endif