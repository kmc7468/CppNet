#include "ArrayList.h"

#include "../ArgumentOutOfRangeException.hpp"
#include "../ArgumentNullException.hpp"

namespace CppNet::System::Collections
{
	const Int32 ArrayList::_defaultCapacity = 4;

	ArrayList::ArrayList(Boolean trash)
	{}

	ArrayList::ArrayList()
	{
		_items = nullptr;
	}

	ArrayList::ArrayList(Int32 capacity)
	{
		if (capacity < 0)
			throw ArgumentOutOfRangeException(nameof(capacity));

		if (capacity == 0)
			_items = nullptr;
		else
		{
			_items = new Object[capacity];
			_items_len = capacity;
		}
	}

	ArrayList::ArrayList(Box<ICollection> c)
	{
		if (c == nullptr)
			throw ArgumentNullException(nameof(c));

		Int32 count = c->Count();
		if (count == 0)
			_items = nullptr;
		else
		{
			_items = new Object[count];
			_items_len = count;
			// TODO AddRange(c);
		}
	}

	Int32 ArrayList::GetCapacity() const
	{
		return _items_len;
	}

	void ArrayList::SetCapacity(Int32 capacity)
	{
		if (capacity < _size)
			throw ArgumentOutOfRangeException(nameof(capacity));

		if (capacity != _items_len)
		{
			if (capacity > 0)
			{
				Object* newItems = new Object[capacity];
				if (_size > 0)
				{
					// TODO Array.Copy
				}
				_items = newItems;
				_items_len = capacity;
			}
			else
			{
				_items = new Object[_defaultCapacity];
				_items_len = _defaultCapacity;
			}
		}
	}

	Int32 ArrayList::Count() const
	{
		return _size;
	}

	Boolean ArrayList::IsFixedSize() const
	{
		return false;
	}

	Boolean ArrayList::IsReadOnly() const
	{
		return false;
	}

	Boolean ArrayList::IsSynchronized() const
	{
		return false;
	}

	const Object& ArrayList::SyncRoot() const
	{
		if (_syncRoot == nullptr)
		{
			_syncRoot = new Object;
		}

		return *_syncRoot;
	}

	const Object& ArrayList::operator[](Int32 index) const
	{
		if (index < 0 || index >= _size)
			throw ArgumentOutOfRangeException(nameof(index));

		return _items[index];
	}

	Object& ArrayList::operator[](Int32 index)
	{
		if (index < 0 || index >= _size)
			throw ArgumentOutOfRangeException(nameof(index));

		return _items[index];
	}

	Int32 ArrayList::Add(Object& object)
	{
		if (_size == _items_len) EnsureCapacity(_size + 1);
		_items[_size] = object;

		return _size++;
	}

	void ArrayList::InsertRange(Int32 index, Box<ICollection> col)
	{
		if (col == nullptr)
			throw ArgumentNullException(nameof(col));
		if (index < 0 || index > _size)
			throw ArgumentOutOfRangeException(nameof(index));
	
		Int32 count = col->Count();

		if (count > 0) 
		{
			EnsureCapacity(_size + count);
			
			if (index < _size) {
				//Array.Copy(_items, index, _items, index + count, _size - index); FIXME
			}

			Object* itemsToInsert = new Object[count];
			//c.CopyTo(itemsToInsert, 0); FIXME
			//itemsToInsert.CopyTo(_items, index);
			_size += count;
		}
	}

	void ArrayList::AddRange(Box<ICollection> c)
	{
		InsertRange(_size, c);
	}

	Int32 ArrayList::BinarySearch(Int32 index, Int32 count, Object& value, Box<IComparer> comparer)
	{
		// TODO

		return Int32();
	}

	Int32 ArrayList::LastIndexOf(Object& value) const
	{
		return LastIndexOf(value, _size - 1, _size);
	}

	Int32 ArrayList::LastIndexOf(Object value, Int32 startIndex) const
	{
		if (startIndex >= _size)
			throw ArgumentOutOfRangeException(nameof(startIndex));

		return LastIndexOf(value, startIndex, startIndex + 1);
	}

	Int32 ArrayList::LastIndexOf(Object value, Int32 startIndex, Int32 count) const
	{
		if (Count() != 0 && (startIndex < 0 || count < 0))
			throw ArgumentOutOfRangeException((startIndex < 0 ? nameof(startIndex) : nameof(count)));
	
		if (_size == 0)
			return -1;

		if (startIndex >= _size || count > startIndex + 1)
			throw ArgumentOutOfRangeException(startIndex >= _size ? nameof(startIndex) : nameof(count));
	
		return Int32(); // TODO
	}

#pragma region Private
	void ArrayList::EnsureCapacity(Int32 min)
	{
		if (_items_len < min) {
			Int32 newCapacity = _items_len == 0 ? _defaultCapacity : _items_len * 2;

			if (newCapacity > 0X7FEFFFFF) newCapacity = 0X7FEFFFFF;
			if (newCapacity < min) newCapacity = min;
			SetCapacity(newCapacity);
		}
	}
#pragma endregion
}