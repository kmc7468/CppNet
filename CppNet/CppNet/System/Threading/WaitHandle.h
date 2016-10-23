#ifndef SYSTEM_THREADING_WAITHANDLE_H
#define SYSTEM_THREADING_WAITHANDLE_H

#include "../../Defines.h"

#include "../Object.h"
#include "../IDisposable.h"
#include "../../SystemTypes.h"
#include "../IntPtr.h"

namespace System
{
	namespace Threading
	{
		class WaitHandle : public Object, public IDisposable
		{
		public:
			static const Int32 WaitTimeout;

		private:
			static const Int32 MAX_WAITHANDLES;
			
		public:
			IntPtr waitHandle;
		};
	}
}

#endif