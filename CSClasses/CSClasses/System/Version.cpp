#include "Version.h"
using namespace System;

#include <regex>

Version::Version(Int32 major)
{
	this->major = major;
	minor = 0;
	build = 0;
	revision = 0;
}

Version::Version(Int32 major, Int32 minor)
{
	this->major = major;
	this->minor = minor;
	build = 0;
	revision = 0;
}

Version::Version(Int32 major, Int32 minor, Int32 build)
{
	this->major = major;
	this->minor = minor;
	this->build = build;
	revision = 0;
}

Version::Version(Int32 major, Int32 minor, Int32 build, Int32 revision)
{
	this->major = major;
	this->minor = minor;
	this->build = build;
	this->revision = revision;
}

Version::Version(const String& version)
{
	
}

Version::Version(Version&& ver)
{
	major = ver.major;
	minor = ver.minor;
	build = ver.build;
	revision = ver.revision;
}

Version::Version(const Version& ver)
{
	major = ver.major;
	minor = ver.minor;
	build = ver.build;
	revision = ver.revision;
}

Boolean Version::operator==(const Object& obj)
{
	return Equals(*const_cast<Object*>(&obj));
}

Boolean Version::operator!=(const Object& obj)
{
	return !Equals(*const_cast<Object*>(&obj));
}

Version Version::Parse(const String& input)
{
	std::regex re(".");
	std::sregex_token_iterator first{ input.begin(), input.end(), re, -1 },
		last;
	
	std::vector<std::string> a{ first, last };

	Version v;
	v.major = std::stoi(a[0]);
	v.minor = std::stoi(a[1]);
	v.build = std::stoi(a[2]);
	v.revision = std::stoi(a[3]);

	return v;
}