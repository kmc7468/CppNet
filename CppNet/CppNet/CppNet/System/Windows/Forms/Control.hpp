#ifndef CPPNET_SYSTEM_WINDOWS_FORMS_CONTROL_HPP
#define CPPNET_SYSTEM_WINDOWS_FORMS_CONTROL_HPP

#include "../../../../Defines.h"

#include "../../Object.h"
#include "../../ComponentModel/Component.h"

#include "IDropTarget.hpp"

namespace CppNet::System::Windows::Forms
{
	class Control : public ComponentModel::Component, public IDropTarget
	{

	};
}

#endif