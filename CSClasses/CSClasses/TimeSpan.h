#ifndef SYSTEM_TIMESPAN_H
#define SYSTEM_TIMESPAN_H

#include "System.h"

namespace System
{
	class TimeSpan : public Object
	{
	public:
		explicit TimeSpan(Int32 hour, Int32 min, Int32 sec)
		{
			this->hour = hour;
			this->min = min;
			this->sec = sec;
		}

		explicit TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec)
		{
			this->day = day;
			this->hour = hour;
			this->min = min;
			this->sec = sec;
		}

		explicit TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec, Int32 mill_sec)
		{
			this->day = day;
			this->hour = hour;
			this->min = min;
			this->sec = sec;
			this->mill_sec = mill_sec;
		}

		explicit TimeSpan(Int64 ticks)
		{

		}

	private:
		Int32 day = 0;
		Int32 hour = 0;
		Int32 min = 0;
		Int32 sec = 0;
		Int32 mill_sec = 0;

	public:
		// Operators

	public:
		
	};
}

#endif