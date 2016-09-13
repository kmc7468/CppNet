#ifndef SYSTEM_ICONVERTIBLE_H
#define SYSTEM_ICONVERTIBLE_H

#include "SystemTypes.h"

#include "DateTime.h"
#include "IFormatProvider.h"
#include "Utility.h"

namespace System
{
	interface IConvertible : public Object
	{
		IConvertible() = delete;
		IConvertible(IConvertible&& i) = delete;
		IConvertible(const IConvertible& i) = delete;
		virtual ~IConvertible() = default;

		virtual Boolean ToBoolean(IFormatProvider i);
		virtual Byte ToByte(IFormatProvider i);
		virtual Char ToChar(IFormatProvider i);
		virtual DateTime ToDateTime(IFormatProvider i);
		virtual Double ToDouble(IFormatProvider i);
		virtual Int16 ToInt16(IFormatProvider i);
		virtual Int32 ToInt32(IFormatProvider i);
		virtual Int64 ToInt64(IFormatProvider i);
		virtual UInt16 ToUInt16(IFormatProvider i);
		virtual UInt32 ToUInt32(IFormatProvider i);
		virtual UInt64 ToUInt64(IFormatProvider i);
		virtual SByte ToSByte(IFormatProvider i);
		virtual Single ToSingle(IFormatProvider i);
		virtual String ToString(IFormatProvider i);
	};
}

#include "IConvertible.inl"

#endif