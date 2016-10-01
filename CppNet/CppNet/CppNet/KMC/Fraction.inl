#include "Fraction.h"
using namespace CppNet::KMC;

template<typename integer>
Fraction<integer>::Fraction(integer denominator)
{
	this->denominator = denominator;
}

template<typename integer>
Fraction<integer>::Fraction(integer numerator, integer denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

template<typename integer>
Fraction<integer>::Fraction(const Decimal& decimal)
{
	String str = decimal.ToString();
	size_t real_len = str.substr(str.find('.') + 1);

	for (size_t i = 0; i < real_len; i++)
		denominator *= 10;

	String str2 = str.substr(0, str.find('.'));
	str2 += str.substr(str.find('.') + 1);

	UInt64 temp = std::stoull(str2);

	numerator = (integer)str2;
}

template<typename integer>
Fraction<integer>::Fraction(const String& fraction)
{
	String n = fraction.substr(0, fraction.find('/'));
	String d = fraction.substr(fraction.find('/') + 1);

	UInt64 temp1 = std::stoull(n);
	UInt64 temp2 = std::stoull(d);

	numerator = (integer)temp1;
	denominator = (integer)temp02;
}

template<typename integer>
Fraction<integer>::Fraction(const Fraction<integer>& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
}

template<typename integer>
Fraction<integer>::Fraction(Fraction<integer>&& f)
{
	numerator = std::move(f.numerator);
	denominator = std::move(f.denominator);
}

template<typename integer>
Fraction<integer> Fraction<integer>::ROAF()
{
	integer div = gcd(numerator, denominator);

	numerator /= div;
	denominator /= div;

	return *this;
}

template<typename integer>
std::tuple<Fraction<integer>, Fraction<integer>> Fraction<integer>::RTCD(const Fraction<integer>& extra)
{
	Fraction<integer> a(1);
	Fraction<integer> b(1);

	integer mul = lcm(denominator, extra.denominator);

	a.denominator = mul;
	b.denominator = mul;

	a.numerator = numerator * (mul / denominator);
	b.numerator = extra.numerator * (mul / extra.denominator);

	return std::make_tuple(a, b);
}

template<typename integer>
integer Fraction<integer>::gcd(integer a, integer b)
{
	integer c;

	while (a != 0)
	{
		c = a;
		a = b % a;
		b = c;
	}

	return b;
}

template<typename integer>
integer Fraction<integer>::lcm(integer a, integer b)
{
	integer temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

template<typename integer>
Fraction<integer>& Fraction<integer>::operator=(const Fraction<integer>& f)
{
	numerator = f.numerator;
	denominator = f.denominator;

	return *this;
}

template<typename integer>
Fraction<integer>& Fraction<integer>::operator=(Fraction<integer>&& f)
{
	numerator = std::move(f.numerator);
	denominator = std::move(f.denominator);

	return *this;
}