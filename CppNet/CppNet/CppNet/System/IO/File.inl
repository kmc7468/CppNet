#include "File.h"
using namespace CppNet::System;
using namespace CppNet::System::IO;

void File::Copy(const String& source, const String& to)
{
	File::Copy(source, to, false);
}