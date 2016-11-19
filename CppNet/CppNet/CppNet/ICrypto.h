#ifndef CPPNET_ICRYPTO_H
#define CPPNET_ICRYPTO_H

#include "../Defines.h"

#include <array>

#include "../Utility.h"
#include "System/Object.h"
#include "System/Tuple.h"

namespace CppNet
{
	template<typename T = Byte>
	interface ICrypto
	{
		virtual System::Tuple<T*, size_t> Encrypt(T* bytes, size_t len) const = 0;
		virtual System::Tuple<T*, size_t> Decrypt(T* bytes, size_t len) const = 0;
	};
}

#endif