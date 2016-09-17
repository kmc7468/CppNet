#include "BitConverter.h"

#include <algorithm>
#include <bitset>

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
	String BitConverter::BytesToBinString(std::array<Byte, size> arr)
	{
		String b = "";

		for (var d : arr)
		{
			b += BytesToBinString(d);
		}

		return b.substr(b.find('1'));
	}

	String BitConverter::BytesToBinString(Byte b)
	{
		String s = "";

		Byte value = b;

		while ((value - (value % 2)) / 2 != 0)
		{
			s = std::to_string(value % 2) + s;

			value = (value - (value % 2)) / 2;
		}

		s = std::to_string(value % 2) + s;

		if (s.length() != 8)
		{
			int more = 8 - s.length();

			for (int i = 0; i < more; i++)
			{
				s = '0' + s;
			}
		}

		return s;
	}

	template<size_t size>
	std::array<Byte, size> BitConverter::BinStringToBytes(const String& binstr)
	{
		std::array<Byte, size> r;

		String bin(binstr);

		if (bin.length() % 8 != 0)
		{
			int add = 8 - (bin.length() % 8);

			for (int i = 0; i < add; i++)
			{
				bin = '0' + bin;
			}
		}

		int start = 0;

		if (bin.length() / 8 < r.size())
		{
			start = r.size() - (bin.length() / 8);
		}

		for (int i = 0; i < start; i++)
		{
			r[i] = 0;
		}

		for (int i = 0; i < bin.length() / 8; i++)
		{
			String str = bin.substr(i * 8, 8);
			Byte b = 0;

			int n = 0;
			for (int j = 7; j >= 0; j--)
			{
				b += (Byte)std::stoi(str.substr(n, 1)) * (Byte)Math::Pow(2, j);
				n++;
			}

			r[start + i] = b;
		}

		return r;
	}

	template<size_t size>
	String BitConverter::BytesToHexString(std::array<Byte, size> arr)
	{
		String b = "";

		for (var d : arr)
		{
			b += BytesToHexString(d);
		}

		while (b[0] == '0')
			b = b.substr(1);

		return b;
	}

	String BitConverter::BytesToHexString(Byte b)
	{
		String str = "";

		Byte value = b;

		while ((value - (value % 16)) / 16 != 0)
		{
			String tempstr = std::to_string(value % 16);

			if (tempstr == "10")
				tempstr = "A";
			else if (tempstr == "11")
				tempstr = "B";
			else if (tempstr == "12")
				tempstr = "C";
			else if (tempstr == "13")
				tempstr = "D";
			else if (tempstr == "14")
				tempstr = "E";
			else if (tempstr == "15")
				tempstr = "F";

			str = tempstr + str;

			value = (value - (value % 16)) / 16;
		}

		String ts = std::to_string(value % 16);

		if (ts == "10")
			ts = "A";
		else if (ts == "11")
			ts = "B";
		else if (ts == "12")
			ts = "C";
		else if (ts == "13")
			ts = "D";
		else if (ts == "14")
			ts = "E";
		else if (ts == "15")
			ts = "F";

		str = ts + str;

		return str;
	}

	template<size_t size>
	std::array<Byte, size> BitConverter::HexStringToBytes(const String& hexstr)
	{
		std::array<Byte, size> r;

		String bin(hexstr);

		if (bin.length() % 2 != 0)
		{
			int add = 2 - (bin.length() % 2);

			for (int i = 0; i < add; i++)
			{
				bin = '0' + bin;
			}
		}

		int start = 0;

		if (bin.length() / 2 < r.size())
		{
			start = r.size() - (bin.length() / 2);
		}

		for (int i = 0; i < start; i++)
		{
			r[i] = 0;
		}

		for (int i = 0; i < bin.length() / 2; i++)
		{
			String str = bin.substr(i * 2, 2);
			Byte b = 0;

			int n = 0;
			for (int j = 1; j >= 0; j--)
			{
				String tempstr = str.substr(n, 1);

				if (tempstr == "A")
					tempstr = "10";
				else if (tempstr == "B")
					tempstr = "11";
				else if (tempstr == "C")
					tempstr = "12";
				else if (tempstr == "D")
					tempstr = "13";
				else if (tempstr == "E")
					tempstr = "14";
				else if (tempstr == "F")
					tempstr = "15";

				b += std::stoi(tempstr) * Math::Pow(16, j);
				n++;
			}

			r[start + i] = b;
		}

		return r;
	}

	template<size_t size>
	String BitConverter::BytesToOctString(std::array<Byte, size> arr)
	{
		String b = "";

		for (var d : arr)
		{
			b += BytesToOctString(d);
		}

		while (b[0] == '0')
			b = b.substr(1);

		return b;
	}

	String BitConverter::BytesToOctString(Byte b)
	{
		String s = "";

		Byte value = b;

		while ((value - (value % 8)) / 8 != 0)
		{
			s = std::to_string(value % 8) + s;

			value = (value - (value % 8)) / 8;
		}

		s = std::to_string(value % 8) + s;

		if (s.length() != 8)
		{
			int more = 8 - s.length();

			for (int i = 0; i < more; i++)
			{
				s = '0' + s;
			}
		}

		return s;
	}

	template<size_t size>
	std::array<Byte, size> BitConverter::OctStringToBytes(const String& octstr)
	{
		std::array<Byte, size> r;

		String bin(binstr);

		if (bin.length() % 8 != 0)
		{
			int add = 8 - (bin.length() % 8);

			for (int i = 0; i < add; i++)
			{
				bin = '0' + bin;
			}
		}

		int start = 0;

		if (bin.length() / 8 < r.size())
		{
			start = r.size() - (bin.length() / 8);
		}

		for (int i = 0; i < start; i++)
		{
			r[i] = 0;
		}

		for (int i = 0; i < bin.length() / 8; i++)
		{
			String str = bin.substr(i * 8, 8);
			Byte b = 0;

			int n = 0;
			for (int j = 7; j >= 0; j--)
			{
				b += (Byte)std::stoi(str.substr(n, 1)) * (Byte)Math::Pow(8, j);
				n++;
			}

			r[start + i] = b;
		}

		return r;
	}
}