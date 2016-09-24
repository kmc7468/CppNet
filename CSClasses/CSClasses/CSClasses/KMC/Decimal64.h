#ifndef CSCLASSES_KMC_DECIMAL64_H
#define CSCLASSES_KMC_DECIMAL64_H

#include "../../SystemTypes.h"
#include <vector>
using namespace System;

namespace CSClasses
{
	namespace KMC
	{
		class Decimal64 final
		{
		public:
			Decimal64() = default;
			Decimal64(const String& str);
			Decimal64(Int64 integer);
			Decimal64(Double real);
			Decimal64(Int64 integer, const String& real);
			Decimal64(Decimal64&& d);
			Decimal64(const Decimal64& d);
			~Decimal64() = default;

		private:
			Decimal64(Int64 integer, Int64 real);

		private:
			Int64 integer;
			Int64 real;

		public:
			inline String ToString() const;
			inline String ToString(size_t realsize) const;
			inline Double ToReal64() const;
			inline Double ToReal64(size_t realsize) const;
			inline Int64 ToInt64() const;

		public:
			inline Decimal64 operator+(const Decimal64& d) const;
			inline Decimal64 operator+(Decimal64&& d) const;

			inline Decimal64 operator+=(const Decimal64& d);
			inline Decimal64 operator+=(Decimal64&& d);

			inline Decimal64 operator++();
			inline Decimal64 operator++(int);
		};
	}
}

#include "Decimal64.inl"

#endif