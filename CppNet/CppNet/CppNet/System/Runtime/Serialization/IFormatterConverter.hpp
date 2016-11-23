#ifndef CPPNET_SYSTEM_RUNTIME_SERIALIZATION_IFORMATTERCONVERTER_HPP
#define CPPNET_SYSTEM_RUNTIME_SERIALIZATION_IFORMATTERCONVERTER_HPP

#include "../../../../Defines.h"
#include "../../../../Utility.h"

#include <type_traits>

#include "../../Object.h"
#include "../../Char.h"
#include "../../DateTime.h"
#include "../../../../SystemTypes.h"

namespace CppNet::System
{
	class Char;
	class DateTime;
}

namespace CppNet::System::Runtime::Serialization
{
	interface IFormatterConverter
	{
		virtual Object* Convert(Object& value, Type& type) = 0;
		virtual Boolean ToBoolean(Object& value) = 0;
		virtual Char ToChar(Object& value) = 0;
		virtual SByte ToSByte(Object& value) = 0;
		virtual Byte ToByte(Object& value) = 0;
		virtual Int16  ToInt16(Object& value) = 0;
		virtual UInt16 ToUInt16(Object& value) = 0;
		virtual Int32 ToInt32(Object& value) = 0;
		virtual UInt32 ToUInt32(Object& value) = 0;
		virtual Int64 ToInt64(Object& value) = 0;
		virtual UInt64 ToUInt64(Object& value) = 0;
		virtual Single ToSingle(Object& value) = 0;
		virtual Double ToDouble(Object& value) = 0;
		virtual DateTime ToDateTime(Object& value) = 0;
		virtual String ToString(Object& value) = 0;
	};
}

#endif