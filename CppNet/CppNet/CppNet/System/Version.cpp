#include "Version.h"

#include <string>
#include <vector>

namespace CppNet::System
{
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
		var a = Parse(version);

		major = a.major;
		minor = a.minor;
		build = a.build;
		revision = a.revision;
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

	Boolean Version::operator==(const Object& obj) const
	{
		return Equals(*const_cast<const Object*>(&obj));
	}

	Boolean Version::operator!=(const Object& obj) const
	{
		return !Equals(*const_cast<const Object*>(&obj));
	}

	Version Version::Parse(const String& input)
	{
		std::vector<String> a;

		size_t i = 0;
		size_t pos = input.find('.');
		while (pos != String::npos)
		{
			a.push_back(input.substr(i, pos - i));
			i = ++pos;
			pos = input.find('.', pos);

			if (pos == String::npos)
				a.push_back(input.substr(i, input.length()));
		}

		Version v;
		v.major = std::stoi(a[0]);
		v.minor = std::stoi(a[1]);
		v.build = std::stoi(a[2]);
		v.revision = std::stoi(a[3]);

		return v;
	}
}