#ifndef CPPNET_SYSTEM_ARITHMETICEXCEPTION_HPP
#define CPPNET_SYSTEM_ARITHMETICEXCEPTION_HPP

#include "../../Defines.h"
#include "../../Language.h"

#include "String.h"
#include "SystemException.h"

namespace CppNet::System
{
	class ArithmeticException : public SystemException
	{
	public:
		ArithmeticException() = default;
		ArithmeticException(const String& message)
			: SystemException(message)
		{}

		ArithmeticException(const String& message, Exception* innerEx)
			: SystemException(message, innerEx)
		{}

		ArithmeticException(const ExceptionData& data)
			: SystemException(data)
		{}

		ArithmeticException(ArithmeticException &&e)
		{
			message = std::move(e.message);
			source = std::move(e.source);
			link = std::move(e.link);
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		ArithmeticException(const ArithmeticException& e)
		{
			message = e.message;
			source = e.source;
			link = e.link;
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		~ArithmeticException() = default;

	public:
		ArithmeticException& operator=(ArithmeticException&& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

		ArithmeticException& operator=(const ArithmeticException& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

	public:
		String Message() const override
		{
			String msg = TXT_ARITHMETIC_DEFMSG;
			if (message != "")
			{
				msg.append(" ");
				msg.append(message);
			}

			return msg;
		}
	};
}

#endif