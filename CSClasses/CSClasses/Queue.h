#ifndef SYSTEM_COLLECTIONS_GENERIC_QUEUE_H
#define SYSTEM_COLLECTIONS_GENERIC_QUEUE_H

#include <queue>
#include "SystemTypes.h"
#include "ICollection.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			class Queue : public IReadOnlyCollection<T>, protected ICollection<T>
			{
			public:
				Queue();
				Queue(const IEnumerable<T>& collection);
				Queue(Int32 capacity);

			public:
				virtual Int32 Count() const override;
				virtual Boolean Contains(const T& item) const override;

			public:
				virtual void Clear() override;
				virtual T& Dequeue();
				virtual void Enqueue(T& item);
				virtual std::unique_ptr<IEnumerator<T>> GetEnumerator() override;
				virtual T& Peek();
				//TODO: ToString();
				virtual void TrimExcess();

			public:
				//virtual Boolean operator==(const Object& obj) override;
				//virtual Boolean operator!=(const Object& obj) override;

			private:
				std::queue<T> queue;

			private:
				virtual void Add(T& item) override;
				virtual Boolean Remove(const T& item) override;
				virtual Boolean IsReadOnly() const override;

			};
		}
	}
}

#include "Queue.inl"

#endif