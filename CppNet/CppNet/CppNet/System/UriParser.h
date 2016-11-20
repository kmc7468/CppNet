#ifndef CPPNET_SYSTEM_URIPARSER_H
#define CPPNET_SYSTEM_URIPARSER_H

#include "../../Defines.h"
#include "../../Utility.h"

#include "Object.h"
#include "String.h"
#include "Boolean.h"
#include "Int32.h"

#include "../Box.hpp"
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

	class BuiltInUriParser;

	class UriParser : public Object
	{
		ABSTRACT_CLASS
		friend class BuiltInUriParser;

	private:
		static Collections::Generic::Dictionary<String, Box<UriParser>>* m_Table;
		static Collections::Generic::Dictionary<String, Box<UriParser>>* m_TempTable;
		static const UriSyntaxFlags c_UpdatableFlags;

	private:
		UriSyntaxFlags m_Flags;
		volatile UriSyntaxFlags m_UpdatableFlags;
		volatile Boolean m_UpdatableFlagsUsed;
		Int32 m_Port = 0;
		String m_Scheme;

	_internal:
		static const Int32 NoDefaultPort;

	private:
		static const Int32 c_InitialTableSize;

	_internal:
		static Box<UriParser> HttpUri;
		static Box<UriParser> HttpsUri;
		static Box<UriParser> WsUri;
		static Box<UriParser> WssUri;
		static Box<UriParser> FtpUri;
		static Box<UriParser> FileUri;
		static Box<UriParser> GopherUri;
		static Box<UriParser> NntpUri;
		static Box<UriParser> NewsUri;
		static Box<UriParser> MailToUri;
		static Box<UriParser> UuidUri;
		static Box<UriParser> TelentUri;
		static Box<UriParser> LdapUri;
		static Box<UriParser> NetTcpUri;
		static Box<UriParser> NetPipeUri;
		static Box<UriParser> VsMacrosUri;

		static const UriSyntaxFlags UnknownV1SyntaxFlags;
		static const UriSyntaxFlags HttpSyntaxFlags;
		static const UriSyntaxFlags FtpSyntaxFlags;
		static const UriSyntaxFlags FileSyntaxFlags;
		static const UriSyntaxFlags VsmacrosSyntaxFlags;
		static const UriSyntaxFlags GopherSyntaxFlags;
		static const UriSyntaxFlags NewsSyntaxFlags;
		static const UriSyntaxFlags NntpSyntaxFlags;
		static const UriSyntaxFlags TelnetSyntaxFlags;
		static const UriSyntaxFlags LdapSyntaxFlags;
		static const UriSyntaxFlags MailtoSyntaxFlags;
		static const UriSyntaxFlags NetPipeSyntaxFlags;
		static const UriSyntaxFlags NetTcpSyntaxFlags;

	private:
		enum class UriQuirksVersion
		{
			V2 = 2,
			V3 = 3,
		};

		static const UriQuirksVersion s_QuirksVersion;

	_internal:
		static Boolean ShouldUseLegacyV2Quirks();

		UriParser();
		UriParser(UriSyntaxFlags flags);

		inline UriSyntaxFlags Flags() const;
		inline Boolean NotAny(UriSyntaxFlags flags) const;
		inline Boolean IsFact(UriSyntaxFlags flags) const;
		inline Boolean IsAllSet(UriSyntaxFlags flags) const;

	private:
		Boolean IsFullMatch(UriSyntaxFlags flags, UriSyntaxFlags expected) const;

		// TODO
	};

	class BuiltInUriParser : public UriParser
	{
		UN_ABSTRACT_CLASS
		friend class UriParser;

	_internal:
		BuiltInUriParser(const String& lwrCaseScheme, Int32 defaultPort, UriSyntaxFlags flags);
	};
}

#endif