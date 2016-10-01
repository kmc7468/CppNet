#ifndef CPPNET_KMC_FRACTION_H
#define CPPNET_KMC_FRACTION_H

#include <tuple>

#include "../../SystemTypes.h"
using namespace System;

#include "Decimal.h"

namespace CppNet
{
	namespace KMC
	{
		template<typename integer = UInt32>
		class Fraction final : public Object
		{
		public:
			Fraction(integer denominator);
			Fraction(integer numerator, integer denominator);
			Fraction(const Decimal& decimal);
			Fraction(const String& fraction);
			Fraction(const Fraction<integer>& f);
			Fraction(Fraction<integer>&& f);
			~Fraction() = default;

		private:
			integer numerator = 1; // 분자
			integer denominator = 1; // 분모

			static inline integer gcd(integer a, integer b); // 최대 공약수
			static inline integer lcm(integer a, integer b); // 최소 공배수

		public:
			Fraction<integer>& operator=(const Fraction<integer>& f);
			Fraction<integer>& operator=(Fraction<integer>&& f);

		public: 
			// 약분
			inline Fraction<integer> ROAF();
			// 통분
			inline std::tuple<Fraction<integer>, Fraction<integer>> RTCD(const Fraction<integer>& extra);
		};

		using Fraction64 = Fraction<UInt64>;
		using Fraction32 = Fraction<UInt32>;
		using Fraction16 = Fraction<UInt16>;
		using Fraction8 = Fraction<Byte>;
	}
}

#include "Fraction.inl"

#endif