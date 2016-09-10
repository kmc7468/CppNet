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

		static inline Byte ToByte(Boolean b)
		{
			return b ? 1 : 0;
		}
		
		static inline Byte ToByte(Byte b)
		{
			return b;
		}

		static inline Byte ToByte(Char c)
		{
			if (c > 255)
			{
				throw Exception(L"오버플로"); // FIXME: Overflow Exception
			}

			return (Byte)c;
		}

		static inline Byte ToByte(DateTime d)
		{
			Byte(*p)(DateTime) = ToByte;
			throw InvalidCastException(Exception::ExceptionData(TXT_INVALID_CAST_DATETIME2BYTE, L"", L"", p, nullptr));
		}

		static inline Byte ToByte(Double d)
		{
			d = Math::Round(d);

			if (d > 255 || d < 0)
			{
				throw Exception(L"오버플로"); // FIXME: Overflow Exception
			}

			return (Byte)d;
		}

		static inline Byte ToByte(Int16 i)
		{
			if (i > 255 || i < 0)
			{
				throw Exception(L"오버플로"); // FIXME: Overflow Exception
			}

			return (Byte)i;
		}

		static inline Byte ToByte(Int32 i)
		{
			if (i > 255 || i < 0)
			{
				throw Exception(L"오버플로"); // FIXME: Overflow Exception
			}

			return (Byte)i;
		}

		static inline Byte ToByte(Int64 i)
		{
			if (i > 255 || i < 0)
			{
				throw Exception(L"오버플로"); // FIXME: Overflow Exception
			}

			return (Byte)i;
		}

		static inline Byte ToByte(Single d)
		{
			d = (Single)Math::Round(d);

			if (d > 255 || d < 0)
			{
				throw Exception(L"오버플로"); // FIXME: Overflow Exception
			}

			return (Byte)d;
		}

		static inline Byte ToByte(const String& str)
		{
			String s = str;
			std::replace(s.begin(), s.end(), L',', L' ');
		
			Int32 i = std::stoi(str);

			if (i > 255 || i < 0)
			{
				throw Exception(L"오버플로"); // FIXME: Overflow Exception
			}

			return (Byte)i;
		}
	};
}

#endif