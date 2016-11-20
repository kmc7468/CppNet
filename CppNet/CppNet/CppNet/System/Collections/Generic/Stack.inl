#include "../../InvalidOperationException.h"
#include "Stack.h"

namespace CppNet
{
	namespace System
	{
		namespace Collections
		{
			namespace Generic
			{
				template <typename T>
				Stack<T>::Stack()
				{
				}

				template<typename T>
				Stack<T>::Stack(IEnumerable<T>& collection)
				{
					var e = collection.GetEnumerator();
					while (e->MoveNext())
						stack.push_front(e->Current());
				}

				template<typename T>
				Int32 Stack<T>::Count() const
				{
					return stack.size();
				}

				template<typename T>
				Boolean Stack<T>::Contains(const T& item) const
				{
					return std::find(stack.cbegin(), stack.cend(), item) != stack.cend();
				}

				template<typename T>
				void Stack<T>::Clear()
				{
					stack.clear();
				}

				template<typename T>
				Box<IEnumerator<T>> Stack<T>::GetEnumerator()
				{
					return Box<IEnumerator<T>>(new Stack<T>::Enumerator(*this));
				}

				template<typename T>
				T& Stack<T>::Peek()
				{
					return stack.front();
				}

				template<typename T>
				T& Stack<T>::Pop()
				{
					var ret = stack.front();
					stack.pop_front();
					return ret;
				}

				template<typename T>
				void Stack<T>::Push(const T& item)
				{
					stack.push_front(item);
				}

				template<typename T>
				void Stack<T>::TrimExcess()
				{
					stack.shrink_to_fit();
				}

				template<typename T>
				Boolean Stack<T>::operator==(const Object& obj)
				{
					return (typeid(Stack<T>) == typeid(obj)) && (stack.size() == dynamic_cast<const Stack<T>&>(obj).stack.size()) && std::equal(stack.cbegin(), stack.cend(), dynamic_cast<const Stack<T>&>(obj).stack.cbegin());
				}

				template<typename T>
				Boolean Stack<T>::operator!=(const Object& obj)
				{
					return !this->operator==(obj);
				}

				template<typename T>
				void Stack<T>::Add(T& item)
				{
					this->Push(item);
				}

				template<typename T>
				Boolean Stack<T>::Remove(const T& item)
				{
					auto it = std::find(stack.begin(), stack.end(), item);
					if (it == stack.end())
						return false;
					stack.erase(it);
					return true;
				}

				template<typename T>
				Boolean Stack<T>::IsReadOnly() const
				{
					return false;
				}

				template<typename T>
				Stack<T>::Enumerator::Enumerator(Stack<T>& original)
					: original(original), iter(original.stack.begin()), first(true)
				{
				}

				template<typename T>
				T& Stack<T>::Enumerator::Current()
				{
					if (first || iter == original.stack.end())
						throw InvalidOperationException();
					return *iter;
				}

				template<typename T>
				Boolean Stack<T>::Enumerator::MoveNext()
				{
					if (first)
						return !(first = false);
					if (++iter == original.stack.end())
						return false;
					return true;
				}

				template<typename T>
				void Stack<T>::Enumerator::Reset()
				{
					iter = original.stack.begin();
					first = true;
				}
			}
		}
	}
}