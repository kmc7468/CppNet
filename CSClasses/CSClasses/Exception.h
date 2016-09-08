#ifndef SYSTEM_EXCEPTION_H
#define SYSTEM_EXCEPTION_H

#include "System.h"

namespace System
{
	class Exception : public Object
	{
	public:
		explicit Exception() = default;
		explicit Exception(const String& message)
		{
			this->message = message;
		}
		explicit Exception(const String& message, Exception* innerEx)
		{
			this->message = message;
			innerException = innerEx;
		}
		Exception(Exception &&sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException 얕은복사
		}
		Exception(const Exception& sNewException)
		{
			message = sNewException.message;
			source = sNewException.source;
			link = sNewException.link;
			targetsite = sNewException.targetsite;
			innerException = sNewException.innerException;
			// FIXME targetsite, innerException 얕은복사
		}
		virtual ~Exception() = default;

	protected:
		String message;
		void* targetsite;
		String source;
		Exception* innerException = nullptr;
		String link;

	public:
		Exception& operator=(const Exception& ex)
		{
			return Exception(ex);
		}
		Exception& operator=(Exception&& ex)
		{
			return Exception(ex);
		}

	public:
		virtual String Message() const
		{
			return message;
		}

		virtual const void* const TargetSite() const
		{
			return targetsite;
		}

		virtual String* Source()
		{
			String* s = &source;
			return s;
		}

		virtual const Exception* const InnerExcpetion()
		{
			return innerException;
		}

		virtual String HelpLink()
		{
			return link;
		}

		// NOTE: 구현하지 않음- StackFrace, HResult
	};
}

#endif