#ifndef CPPNET_SYSTEM_MEDIA_SOUNDPLAYER_H
#define CPPNET_SYSTEM_MEDIA_SOUNDPLAYER_H

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "../ComponentModel/Component.h"
#include "../Runtime/Serialization/ISerializable.h"

#include "../Int32.h"

namespace CppNet::System::Media
{
#ifdef WIN32
	class SoundPlayer : public ComponentModel::Component, public Runtime::Serialization::ISerializable
	{
	private:
		static const Int32 blockSize;
		static const Int32 defaultLoadTimeout;

		// TODO
	};
#endif
}

#endif