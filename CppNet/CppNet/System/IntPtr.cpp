#include "IntPtr.h"
using namespace System;

const IntPtr IntPtr::Zero = IntPtr();

#ifdef BIT_64
IntPtr::IntPtr(Int32 value)
{
	this->value = (void*)((Int64)value);
}
#else
IntPtr::IntPtr(Int32 value)
{
	this->value = (void*)value;
}
#endif

#ifdef BIT_64
IntPtr::IntPtr(Int64 value)
{
	this->value = (void*)value;
}
#endif

IntPtr::IntPtr(void* value)
{
	this->value = value;
}

IntPtr::IntPtr(const IntPtr& value)
{
	this->value = value.value;
}

IntPtr::IntPtr(IntPtr&& value)
{
	this->value = std::move(value.value);
}

Boolean IntPtr::Equals(Object& obj) const
{
	return operator==(obj);
}

Boolean IntPtr::operator==(const Object& obj) const
{
	var ptr = _as(obj, const IntPtr&);

	if (ptr.value == this->value)
	{
		return true;
	}

	return false;
}

Boolean IntPtr::operator!=(const Object& obj) const
{
	return !(operator!=(obj));
}

#ifdef BIT_64
Int64 IntPtr::ToInt64() const
{
	return (Int64)value;
}
#else
Int32 IntPtr::ToInt32() const
{
	return (Int32)value;
}
#endif

IntPtr::operator void*() const
{
	return value;
}

#ifdef BIT_64
IntPtr::operator Int64() const
{
	return ToInt64();
}
#else
IntPtr::operator Int32() const
{
	return ToInt32();
}
#endif

#ifdef BIT_64
IntPtr IntPtr::Add(const IntPtr& ptr, Int64 offset)
{
	return ptr + offset;
}

IntPtr IntPtr::operator+(Int64 offset) const
{
	return IntPtr((Int64)(this->value) + offset);
}

IntPtr IntPtr::Subtract(const IntPtr& ptr, Int64 offset)
{
	return ptr - offset;
}

IntPtr IntPtr::operator-(Int64 offset) const
{
	return IntPtr((Int64)(this->value) - offset);
}

Int32 IntPtr::Size()
{
	return 8;
}
#else
IntPtr IntPtr::Add(const IntPtr& ptr, Int32 offset)
{
	return ptr + offset;
}

IntPtr IntPtr::operator+(Int32 offset) const
{
	return IntPtr((Int32)(this->value) + offset);
}

IntPtr IntPtr::Subtract(const IntPtr& ptr, Int32 offset)
{
	return ptr - offset;
}

IntPtr System::IntPtr::operator-(Int32 offset) const
{
	return IntPtr((Int32)(this->value) - offset);
}

Int32 IntPtr::Size()
{
	return 4;
}
#endif

void* IntPtr::ToPointer() const
{
	return value;
}