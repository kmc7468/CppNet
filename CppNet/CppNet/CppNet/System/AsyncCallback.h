#ifndef SYSTEM_ASYNCCALLBACK_H
#define SYSTEM_ASYNCCALLBACK_H

#include "../../Defines.h"

#include <functional>
#include <memory>

#include "IAsyncResult.h"

namespace CppNet
{
	namespace System
	{
		using AsyncCallback = std::function<void(std::unique_ptr<IAsyncResult>)>;
	}
}

#endif