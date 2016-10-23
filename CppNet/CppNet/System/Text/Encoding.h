#ifndef SYSTEM_TEXT_ENCODING_H
#define SYSTEM_TEXT_ENCODING_H

#include "../../Defines.h"

#include "../Object.h"
#include "../ICloneable.h"

namespace System
{
	namespace Text
	{
		class Encoding : public Object, public ICloneable
		{
		private:
			static volatile Encoding defaultEncoding;
			static volatile Encoding unicodeEncoding;
			static volatile Encoding bigEndianUnicode;
			static volatile Encoding utf7Encoding;
			static volatile Encoding utf8Encoding;
			static volatile Encoding utf32Encoding;
			static volatile Encoding asciiEncoding;
			static volatile Encoding latin1Encoding;
		};
	}
}

#endif