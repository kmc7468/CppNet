#ifndef SYSTEM_ICONVERTIBLE_H
#define SYSTEM_ICONVERTIBLE_H

#include "SystemTypes.h"

#include "DateTime.h"
#include "IFormatProvider.h"
#include "Utility.h"

namespace System
{
	interface IConvertible
	{
		virtual Boolean ToBoolean(IFormatProvider i) = 0;
		virtual Byte ToByte(IFormatProvider i) = 0;
		virtual Char ToChar(IFormatProvider i) = 0;
		virtual DateTime ToDateTime(IFormatProvider i) = 0;
		virtual Double ToDouble(IFormatProvider i) = 0;
		virtual Int16 ToInt16(IFormatProvider i) = 0;
		virtual Int32 ToInt32(IFormatProvider i) = 0;
		virtual Int64 ToInt64(IFormatProvider i) = 0;
		virtual UInt16 ToUInt16(IFormatProvider i) = 0;
		virtual UInt32 ToUInt32(IFormatProvider i) = 0;
		virtual UInt64 ToUInt64(IFormatProvider i) = 0;
		virtual SByte ToSByte(IFormatProvider i) = 0;
		virtual Single ToSingle(IFormatProvider i) = 0;
		virtual String ToString(IFormatProvider i) = 0;
	};
}

#endif