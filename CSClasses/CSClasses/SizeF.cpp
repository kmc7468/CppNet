#include "SizeF.h"

namespace System
{
	namespace Drawing
	{
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
			Width = sf.Width;
			Height = sf.Height;
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
	}
}