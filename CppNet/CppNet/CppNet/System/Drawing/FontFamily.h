#ifndef CPPNET_SYSTEM_DRAWING_FONTFAMILY_H
#define CPPNET_SYSTEM_DRAWING_FONTFAMILY_H

#include "../../../Defines.h"
#include "../../../SystemTypes.h"

#include "../Object.h"
#include "../IDisposable.h"
#include "../IntPtr.h"

namespace CppNet::System::Drawing
{
	class FontFamily final : public Object, public IDisposable
	{
	private:
		static const Int32 LANG_NEUTRAL;

		IntPtr nativeFamily;
		Boolean createDefaultOnFail;

	private:
		void SetNativeFamily(const IntPtr& nativeFamily);

	_internal:
		FontFamily(const IntPtr& nativeFamily);
		FontFamily(const String& name, Boolean createDefaultOnFail);

	public:
		FontFamily(const String& name);
	};
}

#endif