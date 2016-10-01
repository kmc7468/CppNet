#include "Exception.h"

#include "Language.h"

namespace System
{
	Exception::ExceptionData::ExceptionData(const String& message, const String& source, const String& link, void* target, Exception* inner)
	{
		this->message = message;
		this->source = source;
		this->link = link;
		this->target = target;
		this->inner = inner;
	}

	Exception::ExceptionData::ExceptionData(Exception::ExceptionData&& sNewExceptionData)
	{
		message = sNewExceptionData.message;
		source = sNewExceptionData.source;
		link = sNewExceptionData.link;
		target = sNewExceptionData.target;
		inner = sNewExceptionData.inner;
		// FIXME inner ¾èÀºº¹»ç
	}

	Exception::ExceptionData::ExceptionData(const Exception::ExceptionData& sNewExceptionData)
	{
		message = sNewExceptionData.message;
		source = sNewExceptionData.source;
		link = sNewExceptionData.link;
		target = sNewExceptionData.target;
		inner = sNewExceptionData.inner;
		// FIXME inner ¾èÀºº¹»ç
	}

	Exception::ExceptionData Exception::ExceptionData::operator=(const Exception::ExceptionData& ex)
	{
		return Exception::ExceptionData(ex);
	}

	Exception::ExceptionData Exception::ExceptionData::operator=(Exception::ExceptionData&& ex)
	{
		return Exception::ExceptionData(ex);
	}

	String Exception::ExceptionData::Message() const
	{
		return message;
	}

	String Exception::ExceptionData::HelpLink() const
	{
		return link;
	}

	String Exception::ExceptionData::Source() const
	{
		return source;
	}

	void* Exception::ExceptionData::TargetSite() const
	{
		return target;
	}

	Exception* Exception::ExceptionData::InnerException() const
	{
		return inner;
	}

	Exception::Exception(const String& message)
	{
		this->message = message;
	}

	Exception::Exception(const String& message, Exception* innerEx)
	{
		this->message = message;
		innerException = innerEx;
	}

	Exception::Exception(const ExceptionData& data)
	{
		this->message = data.Message();
		this->source = data.Source();
		this->targetsite = data.TargetSite();
		this->link = data.HelpLink();
		this->innerException = data.InnerException();
	}

	Exception::Exception(Exception &&sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	Exception::Exception(const Exception& sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		targetsite = sNewException.targetsite;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	Exception Exception::operator=(const Exception& ex)
	{
		return Exception(ex);
	}
	Exception Exception::operator=(Exception&& ex)
	{
		return Exception(ex);
	}

	String Exception::Message() const
	{
		String msg = TXT_EXCEPTION_DEFMSG;
		msg.append(" ");
		msg.append(message);

		return msg;
	}

	const void* const Exception::TargetSite() const
	{
		return targetsite;
	}

	String* Exception::Source()
	{
		String* s = &source;
		return s;
	}

	const Exception* const Exception::InnerExcpetion() const
	{
		return innerException;
	}

	String Exception::HelpLink() const
	{
		return link;
	}
}