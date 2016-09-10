#ifndef SYSTEM_INVALIDCASTEXCEPTION_H
#define SYSTEM_INVALIDCASTEXCEPTION_H

#include "System.h"

namespace System
{
	class InvalidCastException : public Exception
	{
	public:
		InvalidCastException() = default;
		InvalidCastException(const String& message)
		{
			this->message = message;
		}
		InvalidCastException(const String& message, Exception* innerEx)
		{
			this->message = message;
			innerException = innerEx;
		}
		InvalidCastException(const ExceptionData& data)
		{
			this->message = data.Message();
			this->source = data.Source();
			this->targetsite = data.TargetSite();
			this->link = data.HelpLink();
			this->innerException = data.InnerException();
		}
		InvalidCastException(InvalidCastException &&sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException ¾èÀºº¹»ç
		}
		InvalidCastException(const InvalidCastException& sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException ¾èÀºº¹»ç
		}
		~InvalidCastException() = default;

	public:
		InvalidCastException& operator=(InvalidCastException&& ex)
		{
			return InvalidCastException(ex);
		}

		InvalidCastException& operator=(const InvalidCastException& ex)
		{
			return InvalidCastException(ex);
		}

	public:
		String Message() const override
		{
			String msg = TXT_INVALID_CAST_DEFMSG;
			msg.append(L" ");
			msg.append(message);

			return msg;
		}
	};
}

#endif