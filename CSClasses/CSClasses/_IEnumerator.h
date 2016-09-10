#ifndef SYSTEM_COLLECTIONS_IENUMERATOR_H
#define SYSTEM_COLLECTIONS_IENUMERATOR_H

#include "System.h"

namespace System
{
	namespace Collections
	{
		interface IEnumerator : public Object
		{
			virtual Object& Current() = 0;

			virtual Boolean MoveNext() = 0;

			virtual void Reset() = 0;
		};
	}
}

#endif