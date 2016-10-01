#include <algorithm>
#include "../../InvalidOperationException.h"
#include "Queue.h"
#include "Stack.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			Queue<T>::Queue()
			{
			}

			template <typename T>
			Queue<T>::Queue(const IEnumerable<T>& collection)
			{
				for (auto e = collection.GetEnumerator(); e->MoveNext();)
					queue.push_back(e->Current());
			}

			template<typename T>
			Int32 Queue<T>::Count() const
			{
				return static_cast<Int32>(queue.size());
			}
			template<typename T>
			Boolean Queue<T>::Contains(const T& item) const
			{
				return std::find(queue.cbegin(), queue.cend(), item) != queue.cend();
			}

			template<typename T>
			void Queue<T>::Clear()
			{
				queue.clear();
			}
			template<typename T>
			T& Queue<T>::Dequeue()
			{
				T& front = queue.front();
				queue.pop_front();
				return front;
			}
			template<typename T>
			void Queue<T>::Enqueue(const T& item)
			{
				queue.push_back(item);
			}
			template<typename T>
			inline std::unique_ptr<IEnumerator<T>> Queue<T>::GetEnumerator()
			{
				return std::make_unique<Enumerator>(*this);
			}
			template<typename T>
			T& Queue<T>::Peek()
			{
				return queue.front();
			}
			template<typename T>
			void Queue<T>::TrimExcess()
			{
				queue.shrink_to_fit();
			}

			template<typename T>
			Boolean Queue<T>::operator==(const Object & obj)
			{
				return (typeid(Queue<T>) == typeid(obj)) && (queue.size() == dynamic_cast<const Queue<T>&>(obj).queue.size()) && std::equal(queue.cbegin(), queue.cend(), dynamic_cast<const Queue<T>&>(obj).queue.cbegin());
			}
			template<typename T>
			inline Boolean Queue<T>::operator!=(const Object & obj)
			{
				return !this->operator==(obj);
			}

			template<typename T>
			void Queue<T>::Add(T& item)
			{
				this->Enqueue(item);
			}
			template<typename T>
			Boolean Queue<T>::Remove(const T& item)
			{
				auto it = std::find(queue.begin(), queue.end(), item);
				if (it == queue.end())
					return false;
				queue.erase(it);
				return true;
			}
			template<typename T>
			Boolean Queue<T>::IsReadOnly() const
			{
				return false;
			}

			template <typename T>
			T& Queue<T>::Enumerator::Current()
			{
				if (first || iter == original.queue.end())
					throw InvalidOperationException();
				return *iter;
			}

			template<typename T>
			void Queue<T>::Enumerator::Dispose()
			{
				//NOTE: nothing
			}
			template<typename T>
			Boolean Queue<T>::Enumerator::MoveNext()
			{
				if (first)
					return !(first = false);
				if (++iter == original.queue.end())
					return false;
				return true;
			}

			template<typename T>
			void Queue<T>::Enumerator::Reset()
			{
				iter = original.queue.begin();
				first = true;
			}

			template<typename T>
			Queue<T>::Enumerator::Enumerator(Queue<T>& original)
				: original(original), iter(original.queue.begin()), first(true)
			{
			}
		}
	}
}