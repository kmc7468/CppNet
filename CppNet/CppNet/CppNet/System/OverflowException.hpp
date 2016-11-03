#ifndef CPPNET_SYSTEM_OVERFLOWEXCEPTION_HPP
#define CPPNET_SYSTEM_OVERFLOWEXCEPTION_HPP

#include "../../Defines.h"
#include "../../Language.h"

#include "String.h"
#include "ArithmeticException.hpp"

namespace CppNet::System
{
	class OverflowException final : public ArithmeticException
	{
	public:
		OverflowException() = default;
		OverflowException(const String& message)
			: ArithmeticException(message)
		{}

		OverflowException(const String& message, Exception* innerEx)
			: ArithmeticException(message, innerEx)
		{}

		OverflowException(const ExceptionData& data)
			: ArithmeticException(data)
		{}

		OverflowException(OverflowException &&e)
		{
			message = std::move(e.message);
			source = std::move(e.source);
			link = std::move(e.link);
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		OverflowException(const OverflowException& e)
		{
			message = e.message;
			source = e.source;
			link = e.link;
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		~OverflowException() = default;

	public:
		OverflowException& operator=(OverflowException&& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

		OverflowException& operator=(const OverflowException& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

	public:
		String Message() const override
		{
			String msg = TXT_OVERFLOW_DEFMSG;
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