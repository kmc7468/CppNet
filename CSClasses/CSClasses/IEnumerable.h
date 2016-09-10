#ifndef SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H
#define SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H

#include "System.h"

namespace System
{
	namespace Collections
	{
		interface IEnumerable;

		namespace Generic
		{
			template <typename T>
			interface IEnumerable : Collections::IEnumerable
			{
			};
		}
	}
}

#endif
