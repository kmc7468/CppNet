#ifndef CPPNET_ICRYPTO_H
#define CPPNET_ICRYPTO_H

#include <array>

#include "../Utility.h"
#include "../System/Object.h"
#include "../System/Tuple.h"

namespace CppNet
{
	interface ICrypto
	{
		virtual System::Tuple<System::Byte*, size_t> Encrypt(System::Byte* bytes, size_t len) const = 0;
		virtual System::String Encrypt(const System::String& str) const = 0;

		virtual System::Tuple<System::Byte*, size_t> Decrypt(System::Byte* bytes, size_t len) const = 0;
		virtual System::String Decrypt(const System::String& str) const = 0;
	};
}

#endif