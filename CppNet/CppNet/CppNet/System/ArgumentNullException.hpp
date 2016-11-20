#ifndef CPPNET_SYSTEM_ARGUMENTNULLEXCEPTION_HPP
#define CPPNET_SYSTEM_ARGUMENTNULLEXCEPTION_HPP

#include "../../Defines.h"
#include "../../Language.h"

#include "ArgumentException.h"

namespace CppNet::System
{
	class ArgumentNullException : public ArgumentException
	{
	public:
		ArgumentNullException()
			: ArgumentException()
		{}

		ArgumentNullException(const String& paramName)
			: ArgumentException("", paramName)
		{}

		ArgumentNullException(const String& message, Exception* innerException)
			: ArgumentException(message, innerException, "")
		{}

		ArgumentNullException(const String& paramName, const String& message)
			: ArgumentException(message, paramName)
		{}

		ArgumentNullException(const ArgumentNullException& arg)
			: ArgumentException(arg)
		{}

		ArgumentNullException(ArgumentNullException&& arg)
			: ArgumentException(arg)
		{}

		~ArgumentNullException() = default;

		ArgumentNullException& operator=(const ArgumentNullException& arg)
		{
			ArgumentException::operator=(arg);

			return *this;
		}

		ArgumentNullException& operator=(ArgumentNullException&& arg)
		{
			ArgumentException::operator=(arg);

			return *this;
		}

		String Message() const override
		{
			if (paramName == "")
			{
				String msg = TXT_INVALID_ARGUMENT_NULL_DEFMSG;
				if (message != "")
				{
					msg.append(" ");
					msg.append(message);
				}

				return msg;
			}
			else
			{
				String msg = TXT_INVALID_ARGUMENT_NULL_HASPARAM_DEFMSG;
				while (msg.find("%PARAM_NAME%") != String::npos)
				{
					msg = msg.replace(msg.find("%PARAM_NAME%"), 12, paramName);
				}
				if (message != "")
				{
					msg.append(" ");
					msg.append(message);
				}

				return msg;
			}
		}
	};
}

#endif