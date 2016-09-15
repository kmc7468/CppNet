#ifndef SYSTEM_INVALIDOPERATIONEXCEPTION_H
#define SYSTEM_INVALIDOPERATIONEXCEPTION_H

#include "Exception.h"
#include "String.h"

namespace System
{
	class InvalidOperationException : public Exception
	{
	public:
		InvalidOperationException() = default;
		InvalidOperationException(const String& message);
		InvalidOperationException(const String& message, Exception* innerEx);
		InvalidOperationException(const ExceptionData& data);
		InvalidOperationException(InvalidOperationException &&sNewException);
		InvalidOperationException(const InvalidOperationException& sNewException);
		~InvalidOperationException() = default;

	public:
		InvalidOperationException operator=(InvalidOperationException&& ex);
		InvalidOperationException operator=(const InvalidOperationException& ex);

	public:
		String Message() const override;
	};
}

#endif