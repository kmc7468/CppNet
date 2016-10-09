#include "File.h"
using namespace System;
using namespace System::IO;

#include <fstream>

void File::Copy(const String& source, const String& to)
{
	// TODO 오류처리

	if (!Exists(source))
	{

	}

	std::ifstream srce(source, std::ios::binary);
	std::ofstream dest(to, std::ios::binary);
	
	if (srce.is_open() && dest.is_open())
	{
		dest << srce.rdbuf();

		srce.close();
		dest.close();
	}
	else
	{
		// TODO 열지 못했을 경우 오류처리
	}
}

Boolean File::Exists(const String& source)
{
	if (FILE* f = fopen(source.c_str(), "r"))
	{
		fclose(f);
		return true;
	}
	return false;
}