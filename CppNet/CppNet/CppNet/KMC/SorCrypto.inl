#include "SorCrypto.h"
using namespace CppNet::System;
using namespace CppNet;
using namespace CppNet::KMC;

const String& SorCrypto::GetKey() const
{
	return key.substr(0, key.length() - 4);
}

void SorCrypto::SetKey(const String& key)
{
	this->key = key;

	for (Byte i = 0; i < 4; i++)
	{
		char c = this->key.back();

		c += 100;

		this->key += c;
	}
}

Tuple<Byte*, size_t> SorCrypto::Encrypt(Byte* bytes, size_t len) const
{
	Byte* res = new Byte[len];

	for (size_t i = 0; i < len; i++)
	{
		Byte b = bytes[i];
		b += 30;

		for (size_t j = 0; j < key.length(); j++)
			b ^= key.at(j);

		res[i] = b;
	}

	return std::make_tuple(res, len);
}

Tuple<Byte*, size_t> SorCrypto::Decrypt(Byte* bytes, size_t len) const
{
	Byte* res = new Byte[len];

	for (size_t i = 0; i < len; i++)
	{
		Byte b = bytes[i];

		for (size_t j = 0; j < key.length(); j++)
			b ^= key.at(j);

		b -= 30;

		res[i] = b;
	}

	return std::make_tuple(res, len);
}