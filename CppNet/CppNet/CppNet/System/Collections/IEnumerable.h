#ifndef SYSTEM_COLLECTIONS_IENUMERABLE_H
#define SYSTEM_COLLECTIONS_IENUMERABLE_H

#include "../../../Defines.h"

#include <memory>

#include "../System.h"
#include "IEnumerator.h"

namespace CppNet
{
	namespace System
	{
		namespace Collections
		{
			interface IEnumerable
			{
				virtual std::unique_ptr<IEnumerator> GetEnumerator() = 0;

				//FIXME: 이걸 어찌 해야 할까요...
				//template <typename TResult>
				//virtual Generic::IEnumerable<TResult> Cast() = 0;

				//template <typename TResult>
				//virtual Generic::IEnumerable<TResult> OfType() = 0;

			};
		}
	}
}

#endif