#include "BitConverter.h"

namespace System
{
	std::array<Byte, 1> BitConverter::GetBytes(Boolean boolean, Boolean igroneEndian)
	{
		std::array<Byte, 1> r;

		Byte* p = (Byte*)&boolean;

		r[0] = *p;

		return r;
	}

	std::array<Byte, 2> BitConverter::GetBytes(Char c, Boolean igroneEndian)
	{
		return GetBytes((Int16)c, igroneEndian);
	}

	std::array<Byte, 2> BitConverter::GetBytes(Int16 i, Boolean igroneEndian)
	{
		std::array<Byte, 2> r;

		Byte* p = (Byte*)&i;

		if (igroneEndian)
		{
			r[0] = *p;
			r[1] = *(p + 1);
		}
		else
		{
			if (IsLittleEndian)
			{
				r[0] = *(p + 1);
				r[1] = *p;
			}
			else
			{
				r[0] = *p;
				r[1] = *(p + 1);
			}
		}

		return r;
	}
}