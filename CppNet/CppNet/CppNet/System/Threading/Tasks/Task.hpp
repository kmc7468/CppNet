#ifndef CPPNET_SYSTEM_THAREDING_TASKS_HPP
#define CPPNET_SYSTEM_THAREDING_TASKS_HPP

#include "../../IAsyncResult.h"
#include "../../IDisposable.h"

namespace CppNet::System::Threading::Tasks
{
	class Task : public IAsyncResult, public IDisposable
	{

	};
}

#endif