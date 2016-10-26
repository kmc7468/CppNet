#ifndef SYSTEM_ICONVERTIBLE_H
#define SYSTEM_ICONVERTIBLE_H

#include "../../Defines.h"

#include "../../SystemTypes.h"

#include "DateTime.h"
#include "IFormatProvider.h"
#include "../../Utility.h"

#include <memory>

#include "Char.h"

namespace CppNet
{
	namespace System
	{
		class Char;

		interface IConvertible
		{
			virtual Boolean ToBoolean(std::unique_ptr<IFormatProvider> i) = 0;
			virtual Byte ToByte(std::unique_ptr<IFormatProvider> i) = 0;
			virtual Char ToChar(std::unique_ptr<IFormatProvider> i) = 0;
			virtual DateTime ToDateTime(std::unique_ptr<IFormatProvider> i) = 0;
			virtual Double ToDouble(std::unique_ptr<IFormatProvider> i) = 0;
			virtual Int16 ToInt16(std::unique_ptr<IFormatProvider> i) = 0;
			virtual Int32 ToInt32(std::unique_ptr<IFormatProvider> i) = 0;
			virtual Int64 ToInt64(std::unique_ptr<IFormatProvider> i) = 0;
			virtual UInt16 ToUInt16(std::unique_ptr<IFormatProvider> i) = 0;
			virtual UInt32 ToUInt32(std::unique_ptr<IFormatProvider> i) = 0;
			virtual UInt64 ToUInt64(std::unique_ptr<IFormatProvider> i) = 0;
			virtual SByte ToSByte(std::unique_ptr<IFormatProvider> i) = 0;
			virtual Single ToSingle(std::unique_ptr<IFormatProvider> i) = 0;
			virtual String ToString(std::unique_ptr<IFormatProvider> i) = 0;
		};
	}
}

#endif