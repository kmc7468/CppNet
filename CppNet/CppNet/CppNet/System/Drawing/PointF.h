#ifndef SYSTEM_DRAWING_POINTF_H
#define SYSTEM_DRAWING_POINTF_H

#include "../../../Defines.h"

#include "../Single.h"
#include "../Boolean.h"
#include "../Object.h"

namespace CppNet
{
	namespace System
	{
		namespace Drawing
		{
			class PointF : public Object
			{
			public:
				PointF(Single x, Single y);
				PointF(PointF&& pf);
				PointF(const PointF& pf);

			public:
				static const PointF& Empty;

				// TODO Add(s)
				// TODO Subtract(s)

			public:
				Boolean operator==(const Object& obj) const override;

				Boolean operator!=(const Object& obj) const override;

			public:
				String ToString() const override;

			public:
				Single X = 0.0;
				Single Y = 0.0;
				Boolean IsEmpty() const;
			};
		}
	}
}

#endif