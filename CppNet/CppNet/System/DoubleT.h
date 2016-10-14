#ifndef SYSTEM_DOUBLET_H
#define SYSTEM_DOUBLET_H

#include "../Defines.h"

#include "Object.h"
#include "Double.h"
#include "Char.h"

#include "IFormattable.h"
#include "IConvertible.h"
#include "IEquatable.h"

namespace System
{
	class DoubleT : public Object, public IComparable<Object>, public IComparable<DoubleT>, public IFormattable, public IConvertible, public IEquatable<DoubleT>
	{	
	private:
		Double dat;

	public:
		DoubleT() = default;
		DoubleT(Double dat);
		DoubleT(DoubleT&& sNewDoubleT);
		DoubleT(const DoubleT& sNewDoubleT);
		~DoubleT() = default;

	public:
		static const DoubleT MinValue;
		static const DoubleT MaxValue;

		static const DoubleT Epsilon;
		static const DoubleT NegativeInfinity;
		static const DoubleT PositiveInfinity;
		static const DoubleT NaN;

		static const DoubleT Zero;

		static const DoubleT NegativeZero;

	public:
		inline DoubleT& operator=(DoubleT&& d) const;
		inline DoubleT& operator=(const DoubleT& d) const;
		
		inline Boolean operator==(const Object& obj) const override;
		inline Boolean operator!=(const Object& obj) const override;

		inline operator Double();

	public:
		inline Int32 CompareTo(const Object& obj) const override;
		inline Int32 CompareTo(const DoubleT& obj) const override;
		inline String ToString(String format, std::unique_ptr<IFormatProvider> formatProvider) override;
		inline Boolean ToBoolean(std::unique_ptr<IFormatProvider> i) override;
		inline Byte ToByte(std::unique_ptr<IFormatProvider> i) override;
		inline Char ToChar(std::unique_ptr<IFormatProvider> i) override;
		inline DateTime ToDateTime(std::unique_ptr<IFormatProvider> i) override;
		inline Double ToDouble(std::unique_ptr<IFormatProvider> i) override;
		inline Int16 ToInt16(std::unique_ptr<IFormatProvider> i) override;
		inline Int32 ToInt32(std::unique_ptr<IFormatProvider> i) override;
		inline Int64 ToInt64(std::unique_ptr<IFormatProvider> i) override;
		inline UInt16 ToUInt16(std::unique_ptr<IFormatProvider> i) override;
		inline UInt32 ToUInt32(std::unique_ptr<IFormatProvider> i) override;
		inline UInt64 ToUInt64(std::unique_ptr<IFormatProvider> i) override;
		inline SByte ToSByte(std::unique_ptr<IFormatProvider> i) override;
		inline Single ToSingle(std::unique_ptr<IFormatProvider> i) override;
		inline String ToString(std::unique_ptr<IFormatProvider> i) override;
		inline Boolean Equals(const DoubleT& obj) const override;
		inline String ToString() const override;

	public:
		static inline Boolean IsInfinity(const DoubleT& d);
		static inline Boolean IsPositiveInfinity(const DoubleT& d);
		static inline Boolean IsNegativeInfinity(const DoubleT& d);
		static inline Boolean IsNaN(const DoubleT& d);
		static inline Boolean IsNegative(const DoubleT& d);
	
	public:
		inline Double Data() const;
	};
}

#include "DoubleT.inl"

#endif