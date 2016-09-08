#ifndef SYSTEM_TIMESPAN_H
#define SYSTEM_TIMESPAN_H

#include "System.h"

namespace System
{
	class TimeSpan : public Object
	{
	public:
		static const Int64 TicksPerDay = 864000000000;
		static const Int64 TicksPerHour = 36000000000;
		static const Int64 TicksPerMillisecond = 10000;
		static const Int64 TicksPerMinute = 600000000;
		static const Int64 TicksPerSecond = 10000000;

	public:
		TimeSpan(Int32 hour, Int32 min, Int32 sec)
			: TimeSpan(0, hour, min, sec, 0)
		{ }

		TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec)
			: TimeSpan(day, hour, min, sec, 0)
		{ }

		TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec, Int32 mill_sec)
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