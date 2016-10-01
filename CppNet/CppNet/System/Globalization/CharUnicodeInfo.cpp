#include "CharUnicodeInfo.h"
using namespace System;
using namespace System::Globalization;

#include "../../CppNet/Unicode.h"

Int32 CharUnicodeInfo::GetDecimalDightValue(const Char& c)
{
	return CppNet::Unicode::GetUnicode()->GetDecimalDightValue(c);
}
