#include "CharUnicodeInfo.h"
#include "../../../CppNet/Unicode.h"

namespace CppNet::System::Globalization
{
	Int32 CharUnicodeInfo::GetDecimalDightValue(const Char& c)
	{
		return CppNet::Unicode::GetUnicode()->GetDecimalDightValue(c);
	}
}