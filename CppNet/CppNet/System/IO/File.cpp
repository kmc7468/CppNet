#include "File.h"

#include "FileNotFoundException.h"
using namespace System;
using namespace System::IO;

#include "../../Language.h"

#include <fstream>

void File::Copy(const String& source, const String& to, Boolean overwrite)
{
	// TODO 坷幅贸府

	if (!overwrite && Exists(to))
	{
		throw IOException(TXT_IO_FILEALREADY);
	}

	if (!Exists(source))
	{
		throw FileNotFoundException();
	}

	std::ifstream srce(source, std::ios::binary);
	std::ofstream dest(to, std::ios::binary);

	if (srce.is_open() && dest.is_open())
	{
		dest.clear();

		dest << srce.rdbuf();

		srce.close();
		dest.close();
	}
	else
	{
		throw IOException();
	}
}

void File::Delete(const String& source)
{
	// TODO 坷幅贸府

	if (!Exists(source))
	{
		throw FileNotFoundException();
	}

	if (remove(source.c_str()) == -1)
	{
		throw IOException();
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

void File::Move(const String& source, const String& to)
{
	// TODO 坷幅贸府

	if (!Exists(to))
	{
		throw FileNotFoundException();
	}

	if (rename(source.c_str(), to.c_str()) == -1)
	{
		throw IOException();
	}
}