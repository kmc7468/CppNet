#ifndef CPPNET_UNICODE9_0_H
#define CPPNET_UNICODE9_0_H

#include "../Defines.h"

#include "Unicode.h"

namespace CppNet
{
	class Unicode9_0 final : public Unicode
	{
	public:
		Unicode9_0();
		Unicode9_0(Unicode9_0&& u) = default;
		Unicode9_0(const Unicode9_0& u) = default;
		~Unicode9_0();

	public:
		System::Int32 GetDecimalDightValue(const System::Char& c) const override;
		Unicode* Clone() const override;
	};
}

#endif