#include "Sor8.h"

namespace CppNet
{
	namespace KMC
	{
		const Double Sor8::Version = 2.1;

		Sor8::Sor8(const String& Key)
		{
			SetKey(Key);
		}

		Tuple<Byte*, size_t> Sor8::Encrypt(Byte* bytes, size_t len) const
		{
			Byte* result = new Byte[len];

			for (size_t i = 0; i < len; i++)
			{
				Byte b = bytes[i];

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

		Tuple<Byte*, size_t> Sor8::Decrypt(Byte* bytes, size_t len) const
		{
			Byte* result = new Byte[len];

			for (size_t i = 0; i < len; i++)
			{
				Byte b = bytes[i];

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

		String Sor8::GetKey() const
		{
			String s = key.substr(0, key.length() - 4);

			return s;
		}

		void Sor8::SetKey(const String& Key)
		{
			key = Key;

			for (Byte i = 0; i < 4; i++)
			{
				char c = key.back();

				c += 100;

				key += c;
			}
		}
	}
}