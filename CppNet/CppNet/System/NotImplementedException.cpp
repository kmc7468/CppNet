#include "NotImplementedException.h"

#include "../Language.h"

namespace System
{
	NotImplementedException::NotImplementedException(const String& message)
	{
		this->message = message;
	}

	NotImplementedException::NotImplementedException(const String& message, Exception* innerEx)
	{
		this->message = message;
		innerException = innerEx;
	}

	NotImplementedException::NotImplementedException(const ExceptionData& data)
	{
		this->message = data.Message();
		this->source = data.Source();
		this->targetsite = data.TargetSite();
		this->link = data.HelpLink();
		this->innerException = data.InnerException();
	}

	NotImplementedException::NotImplementedException(NotImplementedException &&sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	NotImplementedException::NotImplementedException(const NotImplementedException& sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	NotImplementedException NotImplementedException::operator=(NotImplementedException&& ex)
	{
		return NotImplementedException(ex);
	}

	NotImplementedException NotImplementedException::operator=(const NotImplementedException& ex)
	{
		return NotImplementedException(ex);
	}

	String NotImplementedException::Message() const
	{
		String msg = TXT_NOTIMPL_DEFMSG;
		msg.append(" ");
		msg.append(message);

		return msg;
	}
}