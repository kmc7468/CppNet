#include "Unicode.h"

#include "../Defines.h"
#include "../Utility.h"

namespace CppNet
{
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

}