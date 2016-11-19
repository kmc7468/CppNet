#include "Stream.h"
#include "../InvalidOperationException.h"

namespace CppNet::System::IO
{
	Boolean Stream::CanTimeout() const
	{
		return false;
	}

	Int32 Stream::GetReadTimeout() const
	{
		throw InvalidOperationException();
	}

	void Stream::SetReadTimeout(Int32 value)
	{
		throw InvalidOperationException();
	}

	Int32 Stream::GetWriteTimeout() const
	{
		throw InvalidOperationException();
	}

	void Stream::SetWriteTimeout(Int32 value)
	{
		throw InvalidOperationException();
	}

	void Stream::Close()
	{
		Dispose(true);
	}

	void Stream::Dispose()
	{
		Close();
	}

	void Stream::Dispose(Boolean disposing)
	{

	}
}