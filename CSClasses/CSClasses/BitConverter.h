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
		static inline Int64 DoubleToInt64Bits(Double d);
		static inline Double Int64BitsToDouble(Int64 i);

		static inline Int32 SingleToInt32Bits(Single d);
		static inline Single Int32BitsToSingle(Int32 i);

		static inline std::array<Byte, 1> GetBytes(Boolean boolean, Boolean igroneEndian = false);
		static inline std::array<Byte, 4> GetBytes(Char c, Boolean igroneEndian = false);
		static inline std::array<Byte, 2> GetBytes(Int16 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 8> GetBytes(Double d, Boolean igroneEndian = false);
		static inline std::array<Byte, 4> GetBytes(Int32 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 8> GetBytes(Int64 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 4> GetBytes(Single d, Boolean igroneEndian = false);
		static inline std::array<Byte, 2> GetBytes(UInt16 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 4> GetBytes(UInt32 i, Boolean igroneEndian = false);
		static inline std::array<Byte, 8> GetBytes(UInt64 i, Boolean igroneEndian = false);

		static inline Char ToChar(std::array<Byte, 4> arr, Boolean igroneEndian = false);
		static inline Int16 ToInt16(std::array<Byte, 2> arr, Boolean igroneEndian = false);
		static inline Int32 ToInt32(std::array<Byte, 4> arr, Boolean igroneEndian = false);
		static inline Int64 ToInt64(std::array<Byte, 8> arr, Boolean igroneEndian = false);
		static inline UInt16 ToUInt16(std::array<Byte, 2> arr, Boolean igroneEndian = false);
		static inline UInt32 ToUInt32(std::array<Byte, 4> arr, Boolean igroneEndian = false);
		static inline UInt64 ToUInt64(std::array<Byte, 8> arr, Boolean igroneEndian = false);
		static inline Single ToSingle(std::array<Byte, 4> arr, Boolean igroneEndian = false);
		static inline Double ToDouble(std::array<Byte, 8> arr, Boolean igroneEndian = false);

		// TODO ToString

	private:
		template<Int32 size, typename T>
		static inline std::array<Byte, size> GetBytesLitile(T t);

		template<Int32 size, typename T>
		static inline std::array<Byte, size> GetBytesBig(T t);
	};
}

#include "BitConverter.inl"

#endif