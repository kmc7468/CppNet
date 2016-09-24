#include "Decimal64.h"
#include "../../Math.h"
using namespace System;
using namespace CSClasses::KMC;

String Decimal64::ToString() const
{
	if (real == 0)
	{
		return std::to_string((Int64)(integer));
	}
	else
	{
		String temp = std::to_string((Int64)(real));
		String add = integer == -1 ? "-" : "";
		return add + std::to_string(integer < 0 ? integer + 1 : integer) + "." + String(temp.rbegin(), temp.rend());
	}
}

String Decimal64::ToString(size_t realsize) const
{
	if (realsize == 0)
	{
		return std::to_string(integer);
	}
	else
	{
		String temp = std::to_string((Int64)(real));
		String temp2 = String(temp.rbegin(), temp.rend()).substr(0, realsize);
		temp2.insert(0, realsize - temp2.length(), '0');
		String add = integer == -1 < 0 ? "-" : "";
		return add + std::to_string(integer < 0 ? integer + 1 : integer) + "." + temp2;
	}
}

Double Decimal64::ToReal64() const
{
	return std::stod(ToString());
}

Double Decimal64::ToReal64(size_t realsize) const
{
	return std::stod(ToString(realsize));
}

Int64 Decimal64::ToInt64() const
{
	return integer;
}

Decimal64 Decimal64::operator=(const Decimal64& d) const
{
	return Decimal64(d);
}

Decimal64 Decimal64::operator=(Decimal64&& d) const
{
	return Decimal64(d);
}

Decimal64 Decimal64::operator+(const Decimal64& d) const
{
	Int64 integer = this->integer + d.integer;
	Int64 real = this->real + d.real;

	var max = Math::Max(std::to_string(d.real).length(), std::to_string(this->real).length());

	String t = std::to_string(real);
	t.insert(0, max - t.length() + 1, '0');

	integer += std::stoll(t.substr(0, max));
	real = std::stoll(t.substr(max));

	Decimal64 r(integer, real);

	return r;
}

Decimal64 Decimal64::operator+(Decimal64&& d) const
{
	Int64 integer = this->integer + d.integer;
	Int64 real = this->real + d.real;

	var max = Math::Max(std::to_string(d.real).length(), std::to_string(this->real).length());

	String t = std::to_string(real);
	t.insert(0, max - t.length() + 1, '0');

	integer += std::stoll(t.substr(0, max));
	real = std::stoll(t.substr(max));

	Decimal64 r(integer, real);

	return r;
}

Decimal64 Decimal64::operator+=(const Decimal64& d)
{
	var a = *this + d;

	integer = a.integer;
	real = a.real;

	return *this;
}

Decimal64 Decimal64::operator+=(Decimal64&& d)
{
	integer += d.integer;
	real += d.real;

	return *this;
}

Decimal64 Decimal64::operator++()
{
	integer += 1;

	return *this;
}

Decimal64 Decimal64::operator++(int)
{
	var r = *this;

	integer += 1;

	return r;
}

Decimal64 Decimal64::operator-(const Decimal64& d) const
{
	Int64 integer = this->integer - d.integer;
	Int64 real = 0;

	if (this->real >= d.real)
	{
		real = this->real - d.real;
	}
	else
	{
		Int64 down = 0;
		integer = this->integer;

		do
		{
			integer -= 1;
			down += 10;
			real = this->real - d.real + down;
		} while (real < 0);

		integer -= d.integer;
	}

	Decimal64 r(integer, real);

	return r;
}

Decimal64 Decimal64::operator-(Decimal64&& d) const
{
	Decimal64 r(integer - d.integer, real - d.real);

	return r;
}

Decimal64 Decimal64::operator-=(const Decimal64& d)
{
	var a = *this - d;

	integer = a.integer;
	real = a.real;

	return *this;
}

Decimal64 Decimal64::operator-=(Decimal64&& d)
{
	var a = *this - d;

	integer = a.integer;
	real = a.real;

	return *this;
}

Decimal64 Decimal64::operator--()
{
	integer -= 1;

	return *this;
}

Decimal64 Decimal64::operator--(int)
{
	var r = *this;

	integer -= 1;

	return r;
}