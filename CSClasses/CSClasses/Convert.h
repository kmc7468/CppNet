#ifndef SYSTEM_CONVERT_H
#define SYSTEM_CONVERT_H

#include "SystemType.h"

#include <algorithm>

namespace System
{
	class Convert final : public Object
	{
	public:
		Convert() = default;
		Convert(Convert &&sNewConvert) = delete;
		Convert(const Convert &sNewConvert) = delete;
		~Convert() = default;

	public:
		Convert &operator=(Convert &&sNewConvert) = delete;
		Convert &operator=(const Convert &sNewConvert) = delete;

	public:
		static inline Boolean ToBoolean(Boolean b);
		static inline Boolean ToBoolean(Char c);
		static inline Boolean ToBoolean(DateTime d);
		static inline Boolean ToBoolean(Byte b);
		static inline Boolean ToBoolean(SByte b);
		static inline Boolean ToBoolean(Double d);
		static inline Boolean ToBoolean(Single d);
		static inline Boolean ToBoolean(Int16 integer);
		static inline Boolean ToBoolean(Int32 integer);
		static inline Boolean ToBoolean(Int64 integer);
		static inline Boolean ToBoolean(UInt16 integer);
		static inline Boolean ToBoolean(UInt32 integer);
		static inline Boolean ToBoolean(UInt64 integer);
		static inline Boolean ToBoolean(const String& str);

		static inline Byte ToByte(Boolean b);
		static inline Byte ToByte(Char c);
		static inline Byte ToByte(DateTime d);
		static inline Byte ToByte(Byte b);
		static inline Byte ToByte(SByte b);
		static inline Byte ToByte(Double d);
		static inline Byte ToByte(Single d);
		static inline Byte ToByte(Int16 i);
		static inline Byte ToByte(Int32 i);
		static inline Byte ToByte(Int64 i);
		static inline Byte ToByte(UInt16 i);
		static inline Byte ToByte(UInt32 i);
		static inline Byte ToByte(UInt64 i);
		static inline Byte ToByte(const String& str);
	};
}

#endif