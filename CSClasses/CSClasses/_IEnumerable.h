#ifndef SYSTEM_COLLECTIONS_IENUMERABLE_H
#define SYSTEM_COLLECTIONS_IENUMERABLE_H

#include "System.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			interface IEnumerable;
		}

		interface IEnumerable : public Object
		{
			//TODO: GetEnumerator

			//FIXME: 이걸 어찌 해야 할까요...
			template <typename TResult>
			virtual Generic::IEnumerable<TResult> Cast() = 0;

			template <typename TResult>
			virtual Generic::IEnumerable<TResult> OfType() = 0;

		};
	}
}

#endif