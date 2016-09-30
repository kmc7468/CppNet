#include "FormatException.h"

#include "Language.h"

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
		this->targetsite = data.TargetSite();
		this->link = data.HelpLink();
		this->innerException = data.InnerException();
	}

	FormatException::FormatException(FormatException &&sNewException)
	{
		message = std::move(sNewException.message);
		source = std::move(sNewException.source);
		link = std::move(sNewException.link);
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	FormatException::FormatException(const FormatException& sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	FormatException FormatException::operator=(FormatException&& ex)
	{
		return FormatException(std::move(ex));
	}

	FormatException FormatException::operator=(const FormatException& ex)
	{
		return FormatException(ex);
	}

	String FormatException::Message() const
	{
		String msg = TXT_FORMAT_DEFMSG;
		msg.append(" ");
		msg.append(message);

		return msg;
	}
}