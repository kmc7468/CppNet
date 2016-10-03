#include "Exception.h"

#include "../Language.h"

namespace System
{
	Exception::ExceptionData::ExceptionData(const String& message, const String& source, const String& link, Exception* inner)
	{
		this->message = message;
		this->source = source;
		this->link = link;
		this->inner = inner;
	}

	Exception::ExceptionData::ExceptionData(Exception::ExceptionData&& sNewExceptionData)
	{
		message = std::move(sNewExceptionData.message);
		source = std::move(sNewExceptionData.source);
		link = std::move(sNewExceptionData.link);
		inner = sNewExceptionData.inner;
		// FIXME inner ¾èÀºº¹»ç
	}

	Exception::ExceptionData::ExceptionData(const Exception::ExceptionData& sNewExceptionData)
	{
		message = sNewExceptionData.message;
		source = sNewExceptionData.source;
		link = sNewExceptionData.link;
		inner = sNewExceptionData.inner;
		// FIXME inner ¾èÀºº¹»ç
	}

	Exception::ExceptionData& Exception::ExceptionData::operator=(const Exception::ExceptionData& ex)
	{
		message = ex.message;
		source = ex.source;
		link = ex.link;
		inner = ex.inner;

		return *this;
	}

	Exception::ExceptionData& Exception::ExceptionData::operator=(Exception::ExceptionData&& ex)
	{
		message = std::move(ex.message);
		source = std::move(ex.source);
		link = std::move(ex.link);
		inner = std::move(ex.inner);

		return *this;
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
		this->link = data.HelpLink();
		this->innerException = data.InnerException();
	}

	Exception::Exception(Exception &&sNewException)
	{
		message = std::move(sNewException.message);
		source = std::move(sNewException.source);
		link = std::move(sNewException.link);
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	Exception::Exception(const Exception& sNewException)
	{
		message = sNewException.message;
		source = sNewException.source;
		link = sNewException.link;
		innerException = sNewException.innerException;
		// FIXME innerException ¾èÀºº¹»ç
	}

	Exception& Exception::operator=(const Exception& ex)
	{
		message = ex.message;
		source = ex.source;
		link = ex.link;
		innerException = ex.innerException;

		return *this;
	}

	Exception& Exception::operator=(Exception&& ex)
	{
		message = std::move(ex.message);
		source = std::move(ex.source);
		link = std::move(ex.link);
		innerException = std::move(ex.innerException);

		return *this;
	}

	String Exception::Message() const
	{
		String msg = TXT_EXCEPTION_DEFMSG;
		msg.append(" ");
		msg.append(message);

		return msg;
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