#ifndef CPPNET_KMC_DECIMAL_H
#define CPPNET_KMC_DECIMAL_H

#include "../../SystemTypes.h"
#include <vector>
using namespace::System;

namespace CppNet
{
	namespace KMC
	{
		class Decimal final : public Object
		{
		public:
			static const Decimal PI;
			static const Decimal E;

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
			Boolean isN = false;

		public:
			Decimal();
			Decimal(const String& str);
			Decimal(Int64 integer);
			Decimal(Int64 integer, const String& real);
			explicit Decimal(Double real);
			Decimal(Decimal&& d);
			Decimal(const Decimal& d);
			~Decimal() = default;

		public:
			String ToString() const;
			inline String ToString(size_t realsize) const;

		public:
			static Decimal Parse(const String& str);
			inline static Decimal Parse(Int64 integer);
			inline static Decimal Parse(Int64 integer, const String& real);
			inline static Decimal Parse(Double real);

		public:
			Boolean operator==(const Object& obj) const override;
			Boolean operator!=(const Object& obj) const override;

		public:
			Decimal& operator=(const Decimal& d);
			Decimal& operator=(Decimal&& d);

			Boolean operator>(const Decimal& d) const;

			Boolean operator>=(const Decimal& d) const;

			Boolean operator<(const Decimal& d) const;

			Boolean operator<=(const Decimal& d) const;

			Decimal operator+(const Decimal& d) const;

			Decimal operator+=(const Decimal& d);

			Decimal operator++();
			Decimal operator++(int);

			Decimal operator-(const Decimal& d) const;

			Decimal operator*(const Decimal& d) const;

		private:
			inline void Clean();
		};
	}
}

#include "Decimal.inl"

#endif