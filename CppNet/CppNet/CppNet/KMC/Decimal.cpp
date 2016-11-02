#include "Decimal.h"
using namespace CppNet::KMC;
using namespace System;

// 소수점 아래 20자리까지 표현
const Decimal Decimal::E = Decimal("2.71828182845904523536");

// 소수점 아래 20자리까지 표현
const Decimal Decimal::PI = Decimal("3.14159265358979323846");

const Decimal Decimal::Zero = Decimal("0");
const Decimal Decimal::One = Decimal("1");
const Decimal Decimal::Two = Decimal("2");
const Decimal Decimal::Three = Decimal("3");
const Decimal Decimal::Four = Decimal("4");
const Decimal Decimal::Five = Decimal("5");
const Decimal Decimal::Six = Decimal("6");
const Decimal Decimal::Seven = Decimal("7");
const Decimal Decimal::Eight = Decimal("8");
const Decimal Decimal::Nine = Decimal("9");
const Decimal Decimal::Ten = Decimal("10");

const Decimal Decimal::NaN = Decimal("0") / Decimal("0");
const Decimal Decimal::PositiveInfinity = Decimal("1") / Decimal("0");
const Decimal Decimal::NegativeInfinity = Decimal("-1") / Decimal("0");
const Decimal Decimal::Ind = Decimal::NegativeInfinity - Decimal::NegativeInfinity;

Decimal::Decimal()
{
	mInteger.push_back(0);
	mReal.push_back(0);
}

Decimal::Decimal(const String& str)
	: Decimal(Parse(str))
{ }

Decimal::Decimal(UInt64 integer)
	: Decimal(std::to_string(integer))
{}

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
	operator=(d);
}

Decimal::Decimal(const Decimal& d)
{
	operator=(d);
}

Decimal Decimal::Parse(const String& str)
{
	Decimal r;

	String s(str);

	if (s[0] == '-')
	{
		r.isN = true;
		s.erase(s.begin());
	}

	if (s.find('.') == String::npos)
	{
		s.insert(0, s.length() & 1, '0');

		size_t n = s.length() >> 1;
		for (size_t i = 0; i < n; i++)
			r.mInteger += ByteTool::IntsToByte(ByteTool::ToByte(s[i << 1]), ByteTool::ToByte(s[(i << 1) + 1]));

		r.mReal += (Byte)0;
	}
	else
	{
		size_t dot = s.find('.');

		String integer = s.substr(0, dot);
		String real = s.substr(dot + 1);

		integer.insert(0, integer.length() & 1, '0');
		real.append(real.length() & 1, '0');

		for (size_t i = 0; i < integer.length() >> 1; i++)
		{
			Byte first = ByteTool::ToByte(integer[i << 1]);
			Byte second = ByteTool::ToByte(integer[(i << 1) + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			r.mInteger += c;
		}

		for (size_t i = 0; i < real.length() >> 1; i++)
		{
			Byte first = ByteTool::ToByte(real[i << 1]);
			Byte second = ByteTool::ToByte(real[(i << 1) + 1]);
			Byte c = ByteTool::IntsToByte(first, second);
			if (i == 0)
				r.mReal = c;
			else
				r.mReal += c;
		}
	}

	r.Clean();

	return r;
}

Boolean Decimal::operator==(const Object& obj) const
{
	if (is<const Decimal>(obj))
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

Boolean Decimal::operator!=(const Object& obj) const
{
	return !Decimal::operator==(obj);
}

Boolean Decimal::operator>(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;

	if (a.isN && !b.isN) return false;
	else if (!a.isN && b.isN) return true;

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

		if (a_one != 0 || b_one != 0)
			if ((!a.isN && a_one > b_one) || (a.isN && a_one < b_one)) return true;

		if (a_two != 0 || b_two != 0)
			if ((!a.isN && a_two > b_two) || (a.isN && a_two < b_two)) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one != 0 || b_one != 0)
			if ((!a.isN && a_one > b_one) || (a.isN && a_one < b_one)) return true;

		if (a_two != 0 || b_two != 0)
			if ((!a.isN && a_two > b_two) || (a.isN && a_two < b_two)) return true;
	}

	return false;
}

Boolean Decimal::operator<(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;

	if (!a.isN && b.isN) return false;
	else if (a.isN && !b.isN) return true;

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

		if (a_one != 0 || b_one != 0)
			if ((!a.isN && a_one < b_one) || (a.isN && a_one > b_one)) return true;

		if (a_two != 0 || b_two != 0)
			if ((!a.isN && a_two < b_two) || (a.isN && a_two > b_two)) return true;
	}

	for (size_t i = 0; i < a.mReal.length(); i++)
	{
		var temp_a = ByteTool::ByteToInts(a.mReal[i]);
		var temp_b = ByteTool::ByteToInts(b.mReal[i]);

		var a_one = std::get<0>(temp_a);
		var a_two = std::get<1>(temp_a);

		var b_one = std::get<0>(temp_b);
		var b_two = std::get<1>(temp_b);

		if (a_one != 0 || b_one != 0)
			if ((!a.isN && a_one < b_one) || (a.isN && a_one > b_one)) return true;

		if (a_two != 0 || b_two != 0)
			if ((!a.isN && a_two < b_two) || (a.isN && a_two > b_two)) return true;
	}

	return false;
}

Decimal& Decimal::operator=(const Decimal& d)
{
	mInteger = d.mInteger;
	mReal = d.mReal;
	isN = d.isN;
	isNaN = d.isNaN;
	isInf = d.isInf;
	isInd = d.isInd;

	Clean();

	return *this;
}
Decimal& Decimal::operator=(Decimal&& d)
{
	mInteger = std::move(d.mInteger);
	mReal = std::move(d.mReal);
	isN = std::move(d.isN);
	isNaN = std::move(d.isNaN);
	isInf = std::move(d.isInf);
	isInd = std::move(d.isInd);

	Clean();

	return *this;
}

String Decimal::ToString() const
{
	if (isNaN)
		return "nan";
	else if (isInf && !isN)
		return "inf";
	else if (isInf && isN)
		return "-inf";
	else if (isInd)
		return "-nan(ind)";

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
	if (d.ToString() == "0") return *this;
	else if (this->ToString() == "0") return d;

	if (this->isNaN || d.isNaN) return Decimal::NaN;
	else if (this->isInd || d.isInd) return Decimal::Ind;

	if (IsPositiveInfinity(*this) && IsPositiveInfinity(d)) return Decimal::PositiveInfinity;
	else if (IsNegativeInfinity(*this) && IsNegativeInfinity(d)) return Decimal::NegativeInfinity;
	else if (IsPositiveInfinity(*this) && IsNegativeInfinity(d)) return Decimal::Ind;
	else if (IsNegativeInfinity(*this) && IsPositiveInfinity(d)) return Decimal::Ind;

	Decimal a = *this;
	Decimal b = Decimal(d);
	Decimal c = 0;
	c.mInteger = (Byte)0;
	c.mReal = (Byte)0;

	Byte up = 0;

	// 둘다 음수이거나 들다 양수일 때
	if (!a.isN && !b.isN || a.isN && b.isN)
	{
		if (a.mReal.length() >= b.mReal.length())
			b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
		else
			a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

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
		Decimal _d = b;
		_d.isN = false;
		c = a - _d;
	}
	// b가 양수일 때
	else if (a.isN && !b.isN)
	{
		Decimal _d = a;
		_d.isN = false;
		c = b - _d;
	}

	c.Clean();

	return c;
}

Decimal& Decimal::operator+=(const Decimal& d)
{
	Decimal a = *this + d;

	mInteger = a.mInteger;
	mReal = a.mReal;

	return *this;
}

Decimal Decimal::operator++()
{
	Decimal a = *this + 1;

	mInteger = a.mInteger;

	return *this;
}
Decimal Decimal::operator++(int)
{
	Decimal a = *this + 1;
	Decimal b = *this;

	mInteger = a.mInteger;

	return b;
}

Decimal Decimal::operator-(const Decimal& d) const
{
	if (d.ToString() == "0") return *this;

	if (this->isNaN || d.isNaN) return Decimal::NaN;
	else if (this->isInd || d.isInd) return Decimal::Ind;

	if (IsPositiveInfinity(*this) && IsPositiveInfinity(d))
	{
		Decimal a;

		a.isInd = true;

		return a;
	}
	else if (IsNegativeInfinity(*this) && IsNegativeInfinity(d))
	{
		Decimal a;

		a.isInd = true;

		return a;
	}
	else if (IsPositiveInfinity(*this) && IsNegativeInfinity(d)) return Decimal::PositiveInfinity;
	else if (IsNegativeInfinity(*this) && IsPositiveInfinity(d)) return Decimal::NegativeInfinity;

	if (isN && !d.isN)
	{
		Decimal d_t = d;
		d_t.isN = true;
		return this->operator+(d_t);
	}
	else if (isN && d.isN)
	{
		Decimal d_t = d;
		d_t.isN = false;
		return this->operator+(d_t);
	}
	else if (!isN && d.isN)
	{
		Decimal d_t = d;
		d_t.isN = false;
		return this->operator+(d_t);
	}
	bool sign = this->operator>=(d);
	Decimal bigger = sign ? *this : d, smaller = sign ? d : *this;
	//패딩
	smaller.mInteger.insert(smaller.mInteger.begin(), bigger.mInteger.length() - smaller.mInteger.length(), 0x00);

	//소수부분 패딩은 자릿수 계산 후에
	bool t = bigger.mReal.length() >= smaller.mReal.length();
	Decimal* shorter = t ? &smaller : &bigger, *longer = t ? &bigger : &smaller;
	shorter->mReal.append(longer->mReal.length() - shorter->mReal.length(), 0x00);

	//소수부분부터 보수로 변환
	//reverse iterator을 사용하는 이유는 끝부터 0이 아님을 체크하기 때문
	auto revit = std::find_if(
		smaller.mReal.rbegin(), smaller.mReal.rend(),
		[](auto byte)
	{
		return byte == 0 ? false : true;
	}
	);
	//t가 false이면 소수 부분이 0인 경우입니다
	if (t = revit != smaller.mReal.rend())
	{
		if (!(*revit & 0x0F))
		{
			*revit = (10 - (*revit >> 4)) << 4;
			++revit;
		}
		else
			*revit -= 1;
	}
	for (; revit != smaller.mReal.rend(); ++revit)
		*revit = (9 - (*revit >> 4)) << 4 | (9 - (*revit & 0x0F));
	//소수 변환 완료

	//소수부분이 0일 경우 정수부분에서도 0을 무시해줘야 합니다
	revit = smaller.mInteger.rbegin();
	if (!t)
	{
		revit = std::find_if(revit, smaller.mInteger.rend(),
			[](auto byte)
		{
			return byte == 0 ? false : true;
		}
		);
		if (revit != smaller.mInteger.rend())
		{
			if (!(*revit & 0x0F))
			{
				*revit = (10 - (*revit >> 4)) << 4;
				++revit;
			}
			else
				*revit -= 1;
		}
	}
	//revit이 처음부터 rend일 경우 따로 처리를 안 해줘도 됩니다.
	for (; revit != smaller.mInteger.rend(); ++revit)
		*revit = (9 - (*revit >> 4)) << 4 | (9 - (*revit & 0x0F));

	//맨 앞쪽은 0 ? 혹은 ? ? 이므로
	//0 ?일 경우 지워줍니다.
	if (!(bigger.mInteger[0] >> 4))
		smaller.mInteger[0] &= 0x0F;

	Decimal ret = bigger + smaller;
	//맨 앞자리는 0 1 혹은 1 ? 입니다.
	//1을 지워줍니다.
	if (ret.mInteger[0] >> 4)
		ret.mInteger[0] &= 0x0F;
	else if (ret.mInteger.length() != 1)
		ret.mInteger.erase(ret.mInteger.begin());

	//부호도 빼먹으면 안됩니다.
	ret.isN = !sign;

	return ret;
}

Decimal& Decimal::operator-=(const Decimal& d)
{
	Decimal a = *this - d;

	mInteger = a.mInteger;
	mReal = a.mReal;

	return *this;
}

Decimal Decimal::operator--()
{
	Decimal a = *this - 1;

	mInteger = a.mInteger;

	return *this;
}
Decimal Decimal::operator--(int)
{
	Decimal a = *this - 1;
	Decimal b = *this;

	mInteger = a.mInteger;

	return b;
}

Decimal Decimal::operator*(const Decimal& d) const
{
	// 불필요한 연산 방지
	if (d.ToString() == "1") return *this;
	else if (this->ToString() == "1") return d;
	else if (d.ToString() == "0" || this->ToString() == "0") return 0.0;

	if (this->isNaN || d.isNaN) return Decimal::NaN;
	else if (this->isInd || d.isInd) return Decimal::Ind;

	if (IsPositiveInfinity(*this) && IsPositiveInfinity(d)) return Decimal::PositiveInfinity;
	else if (IsNegativeInfinity(*this) && IsNegativeInfinity(d)) return Decimal::PositiveInfinity;
	else if (IsPositiveInfinity(*this) && IsNegativeInfinity(d)) return Decimal::NegativeInfinity;
	else if (IsNegativeInfinity(*this) && IsPositiveInfinity(d)) return Decimal::NegativeInfinity;

	// 미리 선언
	Decimal a = *this;
	Decimal b = d;
	Decimal result;

	if (a.isN && b.isN)
		result.isN = false;
	else if ((a.isN && !b.isN) || (!a.isN && b.isN))
		result.isN = true;

	size_t count_real_size = 0;

	// 패딩 편의 및 연산 속도 향상을 위해
	a.Clean();
	b.Clean();

	// 실수점 이하 부분이 0이 아닐경우 자연수 부분에 포함
	if (a.mReal[0] != 0 || a.mReal.length() > 1)
		a.mInteger += a.mReal;

	if (b.mReal[0] != 0 || b.mReal.length() > 1)
		b.mInteger += b.mReal;

	// 실수점 이하 부분이 0이 아닐경우 0으로 만들고 실수점 위치 저장
	if (a.mReal.length() > 1 || a.mReal[0] != 0)
	{
		count_real_size = a.mReal.length() * 2;
		a.mReal = (Byte)0;
	}

	if (b.mReal.length() > 1 || b.mReal[0] != 0)
	{
		count_real_size += b.mReal.length() * 2;
		b.mReal = (Byte)0;
	}

	// 패딩
	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	// 연산
	String plus = "";

	if (a.isInf || b.isInf) goto Z;

	for (size_t i = b.mInteger.length() - 1; i >= 0; i--)
	{
		Byte up = 0;
		String value = "";

		auto b_byte = ByteTool::ByteToInts(b.mInteger.at(i));

		Byte low = std::get<1>(b_byte); // 12에서 2에 해당됨
		Byte high = std::get<0>(b_byte); // 12에서 1에 해당됨

		if (low == 0)
			goto X;

		// low 먼저 계산
		for (size_t j = a.mInteger.length() - 1; j >= 0; j--)
		{
			auto a_byte = ByteTool::ByteToInts(a.mInteger.at(j));

			Byte low_a = std::get<1>(a_byte);
			Byte high_a = std::get<0>(a_byte);

			Byte low_mul = low * low_a + up;
			up = 0;
			if (low_mul > 9)
			{
				up = std::stoi(std::to_string(low_mul).substr(0, 1));
				low_mul = std::stoi(std::to_string(low_mul).substr(1));
			}

			Byte high_mul = low * high_a + up;
			up = 0;
			if (high_mul > 9)
			{
				up = std::stoi(std::to_string(high_mul).substr(0, 1));
				high_mul = std::stoi(std::to_string(high_mul).substr(1));
			}

			value = std::to_string(high_mul) + std::to_string(low_mul) + value;

			if (j == 0)
			{
				value = std::to_string(up) + value;

				break;
			}
		}

	X:
		value += plus;
		plus += '0';

		result += value;

		// 초기화
		value = ""; up = 0;

		if (high == 0)
			goto Y;

		// high 계산
		for (size_t j = a.mInteger.length() - 1; j >= 0; j--)
		{
			auto a_byte = ByteTool::ByteToInts(a.mInteger.at(j));

			Byte low_a = std::get<1>(a_byte);
			Byte high_a = std::get<0>(a_byte);

			Byte low_mul = high * low_a + up;
			up = 0;
			if (low_mul > 9)
			{
				up = std::stoi(std::to_string(low_mul).substr(0, 1));
				low_mul = std::stoi(std::to_string(low_mul).substr(1));
			}

			Byte high_mul = high * high_a + up;
			up = 0;
			if (high_mul > 9)
			{
				up = std::stoi(std::to_string(high_mul).substr(0, 1));
				high_mul = std::stoi(std::to_string(high_mul).substr(1));
			}

			value = std::to_string(high_mul) + std::to_string(low_mul) + value;

			if (j == 0)
			{
				value = std::to_string(up) + value;

				break;
			}
		}

	Y:
		value += plus;
		plus += '0';

		result += value;

		if (i == 0) break; // i--을 연산을 수행한 후 i >= 0을 수행하는데, unsigned라 overflow가 발생하기 때문
	}

	goto Z;

Z:
	if (count_real_size != 0)
	{
		String to = result.ToString();

		if (count_real_size >= to.length())
			to.insert(0, count_real_size - to.length(), '0');

		String integer = to.substr(0, to.length() - count_real_size);
		String real = to.substr(to.length() - count_real_size);

		result = Decimal(integer + "." + real);
	}

	if (a.isN && b.isN)
		result.isN = false;
	else if ((a.isN && !b.isN) || (!a.isN && b.isN))
		result.isN = true;

	result.Clean();

	return result;
}

Decimal& Decimal::operator*=(const Decimal& d)
{
	Decimal a = *this * d;

	mInteger = a.mInteger;
	mReal = a.mReal;

	return *this;
}

Decimal Decimal::operator&(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;
	Decimal result;

	// 패딩 편의를 위한

	a.Clean(); b.Clean();

	// 패딩

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	// & 연산

	for (size_t i = 0; i < a.mInteger.length(); i++)
		result.mInteger += a.mInteger.at(i) & b.mInteger.at(i);

	for (size_t i = 0; i < a.mReal.length(); i++)
		result.mReal += a.mReal.at(i) & b.mReal.at(i);

	return result;
}
Decimal& Decimal::operator&=(const Decimal& d)
{
	Decimal temp = this->operator&(d);

	this->operator=(temp);

	return *this;
}

Decimal Decimal::operator|(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;
	Decimal result;

	// 패딩 편의를 위한

	a.Clean(); b.Clean();

	// 패딩

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	// | 연산

	for (size_t i = 0; i < a.mInteger.length(); i++)
		result.mInteger += a.mInteger.at(i) | b.mInteger.at(i);

	for (size_t i = 0; i < a.mReal.length(); i++)
		result.mReal += a.mReal.at(i) | b.mReal.at(i);

	return result;
}
Decimal& Decimal::operator|=(const Decimal& d)
{
	Decimal temp = this->operator|(d);

	this->operator=(temp);

	return *this;
}

Decimal Decimal::operator^(const Decimal& d) const
{
	Decimal a = *this;
	Decimal b = d;
	Decimal result;

	// 패딩 편의를 위한

	a.Clean(); b.Clean();

	// 패딩

	if (a.mInteger.length() >= b.mInteger.length())
		b.mInteger.insert(0, a.mInteger.length() - b.mInteger.length(), 0);
	else
		a.mInteger.insert(0, b.mInteger.length() - a.mInteger.length(), 0);

	if (a.mReal.length() >= b.mReal.length())
		b.mReal.insert(b.mReal.length(), a.mReal.length() - b.mReal.length(), 0);
	else
		a.mReal.insert(a.mReal.length(), b.mReal.length() - a.mReal.length(), 0);

	// ^ 연산

	for (size_t i = 0; i < a.mInteger.length(); i++)
		result.mInteger += a.mInteger.at(i) ^ b.mInteger.at(i);

	for (size_t i = 0; i < a.mReal.length(); i++)
		result.mReal += a.mReal.at(i) ^ b.mReal.at(i);

	return result;
}
Decimal& Decimal::operator^=(const Decimal& d)
{
	Decimal temp = this->operator^(d);

	this->operator=(temp);

	return *this;
}

Decimal Decimal::operator/(const Decimal& d) const
{
	if (d.ToString() == "0")
	{
		Decimal a;

		if (this->ToString() == "0")
			a.isNaN = true;
		else if (this->isN)
		{
			a.isN = true;
			a.isInf = true;
		}
		else
		{
			a.isN = false;
			a.isInf = true;
		}

		return a;
	}

	if (this->isNaN || d.isNaN) return Decimal::NaN;
	else if (this->isInd || d.isInd) return Decimal::Ind;

	if (IsPositiveInfinity(*this) && IsPositiveInfinity(d)) return Decimal::Ind;
	else if (IsNegativeInfinity(*this) && IsNegativeInfinity(d)) return Decimal::Ind;
	else if (IsPositiveInfinity(*this) && IsNegativeInfinity(d)) return Decimal::Ind;
	else if (IsNegativeInfinity(*this) && IsPositiveInfinity(d)) return Decimal::Ind;

	Decimal a = *this;
	Decimal b = d;
	Decimal result;

	return result;
}
Decimal& Decimal::operator/=(const Decimal& d)
{
	return this->operator=(this->operator/(d));
}

Decimal& Decimal::Pow(Decimal exp)
{
	// 도비님 제공. 감사합니다!

	if (this->isNaN || this->isInf) return *this;

	Decimal bin = *this, ret = 1.0;

	while (exp > 0)
	{
		if (exp % 2 == Decimal(1LL))
			ret = ret * bin;

		exp /= 2;
		bin = bin * bin;
	}

	return operator=(exp);
}

Decimal Decimal::operator%(const Decimal& d) const
{
	if (this->isNaN || d.isNaN) return Decimal::NaN;
	else if (this->isInd || d.isInd) return Decimal::Ind;

	if (IsPositiveInfinity(*this) && IsPositiveInfinity(d)) return Decimal::Ind;
	else if (IsNegativeInfinity(*this) && IsNegativeInfinity(d)) return Decimal::Ind;
	else if (IsPositiveInfinity(*this) && IsNegativeInfinity(d)) return Decimal::Ind;
	else if (IsNegativeInfinity(*this) && IsPositiveInfinity(d)) return Decimal::Ind;

	return Decimal();
}
Decimal& Decimal::operator%=(const Decimal& d)
{
	return this->operator=(this->operator%(d));
}

Decimal& Decimal::Sqrt()
{
	// http://blog.daum.net/_blog/BlogTypeView.do?blogid=0Xrxs&articleno=41

	if (this->isNaN || this->isInf) return *this;

	Decimal x = 1;

	for (Decimal i = 0; i < 10; i++)
		x = (x + (*this / x)) / 2;

	return this->operator=(x);
}