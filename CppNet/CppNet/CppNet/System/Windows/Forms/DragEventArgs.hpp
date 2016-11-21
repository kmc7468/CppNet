#ifndef CPPNET_SYSTEM_WINDOWS_FORMS_DRAGEVENTARGS_HPP
#define CPPNET_SYSTEM_WINDOWS_FORMS_DRAGEVENTARGS_HPP

#include "../../EventArgs.h"
#include "../../Int32.h"

namespace CppNet::System::Windows::Forms
{
	class DragEventArgs : public EventArgs
	{
	private:
		const IDataObject* data;
		const Int32 keyState;
		const Int32 x;
		const Int32 y;
		// TODO
	};
}

#endif