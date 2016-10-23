#include "Context.h"
using namespace System;
using namespace System::Runtime::Remoting::Contexts;

const Int32 Context::CTX_DEFAULT_CONTEXT = 1;
const Int32 Context::CTX_FROZEN = 2;
const Int32 Context::CTX_THREADPOOL_AWARE = 4;
const Int32 Context::GROW_BY = 8;
const Int32 Context::STATICS_BUCKET_SIZE = 8;