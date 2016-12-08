#ifndef CPPNET_SYSTEM_DRAWING_FONTSTYLE_H
#define CPPNET_SYSTEM_DRAWING_FONTSTYLE_H

namespace CppNet::System::Drawing
{
	enum class FontStyle
	{
		Regular = 0,
		Bold = 1,
		Italic = 2,
		Underline = 4,
		Strikeout = 8,
	};
}

#endif