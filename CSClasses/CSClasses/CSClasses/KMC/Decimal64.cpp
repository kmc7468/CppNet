#include "Decimal64.h"
using namespace System;
using namespace CSClasses::KMC;

Decimal64::Decimal64(const String& str)
{
	size_t dot = str.find('.');
	if (dot == String::npos)
	{
		integer = std::stoll(str);
		real = 0;
	}
	else
	{
		integer = std::stoll(str.substr(0, dot));
		String temp = str.substr(dot + 1);
		String real_str(temp.rbegin(), temp.rend());
		real = std::stoll(real_str);
	}
}

Decimal64::Decimal64(Int64 integer)
{
	this->integer = integer;
	real = 0;
}

Decimal64::Decimal64(Double real)
	: Decimal64(std::to_string(real))
{ }

Decimal64::Decimal64(Int64 integer, const String& str)
{
	this->integer = integer;

	real = std::stoll(String(str.rbegin(), str.rend()));
}

Decimal64::Decimal64(Decimal64&& d)
{
	integer = d.integer;
	real = d.real;
}

Decimal64::Decimal64(const Decimal64& d)
{
	integer = d.integer;
	real = d.real;
}

Decimal64::Decimal64(Int64 integer, Int64 real)
{
	this->integer = integer;
	this->real = real;
}