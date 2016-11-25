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
}