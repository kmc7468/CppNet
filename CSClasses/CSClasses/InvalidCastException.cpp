#include "InvalidCastException.h"

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
		this->targetsite = data.TargetSite();
		this->link = data.HelpLink();
		this->innerException = data.InnerException();
	}

	InvalidCastException::InvalidCastException(InvalidCastException &&sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	InvalidCastException::InvalidCastException(const InvalidCastException& sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	InvalidCastException& InvalidCastException::operator=(InvalidCastException&& ex)
	{
		return InvalidCastException(ex);
	}

	InvalidCastException& InvalidCastException::operator=(const InvalidCastException& ex)
	{
		return InvalidCastException(ex);
	}

	String InvalidCastException::Message() const
	{
		String msg = TXT_INVALID_CAST_DEFMSG;
		msg.append(L" ");
		msg.append(message);

		return msg;
	}
}