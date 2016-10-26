#include "InvalidCastException.h"

#include "../../Language.h"

namespace CppNet
{
	namespace System
	{
		InvalidCastException::InvalidCastException(const String& message)
		{
			this->message = message;
		}

		InvalidCastException::InvalidCastException(const String& message, Exception* innerEx)
		{
			this->message = message;
			innerException = innerEx;
		}

		InvalidCastException::InvalidCastException(const ExceptionData& data)
		{
			this->message = data.Message();
			this->source = data.Source();
			this->link = data.HelpLink();
			this->innerException = data.InnerException();
		}

		InvalidCastException::InvalidCastException(InvalidCastException &&sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			innerException = sNewException.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		InvalidCastException::InvalidCastException(const InvalidCastException& sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			innerException = sNewException.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		InvalidCastException &InvalidCastException::operator=(InvalidCastException&& ex)
		{
			message = std::move(ex.message);
			source = std::move(ex.source);
			link = std::move(ex.link);
			innerException = std::move(ex.innerException);

			return *this;
		}

		InvalidCastException &InvalidCastException::operator=(const InvalidCastException& ex)
		{
			message = ex.message;
			source = ex.source;
			link = ex.link;
			innerException = ex.innerException;

			return *this;
		}

		String InvalidCastException::Message() const
		{
			String msg = TXT_INVALID_CAST_DEFMSG;
			if (message != "")
			{
				msg.append(" ");
				msg.append(message);
			}

			return msg;
		}
	}
}