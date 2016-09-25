#ifndef CSCLASSES_KMC_DECIMAL_H
#define CSCLASSES_KMC_DECIMAL_H

#include "../../SystemTypes.h"
#include <vector>
using namespace::System;

namespace CSClasses
{
	namespace KMC
	{
		class Decimal final : public Object
		{
		private:
			class ByteTool final
			{
			public:
				static inline Byte IntsToByte(Byte a, Byte b);
				static inline std::tuple<Byte, Byte> ByteToInts(Byte b);
				static inline Byte ToByte(char c);
				static inline char FromByte(Byte b);
			};

		private:
			std::vector<Byte>* data;

		public:
			Decimal();
			Decimal(const String& str);
			Decimal(Int64 integer);
			Decimal(Int64 integer, const String& real);
			Decimal(Double real);
			Decimal(Decimal&& d);
			Decimal(const Decimal& d);
			~Decimal();

		public:
			String ToString() const;
			inline String ToString(size_t realsize) const;
		};

		//using Decimal64 = Decimal<8, 8, Int64, Double>;
	}
}

#include "Decimal.inl"

#endif