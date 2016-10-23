#ifndef SYSTEM_IO_IOEXCEPTION_H
#define SYSTEM_IO_IOEXCEPTION_H

#include "../../Defines.h"

#include "../Exception.h"
#include "../SystemException.h"

namespace System
{
	namespace IO
	{
		class IOException : public SystemException
		{
		public:
			IOException() = default;
			IOException(const String& message);
			IOException(const String& message, Exception* innerException);
			IOException(const Exception::ExceptionData& data);
			IOException(const IOException& ex);
			IOException(IOException&& ex);
			~IOException() = default;

		public:
			IOException& operator=(const IOException& io);
			IOException& operator=(IOException&& io);

		public:
			String Message() const override;
		};
	}
}

#endif