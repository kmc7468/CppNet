#include "Decimal.h"

#include "../System/BitConverter.h"

namespace CppNet::KMC
{
	using namespace CppNet::System;

	Byte Decimal::ByteTool::IntsToByte(Byte a, Byte b)
	{
		return (a << 4) | (b & 0xF);
	}

	std::tuple<Byte, Byte> Decimal::ByteTool::ByteToInts(Byte b)
	{
		return std::make_tuple(b >> 4, b & 0xF);
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

		if (a == "nan" || a == "inf" || a == "-inf") return a;

		size_t find = a.find('.');

		if (find == String::npos) return a;

		size_t r_size = a.substr(a.find('.')).length();

		if (r_size <= realsize)
		{
			a.insert(a.length(), realsize - r_size + 1, '0');
			return a;
		}

		a = a.substr(0, find) + a.substr(find, realsize + 1);

		if (a.back() == '.')
			a = a.substr(0, a.length() - 1);

		return a;
	}

	void Decimal::Clean()
	{
		while (mReal.size() > 1 && mReal[mReal.size() - 1] == 0)
			mReal.erase(mReal.begin() + (mReal.size() - 1));

		while (mInteger.size() > 1 && mInteger[0] == 0)
			mInteger.erase(mInteger.begin());

		if (mInteger.length() == 1 && mInteger[0] == 0 && mReal.length() == 1 && mReal[0] == 0 && isN)
			isN = false;

		if (this->isNaN || this->isInf)
		{
			mInteger.clear();
			mReal.clear();

			mInteger += (Byte)0;
			mReal += (Byte)0;
		}

		if (this->isNaN)
			isN = false;
	}

	Decimal Decimal::Parse(UInt64 integer)
	{
		return Parse(std::to_string(integer));
	}

	Decimal Decimal::Parse(Int64 integer)
	{
		return Parse(std::to_string(integer));
	}

	Decimal Decimal::Parse(Int64 integer, const String& real)
	{
		return Parse(std::to_string(integer) + "." + real);
	}

	Decimal Decimal::Parse(Double real)
	{
		return Parse(std::to_string(real));
	}

	Boolean Decimal::operator>=(const Decimal& d) const
	{
		Decimal a = *this;
		Decimal b = d;

		Boolean res = a > b;

		return res ? res : a == b;
	}

	Boolean Decimal::operator<=(const Decimal& d) const
	{
		Decimal a = *this;
		Decimal b = d;

		Boolean res = a < b;

		return res ? res : a == b;
	}

	Boolean Decimal::IsPositiveInfinity(const Decimal& d)
	{
		return d.isInf && !d.isN;
	}

	Boolean Decimal::IsNegativeInfinity(const Decimal& d)
	{
		return d.isInf && d.isN;
	}

	Boolean Decimal::IsPositive(const Decimal& d)
	{
		return !d.isNaN && !d.isInf && !d.isN;
	}

	Boolean Decimal::IsNegative(const Decimal& d)
	{
		return !d.isNaN && !d.isInf && d.isN;
	}

	Boolean Decimal::IsNaN(const Decimal& d)
	{
		return d.isNaN;
	}

	Decimal Decimal::Pow(const Decimal& base, const Decimal& exp)
	{
		Decimal a = base;

		return a.Pow(exp);
	}

	Decimal Decimal::Sqrt(const Decimal& base)
	{
		Decimal a = base;

		a.Sqrt();

		return a;
	}
}