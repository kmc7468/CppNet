#include "Decimal.h"
using namespace CSClasses::KMC;
using namespace System;

Decimal::Decimal()
{
	mInteger.push_back(0);
	mReal.push_back(0);
}

Decimal::Decimal(const String& str)
	: Decimal(Parse(str))
{ }

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
	isN = d.isN;

	Clean();
}

Decimal::Decimal(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
	isN = d.isN;

	Clean();
}

Decimal Decimal::Parse(const String& str)
{
	Decimal r;

	String s(str);

	if (s.find('-') != String::npos)
	{
		r.isN = true;
		s = s.substr(1);
	}

	if (s.find('.') == String::npos)
	{
		s.insert(0, s.length() % 2, '0');

		for (size_t i = 0; i < s.length() / 2; i++)
			r.mInteger += ByteTool::IntsToByte(ByteTool::ToByte(s[i * 2]), ByteTool::ToByte(s[i * 2 + 1]));

		r.mReal += (Byte)0;
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
			r.mInteger += c;
		}

		for (size_t i = 0; i < real.length() / 2; i++)
		{
			Byte first = ByteTool::ToByte(real[i * 2]);
			Byte second = ByteTool::ToByte(real[i * 2 + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			r.mReal = c + r.mReal;
		}
	}

	r.Clean();

	return r;
}

Boolean Decimal::operator==(const Object& obj)
{
	if (is<const Decimal, std::remove_reference<const Object&>::type>())
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

Boolean Decimal::operator>(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);
	
	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one > b_one) return true;

		if (a_two > b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one > b_one) return true;

		if (a_two > b_two) return true;
	}

	return false;
}
Boolean Decimal::operator>(Decimal&& d) const
{
	Boolean r = false;

	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one > b_one) return true;

		if (a_two > b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one > b_one) return true;

		if (a_two > b_two) return true;
	}

	return r;
}

Boolean Decimal::operator>=(const Decimal& d) const
{
	Boolean r = false;

	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one >= b_one) return true;

		if (a_two >= b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one >= b_one) return true;

		if (a_two >= b_two) return true;
	}

	return r;
}
Boolean Decimal::operator>=(Decimal&& d) const
{
	Boolean r = false;

	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one >= b_one) return true;

		if (a_two >= b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one >= b_one) return true;

		if (a_two >= b_two) return true;
	}

	return r;
}

Boolean Decimal::operator<(const Decimal& d) const
{
	Boolean r = false;

	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one < b_one) return true;

		if (a_two < b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one < b_one) return true;

		if (a_two < b_two) return true;
	}

	return r;
}
Boolean Decimal::operator<(Decimal&& d) const
{
	Boolean r = false;

	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one < b_one) return true;

		if (a_two < b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one < b_one) return true;

		if (a_two < b_two) return true;
	}

	return r;
}

Boolean Decimal::operator<=(const Decimal& d) const
{
	Boolean r = false;

	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one <= b_one) return true;

		if (a_two <= b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one <= b_one) return true;

		if (a_two <= b_two) return true;
	}

	return r;
}
Boolean Decimal::operator<=(Decimal&& d) const
{
	Boolean r = false;

	Decimal a = *this;
	Decimal b = d;

	// 패딩

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 체크

	for (size_t i = 0; i < a.mInteger.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mInteger[i]);
		var temp_b = ByteTool::ByteToInts(b.mInteger[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one <= b_one) return true;

		if (a_two <= b_two) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one <= b_one) return true;

		if (a_two <= b_two) return true;
	}

	return r;
}

Decimal Decimal::operator=(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
	isN = d.isN;

	Clean();

	return *this;
}
Decimal Decimal::operator=(Decimal&& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
	isN = d.isN;

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

	if (isN)
		integer = "-" + integer;

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

	// 둘다 음수이거나 들다 양수일 때
	if (!a.isN && !b.isN || a.isN && b.isN)
	{
		c.isN = a.isN;

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
				up = temp04 > 9 ? 1 : 0;
				if (up != 0) temp04 -= 10;

				Byte temp03 = one_a + one_b + up;
				up = temp03 > 9 ? 1 : 0;
				if (up != 0) temp03 -= 10;

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
				up = temp04 > 9 ? 1 : 0;
				if (up != 0) temp04 -= 10;

				Byte temp03 = one_a + one_b + up;
				up = temp03 > 9 ? 1 : 0;
				if (up != 0) temp03 -= 10;

				c.mInteger.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));

				if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
			}

			c.mInteger = ByteTool::IntsToByte(0, up) + c.mInteger;
		}
	}
	// a가 양수일 때
	else if (!a.isN && b.isN)
	{
		Decimal d = b;
		d.isN = false;
		c = a - d;
	}
	// b가 양수일 때
	else if (a.isN && !b.isN)
	{
		Decimal d = a;
		d.isN = false;
		c = b - d;
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

	// 둘다 음수이거나 들다 양수일 때
	if (!a.isN && !b.isN || a.isN && b.isN)
	{
		c.isN = a.isN;

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
				up = temp04 > 9 ? 1 : 0;
				if (up != 0) temp04 -= 10;

				Byte temp03 = one_a + one_b + up;
				up = temp03 > 9 ? 1 : 0;
				if (up != 0) temp03 -= 10;

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
				up = temp04 > 9 ? 1 : 0;
				if (up != 0) temp04 -= 10;

				Byte temp03 = one_a + one_b + up;
				up = temp03 > 9 ? 1 : 0;
				if (up != 0) temp03 -= 10;

				c.mInteger.insert(0, 1, ByteTool::IntsToByte(temp03, temp04));

				if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
			}

			c.mInteger = ByteTool::IntsToByte(0, up) + c.mInteger;
		}
	}
	// a가 양수일 때
	else if (!a.isN && b.isN)
	{
		Decimal d = b;
		d.isN = false;
		c = a - d;
	}
	// b가 양수일 때
	else if (a.isN && !b.isN)
	{
		Decimal d = a;
		d.isN = false;
		c = b - d;
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

Decimal Decimal::operator-(const Decimal& d) const
{
	/*TODO
	
	- 내림 구현하기

	*/

	Decimal a = *this;
	Decimal b = Decimal(d);
	Decimal c = 0.0;
	c.mInteger = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();
	c.mReal = std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>>();

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	// 둘다 음수이거나 들다 양수일 때
	if (!a.isN && !b.isN || a.isN && b.isN)
	{
		c.isN = a.isN;

		if (!a.isN && !b.isN && a < b)
		{
			Decimal d = a;
			Decimal e = b;

			a = e;
			b = d;

			c.isN = true;
		}

		if (a.isN && b.isN && a < b)
		{
			Decimal d = b;
			
			d.isN = false;

			c = a + d;
		}
		else
		{
			{ // Real
				for (size_t i = a.mReal.length() - 1; i >= 0; i--)
				{
					var temp01 = ByteTool::ByteToInts(a.mReal[i]);

					var one_a = std::get<0>(temp01);
					var two_a = std::get<1>(temp01);

					var temp02 = ByteTool::ByteToInts(b.mReal[i]);

					var one_b = std::get<0>(temp02);
					var two_b = std::get<1>(temp02);

					Byte temp04 = two_a - two_b;

					Byte temp03 = one_a - one_b;

					c.mReal = ByteTool::IntsToByte(temp03, temp04) + c.mReal;;

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

					Byte temp04 = two_a - two_b;

					Byte temp03 = one_a - one_b;

					c.mInteger = ByteTool::IntsToByte(temp03, temp04) + c.mInteger;

					if (i == 0) break; // NOTE: size_t = unsigned long long이기 때문에 음수를 처리 못해서
				}
			}
		}
	} 
	// a가 양수일 때
	else if (!a.isN && b.isN)
	{
		Decimal d = b;
		d.isN = false;
		c = d + b;
	}
	// b가 양수일 때
	else if (a.isN && !b.isN)
	{
		Decimal d = b;
		d.isN = true;
		c = a + d;
	}

	c.Clean();

	return c;
}