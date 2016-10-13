#include "DoubleT.h"
#include "BitConverter.h"

#include <limits>

namespace System
{
	const DoubleT DoubleT::MinValue = DoubleT(std::numeric_limits<Double>::min());
	const DoubleT DoubleT::MaxValue = DoubleT(std::numeric_limits<Double>::max());

	const DoubleT DoubleT::Zero = DoubleT(0.0);

	const DoubleT DoubleT::NegativeZero = DoubleT(BitConverter::Int64BitsToDouble((UInt64)0x8000000000000000));

	const DoubleT DoubleT::Epsilon = DoubleT(std::numeric_limits<Double>::epsilon());
	const DoubleT DoubleT::NegativeInfinity = DoubleT(-std::numeric_limits<Double>::infinity());
	const DoubleT DoubleT::PositiveInfinity = DoubleT(std::numeric_limits<Double>::infinity());
	const DoubleT DoubleT::NaN = DoubleT(std::numeric_limits<Double>::quiet_NaN());

	DoubleT::DoubleT(Double dat)
	{
		this->dat = dat;
	}

	DoubleT::DoubleT(DoubleT&& sNewDoubleT)
	{
		this->dat = sNewDoubleT.dat;
	}

	DoubleT::DoubleT(const DoubleT& sNewDoubleT)
	{
		this->dat = sNewDoubleT.dat;
	}
}