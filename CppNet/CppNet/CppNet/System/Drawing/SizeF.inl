#include "SizeF.h"
using namespace CppNet::System::Drawing;
using namespace CppNet::System;

#include "../../../Utility.h"

SizeF SizeF::Add(const SizeF& a, const SizeF& b)
{
	return SizeF(a.Width + b.Width, a.Height + b.Height);
}

SizeF SizeF::Subtract(const SizeF& a, const SizeF& b)
{
	return SizeF(a.Width - b.Width, a.Height - b.Height);
}

PointF SizeF::ToPointF() const
{
	return PointF(Width, Height);
}

String SizeF::ToString() const
{
	return "{Width=" + std::to_string(Width) + ", Height=" + std::to_string(Height) + "}";
}

Boolean SizeF::operator==(const Object& obj) const
{
	return Equals(dcst(obj, Object));
}

Boolean SizeF::operator!=(const Object& obj) const
{
	return !Equals(dcst(obj, Object));
}

SizeF SizeF::operator+(const SizeF& sf) const
{
	return Add(*this, sf);
}

SizeF& SizeF::operator+=(const SizeF& sf)
{
	Width += sf.Width;
	Height += sf.Height;

	return *this;
}

SizeF SizeF::operator-(const SizeF& sf) const
{
	return Subtract(*this, sf);
}

SizeF& SizeF::operator-=(const SizeF& sf)
{
	Width -= sf.Width;
	Height -= sf.Height;

	return *this;
}

SizeF::operator PointF() const
{
	return PointF(Width, Height);
}