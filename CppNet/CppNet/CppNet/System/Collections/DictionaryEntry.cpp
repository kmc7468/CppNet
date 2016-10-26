#include "DictionaryEntry.h"
using namespace CppNet::System;
using namespace CppNet::System::Collections;

DictionaryEntry::DictionaryEntry(Object& key, Object& value)
	: key(key), value(value)
{ }