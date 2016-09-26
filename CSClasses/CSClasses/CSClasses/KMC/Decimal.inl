#include "Decimal.h"

#include "../../BitConverter.h"
using namespace System;
using namespace CSClasses::KMC;

Byte Decimal::ByteTool::IntsToByte(Byte a, Byte b)
{
	if (a == 0 && b == 0) return 0;

	String bin1 = a != 0 ? BitConverter::BytesToBinString(std::array<Byte, 1>{a}) : "";
	String bin2 = b != 0 ? BitConverter::BytesToBinString(std::array<Byte, 1>{b}) : "";
	bin1.insert(0, 4 - bin1.length(), '0');
	bin2.insert(0, 4 - bin2.length(), '0');

	var temp = BitConverter::BinStringToBytes<1>(bin1 + bin2);

	return temp[0];
}

std::tuple<Byte, Byte> Decimal::ByteTool::ByteToInts(Byte b)
{
	if (b == 0) return std::make_tuple<Byte, Byte>(0, 0);

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
		a.insert(a.length(), realsize - r_size + 1, '0');
		return a;
	}

	a = a.substr(0, find) + a.substr(find, realsize + 1);

	return a;
}

void Decimal::Clean()
{
	while (mReal.size() > 0 && mReal[mReal.size() - 1] == 0)
		mReal.erase(mReal.begin() + (mReal.size() - 1));

	while (mInteger.size() > 0 && mInteger[0] == 0)
		mInteger.erase(mInteger.begin());
}