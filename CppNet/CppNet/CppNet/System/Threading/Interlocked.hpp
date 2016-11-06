#ifndef CPPNET_SYSTEM_THREADING_INTERLOCKED_HPP
#define CPPNET_SYSTEM_THREADING_INTERLOCKED_HPP

#include "../../../Defines.h"

#include "../Object.h"

namespace CppNet::System::Threading
{
	class Interlocked final : public Object
	{
	public:
		Interlocked() = default;
		Interlocked(const Interlocked& i) = delete;
		Interlocked(Interlocked&& i) = delete;
		~Interlocked() = default;

	public:
		Interlocked& operator=(const Interlocked& i) = delete;
		Interlocked& operator=(Interlocked&& i) = delete;
	};
}

#endif