#ifndef CPPNET_SYSTEM_RUNTIME_INTEROPSERVICES_MARSHAL_H
#define CPPNET_SYSTEM_RUNTIME_INTEROPSERVICES_MARSHAL_H

#include "../../../../Defines.h"

#include "../../Object.h"
#include "../../Int32.h"
#include "../../Int64.h"
#include "../../Boolean.h"
#include "../../IntPtr.h"

namespace CppNet::System::Runtime::InteropServices
{
	enum class CustomQueryInterfaceMode
	{
		Ignore,
		Allow,
	};

	class Marshal : public Object
	{
	public:
		Marshal() = default;
		Marshal(const Marshal&) = delete;
		Marshal(Marshal&&) = delete;
		~Marshal() = default;

	public:
		Marshal& operator=(const Marshal&) = delete;
		Marshal& operator=(Marshal&&) = delete;

	private:
		static const Int32 LMEM_FIXED;
		static const Int32 LMEM_MOVEABLE;
		static const Int64 HIWORDMASK;
		// TODO static Guid IID_IUnknown

	private:
		static Boolean IsWin32Atom(IntPtr ptr);
		static Boolean IsNotWin32Atom(IntPtr ptr);

		// TODO PtrToString(blah blah)(s)

		template<typename T>
		inline static Int32 SizeOf(T data);

		// TODO (s)

	public:
		static const Int32 SystemDefaultCharSize;
	};
}

#include "Marshal.inl"

#endif