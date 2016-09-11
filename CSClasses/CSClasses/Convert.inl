#include "Exception.h"
#include "Language.h"
#include "InvalidCastException.h"
#include "FormatException.h"
#include "Math.h"
#include "Convert.h"

#include "Math.h"
#include "Exception.h"
#include "InvalidCastException.h"
#include "FormatException.h"

#include "Language.h"

namespace System
{
	Boolean Convert::ToBoolean(Boolean b)
	{
		return b;
	}

	Boolean Convert::ToBoolean(Char c)
	{
		Boolean(*p)(Char) = ToBoolean;
		throw InvalidCastException(Exception::ExceptionData(TXT_INVAILD_CAST_CHAR2BOOL, L"", L"", p, nullptr));
	}

	Boolean Convert::ToBoolean(DateTime d)
	{
		Boolean(*p)(DateTime) = ToBoolean;
		throw InvalidCastException(Exception::ExceptionData(TXT_INVALID_CAST_DATETIME2BOOL, L"", L"", p, nullptr));
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
			Boolean(*p)(const String&) = ToBoolean;
			throw FormatException(Exception::ExceptionData(TXT_FORMAT_STRING2BOOL_NOTSTR, L"", L"", p, nullptr));
		}
	}

	Byte Convert::ToByte(Boolean b)
	{
		return b ? 1 : 0;
	}

	Byte Convert::ToByte(Char c)
	{
		if (c > 255)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)c;
	}

	Byte Convert::ToByte(DateTime d)
	{
		Byte(*p)(DateTime) = ToByte;
		throw InvalidCastException(Exception::ExceptionData(TXT_INVALID_CAST_DATETIME2BYTE, L"", L"", p, nullptr));
	}

	Byte Convert::ToByte(Byte b)
	{
		return b;
	}

	Byte Convert::ToByte(SByte b)
	{
		if (b < 0)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)b;
	}

	Byte Convert::ToByte(Double d)
	{
		d = Math::Round(d);

		if (d > 255 || d < 0)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)d;
	}

	Byte Convert::ToByte(Single d)
	{
		d = (Single)Math::Round(d);

		if (d > 255 || d < 0)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)d;
	}

	Byte Convert::ToByte(Int16 i)
	{
		if (i > 255 || i < 0)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)i;
	}

	Byte Convert::ToByte(Int32 i)
	{
		if (i > 255 || i < 0)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)i;
	}

	Byte Convert::ToByte(Int64 i)
	{
		if (i > 255 || i < 0)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)i;
	}

	Byte Convert::ToByte(UInt16 i)
	{
		if (i > 255)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)i;
	}

	Byte Convert::ToByte(UInt32 i)
	{
		if (i > 255)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)i;
	}

	Byte Convert::ToByte(UInt64 i)
	{
		if (i > 255)
		{
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
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
			throw Exception(L"오버플로"); // FIXME: Overflow Exception
		}

		return (Byte)i;
	}
}