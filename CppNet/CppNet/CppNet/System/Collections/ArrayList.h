#ifndef CPPNET_SYSTEM_COLLECTIONS_ARRAYLIST_H
#define CPPNET_SYSTEM_COLLECTIONS_ARRAYLIST_H

#include "IList.hpp"
#include "../ICloneable.h"
#include "../Object.h"
#include "../Int32.h"
#include "../../Box.hpp"
#include "IComparer.hpp"

namespace CppNet::System::Collections
{
	class ArrayList : public IList, public ICloneable
	{
	private:
		Object* _items = nullptr;
		Int32 _size;
		mutable Object* _syncRoot = nullptr;
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
		const Object& SyncRoot() const override;
		const Object& operator[](Int32 index) const override;
		Object& operator[](Int32 index) override;
		virtual void InsertRange(Int32 index, Box<ICollection> col);

	public:
		//static ArrayList Adapter(Box<IList> list);
	
	public:
		virtual void AddRange(Box<ICollection> c);
		Int32 Add(Object& object) override;
		virtual Int32 BinarySearch(Int32 index, Int32 count, Object& value, Box<IComparer> comparer);
		
	private:
		void EnsureCapacity(Int32 min);
	};
}

#endif