#include "Task.hpp"

#include "../../../CTR/Mul.hpp"

namespace CppNet::System::Threading::Tasks
{
	const Int32 StackGuard::MAX_UNCHECKED_INLINING_DEPTH = 20;
	Int32 StackGuard::s_pageSize = 0;
	const Int32 StackGuard::STACK_RESERVED_SPACE = CTR::Mul<Int32, 4096, 16>::Value;

	Task* Task::t_currentTask = nullptr;
	StackGuard* Task::t_stackGuard = nullptr;
	Int32 Task::s_taskIdCounter = 0;
}