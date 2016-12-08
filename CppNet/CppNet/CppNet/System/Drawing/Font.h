#ifndef CPPNET_SYSTEM_DRAWING_FONT_H
#define CPPNET_SYSTEM_DRAWING_FONT_H

#include "../../../Defines.h"
#include "../../../SystemTypes.h"

#include "../Object.h"
#include "../IntPtr.h"
#include "../ICloneable.h"
#include "../IDisposable.h"
#include "../Runtime/Serialization/ISerializable.h"

#include "FontStyle.h"

namespace CppNet::System::Drawing
{
	class Font final : public Object, public ICloneable, public IDisposable, public Runtime::Serialization::ISerializable
	{
	private:
		static const Int32 LogFontCharSetOffset;
		static const Int32 LogFontNameOffset;

		IntPtr nativeFont;
		Single fontSize;
		FontStyle fontStyle;
	};
}

#endif