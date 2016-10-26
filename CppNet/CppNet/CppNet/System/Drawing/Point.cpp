#include "Point.h"

namespace CppNet
{
	namespace System
	{
		namespace Drawing
		{
			const Point& Point::Empty = Point(0, 0);

			Point::Point(Int32 x, Int32 y)
			{
				X = x;
				Y = y;
			}

			Boolean Point::IsEmpty() const
			{
				if (X == 0 && Y == 0)
					return true;
				else
					return false;
			}
		}
	}
}