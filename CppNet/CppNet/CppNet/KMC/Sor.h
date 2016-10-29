#ifndef CPPNET_KMC_SOR8_H
#define CPPNET_KMC_SOR8_H

#include "../../Defines.h"

#include "../ICrypto.h"
#include "../System/Object.h"
#include "../System/String.h"
#include "../System/Double.h"

using namespace CppNet::System;

namespace CppNet
{
	namespace KMC
	{
		template<typename Crypto, typename Key>
		class Sor : public Object, public ICrypto<Crypto>
		{
		public:
			static const Double Version;

		private:
			Key key;

		public:
			Sor() = default;
			explicit Sor(const Key& k);
			~Sor() = default;

		public:
			Key GetKey() const;
			void SetKey(const Key& k);

			Tuple<Crypto*, size_t> Encrypt(Crypto* bytes, size_t len) const override;
			Tuple<Crypto*, size_t> Decrypt(Crypto* bytes, size_t len) const override;
		};
	
		using Sor8 = Sor<Byte, String>;
#ifndef WIN32
		using Sor16 = Sor<UInt16, std::u16string>;
#else
		using Sor16 = Sor<wchar_t, std::wstring>;
#endif

		using Sor32 = Sor<UInt32, std::u32string>;
	}
}

#include "Sor.inl"

#endif