#include "Marshal.h"

namespace CppNet::System::Runtime::InteropServices
{
	template<typename T>
	Int32 Marshal::SizeOf(T data)
	{
		return sizeof(data);
	}

	template<size_t size>
	void Marshal::Copy(std::array<Int32, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(std::array<Char, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(std::array<Int16, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(std::array<Int64, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(std::array<Single, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(std::array<Double, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(std::array<Byte, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(std::array<IntPtr, size> source, Int32 startIndex, IntPtr dest, Int32 length)
	{
		memcpy(dest.ToPointer(), source.data() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<Int32, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<Char, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<Int16, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<Int64, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<Single, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<Double, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<Byte, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	template<size_t size>
	void Marshal::Copy(IntPtr source, std::array<IntPtr, size> dest, Int32 startIndex, Int32 length)
	{
		memcpy(dest.data(), source.ToPointer() + startIndex, length);
	}

	Byte Marshal::ReadByte(IntPtr ptr)
	{
		return ReadByte(ptr, 0);
	}
}