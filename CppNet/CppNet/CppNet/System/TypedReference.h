#ifndef CPPNET_SYSTEM_TYPEDREFERENCE_H
#define CPPNET_SYSTEM_TYPEDREFERENCE_H

#include "Object.h"
#include "IntPtr.h"

namespace CppNet::System
{
	class TypedReference final : public Object
	{
	private:
		IntPtr Value;
		IntPtr Type;

	public:
		Boolean Equals(const Object& obj) const override;

		// TODO
	};
}

#endif