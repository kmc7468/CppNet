#include "Marshal.h"

#include "../../UInt32.h"
#include "../../UInt64.h"
#include "../../AccessViolationException.h"

namespace CppNet::System::Runtime::InteropServices
{
	const Int32 Marshal::LMEM_FIXED = 0;
	const Int32 Marshal::LMEM_MOVEABLE = 2;
	const Int64 Marshal::HIWORDMASK = 0xffffffffffff0000;

	const Int32 Marshal::SystemDefaultCharSize = sizeof(char);

	Boolean Marshal::IsWin32Atom(IntPtr ptr)
	{
#ifdef BIT_64
		UInt64 lPtr = (UInt64)ptr;
#else
		UInt32 lPtr = (UInt32)ptr;
#endif

		return (lPtr & HIWORDMASK) == 0;
	}

	Boolean Marshal::IsNotWin32Atom(IntPtr ptr)
	{
#ifdef BIT_64
		UInt64 lPtr = (UInt64)ptr;
#else
		UInt32 lPtr = (UInt32)ptr;
#endif

		return (lPtr & HIWORDMASK) != 0;
	}

	Byte Marshal::ReadByte(IntPtr ptr, Int32 offset)
	{
		if (ptr.ToPointer() == nullptr)
		{
			throw AccessViolationException();
		}
		else
		{
			Byte* addr = ((Byte*)ptr.ToPointer()) + offset;
			return *addr;
		}
	}
}