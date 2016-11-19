#include "Fraction.h"

#include "../../Defines.h"
#include "../../Language.h"

namespace CppNet::KMC
{
	template<typename integer>
	Fraction<integer>::Fraction(integer numerator)
	{
		this->numerator = numerator;
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
		if (fraction.find('/') == String::npos)
		{
			throw FormatException(Exception::ExceptionData(TXT_FORMAT_FRACTION_NOSLASH, "", "", nullptr));
		}

		String n = fraction.substr(0, fraction.find('/'));
		String d = fraction.substr(fraction.find('/') + 1);

		UInt64 temp1 = std::stoull(n);
		UInt64 temp2 = std::stoull(d);

		numerator = (integer)temp1;
		denominator = (integer)temp2;
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
	Fraction<integer> Fraction<integer>::Irreducible(const Fraction<integer>& f)
	{
		Fraction<integer> r(f);

		integer div = gcd(r.numerator, r.denominator);

		r.numerator /= div;
		r.denominator /= div;

		return r;
	}

	template<typename integer>
	Fraction<integer>& Fraction<integer>::Irreducible()
	{
		integer div = gcd(numerator, denominator);

		numerator /= div;
		denominator /= div;

		return *this;
	}

	template<typename integer>
	Tuple<Fraction<integer>, Fraction<integer>> Fraction<integer>::Reduce(const Fraction<integer>& a, const Fraction<integer>& b)
	{
		Fraction<integer> first(a);
		Fraction<integer> last(b);

		integer mul = lcm(first.denominator, last.denominator);

		first.numerator = first.numerator * (mul / first.denominator);
		last.numerator = last.numerator * (mul / last.denominator);

		first.denominator = mul;
		last.denominator = mul;

		return std::make_tuple(first, last);
	}

	template<typename integer>
	Tuple<Fraction<integer>, Fraction<integer>> Fraction<integer>::Reduce(const Fraction<integer>& f)
	{
		Fraction<integer> last(f);

		integer mul = lcm(denominator, last.denominator);

		numerator = numerator * (mul / denominator);
		last.numerator = last.numerator * (mul / last.denominator);

		denominator = mul;
		last.denominator = mul;

		return std::make_tuple(*this, last);
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

	template<typename integer>
	String Fraction<integer>::ToString() const
	{
		return std::to_string(numerator) + "/" + std::to_string(denominator);
	}

	template<typename integer>
	Object Fraction<integer>::Clone()
	{
		return Fraction<integer>(*this);
	}

	template<typename integer>
	Double Fraction<integer>::ToReal64() const
	{
		return (Double)numerator / (Double)denominator;
	}

	template<typename integer>
	Decimal Fraction<integer>::ToReal() const
	{
		// TODO: Decimal에 나눗셈이 구현되면 주석 해제 후 임시 코드 삭제 바람
		/*Decimal a((Double)numerator);
		Decimal b((Double)denominator);

		return a / b;*/

		return Decimal(ToReal64());
	}

	template<typename integer>
	Boolean Fraction<integer>::operator==(const Object& obj) const
	{
		if (is<const Fraction<integer>, std::remove_reference<const Object&>::type>())
		{
			var a = as<const Fraction<integer>&>(obj);

			Fraction<integer> b(a);

			b.Irreducible();

			Fraction<integer> c(*this);

			c.Irreducible();

			if (b.ToString() == c.ToString())
				return true;
			else
				return false;
		}
		else
			return false;
	}

	template<typename integer>
	Boolean Fraction<integer>::operator!=(const Object& obj) const
	{
		return !((*this).operator==(obj));
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator+(const Fraction<integer>& f) const
	{
		var t = Fraction<integer>::Reduce(*this, f);

		Fraction<integer> a = std::get<0>(t);
		Fraction<integer> b = std::get<1>(t);

		a.numerator += b.numerator;

		return a;
	}

	template<typename integer>
	Fraction<integer>& Fraction<integer>::operator+=(const Fraction<integer>& f)
	{
		var t = Fraction<integer>::Reduce(*this, f);

		Fraction<integer> a = std::get<0>(t);
		Fraction<integer> b = std::get<1>(t);

		a.numerator += b.numerator;

		numerator = a.numerator;
		denominator = a.denominator;

		return *this;
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator++()
	{
		numerator += 1;

		return *this;
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator++(int)
	{
		Fraction<integer> i = *this;

		numerator += 1;

		return i;
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator-(const Fraction<integer>& f) const
	{
		var t = Fraction<integer>::Reduce(*this, f);

		Fraction<integer> a = std::get<0>(t);
		Fraction<integer> b = std::get<1>(t);

		a.numerator -= b.numerator;

		return a;
	}

	template<typename integer>
	Fraction<integer>& Fraction<integer>::operator-=(const Fraction<integer>& f)
	{
		var t = Fraction<integer>::Reduce(*this, f);

		Fraction<integer> a = std::get<0>(t);
		Fraction<integer> b = std::get<1>(t);

		a.numerator -= b.numerator;

		numerator = a.numerator;
		denominator = a.denominator;

		return *this;
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator--()
	{
		numerator -= 1;

		return *this;
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator--(int)
	{
		Fraction<integer> i = *this;

		numerator -= 1;

		return i;
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator*(const Fraction<integer>& f) const
	{
		Fraction<integer> a = *this;
		Fraction<integer> b = f;

		a.numerator *= b.numerator;
		a.denominator *= b.denominator;

		return a;
	}

	template<typename integer>
	Fraction<integer>& Fraction<integer>::operator*=(const Fraction<integer>& f)
	{
		Fraction<integer> a = *this;
		Fraction<integer> b = f;

		a.numerator *= b.numerator;
		a.denominator *= b.denominator;

		numerator = a.numerator;
		denominator = a.denominator;

		return *this;
	}

	template<typename integer>
	Fraction<integer> Fraction<integer>::operator/(const Fraction<integer>& f) const
	{
		Fraction<integer> a = *this;
		Fraction<integer> b = f;
		b.inverse();

		a.numerator *= b.numerator;
		a.denominator *= b.denominator;

		return a;
	}

	template<typename integer>
	Fraction<integer>& Fraction<integer>::operator/=(const Fraction<integer>& f)
	{
		Fraction<integer> a = *this;
		Fraction<integer> b = f;
		b.inverse();

		a.numerator *= b.numerator;
		a.denominator *= b.denominator;

		numerator = a.numerator;
		denominator = a.denominator;

		return *this;
	}

	template<typename integer>
	void Fraction<integer>::inverse()
	{
		integer a = denominator;
		integer b = numerator;

		numerator = a;
		denominator = b;
	}
}