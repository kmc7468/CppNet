#include "TimeSpan.h"

namespace System
{
	const Int64 TimeSpan::TicksPerDay = 864000000000;
	const Int64 TimeSpan::TicksPerHour = 36000000000;
	const Int64 TimeSpan::TicksPerMillisecond = 10000;
	const Int64 TimeSpan::TicksPerMinute = 600000000;
	const Int64 TimeSpan::TicksPerSecond = 10000000;

	TimeSpan::TimeSpan(Int32 hour, Int32 min, Int32 sec)
		: TimeSpan(0, hour, min, sec, 0)
	{ }

	TimeSpan::TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec)
		: TimeSpan(day, hour, min, sec, 0)
	{ }

	TimeSpan::TimeSpan(Int32 day, Int32 hour, Int32 min, Int32 sec, Int32 mill_sec)
	{
		this->day = day;
		this->hour = hour;
		this->min = min;
		this->sec = sec;
		this->mill_sec = mill_sec;

		// FIXME: https://msdn.microsoft.com/ko-kr/library/system.timespan.duration(v=vs.110).aspx
		//       의 예제를 참고하면 음수값인 경우 양수로 들어온 시간에 그 만큼 빼줘야 합니다.
	}

	TimeSpan::TimeSpan(Int64 ticks)
	{
		// TODO
	}

	Int32 TimeSpan::Compare(const TimeSpan& t1, const TimeSpan& t2)
	{
		if (t1.day < t2.day)
			return -1;
		else if (t1.day > t2.day)
			return 1;

		if (t1.hour < t2.hour)
			return -1;
		else if (t1.hour > t2.hour)
			return 1;

		if (t1.min < t2.min)
			return -1;
		else if (t1.min > t2.min)
			return 1;

		if (t1.sec < t2.sec)
			return -1;
		else if (t1.sec > t2.sec)
			return 1;

		if (t1.mill_sec < t2.mill_sec)
			return -1;
		else if (t1.mill_sec > t2.mill_sec)
			return 1;

		return 0;
	}

	Boolean TimeSpan::Equals(const TimeSpan& t1, const TimeSpan& t2)
	{
		return (Compare(t1, t2) == 0);
	}

	TimeSpan TimeSpan::FromDays(Double value)
	{
		return TimeSpan(static_cast<Int64>(value * TicksPerDay));
	}

	TimeSpan TimeSpan::FromHours(Double value)
	{
		return TimeSpan(static_cast<Int64>(value * TicksPerHour));
	}

	TimeSpan TimeSpan::FromMilliseconds(Double value)
	{
		return TimeSpan(static_cast<Int64>(value * TicksPerMillisecond));
	}

	TimeSpan TimeSpan::FromMinutes(Double value)
	{
		return TimeSpan(static_cast<Int64>(value * TicksPerMinute));
	}

	TimeSpan TimeSpan::FromSeconds(Double value)
	{
		return TimeSpan(static_cast<Int64>(value * TicksPerSecond));
	}

	TimeSpan TimeSpan::FromTicks(Int64 value)
	{
		return TimeSpan(value);
	}

	Int32 TimeSpan::CompareTo(const TimeSpan& value)
	{
		return Compare(*this, value);
	}

	TimeSpan TimeSpan::Duration()
	{
		// FIXME: 음수 시간을 어떻게 표현할지 불분명하므로 아래 코드는 임시 조치임.
		return TimeSpan(std::abs(day), std::abs(hour), std::abs(min), std::abs(sec), std::abs(mill_sec));
	}

	TimeSpan TimeSpan::Negate()
	{
		// FIXME: 음수 시간을 어떻게 표현할지 불분명하므로 아래 코드는 임시 조치임.
		return TimeSpan(-day, hour, min, sec, mill_sec);
	}

	Boolean TimeSpan::operator==(const TimeSpan& t)
	{
		return (CompareTo(t) == 0);
	}

	Boolean TimeSpan::operator!=(const TimeSpan& t)
	{
		return (CompareTo(t) != 0);
	}

	Boolean TimeSpan::operator<(const TimeSpan& t)
	{
		return (CompareTo(t) < 0);
	}

	Boolean TimeSpan::operator>(const TimeSpan& t)
	{
		return (CompareTo(t) > 0);
	}

	Boolean TimeSpan::operator<=(const TimeSpan& t)
	{
		return (CompareTo(t) <= 0);
	}

	Boolean TimeSpan::operator>=(const TimeSpan& t)
	{
		return (CompareTo(t) >= 0);
	}
}