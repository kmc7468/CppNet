#ifndef CPPNET_SYSTEM_TEXT_ENCODERFALLBACK_HPP
#define CPPNET_SYSTEM_TEXT_ENCODERFALLBACK_HPP

#include "../../../Defines.h"

#include "../Object.h"

namespace CppNet::System::Text
{
	class EncoderFallback : public Object
	{
	private:
		Boolean bIsMicrosoftBestFitFallback = false;

		EncoderFallback* replacementFallback = nullptr;
		EncoderFallback* exceptionFallback = nullptr;

		static Object* s_InternalSyncObject;
		static const Object* const InternalSyncObject()
		{
			if (s_InternalSyncObject == nullptr)
			{
				Object* o = new Object;
			}

			return s_InternalSyncObject;
		}
	};
}

#endif