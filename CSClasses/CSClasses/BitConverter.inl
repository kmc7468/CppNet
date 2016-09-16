#include "BitConverter.h"

#include <algorithm>

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

	std::array<Byte, 4> BitConverter::GetBytes(Char c, Boolean igroneEndian)
	{
		return GetBytes(c.Unicode(), igroneEndian);
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

	Int64 BitConverter::DoubleToInt64Bits(Double d)
	{
		return *((Int64*)&d);
	}

	Double BitConverter::Int64BitsToDouble(Int64 i)
	{
		return *((Double*)&i);
	}

	Int32 BitConverter::SingleToInt32Bits(Single d)
	{
		return *((Int32*)&d);
	}

	Single BitConverter::Int32BitsToSingle(Int32 i)
	{
		return *((Single*)&i);
	}

	Char BitConverter::ToChar(std::array<Byte, 4> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((Char*)p);
	}

	Int16 BitConverter::ToInt16(std::array<Byte, 2> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((Int16*)p);
	}

	Int32 BitConverter::ToInt32(std::array<Byte, 4> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((Int32*)p);
	}

	Int64 BitConverter::ToInt64(std::array<Byte, 8> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((Int64*)p);
	}

	UInt16 BitConverter::ToUInt16(std::array<Byte, 2> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((UInt16*)p);
	}

	UInt32 BitConverter::ToUInt32(std::array<Byte, 4> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((UInt32*)p);
	}

	UInt64 BitConverter::ToUInt64(std::array<Byte, 8> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((UInt64*)p);
	}

	Single BitConverter::ToSingle(std::array<Byte, 4> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((Single*)p);
	}

	Double BitConverter::ToDouble(std::array<Byte, 8> arr, Boolean igroneEndian)
	{
		if (IsLittleEndian && !igroneEndian)
			std::reverse(arr.begin(), arr.end());

		Byte *p = arr.data();

		return *((Double*)p);
	}

	template<size_t size>
	String BitConverter::ToBinString(std::array<Byte, size> arr)
	{
		String r;

		String temp;

		for (var b : arr)
		{
			Byte value = b;

			while (true)
			{
				Byte mod = value % 2;
				Byte div = (value - mod) / 2;

				temp = std::to_string(mod) + temp;

				value = div;

				if (value == 0)
					break;
			}

			r.append(temp);
		}

		return r;
	}

	template<size_t size>
	std::array<Byte, size> BitConverter::FromBinString(const String& binstr)
	{
		std::array<Byte, size> r;

		Byte temp01 = binstr.length() % 8;
		Byte temp02 = 8 - temp01;

		String s(binstr);

		for (int i = 0; i < temp02; i++)
			s = '0' + s;

		if (s.length() / 8 != size)
		{
			// FIXME Arg 뭐시기 Exception
			throw Exception("응 인자 오류~");
		}

		for (int i = 0; i < s.length() / 8; i++)
		{
			String bin = s.substr(i * 8, 8);

			Byte b = 0;

			int n = 0;
			for (int j = 7; j >= 0; j--)
			{
				b += (Byte)std::stoi(bin[n]) * (Byte)Math::Pow(2, j);

				n++;
			}

			r[i] = b;
		}

		return r;
	}
}