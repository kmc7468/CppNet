#include "Decimal.h"
using namespace CSClasses::KMC;
using namespace System;

Decimal::Decimal()
{
	mInteger.push_back(0);
	mReal.push_back(0);
}

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

	Clean();
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

	Clean();
}

Decimal::Decimal(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;

	Clean();
}

Boolean Decimal::operator==(const Object& obj)
{
	if (is<const Decimal&>(obj))
	{
		var a = as<const Decimal&>(obj);

		if (a.ToString() == (*this).ToString())
			return true;
		else
			return false;
	}
	else
		return false;
}

Boolean Decimal::operator!=(const Object& obj)
{
	return !Decimal::operator==(obj);
}

Decimal Decimal::operator=(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;

	Clean();

	return *this;
}

Decimal Decimal::operator=(Decimal&& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;

	Clean();

	return *this;
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

	while (integer[0] == '0' && integer.length() > 1)
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

	while (real[real.length() - 1] == '0' && real.length() > 1)
		real = real.substr(0, real.length() - 1);

	if (real == "0")
		return integer;

	if (real != "")
		return integer + "." + real;

	return integer;
}

Decimal Decimal::operator+(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = Decimal(d);
	Decimal c = 0.0;

	// TODO

	return c;
}

Decimal Decimal::operator+(Decimal&& d) const
{
	Decimal a = *this;
	Decimal b = Decimal(d);
	Decimal c = 0.0;

	// TODO

	return c;
}

Decimal Decimal::operator+=(const Decimal& d)
{
	Decimal a = *this + d;

	mInteger = a.mInteger;
	mReal = a.mReal;

	return *this;
}

Decimal Decimal::operator+=(Decimal&& d)
{
	Decimal a = *this + d;

	mInteger = a.mInteger;
	mReal = a.mReal;

	return *this;
}

Decimal Decimal::operator++()
{
	Decimal a = *this + 1.0;

	mInteger = a.mInteger;

	return *this;
}

Decimal Decimal::operator++(int)
{
	Decimal a = *this + 1.0;
	Decimal b = *this;

	mInteger = a.mInteger;

	return b;
}