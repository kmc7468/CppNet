#ifndef SYSTEM_EXCEPTION_H
#define SYSTEM_EXCEPTION_H

#include "System.h"

namespace System
{
	class Exception : public Object
	{
	public:
		class ExceptionData
		{
		public:
			ExceptionData(const String& message = L"", const String& source = L"", const String& link = L"", void* target = nullptr, Exception* inner = nullptr)
			{
				this->message = message;
				this->source = source;
				this->link = link;
				this->target = target;
				this->inner = inner;
			}
			ExceptionData(ExceptionData &&sNewExceptionData)
			{
				message = sNewExceptionData.message;
				source = sNewExceptionData.source;
				link = sNewExceptionData.link;
				target = sNewExceptionData.target;
				inner = sNewExceptionData.inner;
				// FIXME inner 얕은복사
			}
			ExceptionData(const ExceptionData& sNewExceptionData)
			{
				message = sNewExceptionData.message;
				source = sNewExceptionData.source;
				link = sNewExceptionData.link;
				target = sNewExceptionData.target;
				inner = sNewExceptionData.inner;
				// FIXME inner 얕은복사
			}
			virtual ~ExceptionData() = default;

		public:
			ExceptionData& operator=(const ExceptionData& ex)
			{
				return ExceptionData(ex);
			}
			ExceptionData& operator=(ExceptionData&& ex)
			{
				return ExceptionData(ex);
			}

		private:
			String message;
			String link;
			String source;
			void* target;
			Exception* inner;

		public:
			String Message() const
			{
				return message;
			}
			 
			String HelpLink() const
			{
				return link;
			}

			String Source() const
			{
				return source;
			}

			void* TargetSite() const
			{
				return target;
			}

			Exception* InnerException() const
			{
				return inner;
			}
		};

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
		explicit Exception(const ExceptionData& data)
		{
			this->message = data.Message();
			this->source = data.Source();
			this->targetsite = data.TargetSite();
			this->link = data.HelpLink();
			this->innerException = data.InnerException();
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
			String msg = TXT_EXCEPTION_DEFMSG;
			msg.append(L" ");
			msg.append(message);

			return msg;
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