#ifndef SYSTEM_WINDOWS_FORMS_CONTROL_H
#define SYSTEM_WINDOWS_FORMS_CONTROL_H

#include "../../../Defines.h"

#include "../../Object.h"

#ifdef WIN32

namespace System
{
	namespace Windows
	{
		namespace Forms
		{
			class Control : public Object
			{
			public:
				Control() = default;
				
				virtual ~Control() = default;
			};
		}
	}
}

#endif

#endif