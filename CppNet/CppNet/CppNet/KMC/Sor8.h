#ifndef CPPNET_KMC_SOR8_H
#define CPPNET_KMC_SOR8_H

#include "../ICrypto.h"
#include "../System/Object.h"
#include "../System/String.h"

namespace CppNet
{
	namespace KMC
	{
		class Sor8 : public Object, public ICrypto
		{
		private:
			String key = "";

		public:
			Sor8() = default;
			explicit Sor8(const String& Key);
			~Sor8() = default;

		public:
			String GetKey() const;
			void SetKey(const String& Key);

			Tuple<Byte*, size_t> Encrypt(Byte* bytes, size_t len) const override;
			Tuple<Byte*, size_t> Decrypt(Byte* bytes, size_t len) const override;
		};
	}
}

#endif