#include "DoubleT.h"

namespace System
{
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