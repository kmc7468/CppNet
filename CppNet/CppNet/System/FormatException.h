#ifndef SYSTEM_FORMATEXCEPTION_H
#define SYSTEM_FORMATEXCEPTION_H

#include "../Defines.h"

#include "Exception.h"
#include "SystemException.h"
#include "String.h"

namespace System
{
	class FormatException : public SystemException
	{
	public:
		FormatException() = default;
		FormatException(const String& message);
		FormatException(const String& message, Exception* innerEx);
		FormatException(const ExceptionData& data);
		FormatException(FormatException &&sNewException);
		FormatException(const FormatException& sNewException);
		~FormatException() = default;

	public:
		FormatException &operator=(FormatException&& ex);
		FormatException &operator=(const FormatException& ex);

	public:
		String Message() const override;
	};
}

#endif