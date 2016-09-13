#include "DoubleT.h"

#include "UInt64.h"
#include "Int64.h"

#include "Utility.h"

namespace System
{
	DoubleT::operator Double()
	{
		return dat;
	}

	Boolean DoubleT::IsNaN(Double d)
	{
		return (*(UInt64*)(&d) & (Int64)0x7FFFFFFFFFFFFFFF) > (Int64)0x7FF0000000000000;
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

	Boolean DoubleT::operator==(const Object& obj) const
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

	Boolean DoubleT::operator!=(const Object& obj) const
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