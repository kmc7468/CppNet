#include "Marshal.h"

namespace CppNet::System::Runtime::InteropServices
{
	template<typename T>
	Int32 Marshal::SizeOf(T data)
	{
		return sizeof(data);
	}
}