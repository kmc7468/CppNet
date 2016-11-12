#ifndef CPPNET_SYSTEM_THAREDING_TASKS_HPP
#define CPPNET_SYSTEM_THAREDING_TASKS_HPP

#include "../../IAsyncResult.h"
#include "../../IDisposable.h"
#include "../IThreadPoolWorkItem.hpp"
#include "../../Int32.h"
#include "../../UInt64.h"
#include "../../Boolean.h"

namespace CppNet::System::Threading::Tasks
{
	class Task;

	class StackGuard
	{
		friend class Task;

	private:
		static const Int32 MAX_UNCHECKED_INLINING_DEPTH;
		static Int32 s_pageSize;
		static const Int32 STACK_RESERVED_SPACE;

	private:
		Int32 m_inliningDepth = 0;
		UInt64 m_lastKnownWatermark = 0;

		Boolean TryBeginInliningScope()
		{
			if (m_inliningDepth < MAX_UNCHECKED_INLINING_DEPTH || CheckForSufficientStack())
			{
				++m_inliningDepth;
				return true;
			}
			else
				return false;
		}

		void EndInliningScope()
		{
			--m_inliningDepth;

			if (m_inliningDepth < 0) m_inliningDepth = 0;
		}

		Boolean CheckForSufficientStack()
		{
			// TODO

			return false;
		}
	};

	class Task/* : public IAsyncResult, public IDisposable, public IThreadPoolWorkItem*/
	{
	private:
		static Task* t_currentTask;
		static StackGuard* t_stackGuard;
		static Int32 s_taskIdCounter;
		
	private:
		volatile Int32 m_taskId = 0;
		Object* m_action = nullptr;
		Object* m_stateObject = nullptr;
	};
}

#endif