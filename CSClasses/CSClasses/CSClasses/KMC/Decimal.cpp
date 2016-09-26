#include "Decimal.h"
using namespace CSClasses::KMC;
using namespace System;

Decimal::Decimal(const String& str)
{
	String s(str);
	s.insert(0, s.length() % 2, '0');

	if (s.find('.') == String::npos)
	{
		for (size_t i = 0; i < s.length() / 2; i++)
		{
			mInteger.push_back(ByteTool::IntsToByte(ByteTool::ToByte(s[i * 2]), ByteTool::ToByte(s[i * 2 + 1])));
		}
	}
	else
	{
		size_t dot = s.find('.');

		String integer = s.substr(0, dot);
		String real = s.substr(dot + 1);

		integer.insert(0, integer.length() % 2, '0');
		real.insert(real.length(), real.length() % 2, '0');

		for (size_t i = 0; i < integer.length() / 2; i++)
		{
			Byte first = ByteTool::ToByte(integer[i * 2]);
			Byte second = ByteTool::ToByte(integer[i * 2 + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			mInteger.push_back(c);
		}

		for (size_t i = 0; i < real.length() / 2; i++)
		{
			Byte first = ByteTool::ToByte(real[i * 2]);
			Byte second = ByteTool::ToByte(real[i * 2 + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			mReal.push_back(c);
		}
	}
}

Decimal::Decimal(Int64 integer)
	: Decimal(std::to_string(integer))
{}

Decimal::Decimal(Int64 integer, const String& real)
	: Decimal(std::to_string(integer) + "." + real)
{}

Decimal::Decimal(Double real)
	: Decimal(std::to_string(real))
{}

Decimal::Decimal(Decimal&& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
}

Decimal::Decimal(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
}


String Decimal::ToString() const
{
	String integer = "";

	for (var b : mInteger)
	{
		var a = ByteTool::ByteToInts(b);

		var one = std::get<0>(a);
		var two = std::get<1>(a);

		integer += ByteTool::FromByte(one);
		integer += ByteTool::FromByte(two);
	}

	while (integer[0] == '0')
		integer = integer.substr(1);

	String real = "";

	for (var b : mReal)
	{
		var a = ByteTool::ByteToInts(b);

		var one = std::get<0>(a);
		var two = std::get<1>(a);

		real += ByteTool::FromByte(one);
		real += ByteTool::FromByte(two);
	}
	
	while (real[real.length() - 1] == '0')
		real = real.substr(0, real.length() - 1);

	if (real != "")
		return integer + "." + real;

	return integer;
}

