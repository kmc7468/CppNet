#include "SorCrypto.h"
using namespace System;
using namespace CppNet;
using namespace CppNet::KMC;

SorCrypto::SorCrypto(const String& key)
{
	SetKey(key);
}