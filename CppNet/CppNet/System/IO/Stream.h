#ifndef SYSTEM_IO_STREAM_H
#define SYSTEM_IO_STREAM_H

#include "../Object.h"
#include "../IDisposable.h"

namespace System
{
	namespace IO
	{
		class Stream : public Object, public IDisposable
		{
		public:
			virtual ~Stream() = default;

		public:
			virtual Boolean CanRead() const = 0;
			virtual Boolean CanSeek() const = 0;
			inline virtual Boolean CanTimeout() const;
			virtual Boolean CanWrite() const = 0;
			virtual Int64 Length() const = 0;
			virtual Int64 GetPosition() const = 0;
			virtual void SetPosition(Int64 pos) = 0;
			inline virtual Int32 GetReadTimeout() const;
			inline virtual void SetReadTimeout(Int32 value);
		};
	}
}

#include "Stream.inl"

#endif