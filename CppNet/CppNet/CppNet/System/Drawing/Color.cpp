#include "Color.h"

namespace CppNet::System::Drawing
{
	const Color Color::Empty = Color();
	const Int16 Color::StateKnownColorValid = 0x0001;
	const Int16 Color::StateARGBValueValid = 0x0002;
	const Int16 Color::StateValueMask = (Int16)Color::StateARGBValueValid;
	const Int16 Color::StateNameValid = 0x0008;
	const Int64 Color::NotDefinedValue = 0;
	const Int32 Color::ARGBAlphaShift = 24;
	const Int32 Color::ARGBRedShift = 16;
	const Int32 Color::ARGBGreenShift = 8;
	const Int32 Color::ARGBBlueShift = 0;

	Color::Color()
		: value(0), state(0), name(""), knownColor(0)
	{ }

	Color::Color(KnownColor color)
		: value(0), state(StateKnownColorValid), name(""), knownColor((Int16)color)
	{ }

	Color::Color(Int64 value, Int16 state, const String& name, KnownColor knownColor)
		: value(value), state(state), name(name), knownColor((Int16)knownColor)
	{ }

	Byte Color::R() const
	{
		return (Byte)((Value() >> ARGBRedShift) & 0xFF);
	}

	Byte Color::G() const
	{
		return (Byte)((Value() >> ARGBGreenShift) & 0xFF);
	}

	Byte Color::B() const
	{
		return (Byte)((Value() >> ARGBBlueShift) & 0xFF);
	}

	Byte Color::A() const
	{
		return (Byte)((Value() >> ARGBAlphaShift) & 0xFF);
	}

	Boolean Color::IsKnownColor() const
	{
		return ((state & StateKnownColorValid) != 0);
	}

	Boolean Color::IsEmpty() const
	{
		return state == 0;
	}

	Boolean Color::IsNamedColor() const
	{
		return ((state & StateNameValid) != 0) || IsKnownColor();
	}

	Boolean Color::IsSystemColor() const
	{
		return IsKnownColor() && ((((KnownColor)knownColor) <= KnownColor::WindowText) || (((KnownColor)knownColor) > KnownColor::YellowGreen));
	}

	String Color::NameAndARGBValue() const
	{
		return "{{Name=" + name + ", ARGB=(" + std::to_string(A()) + ", " + std::to_string(R()) + ", " + std::to_string(G()) + ", " + std::to_string(B()) + ")}}";
	}

	String Color::Name() const
	{
		return ""; // TODO
	}

	Int64 Color::Value() const
	{
		if ((state & StateValueMask) != 0)
			return value;

		/*if (IsKnownColor)
			return (Int32)KnownColorTable.KnownColorToArgb((KnownColor)knownColor);*/
		// TODO

		return NotDefinedValue;
	}
}