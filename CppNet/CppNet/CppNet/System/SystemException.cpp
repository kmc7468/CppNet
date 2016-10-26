#include "SystemException.h"
using namespace CppNet::System;

SystemException::SystemException(const String& message)
	: Exception(message)
{ }

SystemException::SystemException(const String& message, Exception* innerException)
	: Exception(message, innerException)
{ }

SystemException::SystemException(const Exception::ExceptionData& exd)
	: Exception(exd)
{ }

SystemException::SystemException(const SystemException& ex)
	: Exception(ex)
{ }

SystemException::SystemException(SystemException&& ex)
	: Exception(ex)
{ }

SystemException& SystemException::operator=(const SystemException& ex)
{
	Exception::operator=(ex);

	return *this;
}

SystemException& SystemException::operator=(SystemException&& ex)
{
	Exception::operator=(ex);

	return *this;
}