#include "File.h"
using namespace System;
using namespace System::IO;

void File::Copy(const String& source, const String& to)
{
	File::Copy(source, to, false);
}