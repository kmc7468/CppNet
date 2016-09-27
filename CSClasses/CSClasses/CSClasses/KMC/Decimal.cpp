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
			mInteger += ByteTool::IntsToByte(ByteTool::ToByte(s[i * 2]), ByteTool::ToByte(s[i * 2 + 1]));
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
			mInteger += c;
		}

		for (size_t i = 0; i < real.length() / 2; i++)
		{
			Byte first = ByteTool::ToByte(real[i * 2]);
			Byte second = ByteTool::ToByte(real[i * 2 + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			mReal += c;
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

	for (var i = mInteger.begin(); i < mInteger.end(); i++)
	{
		var a = ByteTool::ByteToInts(i[0]);

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
	c.mInteger = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();
	c.mReal = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	Byte up = 0;

	{ // Real
		for (size_t i = a.mReal.length() - 1; i >= 0; i--)
		{
			var temp01 = ByteTool::ByteToInts(a.mReal[i]);

			var one_a = std::get<0>(temp01);
			var two_a = std::get<1>(temp01);

			var temp02 = ByteTool::ByteToInts(b.mReal[i]);

			var one_b = std::get<0>(temp02);
			var two_b = std::get<1>(temp02);

			Byte temp04 = two_a + two_b + up;
			up = temp04 > 9 ? temp04 - 9 : 0;

			Byte temp03 = one_a + one_b + up;
			up = temp03 > 9 ? temp03 - 9 : 0;

			c.mReal.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));
		
			if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
		}
	}

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	{ // Integer
		for (size_t i = a.mInteger.length() - 1; i >= 0; i--)
		{
			var temp01 = ByteTool::ByteToInts(a.mInteger[i]);

			var one_a = std::get<0>(temp01);
			var two_a = std::get<1>(temp01);

			var temp02 = ByteTool::ByteToInts(b.mInteger[i]);

			var one_b = std::get<0>(temp02);
			var two_b = std::get<1>(temp02);

			Byte temp04 = two_a + two_b + up;
			up = temp04 > 9 ? temp04 - 9 : 0;

			Byte temp03 = one_a + one_b + up;
			up = temp03 > 9 ? temp03 - 9 : 0;

			c.mInteger.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));

			if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
		}

		c.mInteger = ByteTool::IntsToByte(0, up) + c.mInteger;
	}

	c.Clean();

	return c;
}

Decimal Decimal::operator+(Decimal&& d) const
{
	Decimal a = *this;
	Decimal b = Decimal(d);
	Decimal c = 0.0;
	c.mInteger = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();
	c.mReal = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	Byte up = 0;

	{ // Real
		for (size_t i = a.mReal.length() - 1; i >= 0; i--)
		{
			var temp01 = ByteTool::ByteToInts(a.mReal[i]);

			var one_a = std::get<0>(temp01);
			var two_a = std::get<1>(temp01);

			var temp02 = ByteTool::ByteToInts(b.mReal[i]);

			var one_b = std::get<0>(temp02);
			var two_b = std::get<1>(temp02);

			Byte temp04 = two_a + two_b + up;
			up = temp04 > 9 ? temp04 - 9 : 0;

			Byte temp03 = one_a + one_b + up;
			up = temp03 > 9 ? temp03 - 9 : 0;

			c.mReal.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));

			if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
		}
	}

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	{ // Integer
		for (size_t i = a.mInteger.length() - 1; i >= 0; i--)
		{
			var temp01 = ByteTool::ByteToInts(a.mInteger[i]);

			var one_a = std::get<0>(temp01);
			var two_a = std::get<1>(temp01);

			var temp02 = ByteTool::ByteToInts(b.mInteger[i]);

			var one_b = std::get<0>(temp02);
			var two_b = std::get<1>(temp02);

			Byte temp04 = two_a + two_b + up;
			up = temp04 > 9 ? temp04 - 9 : 0;

			Byte temp03 = one_a + one_b + up;
			up = temp03 > 9 ? temp03 - 9 : 0;

			c.mInteger.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));

			if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
		}

		c.mInteger = ByteTool::IntsToByte(0, up) + c.mInteger;
	}

	c.Clean();

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