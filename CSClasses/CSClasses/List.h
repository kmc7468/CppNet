#ifndef SYSTEM_COLLECTIONS_GENERIC_LIST_H
#define SYSTEM_COLLECTIONS_GENERIC_LIST_H

#include "System.Collections.Generic.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template<typename T>
			class List : public Object
			{
			public:
				explicit List() = default;
				explicit List(Int32 size)
				{
					max = size;
				}
				explicit List(T* arr)
				{
					this->array = arr;
				}
				List(List<T> &&sNewList)
				{
					this->array = sNewList.array;
				}
				List(const List<T> &sNewList)
				{
					this->array = sNewList.array;
				}
				~List() = default;

			public:
				List<T> &operator=(List<T> &&sNewList)
				{
					return List<T>(sNewList);
				}

				List<T> &operator=(const List<T> &sNewList)
				{
					return List<T>(sNewList);
				}

				T &operator[](int index)
				{
					if (index > sizeof(array) / sizeof(T) - 1)
						return 0;
						// TODO throw OutOfIndexException

					return array[index];
				}

			private:
				T* array = nullptr;
				Int32 max = -1;

			public:
				Int32 Count() const
				{
					return sizeof(array) / sizeof(T);
				}

				Int32 Capactiy() const
				{
					return max;
				}
			};
		}
	}
}

#endif