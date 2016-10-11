#include "BitConverter.h"

#include <algorithm>
#include <string>
#include <bitset>
#include <iomanip>
#include <sstream>
#include "ArgumentException.h"
#include "Math.h"
using namespace std;

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

	std::array<Byte, 1> BitConverter::GetBytes(Boolean boolean)
	{
		std::array<Byte, 1> r;

		Byte* p = (Byte*)&boolean;

		r[0] = *p;

		return r;
	}

	std::array<Byte, 4> BitConverter::GetBytes(Char c, Boolean igroneEndian)
	{
		return GetBytes((UInt32)c, igroneEndian);
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

	Boolean BitConverter::ToBoolean(std::array<Byte, 1> arr)
	{
		if (arr[0] == 0)
			return false;
		else
			return true;
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
	String BitConverter::BytesToBinString(std::array<Byte, size> arr)
	{
		String b = "";

		for (var d : arr)
		{
			std::bitset<8> bit(d);

			String temp = bit.to_string();
			temp.insert(0, 8 - temp.length(), '0');

			b += temp;
		}

		return b.substr(b.find('1'));
	}

	template<size_t size>
	std::array<Byte, size> BitConverter::BinStringToBytes(const String& binstr)
	{
		std::array<Byte, size> r;

		String bin(binstr);
		bin.insert(0, binstr.length() % 8 == 0 ? 0 : 8 - (binstr.length() % 8), '0');

		size_t start = bin.length() / 8 < r.size() ? r.size() - (bin.length() / 8) : 0;

		for (size_t i = 0; i < size; i++)
		{
			if (i < start)
			{
				r[i] = 0;
				continue;
			}

			Byte b = 0;

			std::bitset<8> bit(bin.substr((i - start) * 8, 8));
			b = (Byte) bit.to_ullong();

			r[i] = b;
		}

		return r;
	}

	template<size_t size>
	String BitConverter::BytesToHexString(std::array<Byte, size> arr)
	{
		String b = "";

		for (var d : arr)
		{
			char buf[3];
			sprintf(buf, "%02X", d);

			b += String(buf);
		}

		while (b[0] == '0')
			b = b.substr(1);

		return b;
	}

	template<size_t size>
	std::array<Byte, size> BitConverter::HexStringToBytes(const String& hexstr)
	{
		std::array<Byte, size> r;

		String hex(hexstr);
		hex.insert(0, hexstr.length() % 2 == 0 ? 0 : 2 - (hexstr.length() % 2), '0');

		size_t start = hex.length() / 2 < r.size() ? r.size() - (hex.length() / 2) : 0;

		for (size_t i = 0; i < size; i++)
		{
			if (i < start)
			{
				r[i] = 0;
				continue;
			}

			Byte *b = new Byte(0);

			sscanf(("0x"s + hex.substr((i - start) * 2, 2)).c_str(), "%x", b);

			r[i] = *b;
		}

		return r;
	}
}