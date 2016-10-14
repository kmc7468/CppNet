#include "Version.h"
using namespace System;

#include "Exception.h"

Object Version::Clone()
{
	return Version(major, minor, build, revision);
}
 
Int32 Version::CompareTo(const Object& obj) const
{
	if (is<const Version&>(obj))
	{
		return CompareTo(as<const Version&>(obj));
	}
	else
		throw Exception("응 인자오류~"); // FIXME Arg 뭐시기 Exception
}

Int32 Version::CompareTo(const Version& obj) const
{
	if (major != obj.major)
		if (major > obj.major)
			return 1;
		else
			return -1;

	if (minor != obj.minor)
		if (minor > obj.minor)
			return 1;
		else
			return -1;

	if (build != obj.build)
		if (build > obj.build)
			return 1;
		else
			return -1;

	if (revision != obj.revision)
		if (revision > obj.revision)
			return 1;
		else
			return -1;

	return 0;
}

Boolean Version::Equals(Object& obj) const
{
	if (is<Version&>(obj))
		return Equals(as<Version&>(obj));
	else return false;
}

Boolean Version::Equals(const Version& obj) const
{
	if (major == obj.major &&
		minor == obj.minor &&
		build == obj.build &&
		revision == obj.revision)
		return true;
	else
		return false;
}