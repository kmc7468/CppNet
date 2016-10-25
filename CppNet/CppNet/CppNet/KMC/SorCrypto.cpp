#include "SorCrypto.h"
using namespace System;
using namespace CppNet;
using namespace CppNet::KMC;

SorCrypto::SorCrypto(const String& key)
	: key(key)
{}

//Tuple<Byte*, size_t> SorCrypto::Encrypt(Byte* bytes, size_t len) const
//{
//	
//}