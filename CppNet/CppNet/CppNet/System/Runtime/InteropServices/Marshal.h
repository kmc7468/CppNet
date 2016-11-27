#ifndef CPPNET_SYSTEM_RUNTIME_INTEROPSERVICES_MARSHAL_H
#define CPPNET_SYSTEM_RUNTIME_INTEROPSERVICES_MARSHAL_H

#include "../../../../Defines.h"

#include "../../../../SystemTypes.h"
#include "../../Object.h"
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

		// TODO OffsetOf(s)
		// TODO UnsafeAddrOfPinnedArrayElement

		template<size_t size>
		inline static void Copy(std::array<Int32, size> source, Int32 startIndex, IntPtr dest, Int32 length);
		template<size_t size>
		inline static void Copy(std::array<Char, size> source, Int32 startIndex, IntPtr dest, Int32 length);
		template<size_t size>
		inline static void Copy(std::array<Int16, size> source, Int32 startIndex, IntPtr dest, Int32 length);
		template<size_t size>
		inline static void Copy(std::array<Int64, size> source, Int32 startIndex, IntPtr dest, Int32 length);
		template<size_t size>
		inline static void Copy(std::array<Single, size> source, Int32 startIndex, IntPtr dest, Int32 length);
		template<size_t size>
		inline static void Copy(std::array<Double, size> source, Int32 startIndex, IntPtr dest, Int32 length);
		template<size_t size>
		inline static void Copy(std::array<Byte, size> source, Int32 startIndex, IntPtr dest, Int32 length);
		template<size_t size>
		inline static void Copy(std::array<IntPtr, size> source, Int32 startIndex, IntPtr dest, Int32 length);

		template<size_t size>
		inline static void Copy(IntPtr source, std::array<Int32, size> dest, Int32 startIndex, Int32 length);
		template<size_t size>
		inline static void Copy(IntPtr source, std::array<Char, size> dest, Int32 startIndex, Int32 length);
		template<size_t size>
		inline static void Copy(IntPtr source, std::array<Int16, size> dest, Int32 startIndex, Int32 length);
		template<size_t size>
		inline static void Copy(IntPtr source, std::array<Int64, size> dest, Int32 startIndex, Int32 length);
		template<size_t size>
		inline static void Copy(IntPtr source, std::array<Single, size> dest, Int32 startIndex, Int32 length);
		template<size_t size>
		inline static void Copy(IntPtr source, std::array<Double, size> dest, Int32 startIndex, Int32 length);
		template<size_t size>
		inline static void Copy(IntPtr source, std::array<Byte, size> dest, Int32 startIndex, Int32 length);
		template<size_t size>
		inline static void Copy(IntPtr source, std::array<IntPtr, size> dest, Int32 startIndex, Int32 length);

		static Byte ReadByte(IntPtr ptr, Int32 offset);
		inline static Byte ReadByte(IntPtr ptr);

	public:
		static const Int32 SystemDefaultCharSize;
	};
}

#include "Marshal.inl"

#endif