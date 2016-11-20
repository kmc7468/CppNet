#ifndef SYSTEM_COLLECTIONS_GENERIC_QUEUE_H
#define SYSTEM_COLLECTIONS_GENERIC_QUEUE_H

#include "../../../../Defines.h"

#include <deque>
#include "../../../../SystemTypes.h"
#include "IEnumerator.h"
#include "ICollection.h"

namespace CppNet
{
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
					//TODO: Queue(Int32 capacity);

				public:
					virtual Int32 Count() const override;
					virtual Boolean Contains(const T& item) const override;

				public:
					virtual void Clear() override;
					virtual T& Dequeue();
					virtual void Enqueue(const T& item);
					virtual Box<IEnumerator<T>> GetEnumerator() override;
					virtual T& Peek();
					//TODO: ToString();
					virtual void TrimExcess();

				public:
					virtual Boolean operator==(const Object& obj) override;
					virtual Boolean operator!=(const Object& obj) override;

				protected:
					virtual void Add(T& item) override;
					virtual Boolean Remove(const T& item) override;
					virtual Boolean IsReadOnly() const override;

				private:
					std::deque<T> queue;

				private:
					class Enumerator : public IEnumerator<T>
					{
					public:
						virtual T& Current() override;
						virtual Boolean MoveNext() override;
						virtual void Reset() override;

					public:
						Enumerator(Queue<T>& original);

					private:
						Queue<T>& original;
						typename std::deque<T>::iterator iter;
						bool first;
					};
				};
			}
		}
	}
}

#include "Queue.inl"

#endif