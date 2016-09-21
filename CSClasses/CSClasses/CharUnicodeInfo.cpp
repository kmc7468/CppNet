#include "CharUnicodeInfo.h"
using namespace System;
using namespace System::Globalization;

Int32 CharUnicodeInfo::GetDecimalDightValue(const Char& c)
{
	Char cc = *const_cast<Char*>(&c);
	if (cc >= U'0' && cc <= U'9')
	{
		return cc - U'0';
	}
	// TODO
	return 0;
}
