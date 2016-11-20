#include "ArgumentException.h"

#include "../../Language.h"

#include <algorithm>

namespace CppNet
{
	namespace System
	{
		ArgumentException::ArgumentException(const String& message, const String& paramName)
			: SystemException(message)
			, paramName(paramName)
		{

		}

		ArgumentException::ArgumentException(const String& message, Exception* innerEx, const String& paramName)
			: SystemException(message, innerEx)
			, paramName(paramName)
		{

		}

		ArgumentException::ArgumentException(const ExceptionData& data, const String& paramName)
			: SystemException(data)
			, paramName(paramName)
		{

		}

		ArgumentException::ArgumentException(ArgumentException &&sNewException)
		{
			message = std::move(sNewException.message);
			source = std::move(sNewException.source);
			link = std::move(sNewException.link);
			innerException = sNewException.innerException;
			// FIXME innerException ¾èÀºº¹»ç

			paramName = std::move(sNewException.paramName);
		}

		ArgumentException::ArgumentException(const ArgumentException& sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			innerException = sNewException.innerException;
			// FIXME innerException ¾èÀºº¹»ç

			paramName = sNewException.paramName;
		}

		ArgumentException& ArgumentException::operator=(ArgumentException&& ex)
		{
			Exception::operator=(std::move(ex));

			paramName = std::move(ex.paramName);


			return *this;
		}

		ArgumentException& ArgumentException::operator=(const ArgumentException& ex)
		{
			Exception::operator=(ex);

			paramName = ex.paramName;


			return *this;
		}

		String ArgumentException::Message() const
		{
			if (paramName == "")
			{
				String msg = TXT_INVALID_ARGUMENT_DEFMSG;
				if (message != "")
				{
					msg.append(" ");
					msg.append(message);
				}

				return msg;
			}
			else
			{
				String msg = TXT_INVALID_ARGUMENT_HASPARAM_DEFMSG;
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

		String ArgumentException::ParamName() const
		{
			return paramName;
		}
	}
}