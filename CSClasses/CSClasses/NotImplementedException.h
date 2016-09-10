#ifndef SYSTEM_NOTIMPLEMENTEDEXCEPTION_H
#define SYSTEM_NOTIMPLEMENTEDEXCEPTION_H

#include "System.h"

namespace System
{
	class NotImplementedException : public Exception
	{
	public:
		NotImplementedException() = default;
		NotImplementedException(const String& message);
		NotImplementedException(const String& message, Exception* innerEx);
		NotImplementedException(const ExceptionData& data);
		NotImplementedException(NotImplementedException &&sNewException);
		NotImplementedException(const NotImplementedException& sNewException);
		~NotImplementedException() = default;

	public:
		NotImplementedException& operator=(NotImplementedException&& ex);
		NotImplementedException& operator=(const NotImplementedException& ex);

	public:
		String Message() const override;
	};
}

#endif