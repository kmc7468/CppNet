#include "BitConverter.h"

namespace System
{
#ifdef BIGENDIAN
	const Boolean BitConverter::IsLittleEndian = false;
#else
	const Boolean BitConverter::IsLittleEndian = true;
#endif
}