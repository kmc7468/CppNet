#include "DictionaryEntry.h"
using namespace System;
using namespace System::Collections;

DictionaryEntry::DictionaryEntry(Object& key, Object& value)
	: key(key), value(value)
{ }