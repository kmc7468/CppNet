#ifndef CPPNET_SYSTEM_URIPARSER_H
#define CPPNET_SYSTEM_URIPARSER_H

#include "../../Defines.h"
#include "../../Utility.h"

#include "Object.h"
#include "String.h"

#include "Collections/Generic/Dictionary.h"

#include <memory>

namespace CppNet::System
{
	enum class UriSyntaxFlags
	{
		None = 0x0,

		MustHaveAuthority = 0x1,
		OptionalAuthority = 0x2,
		MayHaveUserInfo = 0x4,
		MayHavePort = 0x8,
		MayHavePath = 0x10,
		MayHaveQuery = 0x20,
		MayHaveFragment = 0x40,
		AllowEmptyHost = 0x80,
		AllowUncHost = 0x100,
		AllowDnsHost = 0x200,
		AllowIPv4Host = 0x400,
		AllowIPv6Host = 0x800,
		AllowAnInternetHost = AllowDnsHost | AllowIPv4Host | AllowIPv6Host,
		AllowAnyOtherHost = 0x1000,
		FileLikeUri = 0x2000,
		MailToLikeUri = 0x4000,
		V1_UnknownUri = 0x10000,
		SimpleUserSyntax = 0x20000,
		BuiltInSyntax = 0x40000,
		ParserSchemeOnly = 0x80000,
		AllowDOSPath = 0x100000,
		PathIsRooted = 0x200000,
		ConvertPathSlashes = 0x400000,
		CompressPath = 0x800000,
		CanonicalizeAsFilePath = 0x1000000,
		UnEscapeDotsAndSlashes = 0x2000000,
		AllowIdn = 0x4000000,
		AllowIriParsing = 0x10000000,
	};

	class UriParser : public Object
	{
		ABSTRACT_CLASS

	private:
		static const Collections::Generic::Dictionary<String, std::unique_ptr<UriParser>>* m_Table;
		static Collections::Generic::Dictionary<String, std::unique_ptr<UriParser>>* m_TempTable;

	private:
		UriSyntaxFlags m_Flags;
	};
}

#endif