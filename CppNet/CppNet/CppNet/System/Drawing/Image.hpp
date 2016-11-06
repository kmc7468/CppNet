#ifndef CPPNET_SYSTEM_DRAWING_IMAGE_HPP
#define CPPNET_SYSTEM_DRAWING_IMAGE_HPP

#include "../../../Defines.h"

#include "../Object.h"
#include "../ICloneable.h"
#include "../IDisposable.h"
#include "../IntPtr.h"

#include "../Runtime/Serialization/ISerializable.h"

namespace CppNet::System::Drawing
{
	using namespace Runtime::Serialization;

	class Image abstract : public Object, public ICloneable, public IDisposable, public ISerializable
	{
	public:
		using GetThumbnailImageAbort = std::function<Boolean(void)>;

	private:
		IntPtr nativeImage = 0;
		Byte* rowData = nullptr;
		Object userData;

	private:
		Image() = default;
		Image(const SerializationInfo& info, const StreamingContext& context)
		{

		}
	};
}

#endif