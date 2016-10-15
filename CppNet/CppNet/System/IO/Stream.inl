#include "Stream.h"
using namespace System;
using namespace System::IO;

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