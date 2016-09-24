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
	t.insert(0, max - t.length(), '0');

	if(t.length() != max)
		integer += std::stoll(t.substr(max));
	real = std::stoll(t.substr(0, max));

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
	var a = *this + d;

	integer = a.integer;
	real = a.real;

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

Decimal64 Decimal64::operator*(const Decimal64& d) const
{
	Int64 integer = 0;
	Decimal64 real = 0LL;

	integer = this->integer * d.integer;
	Decimal64 tmp = this->integer * d.real;
	if (d.real != 0)
	{
		for (size_t i = 0; i < std::to_string(d.real).length(); i++)
		{
			if (tmp.integer == 0)
			{
				tmp.real = std::stoll(std::to_string(tmp.real) + "0");
				continue;
			}

			String temp = std::to_string(tmp.real);
			String temp2 = std::to_string(tmp.integer);
			temp += temp2[temp2.length() - 1];
			temp2 = temp2.substr(0, temp2.length() - 1);

			tmp.integer = std::stoll(temp2);
			tmp.real = std::stoll(temp);
		}
	}
	integer += tmp.integer;
	real += Decimal64(0, tmp.real);

	Decimal64 tmp2 = this->real * d.integer;
	if (this->real != 0)
	{
		size_t c = std::to_string(this->real).length();
		for (size_t i = 0; i < c; i++)
		{
			if (tmp2.integer == 0)
			{
				tmp2.real = std::stoll(std::to_string(tmp2.real) + "0");
				continue;
			}

			String temp = std::to_string(tmp2.real);
			String temp2 = std::to_string(tmp2.integer);
			temp += temp2[temp2.length() - 1];
			temp2 = temp2.substr(0, temp2.length() - 1);
			if (temp2 == "")
				temp2 = "0";

			tmp2.integer = std::stoll(temp2);
			tmp2.real = std::stoll(temp);
		}
	}
	integer += tmp2.integer;
	real += Decimal64(0, tmp2.real);

	Decimal64 tmp3 = Decimal64(this->real * d.real);
	tmp3.real = 0;
	if (this->real != 0 || d.real != 0)
	{
		size_t c = std::to_string(this->real).length() + std::to_string(d.real).length();
		for (size_t i = 0; i < c; i++)
		{
			if (tmp3.integer == 0)
			{
				tmp3.real = std::stoll(std::to_string(tmp3.real) + "0");
				continue;
			}

			String temp = std::to_string(tmp3.real);
			String temp2 = std::to_string(tmp3.integer);
			temp += temp2[temp2.length() - 1];
			temp2 = temp2.substr(0, temp2.length() - 1);
			if (temp2 == "")
				temp2 = "0";

			tmp3.integer = std::stoll(temp2);
			tmp3.real = std::stoll(temp);
		}
	}
	integer += tmp3.integer;
	real += Decimal64(0, tmp3.real);

	Decimal64 r(integer, real.real);

	return r;
}

Decimal64 Decimal64::operator*(Decimal64&& d) const
{
	Int64 integer = 0, real = 0;

	integer = this->integer * d.integer;
	integer *= d.real;

	real = this->real * d.real;
	real *= d.integer;

	Decimal64 r(integer, real);

	return r;
}

Decimal64 Decimal64::operator*=(const Decimal64& d)
{
	var r = *this * d;

	integer = r.integer;
	real = r.real;

	return *this;
}

Decimal64 Decimal64::operator*=(Decimal64&& d)
{
	var r = *this * d;

	integer = r.integer;
	real = r.real;

	return *this;
}