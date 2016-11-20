#include "UriParser.h"

namespace CppNet::System
{
	Collections::Generic::Dictionary<String, Box<UriParser>>* UriParser::m_Table = nullptr;
	Collections::Generic::Dictionary<String, Box<UriParser>>* UriParser::m_TempTable = nullptr;
	const UriSyntaxFlags UriParser::c_UpdatableFlags = UriSyntaxFlags::UnEscapeDotsAndSlashes;
	const Int32 UriParser::NoDefaultPort = -1;
	const Int32 UriParser::c_InitialTableSize = 25;

	Box<UriParser> UriParser::HttpUri = nullptr;
	Box<UriParser> UriParser::HttpsUri = nullptr;
	Box<UriParser> UriParser::WsUri = nullptr;
	Box<UriParser> UriParser::WssUri = nullptr;
	Box<UriParser> UriParser::FtpUri = nullptr;
	Box<UriParser> UriParser::FileUri = nullptr;
	Box<UriParser> UriParser::GopherUri = nullptr;
	Box<UriParser> UriParser::NntpUri = nullptr;
	Box<UriParser> UriParser::NewsUri = nullptr;
	Box<UriParser> UriParser::MailToUri = nullptr;
	Box<UriParser> UriParser::UuidUri = nullptr;
	Box<UriParser> UriParser::TelentUri = nullptr;
	Box<UriParser> UriParser::LdapUri = nullptr;
	Box<UriParser> UriParser::NetTcpUri = nullptr;
	Box<UriParser> UriParser::NetPipeUri = nullptr;
	Box<UriParser> UriParser::VsMacrosUri = nullptr;

	const UriSyntaxFlags UriParser::UnknownV1SyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::V1_UnknownUri |
		(Int32)UriSyntaxFlags::OptionalAuthority |
			(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveQuery |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowEmptyHost |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::AllowDOSPath |
			(Int32)UriSyntaxFlags::ConvertPathSlashes |
			(Int32)UriSyntaxFlags::CompressPath |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::HttpSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveQuery |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::ConvertPathSlashes |
			(Int32)UriSyntaxFlags::CompressPath |
			(Int32)UriSyntaxFlags::CanonicalizeAsFilePath |
			(UriParser::ShouldUseLegacyV2Quirks()
				? (Int32)UriSyntaxFlags::UnEscapeDotsAndSlashes : (Int32)UriSyntaxFlags::None) |
				(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::FtpSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::ConvertPathSlashes |
			(Int32)UriSyntaxFlags::CompressPath |
			(Int32)UriSyntaxFlags::CanonicalizeAsFilePath |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::FileSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::AllowEmptyHost |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(UriParser::ShouldUseLegacyV2Quirks()
				? (Int32)UriSyntaxFlags::None : (Int32)UriSyntaxFlags::MayHaveQuery) |
				(Int32)UriSyntaxFlags::FileLikeUri |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::AllowDOSPath |
			(Int32)UriSyntaxFlags::ConvertPathSlashes |
			(Int32)UriSyntaxFlags::CompressPath |
			(Int32)UriSyntaxFlags::CanonicalizeAsFilePath |
			(Int32)UriSyntaxFlags::UnEscapeDotsAndSlashes |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::VsmacrosSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::AllowEmptyHost |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::FileLikeUri |
			(Int32)UriSyntaxFlags::AllowDOSPath |
			(Int32)UriSyntaxFlags::ConvertPathSlashes |
			(Int32)UriSyntaxFlags::CompressPath |
			(Int32)UriSyntaxFlags::CanonicalizeAsFilePath |
			(Int32)UriSyntaxFlags::UnEscapeDotsAndSlashes |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::GopherSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::NewsSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MayHavePath |
		(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::NntpSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::TelnetSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::LdapSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::AllowEmptyHost |
			(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveQuery |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::MailtoSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::AllowEmptyHost |
		(Int32)UriSyntaxFlags::AllowUncHost |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::MayHaveUserInfo |
			(Int32)UriSyntaxFlags::MayHavePort |
			(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::MayHaveQuery |
			(Int32)UriSyntaxFlags::MailToLikeUri |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::NetPipeSyntaxFlags =
		(UriSyntaxFlags)((Int32)UriSyntaxFlags::MustHaveAuthority |
		(Int32)UriSyntaxFlags::MayHavePath |
			(Int32)UriSyntaxFlags::MayHaveQuery |
			(Int32)UriSyntaxFlags::MayHaveFragment |
			(Int32)UriSyntaxFlags::AllowAnInternetHost |
			(Int32)UriSyntaxFlags::PathIsRooted |
			(Int32)UriSyntaxFlags::ConvertPathSlashes |
			(Int32)UriSyntaxFlags::CompressPath |
			(Int32)UriSyntaxFlags::CanonicalizeAsFilePath |
			(Int32)UriSyntaxFlags::UnEscapeDotsAndSlashes |
			(Int32)UriSyntaxFlags::AllowIdn |
			(Int32)UriSyntaxFlags::AllowIriParsing);

	const UriSyntaxFlags UriParser::NetTcpSyntaxFlags = (UriSyntaxFlags)((Int32)NetPipeSyntaxFlags | (Int32)UriSyntaxFlags::MayHavePort);

	const UriParser::UriQuirksVersion UriParser::s_QuirksVersion = UriParser::UriQuirksVersion::V3;

	Boolean UriParser::ShouldUseLegacyV2Quirks()
	{
		return s_QuirksVersion <= UriQuirksVersion::V2;
	}

	UriParser::UriParser()
	{
		static bool isFirst = false;

		if (isFirst) return;
		isFirst = true;

		m_Table = new Collections::Generic::Dictionary<String, Box<UriParser>>;
		m_TempTable = new Collections::Generic::Dictionary<String, Box<UriParser>>;

		auto& table = *m_Table;

		HttpUri = new BuiltInUriParser("http", 80, HttpSyntaxFlags);
		table[HttpsUri->m_Scheme] = HttpUri;
		
		HttpsUri = new BuiltInUriParser("https", 443, HttpUri->m_Flags);
		table[HttpsUri->m_Scheme] = HttpsUri;

		WsUri = new BuiltInUriParser("ws", 80, HttpSyntaxFlags);
		table[WsUri->m_Scheme] = WsUri;

		WssUri = new BuiltInUriParser("wss", 443, HttpSyntaxFlags);
		table[WssUri->m_Scheme] = WssUri;

		FtpUri = new BuiltInUriParser("ftp", 21, FtpSyntaxFlags);
		table[FtpUri->m_Scheme] = FtpUri;

		FileUri = new BuiltInUriParser("file", NoDefaultPort, FileSyntaxFlags);
		table[FileUri->m_Scheme] = FileUri;

		GopherUri = new BuiltInUriParser("gopher", 70, GopherSyntaxFlags);
		table[GopherUri->m_Scheme] = GopherUri;

		NntpUri = new BuiltInUriParser("nntp", 119, NntpSyntaxFlags);
		table[NntpUri->m_Scheme] = NntpUri;

		NewsUri = new BuiltInUriParser("news", NoDefaultPort, NewsSyntaxFlags);
		table[NewsUri->m_Scheme] = NewsUri;

		MailToUri = new BuiltInUriParser("mailto", 25, MailtoSyntaxFlags);
		table[MailToUri->m_Scheme] = MailToUri;

		UuidUri = new BuiltInUriParser("uuid", NoDefaultPort, NewsUri->m_Flags);
		table[UuidUri->m_Scheme] = UuidUri;

		TelentUri = new BuiltInUriParser("telent", 23, TelnetSyntaxFlags);
		table[TelentUri->m_Scheme] = TelentUri;
	
		LdapUri = new BuiltInUriParser("ldap", 389, LdapSyntaxFlags);
		table[LdapUri->m_Scheme] = LdapUri;

		NetTcpUri = new BuiltInUriParser("net.tcp", 808, NetTcpSyntaxFlags);
		table[NetTcpUri->m_Scheme] = NetTcpUri;

		NetPipeUri = new BuiltInUriParser("net.pipe", NoDefaultPort, NetPipeSyntaxFlags);
		table[NetPipeUri->m_Scheme] = NetPipeUri;

		VsMacrosUri = new BuiltInUriParser("vsmacros", NoDefaultPort, VsmacrosSyntaxFlags);
		table[VsMacrosUri->m_Scheme] = VsMacrosUri;
	}

	BuiltInUriParser::BuiltInUriParser(const String& lwrCaseScheme, Int32 defaultPort, UriSyntaxFlags flags)
		/*: UriParser(((Int32)flags | (Int32)UriSyntaxFlags::SimpleUserSyntax | (Int32)UriSyntaxFlags::BuiltInSyntax))*/
	{
		m_Scheme = lwrCaseScheme;
		m_Port = defaultPort;
	}
}