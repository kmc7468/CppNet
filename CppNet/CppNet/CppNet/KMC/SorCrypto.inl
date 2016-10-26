#include "SorCrypto.h"
using namespace CppNet::System;
using namespace CppNet;
using namespace CppNet::KMC;

const String& SorCrypto::Key() const
{
	return key;
}

String& SorCrypto::Key()
{
	return key;
}