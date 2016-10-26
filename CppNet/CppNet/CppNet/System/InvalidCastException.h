#ifndef SYSTEM_INVALIDCASTEXCEPTION_H
#define SYSTEM_INVALIDCASTEXCEPTION_H

#include "../../Defines.h"

#include "Exception.h"
#include "SystemException.h"
#include "String.h"

namespace CppNet
{
	namespace System
	{
		class InvalidCastException : public SystemException
		{
		public:
			InvalidCastException() = default;
			InvalidCastException(const String& message);
			InvalidCastException(const String& message, Exception* innerEx);
			InvalidCastException(const ExceptionData& data);
			InvalidCastException(InvalidCastException &&sNewException);
			InvalidCastException(const InvalidCastException& sNewException);
			~InvalidCastException() = default;

		public:
			InvalidCastException &operator=(InvalidCastException&& ex);
			InvalidCastException &operator=(const InvalidCastException& ex);

		public:
			String Message() const override;
		};
	}
}

#endif