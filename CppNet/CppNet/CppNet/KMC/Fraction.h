#ifndef CPPNET_KMC_FRACTION_H
#define CPPNET_KMC_FRACTION_H

#include "../../SystemTypes.h"
using namespace System;

#include "Decimal.h"

namespace CppNet::KMC
{
	template<typename integer = UInt32>
	class Fraction final : public Object
	{
	public:
		Fraction(integer denominator);
		Fraction(integer numerator, integer denominator);
		Fraction(const Decimal& decimal);
		Fraction(Decimal&& decimal);
		Fraction(const String& fraction);
		Fraction(const Fraction& f);
		Fraction(Fraction&& f);
		~Fration() = default;

	private:
		integer numerator = 1; // 분자
		integer denominator; // 분모
	};
}

#endif