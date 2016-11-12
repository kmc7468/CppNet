#ifndef CPPNET_SYSTEM_THREADING_TASKS_TASKSCHEDULER_HPP
#define CPPNET_SYSTEM_THREADING_TASKS_TASKSCHEDULER_HPP

#include "../../../../Defines.h"
#include "../../../../Utility.h"

#include "../../Object.h"
#include "../../Collections/Generic/IEnumerable.h"

#include "Task.hpp"

namespace CppNet::System::Threading::Tasks
{
	class TaskScheduler : public Object
	{
	protected:
		virtual void QueueTask(const Task& task) const = 0;
		virtual Boolean TryExecuteTaskInline(const Task& task, Boolean taskWasPreviouslyQueued) const = 0;
		virtual Collections::Generic::IEnumerable<const Task&> GetScheduledTasks() const = 0;

	public:
		virtual Int32 MaximumConcurrencyLevel() const
		{
			return _MaxValue(Int32);
		}

	_internal:
		Boolean TryRunInline(const Task& task, Boolean taskWasPreviouslyQueued) const
		{
			// TODO

			Boolean bInlined = false;

			try
			{
				// TODO
			}
			catch (...)
			{
			}

			// TODO

			return bInlined;
		}

	protected:
		virtual Boolean TryDequeue(const Task& task) const
		{
			return false;
		}

		virtual void NotifyWorkItemProgress() const
		{

		}

	_internal:
		virtual Boolean RequiresAtomicStartTransition() const
		{
			return true;
		}

		void InternalQueueTask(const Task& task) const
		{
			// TODO

			this->QueueTask(task);
		}

	private:

	};
}

#endif