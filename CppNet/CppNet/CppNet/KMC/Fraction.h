#ifndef CPPNET_KMC_FRACTION_H
#define CPPNET_KMC_FRACTION_H

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

		public:
			Fraction<integer> Reduction();
		};

		using Fraction64 = Fraction<UInt64>;
		using Fraction32 = Fraction<UInt32>;
		using Fraction16 = Fraction<UInt16>;
		using Fraction8 = Fraction<Byte>;
	}
}

#include "Fraction.inl"

#endif