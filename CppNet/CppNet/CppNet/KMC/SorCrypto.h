#ifndef CPPNET_KMC_SORCRYPTO_H
#define CPPNET_KMC_SORCRYPTO_H

#include "../ICrypto.h"
#include "../System/Tuple.h"
#include "../System/Tuple.h"
#include "../System/String.h"
#include "../System/Byte.h"

namespace CppNet
{
	namespace KMC
	{
		class SorCrypto : public ICrypto
		{
		private:
			System::String key = "";

		public:
			SorCrypto() = default;
			SorCrypto(const System::String& key);
			~SorCrypto() = default;

		public:
			inline const System::String& GetKey() const;
			inline void SetKey(const System::String& key);

		public:
			System::Tuple<System::Byte*, size_t> Encrypt(System::Byte* bytes, size_t len) const override;
			System::Tuple<System::Byte*, size_t> Decrypt(System::Byte* bytes, size_t len) const override;
		};
	}
}

#include "SorCrypto.inl"

#endif