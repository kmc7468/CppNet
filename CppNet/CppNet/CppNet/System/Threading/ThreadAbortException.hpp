#ifndef CPPNET_SYSTEM_THREADING_THREADABORTEXCEPTION_HPP
#define CPPNET_SYSTEM_THREADING_THREADABORTEXCEPTION_HPP

#include "../../../Defines.h"
#include "../../../Language.h"

#include "../SystemException.h"

namespace CppNet::System::Threading
{
	class ThreadAbortException final : public SystemException
	{
	public:
		ThreadAbortException() = default;
		ThreadAbortException(const String& message)
			: SystemException(message)
		{}

		ThreadAbortException(const String& message, Exception* innerEx)
			: SystemException(message, innerEx)
		{}

		ThreadAbortException(const ExceptionData& data)
			: SystemException(data)
		{}

		ThreadAbortException(ThreadAbortException &&e)
		{
			message = std::move(e.message);
			source = std::move(e.source);
			link = std::move(e.link);
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		ThreadAbortException(const ThreadAbortException& e)
		{
			message = e.message;
			source = e.source;
			link = e.link;
			innerException = e.innerException;
			// FIXME innerException ¾èÀºº¹»ç
		}

		~ThreadAbortException() = default;

	public:
		ThreadAbortException& operator=(ThreadAbortException&& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

		ThreadAbortException& operator=(const ThreadAbortException& ex)
		{
			Exception::operator=(ex);

			return *this;
		}

	public:
		String Message() const override
		{
			String msg = TXT_THREAD_ABORT_DEFMSG;
			if (message != "")
			{
				msg.append(" ");
				msg.append(message);
			}

			return msg;
		}
	};
}

#endif