#include "Random.hpp"

int pe::Random::getInteger(int min, int max)
{
	if (max < min)
	{
		int aux = min;
		min = max;
		max = aux;
	}

	return std::bind(std::uniform_int_distribution<int>
		(min, max), std::mt19937(Random::getSeed()))();
}

float pe::Random::getFloat(float min, float max)
{
	if (max < min)
	{
		float aux = min;
		min = max;
		max = aux;
	}

	return std::bind(std::uniform_real_distribution<float>
		(min, max), std::mt19937(Random::getSeed()))();
}

std::mt19937::result_type pe::Random::getSeed()
{
	return unsigned int((std::chrono::high_resolution_clock::now().time_since_epoch()).count());
}