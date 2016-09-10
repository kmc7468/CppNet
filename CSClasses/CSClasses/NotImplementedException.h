#ifndef SYSTEM_NOTIMPLEMENTEDEXCEPTION_H
#define SYSTEM_NOTIMPLEMENTEDEXCEPTION_H

#include "System.h"

namespace System
{
	class NotImplementedException : public Exception
	{
	public:
		NotImplementedException() = default;
		NotImplementedException(const String& message)
		{
			this->message = message;
		}
		NotImplementedException(const String& message, Exception* innerEx)
		{
			this->message = message;
			innerException = innerEx;
		}
		NotImplementedException(const ExceptionData& data)
		{
			this->message = data.Message();
			this->source = data.Source();
			this->targetsite = data.TargetSite();
			this->link = data.HelpLink();
			this->innerException = data.InnerException();
		}
		NotImplementedException(NotImplementedException &&sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException ¾èÀºº¹»ç
		}
		NotImplementedException(const NotImplementedException& sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException ¾èÀºº¹»ç
		}
		~NotImplementedException() = default;

	public:
		NotImplementedException& operator=(NotImplementedException&& ex)
		{
			return NotImplementedException(ex);
		}

		NotImplementedException& operator=(const NotImplementedException& ex)
		{
			return NotImplementedException(ex);
		}

	public:
		String Message() const override
		{
			String msg = TXT_NOTIMPL_DEFMSG;
			msg.append(L" ");
			msg.append(message);

			return msg;
		}
	};
}

#endif