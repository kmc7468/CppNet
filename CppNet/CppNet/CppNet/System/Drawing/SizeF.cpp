#include "SizeF.h"

#include "../../../Utility.h"

namespace CppNet
{
	namespace System
	{
		namespace Drawing
		{
			const SizeF& SizeF::Empty = SizeF(0.0, 0.0);

			SizeF::SizeF(const PointF& pf)
			{
				Width = pf.X;
				Height = pf.Y;
			}

			SizeF::SizeF(Single w, Single h)
			{
				Width = w;
				Height = h;
			}

			SizeF::SizeF(SizeF&& sf)
			{
				Width = std::move(sf.Width);
				Height = std::move(sf.Height);
			}

			SizeF::SizeF(const SizeF& sf)
			{
				Width = sf.Width;
				Height = sf.Height;
			}

			Boolean SizeF::IsEmpty() const
			{
				return (Width == 0.0 && Height == 0.0);
			}

			Boolean SizeF::Equals(Object& obj) const
			{
				if (_is(obj, SizeF))
				{
					auto a = _as(obj, SizeF&);

					if (Width == a.Width && Height == a.Height)
						return true;
				}

				return false;
			}
		}
	}
}