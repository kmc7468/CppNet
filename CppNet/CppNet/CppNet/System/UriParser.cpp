#include "UriParser.h"

namespace CppNet::System
{
	const Collections::Generic::Dictionary<String, Box<UriParser>>* UriParser::m_Table = nullptr;
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
}