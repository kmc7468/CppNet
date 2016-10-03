#include "InvalidOperationException.h"

#include "../Language.h"

namespace System
{
	InvalidOperationException::InvalidOperationException(const String& message)
	{
		this->message = message;
	}

	InvalidOperationException::InvalidOperationException(const String& message, Exception* innerEx)
	{
		this->message = message;
		innerException = innerEx;
	}

	InvalidOperationException::InvalidOperationException(const ExceptionData& data)
	{
		this->message = data.Message();
		this->source = data.Source();
		this->link = data.HelpLink();
		this->innerException = data.InnerException();
	}

	InvalidOperationException::InvalidOperationException(InvalidOperationException &&sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	InvalidOperationException::InvalidOperationException(const InvalidOperationException& sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	InvalidOperationException InvalidOperationException::operator=(InvalidOperationException&& ex)
	{
		message = std::move(ex.message);
		source = std::move(ex.source);
		link = std::move(ex.link);
		innerException = std::move(ex.innerException);

		return *this;
	}

	InvalidOperationException InvalidOperationException::operator=(const InvalidOperationException& ex)
	{
		message = ex.message;
		source = ex.source;
		link = ex.link;
		innerException = ex.innerException;

		return *this;
	}

	String InvalidOperationException::Message() const
	{
		String msg = TXT_INVALID_OPER_DEFMSG;
		msg.append(" ");
		msg.append(message);

		return msg;
	}
}