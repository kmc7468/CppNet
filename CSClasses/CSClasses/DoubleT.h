#ifndef SYSTEM_DOUBLET_H
#define SYSTEM_DOUBLET_H

#include "Object.h"
#include "Double.h"

namespace System
{
	class DoubleT : public Object
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
		inline DoubleT& operator=(DoubleT&& d) const;
		inline DoubleT& operator=(const DoubleT& d) const;
		
		inline Boolean operator==(const Object& obj) const override;
		inline Boolean operator!=(const Object& obj) const override;

		inline operator Double();

	public:
		static inline Boolean IsNaN(Double d);
	
	public:
		inline Double Data() const;
	};
}

#include "DoubleT.inl"

#endif