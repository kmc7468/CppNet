#include "UriParser.h"

namespace CppNet::System
{
	const Collections::Generic::Dictionary<String, std::unique_ptr<UriParser>>* UriParser::m_Table = nullptr;
	Collections::Generic::Dictionary<String, std::unique_ptr<UriParser>>* UriParser::m_TempTable = nullptr;
}