#include "gc.h"
using namespace CppNet;

std::vector<void*> gc::allocs = std::vector<void*>();
std::vector<size_t> gc::refcounts = std::vector<size_t>();