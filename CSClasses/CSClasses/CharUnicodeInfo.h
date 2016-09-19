#ifndef SYSTEM_GLOBALIZATION_CHARUNICODEINFO_H
#define SYSTEM_GLOBALIZATION_CHARUNICODEINFO_H

#include "Object.h"

namespace System
{
	namespace Globalization
	{
		class CharUnicodeInfo final : public Object
		{
		public:
			CharUnicodeInfo() = default;
			CharUnicodeInfo(CharUnicodeInfo&& c) = delete;
			CharUnicodeInfo(const CharUnicodeInfo& c) = delete;
			~CharUnicodeInfo() = default;

			CharUnicodeInfo& operator=(CharUnicodeInfo&& c) = delete;
			CharUnicodeInfo& operator=(const CharUnicodeInfo& c) = delete;

		public:

		};
	}
}

#endif