#include "BitConverter.h"

namespace System
{
	template<Int32 size, typename T>
	std::array<Byte, size> BitConverter::GetBytesLitile(T t)
	{
		std::array<Byte, size> r;

		Byte* p = (Byte*)&t;

		Int32 index = 0;
		for (Int32 i = size - 1; i >= 0; i--)
		{
			r[index] = *(p + i);

			index++;
		}

		return r;
	}

	template<Int32 size, typename T>
	std::array<Byte, size> BitConverter::GetBytesBig(T t)
	{
		std::array<Byte, size> r;

		Byte* p = (Byte*)&t;

		Int32 index = 0;
		for (Int32 i = 0; i < size; i++)
		{
			r[index] = *(p + i);

			index++;
		}

		return r;
	}

	std::array<Byte, 1> BitConverter::GetBytes(Boolean boolean, Boolean igroneEndian)
	{
		std::array<Byte, 1> r;

		Byte* p = (Byte*)&boolean;

		r[0] = *p;

		return r;
	}

	std::array<Byte, 2> BitConverter::GetBytes(Char c, Boolean igroneEndian)
	{
		return GetBytes((Int16)c, igroneEndian);
	}

	std::array<Byte, 2> BitConverter::GetBytes(Int16 i, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<2>(i) : GetBytesLitile<2>(i);
	}

	std::array<Byte, 8> BitConverter::GetBytes(Double d, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<8>(d) : GetBytesLitile<8>(d);
	}

	std::array<Byte, 4> BitConverter::GetBytes(Int32 i, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<4>(i) : GetBytesLitile<4>(i);
	}

	std::array<Byte, 8> BitConverter::GetBytes(Int64 i, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<8>(i) : GetBytesLitile<8>(i);
	}

	std::array<Byte, 4> BitConverter::GetBytes(Single d, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<4>(d) : GetBytesLitile<4>(d);
	}

	std::array<Byte, 2> BitConverter::GetBytes(UInt16 i, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<2>(i) : GetBytesLitile<2>(i);
	}

	std::array<Byte, 4> BitConverter::GetBytes(UInt32 i, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<4>(i) : GetBytesLitile<4>(i);
	}

	std::array<Byte, 8> BitConverter::GetBytes(UInt64 i, Boolean igroneEndian)
	{
		return igroneEndian || !IsLittleEndian ? GetBytesBig<8>(i) : GetBytesLitile<8>(i);
	}

	Int64 BitConverter::DoubleToInt64Bits(Double d, Boolean igroneEndian)
	{
		return igroneEndian ? *((Int64*)&d) : (IsLittleEndian ? DTI64L(d) : *((Int64*)&d));
	}

	Int64 BitConverter::DTI64L(Double d)
	{
		return 0;
	}
}