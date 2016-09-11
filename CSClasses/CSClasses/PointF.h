#ifndef SYSTEM_DRAWING_POINTF_H
#define SYSTEM_DRAWING_POINTF_H

#include "System.h"

namespace System
{
	namespace Drawing
	{
		class PointF : public Object
		{
		public:
			PointF(Single x, Single y);

		public:
			static const PointF& Empty;

			// TODO Add(s)

		public:
			Boolean operator==(const Object& obj) override;

			Boolean operator!=(const Object& obj) override;

		public:
			Single X = 0.0;
			Single Y = 0.0;
			Boolean IsEmpty() const;
		};
	}
}

#endif