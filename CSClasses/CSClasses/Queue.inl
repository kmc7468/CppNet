#include <algorithm>
#include "Queue.h"

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
					queue.push(e->Current());
			}

			template<typename T>
			Int32 Queue<T>::Count() const
			{
				return static_cast<Int32>(queue.size());
			}
			template<typename T>
			Boolean Queue<T>::Contains(const T& item) const
			{
				return std::find(queue._Get_container().cbegin(), queue._Get_container().cend(), item) != queue._Get_container().cend();
			}

			template<typename T>
			void Queue<T>::Clear()
			{
				while (!queue.empty())
					queue.pop();
			}
			template<typename T>
			T& Queue<T>::Dequeue()
			{
				T& data = queue.front();
				queue.pop();
				return data;
			}
			template<typename T>
			void Queue<T>::Enqueue(const T& item)
			{
				queue.push(item);
			}
			template<typename T>
			inline std::unique_ptr<IEnumerator<T>> Queue<T>::GetEnumerator()
			{
				return nullptr;
			}
			template<typename T>
			T& Queue<T>::Peek()
			{
				return queue.back();
			}
			template<typename T>
			void Queue<T>::TrimExcess()
			{
				throw NotImplementedException();
			}
			
			template<typename T>
			Boolean Queue<T>::operator==(const Object & obj)
			{
				return (typeid(Queue<T>) == typeid(obj)) && (queue.size() == dynamic_cast<const Queue<T>&>(obj).queue.size()) && std::equal(queue._Get_container().cbegin(), queue._Get_container().cend(), dynamic_cast<const Queue<T>&>(obj).queue._Get_container().cbegin());
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
			Boolean Queue<T>::Remove(const T & item)
			{
				throw NotImplementedException();
			}
			template<typename T>
			Boolean Queue<T>::IsReadOnly() const
			{
				return false;
			}
		}
	}
}