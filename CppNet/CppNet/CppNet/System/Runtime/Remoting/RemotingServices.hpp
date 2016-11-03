#ifndef CPPNET_SYSTEM_RUNTIME_REMOTING_REMOTINGSERVICES_HPP
#define CPPNET_SYSTEM_RUNTIME_REMOTING_REMOTINGSERVICES_HPP

#include "../../Object.h"

namespace CppNet::System::Runtime::Remoting
{
	class RemotingServices final : public Object
	{
	public:
		RemotingServices() = default;
		RemotingServices(const RemotingServices& r) = delete;
		RemotingServices(RemotingServices&& r) = delete;
		~RemotingServices() = default;

	public:
		RemotingServices& operator=(const RemotingServices& r) = delete;
		RemotingServices& operator=(RemotingServices&& r) = delete;

	public:

	};
}

#endif