#include "Exception.h"
#include "Math.h"
#include "Convert.h"
#include "Exception.h"
#include "InvalidCastException.h"
#include "FormatException.h"
#include "NotImplementedException.h"
#include "OverflowException.hpp"

#include "../../Language.h"

namespace CppNet
{
	namespace System
	{
		Boolean Convert::ToBoolean(Boolean b)
		{
			return b;
		}

		Boolean Convert::ToBoolean(Char c)
		{
			throw InvalidCastException(Exception::ExceptionData(TXT_INVAILD_CAST_CHAR2BOOL, "", "", nullptr));
		}

		Boolean Convert::ToBoolean(DateTime d)
		{
			throw InvalidCastException(Exception::ExceptionData(TXT_INVALID_CAST_DATETIME2BOOL, "", "", nullptr));
		}

		Boolean Convert::ToBoolean(Byte b)
		{
			if (b == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(SByte b)
		{
			if (b == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(Double d)
		{
			if (d == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(Single d)
		{
			if (d == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(Int16 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(Int32 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(Int64 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(UInt16 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(UInt32 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(UInt64 integer)
		{
			if (integer == 0) return false;
			else return true;
		}

		Boolean Convert::ToBoolean(const String& str)
		{
			String s = str;
			std::transform(s.begin(), s.end(), s.begin(), ::tolower);

			if (s == "true")
			{
				return true;
			}
			else if (s == "false")
			{
				return false;
			}
			else
			{
				throw FormatException(Exception::ExceptionData(TXT_FORMAT_STRING2BOOL_NOTSTR, "", "", nullptr));
			}
		}

		Boolean Convert::ToBoolean(const Object& obj, std::unique_ptr<IFormatProvider> format)
		{
			if (is<const IConvertible>(obj))
			{
				// TODO
				throw NotImplementedException();
			}
			else
			{
				// FIXME
				throw InvalidCastException();
			}
		}

		Byte Convert::ToByte(Boolean b)
		{
			return b ? 1 : 0;
		}

		Byte Convert::ToByte(Char c)
		{
			if ((Int32)c > 255 || (Int32)c < 0)
			{
				throw OverflowException();
			}

			return (Byte)c;
		}

		Byte Convert::ToByte(DateTime d)
		{
			throw InvalidCastException(Exception::ExceptionData(TXT_INVALID_CAST_DATETIME2BYTE, "", "", nullptr));
		}

		Byte Convert::ToByte(Byte b)
		{
			return b;
		}

		Byte Convert::ToByte(SByte b)
		{
			if (b < 0)
			{
				throw OverflowException();
			}

			return (Byte)b;
		}

		Byte Convert::ToByte(Double d)
		{
			d = Math::Round(d);

			if (d > 255 || d < 0)
			{
				throw OverflowException();
			}

			return (Byte)d;
		}

		Byte Convert::ToByte(Single d)
		{
			d = (Single)Math::Round(d);

			if (d > 255 || d < 0)
			{
				throw OverflowException();
			}

			return (Byte)d;
		}

		Byte Convert::ToByte(Int16 i)
		{
			if (i > 255 || i < 0)
			{
				throw OverflowException();
			}

			return (Byte)i;
		}

		Byte Convert::ToByte(Int32 i)
		{
			if (i > 255 || i < 0)
			{
				throw OverflowException();
			}

			return (Byte)i;
		}

		Byte Convert::ToByte(Int64 i)
		{
			if (i > 255 || i < 0)
			{
				throw OverflowException();
			}

			return (Byte)i;
		}

		Byte Convert::ToByte(UInt16 i)
		{
			if (i > 255)
			{
				throw OverflowException();
			}

			return (Byte)i;
		}

		Byte Convert::ToByte(UInt32 i)
		{
			if (i > 255)
			{
				throw OverflowException();
			}

			return (Byte)i;
		}

		Byte Convert::ToByte(UInt64 i)
		{
			if (i > 255)
			{
				throw OverflowException();
			}

			return (Byte)i;
		}

		Byte Convert::ToByte(const String& str)
		{
			String s = str;
			std::replace(s.begin(), s.end(), L',', L' ');

			Int32 i = std::stoi(str);

			if (i > 255 || i < 0)
			{
				throw OverflowException();
			}

			return (Byte)i;
		}

		Byte Convert::ToByte(const Object& obj, std::unique_ptr<IFormatProvider> format)
		{
			if (is<const IConvertible>(obj))
			{
				// TODO
				throw NotImplementedException();
			}
			else
			{
				// FIXME
				throw InvalidCastException();
			}
		}
	}
}