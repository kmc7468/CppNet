#ifndef SYSTEM_GLOBALIZATION_CHARUNICODEINFO_H
#define SYSTEM_GLOBALIZATION_CHARUNICODEINFO_H

#include "../../Defines.h"

#include "../Object.h"

#include "../Int32.h"
#include "../Char.h"

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
			static Int32 GetDecimalDightValue(const Char& c);
			/*static Int32 GetDecimalDightValue(const String& str, Int32 index); TODO*/

			
		};
	}
}

#endif