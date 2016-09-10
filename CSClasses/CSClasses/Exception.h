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
			ExceptionData(const String& message = L"", const String& source = L"", const String& link = L"", void* target = nullptr, Exception* inner = nullptr);
			ExceptionData(ExceptionData &&sNewExceptionData);
			ExceptionData(const ExceptionData& sNewExceptionData);
			virtual ~ExceptionData() = default;

		public:
			ExceptionData& operator=(const ExceptionData& ex);
			ExceptionData& operator=(ExceptionData&& ex);

		private:
			String message;
			String link;
			String source;
			void* target;
			Exception* inner;

		public:
			String Message() const;
			String HelpLink() const;
			String Source() const;
			void* TargetSite() const;
			Exception* InnerException() const;
		};

	public:
		Exception() = default;
		Exception(const String& message);
		Exception(const String& message, Exception* innerEx);
		Exception(const ExceptionData& data);
		Exception(Exception &&sNewException);
		Exception(const Exception& sNewException);
		virtual ~Exception() = default;

	protected:
		String message;
		void* targetsite;
		String source;
		Exception* innerException = nullptr;
		String link;

	public:
		Exception& operator=(const Exception& ex);
		Exception& operator=(Exception&& ex);

	public:
		virtual String Message() const;
		virtual const void* const TargetSite() const;
		virtual String* Source();
		virtual const Exception* const InnerExcpetion() const;
		virtual String HelpLink() const;

		// NOTE: 구현하지 않음- StackFrace, HResult
	};
}

#endif