#ifndef SYSTEM_EXCEPTION_H
#define SYSTEM_EXCEPTION_H

#include "System.h"

namespace System
{
	class Exception
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
		}
		Exception(const Exception& sNewException)
		{
			message = sNewException.message;
		}
		virtual ~Exception() = default;

	protected:
		String message;
		void* targetsite;
		String source;
		Exception* innerException = nullptr;
		String link;

	public:
		// Operators

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