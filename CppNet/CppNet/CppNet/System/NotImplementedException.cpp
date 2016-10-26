#include "NotImplementedException.h"

#include "../../Language.h"

namespace CppNet
{
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
			this->link = data.HelpLink();
			this->innerException = data.InnerException();
		}

		NotImplementedException::NotImplementedException(NotImplementedException &&sNewException)
		{
			message = std::move(sNewException.message);
			source = std::move(sNewException.source);
			link = std::move(sNewException.link);
			innerException = sNewException.innerException;
			// FIXME innerException ¾èÀº º¹»ç
		}

		NotImplementedException::NotImplementedException(const NotImplementedException& sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			innerException = sNewException.innerException;
			// FIXME innerException ¾èÀº º¹»ç
		}

		NotImplementedException &NotImplementedException::operator=(NotImplementedException&& ex)
		{
			message = std::move(ex.message);
			source = std::move(ex.source);
			link = std::move(ex.link);
			innerException = std::move(ex.innerException);

			return *this;
		}

		NotImplementedException &NotImplementedException::operator=(const NotImplementedException& ex)
		{
			message = ex.message;
			source = ex.source;
			link = ex.link;
			innerException = ex.innerException;

			return *this;
		}

		String NotImplementedException::Message() const
		{
			String msg = TXT_NOTIMPL_DEFMSG;
			if (message != "")
			{
				msg.append(" ");
				msg.append(message);
			}

			return msg;
		}
	}
}