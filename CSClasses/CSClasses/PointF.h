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
			PointF(Single x, Single y)
			{
				X = x;
				Y = y;
			}

		public:
			static const PointF& Empty;

			// TODO Add(s)

		public:
			Boolean Equals(Object& obj) const override
			{
				if (is<Point&>(obj))
				{
					Point& p = dynamic_cast<Point&>(obj);

					// FIXME: 저장 방식에 의한 오차 반영 필요
					if (p.X == X && p.Y == Y) return true;
					else return false;
				}
				else
					return false;
			}

		public:
			Single X = 0.0;
			Single Y = 0.0;
			Boolean IsEmpty()
			{
				if (X == 0.0 && Y == 0.0) return true;
				else return false;
			}
		};

		const PointF& PointF::Empty = PointF(0.0, 0.0);
	}
}

#endif