#include "AccessViolationException.h"

#include "../../Defines.h"
#include "../../Language.h"

namespace CppNet::System
{
	AccessViolationException::AccessViolationException()
		: SystemException()
	{ }

	AccessViolationException::AccessViolationException(const String& message)
		: SystemException(message)
	{ }

	AccessViolationException::AccessViolationException(const String& message, Exception* innerException)
		: SystemException(message, innerException)
	{ }

	String AccessViolationException::Message() const
	{
		String msg = TXT_INVALID_ACCESS_DEFMSG;
		if (message != "")
		{
			msg += " " + message;
		}

		return msg;
	}
}