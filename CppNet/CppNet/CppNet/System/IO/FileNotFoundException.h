#ifndef SYSTEM_IO_FILENOTFOUNDEXCEPTION_H
#define SYSTEM_IO_FILENOTFOUNDEXCEPTION_H

#include "../../../Defines.h"

#include "IOException.h"

#include "../String.h"

namespace CppNet
{
	namespace System
	{
		namespace IO
		{
			class FileNotFoundException : public IOException
			{
			public:
				FileNotFoundException() = default;
				FileNotFoundException(const String& message);
				FileNotFoundException(const String& message, Exception* innerException);
				FileNotFoundException(const Exception::ExceptionData& data);
				FileNotFoundException(const FileNotFoundException& ex);
				FileNotFoundException(FileNotFoundException&& ex);
				~FileNotFoundException() = default;

			public:
				FileNotFoundException& operator=(const FileNotFoundException& ex);
				FileNotFoundException& operator=(FileNotFoundException&& ex);

			public:
				String Message() const override;
			};
		}
	}
}

#endif