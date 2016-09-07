#ifndef SYSTEM_RANDOM_H
#define SYSTEM_RANDOM_H

#include "System.h"
#include <random>

namespace System
{
	enum class RandomType
	{
		MT19937,
		MT19937_64,
		WELL512,
		RANDOM_DEVICE,
	};

	class Random : public Object
	{
	public:
		Random(RandomType type = RandomType::MT19937)
		{
			this->type = type;
			seed = std::random_device()();
		}
		Random(RandomType type, int seed)
		{
			this->type = type;
			this->seed = seed;
		}
		Random(Random &&sNewRandom)
		{
			type = sNewRandom.type;
			seed = sNewRandom.seed;
		}
		Random(const Random &sNewRandom)
		{
			type = sNewRandom.type;
			seed = sNewRandom.seed;
		}
		~Random() = default;

	public:
		Random &operator=(Random &&sNewRandom)
		{
			return Random(*this);
		}
		Random &operator=(const Random &sNewRandom)
		{
			return Random(*this);
		}

	private:
		Int32 seed;
		RandomType type;

	public:
		inline Int32 Next() const
		{
			if (type == RandomType::MT19937)
			{
				std::mt19937 mt(seed);
				return mt();
			}
			else if (type == RandomType::MT19937_64)
			{
				std::mt19937_64 mt(seed);
				return mt();
			}
			else if (type == RandomType::WELL512)
			{

			}
			else if (type == RandomType::RANDOM_DEVICE)
			{
				std::random_device rd;
				return rd();
			}
		}

		inline Int32 Next(Int32 max) const
		{
			if (type == RandomType::MT19937)
			{
				std::mt19937 mt(seed);
				std::uniform_int_distribution<Int32> u(max);
				return u(mt);
			}
			else if (type == RandomType::MT19937_64)
			{
				std::mt19937_64 mt(seed);
				std::uniform_int_distribution<Int32> u(max);
				return u(mt);
			}
			else if (type == RandomType::WELL512)
			{

			}
			else if (type == RandomType::RANDOM_DEVICE)
			{
				std::random_device rd;
				std::uniform_int_distribution<Int32> u(max);
				return u(rd);
			}
		}

		inline Int32 Next(Int32 min, Int32 max) const
		{
			if (type == RandomType::MT19937)
			{
				std::mt19937 mt(seed);
				std::uniform_int_distribution<Int32> u(min, max);
				return u(mt);
			}
			else if (type == RandomType::MT19937_64)
			{
				std::mt19937_64 mt(seed);
				std::uniform_int_distribution<Int32> u(min, max);
				return u(mt);
			}
			else if (type == RandomType::WELL512)
			{

			}
			else if (type == RandomType::RANDOM_DEVICE)
			{
				std::random_device rd;
				std::uniform_int_distribution<Int32> u(min, max);
				return u(rd);
			}
		}

		// TODO NextBytes

		inline Double NextDouble() const
		{
			if (type == RandomType::MT19937)
			{
				std::mt19937 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			else if (type == RandomType::MT19937_64)
			{
				std::mt19937_64 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			else if (type == RandomType::WELL512)
			{

			}
			else if (type == RandomType::RANDOM_DEVICE)
			{
				std::random_device rd;
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(rd);
			}
		}

		inline Double Sample() const
		{
			if (type == RandomType::MT19937)
			{
				std::mt19937 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			else if (type == RandomType::MT19937_64)
			{
				std::mt19937_64 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			else if (type == RandomType::WELL512)
			{

			}
			else if (type == RandomType::RANDOM_DEVICE)
			{
				std::random_device rd;
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(rd);
			}
		}
	};
}

#endif