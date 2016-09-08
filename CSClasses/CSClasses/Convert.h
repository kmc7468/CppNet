#ifndef SYSTEM_CONVERT_H
#define SYSTEM_CONVERT_H

#include "System.h"

#include <algorithm>

namespace System
{
	static class Convert final
	{
		static inline Boolean ToBoolean(Boolean b)
		{
			return b;
		}

		static inline Boolean ToBoolean(Char c)
		{
			return false;
			// TODO throw InvalidCastException
		}

		// TODO ToBoolean(DateTime)

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

		static inline Boolean ToBoolean(String str)
		{
			std::transform(str.begin(), str.end(), str.begin(), ::tolower);

			if (str == L"true")
			{
				return true;
			}
			else if (str == L"false")
			{
				return false;
			}
			else
			{
				// TODO throw FormatException
				return false;
			}
		}
	};
}

#endif