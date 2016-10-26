#ifndef SYSTEM_COLLECTIONS_IENUMERATOR_H
#define SYSTEM_COLLECTIONS_IENUMERATOR_H

#include "../../../Defines.h"

#include "../System.h"

namespace CppNet
{
	namespace System
	{
		namespace Collections
		{
			interface IEnumerator
			{
				virtual Object& Current() = 0;

				virtual Boolean MoveNext() = 0;

				virtual void Reset() = 0;
			};
		}
	}
}

#endif