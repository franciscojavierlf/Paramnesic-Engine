#pragma once

#include <random>
#include <time.h>
#include <functional>
#include <chrono>

namespace pe
{
	class Random final
	{
	public:
		Random() = delete;

		static int getInteger(int min, int max);
		static float getFloat(float min, float max);

	private:
		static std::mt19937::result_type getSeed();
	};
}