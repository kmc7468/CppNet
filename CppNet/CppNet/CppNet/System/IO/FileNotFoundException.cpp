#include "FileNotFoundException.h"
#include "../../../Language.h"

namespace CppNet::System::IO
{
	FileNotFoundException::FileNotFoundException(const String& message)
		: IOException(message)
	{ }

	FileNotFoundException::FileNotFoundException(const String& message, Exception* innerException)
		: IOException(message, innerException)
	{ }

	FileNotFoundException::FileNotFoundException(const Exception::ExceptionData& data)
		: IOException(data)
	{ }

	FileNotFoundException::FileNotFoundException(const FileNotFoundException& ex)
		: IOException(ex)
	{ }

	FileNotFoundException::FileNotFoundException(FileNotFoundException&& ex)
		: IOException(ex)
	{ }

	FileNotFoundException& FileNotFoundException::operator=(const FileNotFoundException& ex)
	{
		IOException::operator=(ex);

		return *this;
	}

	FileNotFoundException& FileNotFoundException::operator=(FileNotFoundException&& ex)
	{
		IOException::operator=(ex);

		return *this;
	}

	String FileNotFoundException::Message() const
	{
		String msg = TXT_IO_FILE404;
		if (message != "")
		{
			msg.append(" ");
			msg.append(message);
		}

		return msg;
	}
}