#include "CharUnicodeInfo.h"
using namespace CppNet::System;
using namespace CppNet::System::Globalization;

#include "../../../CppNet/Unicode.h"

Int32 CharUnicodeInfo::GetDecimalDightValue(const Char& c)
{
	return CppNet::Unicode::GetUnicode()->GetDecimalDightValue(c);
}
