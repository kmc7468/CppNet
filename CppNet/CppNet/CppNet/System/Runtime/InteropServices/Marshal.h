#ifndef CPPNET_SYSTEM_RUNTIME_INTEROPSERVICES_MARSHAL_H
#define CPPNET_SYSTEM_RUNTIME_INTEROPSERVICES_MARSHAL_H

#include "../../Object.h"

namespace CppNet::System::Runtime::InteropServices
{
	class Marshal : public Object
	{
	public:
		Marshal() = default;
		Marshal(const Marshal&) = delete;
		Marshal(Marshal&&) = delete;
		~Marshal() = default;

	public:
		Marshal& operator=(const Marshal&) = delete;
		Marshal& operator=(Marshal&&) = delete;

	private:

	};
}

#endif