#ifndef SYSTEM_IO_FILE_H
#define SYSTEM_IO_FILE_H

#include "../../Defines.h"

#include "../Object.h"
#include "../String.h"
#include "../Boolean.h"

namespace System
{
	namespace IO
	{
		class File final : public Object
		{
		public:
			File() = default;
			File(File&& f) = delete;
			File(const File& f) = delete;
			~File() = default;

		public:
			File& operator=(const File& f) = delete;
			File& operator=(File&& f) = delete;

		public:
			// TODO

			inline static void Copy(const String& source, const String& to);
			static void Copy(const String& source, const String& to, Boolean overwrite);

			// TODO

			static void Delete(const String& source);

			// TODO

			static Boolean Exists(const String& source);

			// TODO

			static void Move(const String& source, const String& to);
		};
	}
}

#include "File.inl"

#endif