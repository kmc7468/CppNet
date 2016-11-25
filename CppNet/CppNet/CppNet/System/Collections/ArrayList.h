#ifndef CPPNET_SYSTEM_COLLECTIONS_ARRAYLIST_H
#define CPPNET_SYSTEM_COLLECTIONS_ARRAYLIST_H

#include "IList.hpp"
#include "../ICloneable.h"
#include "../Object.h"
#include "../Int32.h"
#include "../../Box.hpp"

namespace CppNet::System::Collections
{
	class ArrayList : public IList, public ICloneable
	{
	private:
		Object* _items = nullptr;
		Int32 _size;
		Int32 _version;
		Object* _syncRoot = nullptr;
		Int32 _items_len;

	private:
		static const Int32 _defaultCapacity;

	_internal:
		ArrayList(Boolean trash);

	public:
		ArrayList();
		ArrayList(Int32 capacity);
		ArrayList(Box<ICollection> c);

	public:
		virtual Int32 GetCapacity() const;
		virtual void SetCapacity(Int32 capacity);
		Int32 Count() const override;
		Boolean IsFixedSize() const override;
		Boolean IsReadOnly() const override;
		Boolean IsSynchronized() const override;

		// TODO
	};
}

#endif