#ifndef SYSTEM_BITCONVERTER_H
#define SYSTEM_BITCONVERTER_H

#include "SystemTypes.h"

#include <array>

namespace System
{
	class BitConverter final : public Object
	{
	public:
		BitConverter() = default;
		BitConverter(BitConverter&& sNewBitConverter) = delete;
		BitConverter(const BitConverter& sNewBitConverter) = delete;
		~BitConverter() = default;

	public:
		BitConverter &operator=(BitConverter &&sNewBitConverter) = delete;
		BitConverter &operator=(const BitConverter &sNewBitConverter) = delete;

	public:
		static const Boolean IsLittleEndian;

	public:
		static inline Int64 DoubleToInt64Bits(Double d, Boolean igroneEndian = true);

		static inline std::array<Byte, 1> GetBytes(Boolean boolean, Boolean igroneEndian = false);
		static inline std::array<Byte, 2> GetBytes(Char c, Boolean igroneEndian = false);
		static inline std::array<Byte, 2> GetBytes(Int16 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 8> GetBytes(Double d, Boolean igroneEndian = false);
		static inline std::array<Byte, 4> GetBytes(Int32 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 8> GetBytes(Int64 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 4> GetBytes(Single d, Boolean igroneEndian = false);
		static inline std::array<Byte, 2> GetBytes(UInt16 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 4> GetBytes(UInt32 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 8> GetBytes(UInt64 i, Boolean igroneEndian = false);

	private:
		template<Int32 size, typename T>
		static inline std::array<Byte, size> GetBytesLitile(T t);

		template<Int32 size, typename T>
		static inline std::array<Byte, size> GetBytesBig(T t);

		static inline Int64 DTI64L(Double d);
	};
}

#include "BitConverter.inl"

#endif