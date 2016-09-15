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
		// TODO DoubleToInt64Bits

		static inline std::array<Byte, 1> GetBytes(Boolean boolean, Boolean igroneEndian = false);
		static inline std::array<Byte, 2> GetBytes(Char c, Boolean igroneEndian = false);
		static inline std::array<Byte, 2> GetBytes(Int16 i, Boolean igroneEndian = false);
	};
}

#include "BitConverter.inl"

#endif