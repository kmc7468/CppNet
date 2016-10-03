#include "FormatException.h"

#include "../Language.h"

namespace System
{
	FormatException::FormatException(const String& message)
	{
		this->message = message;
	}

	FormatException::FormatException(const String& message, Exception* innerEx)
	{
		this->message = message;
		innerException = innerEx;
	}

	FormatException::FormatException(const ExceptionData& data)
	{
		this->message = data.Message();
		this->source = data.Source();
		this->link = data.HelpLink();
		this->innerException = data.InnerException();
	}

	FormatException::FormatException(FormatException &&sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	FormatException::FormatException(const FormatException& sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	FormatException FormatException::operator=(FormatException&& ex)
	{
		message = std::move(ex.message);
		source = std::move(ex.source);
		link = std::move(ex.link);
		innerException = std::move(ex.innerException);

		return *this;
	}

	FormatException FormatException::operator=(const FormatException& ex)
	{
		message = ex.message;
		source = ex.source;
		link = ex.link;
		innerException = ex.innerException;

		return *this;
	}

	String FormatException::Message() const
	{
		String msg = TXT_FORMAT_DEFMSG;
		msg.append(" ");
		msg.append(message);

		return msg;
	}
}