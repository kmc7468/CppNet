#ifndef SYSTEM_DRAWING_POINT_H
#define SYSTEM_DRAWING_POINT_H

#include "System.h"

namespace System
{
	namespace Drawing
	{
		class Point : public Object
		{
		public:
			Point() = default;
			Point(Int32 x, Int32 y);
			// TODO: Point(Size)
			virtual ~Point() = default;

		public:
			static const Point& Empty;

		public:
			Int32 X = 0;
			Int32 Y = 0;
			Boolean IsEmpty() const;
		};

		const Point& Point::Empty = Point(0, 0);
	}
}

#endif