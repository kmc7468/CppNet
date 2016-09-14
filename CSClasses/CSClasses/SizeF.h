#ifndef SYSTEM_DRAWING_SIZEF_H
#define SYSTEM_DRAWING_SIZEF_H

#include "Object.h"
#include "PointF.h"
#include "Single.h"

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
			Single Width = 0.0;
			Single Height = 0.0;
			Boolean IsEmpty() const;
		};
	}
}

#endif