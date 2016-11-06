#ifndef CPPNET_SYSTEM_GLOBALIZATION_ENCODINGTABLE_HPP
#define CPPNET_SYSTEM_GLOBALIZATION_ENCODINGTABLE_HPP

#include "../../../Defines.h"

#include "../Object.h"

namespace CppNet::System::Text
{
	class Encoding;
}

#include "../Text/Encoding.h"
#include "../Collections/Hashtable.h"

namespace CppNet::System::Globalization
{
	class EncodingTable final : public Object
	{
		friend class Text::Encoding;

	public:
		EncodingTable() = default;
		EncodingTable(const EncodingTable&) = delete;
		EncodingTable(EncodingTable&&) = delete;
		~EncodingTable() = default;

	public:
		EncodingTable& operator=(const EncodingTable&) = delete;
		EncodingTable& operator=(EncodingTable&&) = delete;

	private:
		static Int32 lastEncodingItem;
		static volatile Int32 lastCodePageItem;
	};

	
}

#endif