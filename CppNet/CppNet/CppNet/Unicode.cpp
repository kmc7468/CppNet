#include "Unicode.h"
#include "Unicode9_0.h"

#include "../Defines.h"

namespace CppNet
{
#ifdef UNICODE_CUSTOM // 커스텀일 경우
	Unicode* Unicode::unicode = nullptr;

#else // 지정하지 않은 경우 (Unicode 9.0)
	Unicode* Unicode::unicode = new Unicode9_0();
#endif
}