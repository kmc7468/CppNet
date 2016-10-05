#include "Unicode.h"
using namespace CppNet;

#include "../Utility.h"

const Unicode* const Unicode::GetUnicode()
{
	return unicode;
}

#ifdef UNICODE_CUSTOM
void Unicode::SetUnicode(Unicode* uni)
{
	*unicode = *uni;
}
#endif