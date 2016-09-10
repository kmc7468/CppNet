#ifndef SYSTEM_FORMATEXCEPTION_H
#define SYSTEM_FORMATEXCEPTION_H

#include "System.h"

namespace System
{
	class FormatException : public Exception
	{
	public:
		explicit FormatException() = default;
		explicit FormatException(const String& message)
		{
			this->message = message;
		}
		FormatException(const String& message, Exception* innerEx)
		{
			this->message = message;
			innerException = innerEx;
		}
		explicit FormatException(const ExceptionData& data)
		{
			this->message = data.Message();
			this->source = data.Source();
			this->targetsite = data.TargetSite();
			this->link = data.HelpLink();
			this->innerException = data.InnerException();
		}
		FormatException(FormatException &&sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException ¾èÀºº¹»ç
		}
		FormatException(const FormatException& sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException ¾èÀºº¹»ç
		}
		~FormatException() = default;

	public:
		FormatException& operator=(FormatException&& ex)
		{
			return FormatException(ex);
		}

		FormatException& operator=(const FormatException& ex)
		{
			return FormatException(ex);
		}

	public:
		String Message() const override
		{
			String msg = TXT_FORMAT_DEFMSG;
			msg.append(L" ");
			msg.append(message);

			return msg;
		}
	};
}

#endif