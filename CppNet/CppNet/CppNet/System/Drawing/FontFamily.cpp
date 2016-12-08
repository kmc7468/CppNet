#include "FontFamily.h"

#include "../ArgumentException.h"

namespace CppNet::System::Drawing
{
	const Int32 FontFamily::LANG_NEUTRAL = 0;

	void FontFamily::SetNativeFamily(const IntPtr& nativeFamily)
	{
		if (nativeFamily == IntPtr::Zero)
			throw ArgumentException();

		this->nativeFamily = nativeFamily;
	}

	FontFamily::FontFamily(const IntPtr& nativeFamily)
		: nativeFamily(nullptr)
	{
		SetNativeFamily(nativeFamily);
	}

	FontFamily::FontFamily(const String& name, Boolean createDefaultOnFail)
		: nativeFamily(nullptr), createDefaultOnFail(createDefaultOnFail)
	{
		// TODO
	}

	FontFamily::FontFamily(const String& name)
		: nativeFamily(nullptr)
	{
		// TODO
	}
}