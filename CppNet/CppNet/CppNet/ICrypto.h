#ifndef CPPNET_ICRYPTO_H
#define CPPNET_ICRYPTO_H

#include <array>

#include "../Utility.h"
#include "System/Object.h"
#include "System/Tuple.h"

using namespace CppNet::System;

namespace CppNet
{
	template<typename T = Byte>
	interface ICrypto
	{
		virtual Tuple<T*, size_t> Encrypt(T* bytes, size_t len) const = 0;
		virtual Tuple<T*, size_t> Decrypt(T* bytes, size_t len) const = 0;
	};
}

#endif