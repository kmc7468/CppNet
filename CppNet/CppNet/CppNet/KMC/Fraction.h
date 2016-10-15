#ifndef CPPNET_KMC_FRACTION_H
#define CPPNET_KMC_FRACTION_H

#include "../../Defines.h"

#include <tuple>

#include "../../SystemTypes.h"
using namespace System;

#include "Decimal.h"

namespace CppNet
{
	namespace KMC
	{
		template<typename integer = UInt32>
		class Fraction final : public Object, public ICloneable
		{
		public:
			Fraction(integer numerator);
			Fraction(integer numerator, integer denominator);
			Fraction(const Decimal& decimal);
			Fraction(const String& fraction);
			Fraction(const Fraction<integer>& f);
			Fraction(Fraction<integer>&& f);
			~Fraction() = default;

		public:
			inline String ToString() const override;
			inline Object Clone() override;
			inline Double ToReal64() const;
			inline Decimal ToReal() const;

		private:
			integer numerator = 1;
			integer denominator = 1;

			static inline integer gcd(integer a, integer b); // 최대 공약수
			static inline integer lcm(integer a, integer b); // 최소 공배수
			inline void inverse();

		public:
			Fraction<integer>& operator=(const Fraction<integer>& f);
			Fraction<integer>& operator=(Fraction<integer>&& f);

			Boolean operator==(const Object& obj) const override;
			Boolean operator!=(const Object& obj) const override;

			Fraction<integer> operator+(const Fraction<integer>& f) const;
			Fraction<integer>& operator+=(const Fraction<integer>& f);
			Fraction<integer> operator++();
			Fraction<integer> operator++(int);

			Fraction<integer> operator-(const Fraction<integer>& f) const;
			Fraction<integer>& operator-=(const Fraction<integer>& f);
			Fraction<integer> operator--();
			Fraction<integer> operator--(int);

			Fraction<integer> operator*(const Fraction<integer>& f) const;
			Fraction<integer>& operator*=(const Fraction<integer>& f);

			Fraction<integer> operator/(const Fraction<integer>& f) const;
			Fraction<integer>& operator/=(const Fraction<integer>& f);

		public: 
			static Fraction<integer> Irreducible(const Fraction<integer>& f);
			Fraction<integer>& Irreducible();

			static Tuple<Fraction<integer>, Fraction<integer>> Reduce(const Fraction<integer>& a, const Fraction<integer>& b);
			Tuple<Fraction<integer>, Fraction<integer>> Reduce(const Fraction<integer>& f);
		};

		using Fraction64 = Fraction<UInt64>;
		using Fraction32 = Fraction<UInt32>;
		using Fraction16 = Fraction<UInt16>;
		using Fraction8 = Fraction<Byte>;
	}
}

#include "Fraction.inl"

#endif