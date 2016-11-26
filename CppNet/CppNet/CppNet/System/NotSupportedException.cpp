#include "NotSupportedException.h"

#include "../../Defines.h"
#include "../../Language.h"

namespace CppNet::System
{
	NotSupportedException::NotSupportedException()
		: SystemException()
	{}

	NotSupportedException::NotSupportedException(const String& message)
		: SystemException(message)
	{}

	NotSupportedException::NotSupportedException(const String& message, Exception* innerException)
		: SystemException(message, innerException)
	{}

	String NotSupportedException::Message() const
	{
		String msg = TXT_NOTSUPPORT_DEFMSG;
		if (message != "")
		{
			msg += " " + message;
		}

		return msg;
	}
}