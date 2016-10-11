#ifndef CPPNET_KMC_INTEGER_H
#define CPPNET_KMC_INTEGER_H

#include "../../Defines.h"

#include "../../System/Object.h"
#include "../../System/Byte.h"
#include "../../System/Int64.h"

using namespace std;
using namespace System;

namespace CppNet
{
	namespace KMC
	{
		class Integer final : public Object
		{
		private:
			Byte* data = nullptr;
			size_t len = 0;
			/* len의 자료형을 조정하면 더 넓은 범위를 표현할 수 있습니다.
			조정하게 될 경우 반드시 unsigned로 해주세요. signed로 설정시 unsigned의 절반 정도만큼만
			표현할 수 있게 됩니다.
			Byte=2^255만큼의 수 처리 가능
			UInt16=2^65535만큼의 수 처리 가능
			UInt32=2^(2^32-1)만큼의 수 처리 가능
			UInt64=2^(2^64-1)만큼의 수 처리 가능*/

		public:
			Integer();
			Integer(Int64 i);
			Integer(const Integer& i);
			Integer(Integer&& i);
			~Integer();

		private:
			void resize(size_t newsize);

		public:
			Integer operator+(const Integer& i) const;
			Integer& operator+=(const Integer& i);

		public:
			String ToString() const override;
		};
	}
}

#endif