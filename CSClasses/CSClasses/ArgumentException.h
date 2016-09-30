#ifndef SYSTEM_ARGUMENTEXCEPTION_H
#define SYSTEM_ARGUMENTEXCEPTION_H

#include "Exception.h"
#include "String.h"

namespace System
{
	class ArgumentException : public Exception
	{
	public:
		ArgumentException() = default;
		ArgumentException(const String& message, const String& paramName = "");
		ArgumentException(const String& message, Exception* innerEx, const String& paramName = "");
		ArgumentException(const ExceptionData& data, const String& paramName = "");
		ArgumentException(ArgumentException &&sNewException);
		ArgumentException(const ArgumentException& sNewException);
		~ArgumentException() = default;

	protected:
		String paramName;

	public:
		ArgumentException& operator=(ArgumentException&& ex);
		ArgumentException& operator=(const ArgumentException& ex);

	public:
		String Message() const override;

	public:
		virtual String ParamName() const;
	};
}

#endif