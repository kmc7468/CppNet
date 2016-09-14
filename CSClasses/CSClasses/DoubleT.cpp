#include "DoubleT.h"

namespace System
{
	const DoubleT DoubleT::MinValue = DoubleT(-1.7976931348623157E+308);
	const DoubleT DoubleT::MaxValue = DoubleT(1.7976931348623157E+308);

	const DoubleT DoubleT::Epsilon = DoubleT(4.9406564584124654E-324);
	const DoubleT DoubleT::NegativeInfinity = DoubleT((Double)-1.0 / (Double)0.0);
	const DoubleT DoubleT::PositiveInfinity = DoubleT((Double)1.0 / (Double)0.0);
	const DoubleT DoubleT::NaN = DoubleT((Double)0.0 / (Double)0.0);

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