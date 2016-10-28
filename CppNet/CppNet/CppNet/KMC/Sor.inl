#include "Sor.h"

using namespace CppNet::System;

namespace CppNet
{
	namespace KMC
	{
		template<typename Crypto, typename Key>
		const Double Sor<Crypto, Key>::Version = 2.1;

		template<typename Crypto, typename Key>
		Sor<Crypto, Key>::Sor(const Key& k)
		{
			SetKey(k);
		}

		template<typename Crypto, typename Key>
		Key Sor<Crypto, Key>::GetKey() const
		{
			return key.substr(0, key.length() - 4);
		}

		template<typename Crypto, typename Key>
		void Sor<Crypto, Key>::SetKey(const Key& k)
		{
			key = k;

			for (Byte i = 0; i < 4; i++)
			{
				Key::value_type c = key.back();

				c += 100;

				key += c;
			}
		}

		template<typename Crypto, typename Key>
		Tuple<Crypto*, size_t> Sor<Crypto, Key>::Encrypt(Crypto* bytes, size_t len) const
		{
			Crypto* result = new Crypto[len];

			for (size_t i = 0; i < len; i++)
			{
				Crypto b = bytes[i];

				b += 30;

				for (size_t j = 0; j < key.length(); j++)
					b = b ^ key.at(j);

				b += 30;

				for (size_t j = key.length() - 1; j >= 0; j--)
				{
					b = b ^ key.at(j);
					if (j == 0) break;
				}

				result[i] = b;
			}

			return std::make_tuple(result, len);
		}

		template<typename Crypto, typename Key>
		Tuple<Crypto*, size_t> Sor<Crypto, Key>::Decrypt(Crypto* bytes, size_t len) const
		{
			Crypto* result = new Crypto[len];

			for (size_t i = 0; i < len; i++)
			{
				Crypto b = bytes[i];

				for (size_t j = 0; j < key.length(); j++)
					b = b ^ key.at(j);

				b -= 30;

				for (size_t j = key.length() - 1; j >= 0; j--)
				{
					b = b ^ key.at(j);
					if (j == 0) break;
				}

				b -= 30;

				result[i] = b;
			}

			return std::make_tuple(result, len);
		}
	}
}