#include "Random.h"

namespace CppNet
{
	namespace System
	{
		Random::Random(RandomType type)
		{
			this->type = type;
			seed = std::random_device()();
		}

		Random::Random(RandomType type, UInt32 seed)
		{
			this->type = type;
			this->seed = seed;
		}

		Random::Random(Random &&sNewRandom)
		{
			type = sNewRandom.type;
			seed = sNewRandom.seed;
		}

		Random::Random(const Random &sNewRandom)
		{
			type = sNewRandom.type;
			seed = sNewRandom.seed;
		}

		Random Random::operator=(Random &&sNewRandom)
		{
			return Random(*this);
		}

		Random Random::operator=(const Random &sNewRandom)
		{
			return Random(*this);
		}

		Int64 Random::Next() const
		{
			switch (this->type)
			{
			case RandomType::MT19937:
			{
				std::mt19937 mt(seed);
				return mt();
			}
			case RandomType::MT19937_64:
			{
				std::mt19937_64 mt(seed);
				return mt();
			}
			default:
			{
				std::random_device rd;
				return rd();
			}
			}
		}

		Int64 Random::Next(const Int64& max) const
		{
			switch (this->type)
			{
			case RandomType::MT19937:
			{
				std::mt19937 mt(seed);
				std::uniform_int_distribution<Int64> u(max);
				return u(mt);
			}
			case RandomType::MT19937_64:
			{
				std::mt19937_64 mt(seed);
				std::uniform_int_distribution<Int64> u(max);
				return u(mt);
			}
			default:
			{
				std::random_device rd;
				std::uniform_int_distribution<Int64> u(max);
				return u(rd);
			}
			}
		}

		Int32 Random::Next(const Int32& max) const
		{
			switch (this->type)
			{
			case RandomType::MT19937:
			{
				std::mt19937 mt(seed);
				std::uniform_int_distribution<Int32> u(max);
				return u(mt);
			}
			case RandomType::MT19937_64:
			{
				std::mt19937_64 mt(seed);
				std::uniform_int_distribution<Int32> u(max);
				return u(mt);
			}
			default:
			{
				std::random_device rd;
				std::uniform_int_distribution<Int32> u(max);
				return u(rd);
			}
			}
		}

		Int64 Random::Next(const Int64& min, const Int64& max) const
		{
			switch (this->type)
			{
			case RandomType::MT19937:
			{
				std::mt19937 mt(seed);
				std::uniform_int_distribution<Int64> u(min, max);
				return u(mt);
			}
			case RandomType::MT19937_64:
			{
				std::mt19937_64 mt(seed);
				std::uniform_int_distribution<Int64> u(min, max);
				return u(mt);
			}
			default:
			{
				std::random_device rd;
				std::uniform_int_distribution<Int64> u(min, max);
				return u(rd);
			}
			}
		}

		Int32 Random::Next(const Int32& min, const Int32& max) const
		{
			switch (this->type)
			{
			case RandomType::MT19937:
			{
				std::mt19937 mt(seed);
				std::uniform_int_distribution<Int32> u(min, max);
				return u(mt);
			}
			case RandomType::MT19937_64:
			{
				std::mt19937_64 mt(seed);
				std::uniform_int_distribution<Int32> u(min, max);
				return u(mt);
			}
			default:
			{
				std::random_device rd;
				std::uniform_int_distribution<Int32> u(min, max);
				return u(rd);
			}
			}
		}

		Double Random::NextDouble() const
		{
			switch (this->type)
			{
			case RandomType::MT19937:
			{
				std::mt19937 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			case RandomType::MT19937_64:
			{
				std::mt19937_64 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			default:
			{
				std::random_device rd;
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(rd);
			}
			}
		}

		Double Random::Sample() const
		{
			switch (this->type)
			{
			case RandomType::MT19937:
			{
				std::mt19937 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			case RandomType::MT19937_64:
			{
				std::mt19937_64 mt(seed);
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(mt);
			}
			default:
			{
				std::random_device rd;
				std::uniform_real_distribution<Double> u(0.0, 1.0);
				return u(rd);
			}
			}
		}
	}
}