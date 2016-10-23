#ifndef SYSTEM_INTPTR_H
#define SYSTEM_INTPTR_H

#include "../Defines.h"

#include "../SystemTypes.h"

namespace System
{
	class IntPtr : public Object
	{
	private:
		void* value = nullptr;

	public:
		static const IntPtr Zero;

		IntPtr(Int32 value);
#ifdef BIT_64
		IntPtr(Int64 value);
#endif
		IntPtr(void* value);
		IntPtr(const IntPtr& value);
		IntPtr(IntPtr&& value);
		~IntPtr() = default;

	private:
		IntPtr() = default;

	public:
		Boolean Equals(Object& obj) const override;
		Boolean operator==(const Object& obj) const override;
		Boolean operator!=(const Object& obj) const override;

#ifdef BIT_64
		Int64 ToInt64() const;
#else
		Int32 ToInt32() const;
#endif

		// TODO ToString

		operator void*() const;
#ifdef BIT_64
		operator Int64() const;
#else
		operator Int32() const;
#endif

#ifdef BIT_64
		static IntPtr Add(const IntPtr& ptr, Int64 offset);
		IntPtr operator+(Int64 offset) const;

		static IntPtr Subtract(const IntPtr& ptr, Int64 offset);
		IntPtr operator-(Int64 offset) const;
#else
		static IntPtr Add(const IntPtr& ptr, Int32 offset);
		IntPtr operator+(Int32 offset) const;

		static IntPtr Subtract(const IntPtr& ptr, Int32 offset);
		IntPtr operator-(Int32 offset) const;
#endif

		static Int32 Size();

		void* ToPointer() const;
	};
}

#endif