#ifndef CPPNET_SYSTEM_ACCESSVIOLATIONEXCEPTION_H
#define CPPNET_SYSTEM_ACCESSVIOLATIONEXCEPTION_H

#include "SystemException.h"

namespace CppNet::System
{
	class AccessViolationException : public SystemException
	{
	public:
		AccessViolationException();
		AccessViolationException(const String& message);
		AccessViolationException(const String& message, Exception* innerException);
		~AccessViolationException() = default;

	public:
		String Message() const override;
	};
}

#endif