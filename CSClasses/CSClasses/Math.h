#ifndef SYSTEM_MATH_H
#define SYSTEM_MATH_H

#include "System.h"
#include <cmath>

namespace System
{
	class Math final : public Object
	{
	public:
		inline Double Abs(Double d) const
		{
			return abs(d);
		}

		inline Int64 Abs(Int64 integer) const
		{
			return abs(integer);
		}

		inline Int32 Abs(Int32 integer) const
		{
			return abs(integer);
		}

		inline Int16 Abs(Int16 integer) const
		{
			return abs(integer);
		}

		inline Double Acos(Double d) const
		{
			return acos(d);
		}

		inline Double Asin(Double d) const
		{
			return asin(d);
		}

		inline Double Atan(Double d) const
		{
			return atan(d);
		}

		inline Double Atan2(Double d, Double d2) const
		{
			return atan2(d, d2);
		}

		inline Int64 BigMul(Int32 integer, Int32 integer2) const
		{
			return integer * integer2;
		}

		inline Double Ceiling(Double d) const
		{
			return ceil(d);
		}

		inline Double Cos(Double d) const
		{
			return cos(d);
		}

		inline Double Cosh(Double d) const
		{
			return cosh(d);
		}

		// TODO DivRem

		inline Double Exp(Double d) const
		{
			return exp(d);
		}

		// TODO IEEERemainder

		inline Double Log(Double d) const
		{
			return log(d);
		}

		// TODO Log(Double, Double)

		inline Double Log10(Double d) const
		{
			return log10(d);
		}

		inline Byte Max(Byte b, Byte b2) const
		{
			if (b > b2) return b;
			else return b2;
		}

		inline Double Max(Double d, Double d2) const
		{
			if (d > d2) return d;
			else return d2;
		}

		inline Int16 Max(Int16 integer, Int16 integer2) const
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		inline Int32 Max(Int32 integer, Int32 integer2) const
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		inline Int64 Max(Int64 integer, Int64 integer2) const
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		inline UInt16 Max(UInt16 integer, UInt16 integer2) const
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		inline UInt32 Max(UInt32 integer, UInt32 integer2) const
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		inline UInt64 Max(UInt64 integer, UInt64 integer2) const
		{
			if (integer > integer2) return integer;
			else return integer2;
		}

		inline Single Max(Single d, Single d2) const
		{
			if (d > d2) return d;
			else return d2;
		}

		inline Byte Min(Byte b, Byte b2) const
		{
			if (b < b2) return b;
			else return b2;
		}

		inline Double Min(Double d, Double d2) const
		{
			if (d < d2) return d;
			else return d2;
		}

		inline Int16 Min(Int16 integer, Int16 integer2) const
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		inline Int32 Min(Int32 integer, Int32 integer2) const
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		inline Int64 Min(Int64 integer, Int64 integer2) const
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		inline UInt16 Min(UInt16 integer, UInt16 integer2) const
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		inline UInt32 Min(UInt32 integer, UInt32 integer2) const
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		inline UInt64 Min(UInt64 integer, UInt64 integer2) const
		{
			if (integer < integer2) return integer;
			else return integer2;
		}

		inline Single Min(Single d, Single d2) const
		{
			if (d < d2) return d;
			else return d2;
		}

		inline Double Pow(Double d, Double d2) const
		{
			return pow(d, d2);
		}

		inline Double Round(Double d) const
		{
			return round(d);
		}

		// TODO Round(Double, Int32)

		inline Double Sign(Double d) const
		{
			return signbit(d);
		}

		inline Single Sign(Single d) const
		{
			return signbit(d);
		}

		inline Double Sin(Double d) const
		{
			return sin(d);
		}

		// TODO Sinh

		inline Double Sqrt(Double d) const
		{
			return Sqrt(d);
		}

		inline Double Tan(Double d) const
		{
			return tan(d);
		}

		inline Double Tanh(Double d) const
		{
			return tanh(d);
		}

		inline Double Truncaste(Double d) const
		{
			return trunc(d);
		}
	};
}

#endif