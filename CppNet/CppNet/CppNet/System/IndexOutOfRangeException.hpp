#ifndef CPPNET_SYSTEM_INDEXOUTOFRANGEEXCEPTION_HPP
#define CPPNET_SYSTEM_INDEXOUTOFRANGEEXCEPTION_HPP

#include "../../Defines.h"
#include "../../Language.h"

#include "String.h"
#include "SystemException.h"

namespace CppNet::System
{
	class IndexOutOfRangeException final : public SystemException
	{
	public:
		IndexOutOfRangeException() = default;
		IndexOutOfRangeException(const String& message)
			: SystemException(message)
		{}

		IndexOutOfRangeException(const String& message, Exception* innerEx)
			: SystemException(message, innerEx)
		{}

		IndexOutOfRangeException(const ExceptionData& data)
			: SystemException(data)
		{}

		IndexOutOfRangeException(IndexOutOfRangeException &&e)
		{
			message = std::move(e.message);
			source = std::move(e.source);
			link = std::move(e.link);
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		IndexOutOfRangeException(const IndexOutOfRangeException& e)
		{
			message = e.message;
			source = e.source;
			link = e.link;
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		~IndexOutOfRangeException() = default;

	public:
		IndexOutOfRangeException& operator=(IndexOutOfRangeException&& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

		IndexOutOfRangeException& operator=(const IndexOutOfRangeException& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

	public:
		String Message() const override
		{
			String msg = TXT_INDEX_DEFMSG;
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