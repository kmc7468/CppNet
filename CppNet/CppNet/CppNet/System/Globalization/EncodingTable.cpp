#include "EncodingTable.hpp"

namespace CppNet::System::Globalization
{
	Int32 EncodingTable::lastEncodingItem = 0; // FIXME
	volatile Int32 EncodingTable::lastCodePageItem = 0;
}