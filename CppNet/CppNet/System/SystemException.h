#ifndef SYSTEM_SYSTEMEXCEPTION_H
#define SYSTEM_SYSTEMEXCEPTION_H

#include "../Defines.h"

#include "Exception.h"

namespace System
{
	class SystemException : public Exception
	{
	public:
		SystemException() = default;
		SystemException(const String& message);
		SystemException(const String& message, Exception* innerException);
		SystemException(const Exception::ExceptionData& data);
		SystemException(SystemException&& ex);
		SystemException(const SystemException& ex);
		~SystemException() = default;

	public:
		SystemException& operator=(SystemException&& ex);
		SystemException& operator=(const SystemException& ex);
	};
}

#endif