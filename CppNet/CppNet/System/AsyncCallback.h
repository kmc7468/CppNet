#ifndef SYSTEM_ASYNCCALLBACK_H
#define SYSTEM_ASYNCCALLBACK_H

#include <functional>
#include <memory>

#include "IAsyncResult.h"

namespace System
{
	using AsyncCallback = std::function<void(std::unique_ptr<IAsyncResult>)>;
}

#endif