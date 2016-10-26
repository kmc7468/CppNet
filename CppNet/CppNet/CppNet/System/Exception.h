#ifndef SYSTEM_EXCEPTION_H
#define SYSTEM_EXCEPTION_H

#include "../../Defines.h"

#include "String.h"
#include "Object.h"

namespace CppNet
{
	namespace System
	{
		class Exception : public Object, private std::exception
		{
		public:
			class ExceptionData
			{
			public:
				ExceptionData(const String& message = "", const String& source = "", const String& link = "", Exception* inner = nullptr);
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
			String source;
			Exception* innerException = nullptr;
			String link;

		public:
			Exception& operator=(const Exception& ex);
			Exception& operator=(Exception&& ex);

		public:
			virtual String Message() const;
			virtual String* Source();
			virtual const Exception* const InnerExcpetion() const;
			virtual String HelpLink() const;

			// NOTE: 구현하지 않음- StackFrace, HResult
		};
	}
}

#endif