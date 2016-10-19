#include "DictionaryEntry.h"
using namespace System;
using namespace System::Collections;

const Object& DictionaryEntry::Key() const
{
	return key;
}

Object& DictionaryEntry::Key()
{
	return key;
}

const Object& DictionaryEntry::Value() const
{
	return value;
}

Object& DictionaryEntry::Value()
{
	return value;
}