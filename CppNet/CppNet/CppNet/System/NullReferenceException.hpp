#ifndef CPPNET_SYSTEM_NULLREFERENCEEXCEPTION_HPP
#define CPPNET_SYSTEM_NULLREFERENCEEXCEPTION_HPP

#include "../../Defines.h"
#include "../../Language.h"

#include "SystemException.h"

namespace CppNet::System
{
	class NullReferenceException : public SystemException
	{
	public:
		NullReferenceException() = default;
		NullReferenceException(const String& message)
			: SystemException(message)
		{}

		NullReferenceException(const String& message, Exception* innerEx)
			: SystemException(message, innerEx)
		{}

		NullReferenceException(const ExceptionData& data)
			: SystemException(data)
		{}

		NullReferenceException(NullReferenceException &&e)
		{
			message = std::move(e.message);
			source = std::move(e.source);
			link = std::move(e.link);
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		NullReferenceException(const NullReferenceException& e)
		{
			message = e.message;
			source = e.source;
			link = e.link;
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		~NullReferenceException() = default;

	public:
		NullReferenceException& operator=(NullReferenceException&& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

		NullReferenceException& operator=(const NullReferenceException& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

	public:
		String Message() const override
		{
			String msg = TXT_NULLREF_DEFMSG;
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