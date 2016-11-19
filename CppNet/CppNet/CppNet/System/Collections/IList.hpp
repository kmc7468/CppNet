#ifndef CPPNET_SYSTEM_COLLECTIONS_ILIST_HPP
#define CPPNET_SYSTEM_COLLECTIONS_ILIST_HPP

#include "../../../Defines.h"
#include "../../../Utility.h"
#include "../Object.h"
#include "../Int32.h"

#include "ICollection.h"

namespace CppNet::System::Collections
{
	interface IList : public ICollection
	{
		virtual const Object& operator[](Int32 index) const = 0;
		virtual Object& operator[](Int32 index) = 0;
		virtual Int32 Add(Object& obj) = 0;
		virtual Boolean Contains(Object& value) const = 0;
		virtual void Clear() = 0;
		virtual Boolean IsReadOnly() const = 0;
		virtual Boolean IsFixedSize() const = 0;
		virtual Int32 IndexOf(Object& value) const = 0;
		virtual void Insert(Int32 index, Object& value) = 0;
		virtual void Remove(Object& value) = 0;
		virtual void RemoveAt(Int32 index) = 0;
	};
}

#endif