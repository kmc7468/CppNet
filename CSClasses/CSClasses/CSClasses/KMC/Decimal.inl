#include "Decimal.h"

#include "../../BitConverter.h"
using namespace System;
using namespace CSClasses::KMC;

Byte Decimal::ByteTool::IntsToByte(Byte a, Byte b)
{
	String bin = BitConverter::BytesToBinString(std::array<Byte, 2>{a, b});

	return BitConverter::BinStringToBytes<1>(bin)[0];
}

std::tuple<Byte, Byte> Decimal::ByteTool::ByteToInts(Byte b)
{
	String bin = BitConverter::BytesToBinString(std::array<Byte, 1>{b});
	bin.insert(0, 8 - bin.length(), '0');

	Byte a = BitConverter::BinStringToBytes<1>(bin.substr(0, 4))[0];
	Byte c = BitConverter::BinStringToBytes<1>(bin.substr(4, 4))[0];

	return std::make_tuple(a, c);
}

Byte Decimal::ByteTool::ToByte(char c)
{
	return c - '0';
}

char Decimal::ByteTool::FromByte(Byte b)
{
	return b + '0';
}

String Decimal::ToString(size_t realsize) const
{
	var a = ToString();

	size_t find = a.find('.');

	if (find == String::npos) return a;

	size_t r_size = a.substr(a.find('.')).length();

	if (r_size <= realsize)
	{
		a.insert(a.length() - 1, realsize - r_size, '0');
		return a;
	}

	a = a.substr(0, find) + a.substr(find, realsize + 1);

	return a;
}