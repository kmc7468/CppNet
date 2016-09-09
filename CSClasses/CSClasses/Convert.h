#ifndef SYSTEM_CONVERT_H
#define SYSTEM_CONVERT_H

#include "System.h"

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
		static inline Boolean ToBoolean(Boolean b)
		{
			return b;
		}

		static inline Boolean ToBoolean(Char c)
		{
			Boolean(*p)(DateTime) = ToBoolean;
			throw InvalidCastException(Exception::ExceptionData(TXT_INVAILD_CAST_CHAR2BOOL, L"", L"", p, nullptr));
		}

		static inline Boolean ToBoolean(DateTime d)
		{
			Boolean(*p)(DateTime) = ToBoolean;
			throw InvalidCastException(Exception::ExceptionData(TXT_INVALID_CAST_DATETIME2BOOL, L"", L"", p, nullptr));
		}

		static inline Boolean ToBoolean(Byte b)
		{
			if (b == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(SByte b)
		{
			if (b == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(Double d)
		{
			if (d == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(Single d)
		{
			if (d == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(Int16 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(Int32 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(Int64 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(UInt16 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(UInt32 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(UInt64 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		static inline Boolean ToBoolean(const String& str)
		{
			String s = str;
			std::transform(s.begin(), s.end(), s.begin(), ::tolower);

			if (s == L"true")
			{
				return true;
			}
			else if (s == L"false")
			{
				return false;
			}
			else
			{
				throw FormatException(TXT_FORMAT_STRING2BOOL_NOTSTR);
			}
		}
	};
}

#endif