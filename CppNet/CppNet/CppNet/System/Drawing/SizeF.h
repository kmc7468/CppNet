#ifndef SYSTEM_DRAWING_SIZEF_H
#define SYSTEM_DRAWING_SIZEF_H

#include "../../../Defines.h"

#include "../Object.h"
#include "PointF.h"
#include "../Single.h"

namespace CppNet
{
	namespace System
	{
		namespace Drawing
		{
			class SizeF : public Object
			{
			public:
				SizeF(const PointF& pf);
				SizeF(Single w, Single h);
				SizeF(SizeF&& sf);
				SizeF(const SizeF& sf);
				~SizeF() = default;

			public:
				inline Boolean operator==(const Object& obj) const override;
				inline Boolean operator!=(const Object& obj) const override;

				inline SizeF operator+(const SizeF& sf) const;
				inline SizeF& operator+=(const SizeF& sf);
				inline SizeF operator-(const SizeF& sf) const;
				inline SizeF& operator-=(const SizeF& sf);

				inline operator PointF() const;

			public:
				static const SizeF& Empty;

				inline static SizeF Add(const SizeF& a, const SizeF& b);
				inline static SizeF Subtract(const SizeF& a, const SizeF& b);

			public:
				Single Width = 0.0;
				Single Height = 0.0;
				Boolean IsEmpty() const;

			public:
				inline PointF ToPointF() const;
				// TODO ToSize

				inline String ToString() const override;
				Boolean Equals(Object& obj) const override;
			};
		}
	}
}

#include "SizeF.inl"

#endif