#ifndef CPPNET_KMC_DECIMAL_H
#define CPPNET_KMC_DECIMAL_H

#include "../../Defines.h"

#include "../../SystemTypes.h"
#include <vector>

namespace CppNet
{
	namespace KMC
	{
		using namespace CppNet::System;

		class Decimal final : public Object
		{
		public:
			static const Decimal PI;
			static const Decimal E;

			static const Decimal Zero;
			static const Decimal One;
			static const Decimal Two;
			static const Decimal Three;
			static const Decimal Four;
			static const Decimal Five;
			static const Decimal Six;
			static const Decimal Seven;
			static const Decimal Eight;
			static const Decimal Nine;
			static const Decimal Ten;

			static const Decimal NaN;
			static const Decimal PositiveInfinity;
			static const Decimal NegativeInfinity;
			static const Decimal Ind;

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
			typedef std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>> t;

		private:
			t mInteger;
			t mReal;
			Boolean isN = false; // 음수인지
			Boolean isNaN = false; // NaN 인지
			Boolean isInf = false; // +-inf 인지
			Boolean isInd = false; // -nan(ind) 인지

		public:
			Decimal();
			Decimal(const String& str);
			explicit Decimal(Int64 integer);
			Decimal(Int64 integer, const String& real);
			explicit Decimal(UInt64 integer);
			Decimal(Double real);
			Decimal(Decimal&& d);
			Decimal(const Decimal& d);
			~Decimal() = default;

		public:
			String ToString() const override;
			inline String ToString(size_t realsize) const;

		public:
			static Decimal Parse(const String& str);
			inline static Decimal Parse(UInt64 integer);
			inline static Decimal Parse(Int64 integer);
			inline static Decimal Parse(Int64 integer, const String& real);
			inline static Decimal Parse(Double real);

			static inline Boolean IsPositiveInfinity(const Decimal& d);
			static inline Boolean IsNegativeInfinity(const Decimal& d);
			static inline Boolean IsPositive(const Decimal& d);
			static inline Boolean IsNegative(const Decimal& d);
			static inline Boolean IsNaN(const Decimal& d);

			static inline Decimal Pow(const Decimal& base, const Decimal& exp);
			static inline Decimal Sqrt(const Decimal& base);

		public:
			Decimal& Pow(Decimal exp);
			Decimal& Sqrt();

		public:
			Boolean operator==(const Object& obj) const override;
			Boolean operator!=(const Object& obj) const override;

		public:
			Decimal& operator=(const Decimal& d);
			Decimal& operator=(Decimal&& d);

			Boolean operator>(const Decimal& d) const;
			inline Boolean operator>=(const Decimal& d) const;

			Boolean operator<(const Decimal& d) const;
			inline Boolean operator<=(const Decimal& d) const;

			Decimal operator+(const Decimal& d) const;
			Decimal& operator+=(const Decimal& d);
			Decimal operator++();
			Decimal operator++(int);

			Decimal operator-(const Decimal& d) const;
			Decimal& operator-=(const Decimal& d);
			Decimal operator--();
			Decimal operator--(int);

			Decimal operator*(const Decimal& d) const;
			Decimal& operator*=(const Decimal& d);

			Decimal operator/(const Decimal& d) const;
			Decimal& operator/=(const Decimal& d);

			Decimal operator%(const Decimal& d) const;
			Decimal& operator%=(const Decimal& d);

			Decimal operator&(const Decimal& d) const;
			Decimal& operator&=(const Decimal& d);
			
			Decimal operator|(const Decimal& d) const;
			Decimal& operator|=(const Decimal& d);

			Decimal operator^(const Decimal& d) const;
			Decimal& operator^=(const Decimal& d);

		private:
			inline void Clean();
		};
	}
}

#include "Decimal.inl"

#endif