#include "IOException.h"
using namespace CppNet::System;
using namespace CppNet::System::IO;

#include "../../../Language.h"

IOException::IOException(const String& message)
	: SystemException(message)
{ }

IOException::IOException(const String& message, Exception* innerException)
	: SystemException(message, innerException)
{ }

IOException::IOException(const Exception::ExceptionData& data)
	: SystemException(data)
{ }

IOException::IOException(const IOException& ex)
	: SystemException(ex)
{ }

IOException::IOException(IOException&& ex)
	: SystemException(ex)
{ }

IOException& IOException::operator=(const IOException& io)
{
	SystemException::operator=(io);

	return *this;
}

IOException& IOException::operator=(IOException&& io)
{
	SystemException::operator=(io);

	return *this;
}

String IOException::Message() const
{
	String msg = TXT_IO_DEFMSG;
	if (message != "")
	{
		msg.append(" ");
		msg.append(message);
	}

	return msg;
}