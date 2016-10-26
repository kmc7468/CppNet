#include "PointF.h"

#include "../../../Utility.h"

namespace CppNet
{
	namespace System
	{
		namespace Drawing
		{
			const PointF& PointF::Empty = PointF(0.0, 0.0);

			PointF::PointF(Single x, Single y)
			{
				X = x;
				Y = y;
			}

			PointF::PointF(PointF&& pf)
			{
				X = std::move(pf.X);
				Y = std::move(pf.Y);
			}

			PointF::PointF(const PointF& pf)
			{
				X = pf.X;
				Y = pf.Y;
			}

			Boolean PointF::operator==(const Object& obj) const
			{
				if (is<const PointF>(obj))
				{
					const PointF& p = dynamic_cast<const PointF&>(obj);

					// FIXME: 저장 방식에 의한 오차 반영 필요
					if (p.X == X && p.Y == Y) return true;
					else return false;
				}
				else
					return false;
			}

			Boolean PointF::operator!=(const Object& obj) const
			{
				if (is<const PointF>(obj))
				{
					const PointF& p = dynamic_cast<const PointF&>(obj);

					// FIXME: 저장 방식에 의한 오차 반영 필요
					if (p.X == X && p.Y == Y) return false;
					else return true;
				}
				else
					return true;
			}

			Boolean PointF::IsEmpty() const
			{
				if (X == 0.0 && Y == 0.0) return true;
				else return false;
			}

			String PointF::ToString() const
			{
				return "X=" + std::to_string(X) + ", Y=" + std::to_string(Y);
			}
		}
	}
}