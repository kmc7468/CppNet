#ifndef SYSTEM_COLLECTIONS_GENERIC_STACK_H
#define SYSTEM_COLLECTIONS_GENERIC_STACK_H

#include "../../../Defines.h"

#include <deque>
#include "../../../SystemTypes.h"
#include "IEnumerable.h"
#include "IEnumerator.h"
#include "ICollection.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			class Stack : public Object, public IReadOnlyCollection<T>, protected ICollection<T>
			{
			public:
				Stack();
				Stack(IEnumerable<T>& collection);
				//TODO: Stack(Int32 capacity);

			public:
				virtual Int32 Count() const override;
				virtual Boolean Contains(const T& item) const override;

			public:
				virtual void Clear() override;
				virtual std::unique_ptr<IEnumerator<T>> GetEnumerator() override;
				virtual T& Peek();
				virtual T& Pop();
				virtual void Push(const T& item);
				//TODO: ToString
				virtual void TrimExcess();

			public:
				virtual Boolean operator==(const Object& obj) override;
				virtual Boolean operator!=(const Object& obj) override;

			protected:
				virtual void Add(T& item) override;
				virtual Boolean Remove(const T& item) override;
				virtual Boolean IsReadOnly() const override;

			private:
				std::deque<T> stack;

			private:
				struct Enumerator : public IEnumerator<T>
				{
				public:
					Enumerator(Stack<T>& original);

				public:
					virtual T& Current() override;
					virtual Boolean MoveNext() override;
					virtual void Reset() override;

				private:
					Stack<T>& original;
					typename std::deque<T>::iterator iter;
					bool first;

				};
			};
		}
	}
}

#include "Stack.inl"

#endif