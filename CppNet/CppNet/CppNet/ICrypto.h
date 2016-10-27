#ifndef CPPNET_ICRYPTO_H
#define CPPNET_ICRYPTO_H

#include <array>

#include "../Utility.h"
#include "System/Object.h"
#include "System/Tuple.h"

using namespace CppNet::System;

namespace CppNet
{
	interface ICrypto
	{
		virtual Tuple<Byte*, size_t> Encrypt(Byte* bytes, size_t len) const = 0;
		virtual Tuple<Byte*, size_t> Decrypt(Byte* bytes, size_t len) const = 0;
	};
}

#endif