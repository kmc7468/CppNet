#include "Math.h"

#include <string>
using namespace std;

namespace CppNet
{
	namespace System
	{
		Double Math::Abs(Double d)
		{
			return abs(d);
		}

		Int64 Math::Abs(Int64 integer)
		{
			return abs(integer);
		}

		Int32 Math::Abs(Int32 integer)
		{
			return abs(integer);
		}

		Int16 Math::Abs(Int16 integer)
		{
			return abs(integer);
		}

		Double Math::Acos(Double d)
		{
			return acos(d);
		}

		Double Math::Asin(Double d)
		{
			return asin(d);
		}

		Double Math::Atan(Double d)
		{
			return atan(d);
		}

		Double Math::Atan2(Double d, Double d2)
		{
			return atan2(d, d2);
		}

		Int64 Math::BigMul(Int32 integer, Int32 integer2)
		{
			return ((Int64)integer) * integer2;
		}

		Double Math::Ceiling(Double d)
		{
			return ceil(d);
		}

		Double Math::Cos(Double d)
		{
			return cos(d);
		}

		Double Math::Cosh(Double d)
		{
			return cosh(d);
		}

		Int64 Math::DivRem(Int64 a, Int64 b, Int64& result)
		{
			result = a%b;
			return a / b;
		}

		Int32 Math::DivRem(Int32 a, Int32 b, Int32& result)
		{
			result = a%b;
			return a / b;
		}

		Double Math::Exp(Double d)
		{
			return exp(d);
		}

		Double Math::Log(Double d)
		{
			return log(d);
		}

		Double Math::Log(Double d, Double newBase)
		{
			return log(d) / log(newBase);
		}

		Double Math::Log10(Double d)
		{
			return log10(d);
		}

		Byte Math::Max(Byte b, Byte b2)
		{
			if (b > b2) return b;
			else return b2;
		}

		Double Math::Max(Double d, Double d2)
		{
			if (d > d2) return d;
			else return d2;
		}

		Int16 Math::Max(Int16 integer, Int16 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		Int32 Math::Max(Int32 integer, Int32 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		Int64 Math::Max(Int64 integer, Int64 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		UInt16 Math::Max(UInt16 integer, UInt16 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		UInt32 Math::Max(UInt32 integer, UInt32 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		UInt64 Math::Max(UInt64 integer, UInt64 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		Single Math::Max(Single d, Single d2)
		{
			if (d > d2) return d;
			else return d2;
		}

		Byte Math::Min(Byte b, Byte b2)
		{
			if (b < b2) return b;
			else return b2;
		}

		Double Math::Min(Double d, Double d2)
		{
			if (d < d2) return d;
			else return d2;
		}

		Int16 Math::Min(Int16 integer, Int16 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		Int32 Math::Min(Int32 integer, Int32 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		Int64 Math::Min(Int64 integer, Int64 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		UInt16 Math::Min(UInt16 integer, UInt16 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		UInt32 Math::Min(UInt32 integer, UInt32 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		UInt64 Math::Min(UInt64 integer, UInt64 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		Single Math::Min(Single d, Single d2)
		{
			if (d < d2) return d;
			else return d2;
		}

		Double Math::Pow(Double d, Double d2)
		{
			return pow(d, d2);
		}

		Double Math::Round(Double d)
		{
			return round(d);
		}

		Double Math::Sign(Double d)
		{
			return signbit(d);
		}

		Single Math::Sign(Single d)
		{
			return signbit(d);
		}

		Double Math::Sin(Double d)
		{
			return sin(d);
		}

		Double Math::Sinh(Double d)
		{
			return sinh(d);
		}

		Double Math::Sqrt(Double d)
		{
			return Sqrt(d);
		}

		Double Math::Tan(Double d)
		{
			return tan(d);
		}

		Double Math::Tanh(Double d)
		{
			return tanh(d);
		}

		Double Math::Truncaste(Double d)
		{
			return trunc(d);
		}

		Double Math::IEEERemainder(Double a, Double b)
		{
			return std::remainder(a, b);
		}

		// http://shaeod.tistory.com/384

		Double Math::Round(Double d, Int32 digits)
		{
			return (floor((d)* pow(1.0, digits) + 0.5f) / pow(10.0, digits));
		}

		UInt64 Math::Factorial(UInt64 i)
		{
			UInt64 v = 0;

			for (UInt64 j = i; j >= 1; j--)
			{
				v *= j;
			}

			return v;
		}

		KMC::Decimal Math::Energy(KMC::Decimal m)
		{
			return m * "18446744072314778980"s;
		}
	}
}