#ifndef SYSTEM_COLLECTIONS_GENERIC_QUEUE_H
#define SYSTEM_COLLECTIONS_GENERIC_QUEUE_H

#include "System.h"
#include "IEnumerable.h"
#include "ICollection.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			class Queue : public IEnumerable<T>, public Object
			{
			public:
				Queue();
				Queue(const IEnumerable<T>& collection);
				Queue(Int32 capacity);

			public:
				virtual Boolean IsReadOnly() override;

			public:
				virtual void Clear() override;
				virtual 
			};
		}
	}
}

#endif