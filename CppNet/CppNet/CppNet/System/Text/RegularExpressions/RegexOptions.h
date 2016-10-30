#ifndef CPPNET_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEXOPTIONS_H
#define CPPNET_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEXOPTIONS_H

namespace CppNet
{
	namespace System
	{
		namespace Text
		{
			namespace RegularExpressions
			{
				enum class RegexOptions
				{
					None = 0x0000,
					IgnoreCase = 0x0001,
					Multiline = 0x0002,
					ExplicitCapture = 0x0004,

					Compiled = 0x0008,
					Singleline = 0x0010,
					IgnorePatternWhitespace = 0x0020,
					RightToLeft = 0x0040,

					Debug = 0x0080,
					ECMAScript = 0x0100,
					CultureInvariant = 0x0200,
				};
			}
		}
	}
}

#endif