#include "UriParser.h"

namespace CppNet::System
{
	const Collections::Generic::Dictionary<String, Box<UriParser>>* UriParser::m_Table = nullptr;
	Collections::Generic::Dictionary<String, Box<UriParser>>* UriParser::m_TempTable = nullptr;
	const UriSyntaxFlags UriParser::c_UpdatableFlags = UriSyntaxFlags::UnEscapeDotsAndSlashes;
	const Int32 UriParser::NoDefaultPort = -1;
	const Int32 UriParser::c_InitialTableSize = 25;
}