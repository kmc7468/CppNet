#ifndef CPPNET_SYSTEM_NOTSUPPORTEDEXCEPTION_H
#define CPPNET_SYSTEM_NOTSUPPORTEDEXCEPTION_H

#include "SystemException.h"
#include "String.h"
#include "Exception.h"

namespace CppNet::System
{
	class NotSupportedException : public SystemException
	{
	public:
		NotSupportedException();
		NotSupportedException(const String& message);
		NotSupportedException(const String& message, Exception* innerException);

	public:
		String Message() const override;
	};
}

#endif