#include "DoubleT.h"

#include "UInt64.h"
#include "Int64.h"
#include "Exception.h"
#include "Int32.h"

#include "../Utility.h"

namespace System
{
	DoubleT::operator Double()
	{
		return dat;
	}

	Int32 DoubleT::CompareTo(const Object& obj)
	{
		if (is<const DoubleT&>(obj))
		{
			var d = as<const DoubleT&>(obj);

			if (dat < d) return -1;
			if (dat > d) return 1;
			if (dat == d) return 0;

			if (IsNaN(dat))
				return (IsNaN(d) ? 0 : -1);
			else
				return 1;
		}

		throw Exception("파라미터 오류"); // FIXME ArgumentException
	}

	Int32 DoubleT::CompareTo(const DoubleT& obj)
	{
		var d = as<const DoubleT&>(obj);

		if (dat < d) return -1;
		if (dat > d) return 1;
		if (dat == d) return 0;

		if (IsNaN(dat))
			return (IsNaN(d) ? 0 : -1);
		else
			return 1;
	}

	String DoubleT::ToString(String format, std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return String();
	}

	Boolean DoubleT::ToBoolean(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return true;
	}

	Byte DoubleT::ToByte(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	Char DoubleT::ToChar(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return Char();
	}

	DateTime DoubleT::ToDateTime(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return DateTime();
	}

	Double DoubleT::ToDouble(std::unique_ptr<IFormatProvider> formatProvider)
	{
		return dat;
	}

	Int16 DoubleT::ToInt16(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	Int32 DoubleT::ToInt32(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	Int64 DoubleT::ToInt64(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	UInt16 DoubleT::ToUInt16(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	UInt32 DoubleT::ToUInt32(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	UInt64 DoubleT::ToUInt64(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	SByte DoubleT::ToSByte(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	Single DoubleT::ToSingle(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return 0;
	}

	String DoubleT::ToString(std::unique_ptr<IFormatProvider> formatProvider)
	{
		// TODO
		return "";
	}

	Boolean DoubleT::Equals(const DoubleT& obj) const
	{
		if (const_cast<DoubleT&>(obj) == *const_cast<DoubleT*>(this))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	String DoubleT::ToString() const
	{
		return std::to_string(dat);
	}

	Boolean DoubleT::IsInfinity(const DoubleT& d)
	{
		var a = d.dat;
		return (*(Int64*)(&a) & (Int64)0x7FFFFFFFFFFFFFFF) == (Int64)0x7FF0000000000000;
	}

	Boolean DoubleT::IsPositiveInfinity(const DoubleT& d)
	{
		if (d.dat == DoubleT::PositiveInfinity.dat)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Boolean DoubleT::IsNegativeInfinity(const DoubleT& d)
	{
		if (d.dat == DoubleT::NegativeInfinity.dat)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Boolean DoubleT::IsNaN(const DoubleT& d)
	{
		var a = d.dat;
		return (*(UInt64*)(&a) & (Int64)0x7FFFFFFFFFFFFFFF) > (Int64)0x7FF0000000000000;
	}

	Double DoubleT::Data() const
	{
		return dat;
	}

	DoubleT& DoubleT::operator=(DoubleT&& d) const
	{
		return DoubleT(d);
	}

	DoubleT& DoubleT::operator=(const DoubleT& d) const
	{
		return DoubleT(d);
	}

	Boolean DoubleT::operator==(const Object& obj)
	{
		if (is<const DoubleT&>(obj))
		{
			var d = as<const DoubleT&>(obj);

			// FIXME: 저장 방식에 따른 오차 반영 필요
			if (d.dat == dat) return true;
			else return false;
		}
		else return false;
	}

	Boolean DoubleT::operator!=(const Object& obj)
	{
		if (is<const DoubleT&>(obj))
		{
			var d = as<const DoubleT&>(obj);

			// FIXME: 저장 방식에 따른 오차 반영 필요
			if (d.dat == dat) return false;
			else return true;
		}
		else return true;
	}
}