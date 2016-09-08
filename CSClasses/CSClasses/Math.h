
/*
	2016.09.07
	Created by kmc7468
*/

#ifndef SYSTEM_MATH_H

#define SYSTEM_MATH_H

#include "System.h"

#include <cmath>

namespace System
{

	static class Math final : public Object
	{
	public:
		Math() = default;
		Math(Math &&sNewMath) = delete;
		Math(const Math &sNewMath) = delete;
		~Math() = default;

	public:
		Math &operator=(Math &&sNewMath) = delete;
		Math &operator=(const Math &sNewMath) = delete;

	public:
		static const Double PI;
		static const Double E;

		static inline Double Abs(Double d)
		{
			return abs(d);
		}

		static inline Int64 Abs(Int64 integer)
		{
			return abs(integer);
		}

		static inline Int32 Abs(Int32 integer)
		{
			return abs(integer);
		}

		static inline Int16 Abs(Int16 integer)
		{
			return abs(integer);
		}

		static inline Double Acos(Double d)
		{
			return acos(d);
		}

		static inline Double Asin(Double d)
		{
			return asin(d);
		}

		static inline Double Atan(Double d)
		{
			return atan(d);
		}

		static inline Double Atan2(Double d, Double d2)
		{
			return atan2(d, d2);
		}

		static inline Int64 BigMul(Int32 integer, Int32 integer2)
		{
			return integer * integer2;
		}

		static inline Double Ceiling(Double d)
		{
			return ceil(d);
		}

		static inline Double Cos(Double d)
		{
			return cos(d);
		}

		static inline Double Cosh(Double d)
		{
			return cosh(d);
		}

		// TODO DivRem

		static inline Double Exp(Double d)
		{
			return exp(d);
		}

		// TODO IEEERemainder

		static inline Double Log(Double d)
		{
			return log(d);
		}

		// TODO Log(Double, Double)

		static inline Double Log10(Double d)
		{
			return log10(d);
		}

		static inline Byte Max(Byte b, Byte b2)
		{
			if (b > b2) return b;
			else return b2;
		}

		static inline Double Max(Double d, Double d2)
		{
			if (d > d2) return d;
			else return d2;
		}

		static inline Int16 Max(Int16 integer, Int16 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		static inline Int32 Max(Int32 integer, Int32 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		static inline Int64 Max(Int64 integer, Int64 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		static inline UInt16 Max(UInt16 integer, UInt16 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		static inline UInt32 Max(UInt32 integer, UInt32 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		static inline UInt64 Max(UInt64 integer, UInt64 integer2)
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		static inline Single Max(Single d, Single d2)
		{
			if (d > d2) return d;
			else return d2;
		}

		static inline Byte Min(Byte b, Byte b2)
		{
			if (b < b2) return b;
			else return b2;
		}

		static inline Double Min(Double d, Double d2)
		{
			if (d < d2) return d;
			else return d2;
		}

		static inline Int16 Min(Int16 integer, Int16 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		static inline Int32 Min(Int32 integer, Int32 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		static inline Int64 Min(Int64 integer, Int64 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		static inline UInt16 Min(UInt16 integer, UInt16 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		static inline UInt32 Min(UInt32 integer, UInt32 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		static inline UInt64 Min(UInt64 integer, UInt64 integer2)
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		static inline Single Min(Single d, Single d2)
		{
			if (d < d2) return d;
			else return d2;
		}

		static inline Double Pow(Double d, Double d2)
		{
			return pow(d, d2);
		}

		static inline Double Round(Double d)
		{
			return round(d);
		}

		// TODO Round(Double, Int32)

		static inline Double Sign(Double d)
		{
			return signbit(d);
		}

		static inline Single Sign(Single d)
		{
			return signbit(d);
		}

		static inline Double Sin(Double d)
		{
			return sin(d);
		}

		// TODO Sinh

		static inline Double Sqrt(Double d)
		{
			return Sqrt(d);
		}

		static inline Double Tan(Double d)
		{
			return tan(d);
		}

		static inline Double Tanh(Double d)
		{
			return tanh(d);
		}

		static inline Double Truncaste(Double d)
		{
			return trunc(d);
		}
	};

	const Double Math::PI = 3.14159265358979323846;
	const Double Math::E = 2.7182818284590452354;
}

#endif