#ifndef CPPNET_SYSTEM_DRAWING_COLOR_H
#define CPPNET_SYSTEM_DRAWING_COLOR_H

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../Object.h"
#include "../Int32.h"
#include "../Int16.h"
#include "../Int64.h"
#include "../Byte.h"

#include "KnownColor.h"

namespace CppNet::System::Drawing
{
	class Color final : public Object
	{
	public:
		static const Color Empty;

	private:
		static const Int16 StateKnownColorValid;
		static const Int16 StateARGBValueValid;
		static const Int16 StateValueMask;
		static const Int16 StateNameValid;
		static const Int64 NotDefinedValue;

		static const Int32 ARGBAlphaShift;
		static const Int32 ARGBRedShift;
		static const Int32 ARGBGreenShift;
		static const Int32 ARGBBlueShift;

	private:
		const String name;
		const Int64 value;
		const Int16 knownColor;
		const Int16 state;

	_internal:
		Color(KnownColor color);

	private:
		Color();
		Color(Int64 value, Int16 state, const String& name, KnownColor knownColor);

	public:
		Byte R() const;
		Byte G() const;
		Byte B() const;
		Byte A() const;

		Boolean IsKnownColor() const;
		Boolean IsEmpty() const;
		Boolean IsNamedColor() const;
		Boolean IsSystemColor() const;

	private:
		String NameAndARGBValue() const;

	public:
		String Name() const;

	private:
		Int64 Value() const;

		// TODO
	};
}

#endif