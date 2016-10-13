#include "Math.h"

#include "DoubleT.h"

namespace System
{
	const Double Math::PI = 3.14159265358979323846;
	const Double Math::E = 2.7182818284590452354;

	Double Math::IEEERemainder(Double a, Double b)
	{
		if (DoubleT::IsNaN(a))
			return a;
		
		if (DoubleT::IsNaN(b))
			return b;

		Double mod = fmod(a, b);
		if (DoubleT::IsNaN(mod))
			return DoubleT::NaN.Data();

		if (DoubleT::IsNegative(mod))
			return DoubleT::NegativeZero.Data();

		Double result = 0;
		result = mod - (Abs(b) * Sign(a));
		if (Abs(result) == Abs(mod))
		{
			Double divResult = a / b;
			Double roundedResult = Round(divResult);
			if (Abs(roundedResult) > Abs(divResult))
				return result;
			else
				return mod;
		}
		if (Abs(result) < Abs(mod))
			return result;
		else
			return mod;
	}
}