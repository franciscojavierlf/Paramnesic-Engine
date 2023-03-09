#include "Math.hpp"

inline char pe::Math::abs(const char& n)
{
	if (n < 0) return -n;
	return n;
}

inline short pe::Math::abs(const short& n)
{
	if (n < 0) return -n;
	return n;
}

inline int pe::Math::abs(const int& n)
{
	if (n < 0) return -n;
	return n;
}

inline long pe::Math::abs(const long& n)
{
	if (n < 0) return -n;
	return n;
}

inline long long pe::Math::abs(const long long& n)
{
	if (n < 0) return -n;
	return n;
}

inline float pe::Math::abs(const float& n)
{
	if (n < 0) return -n;
	return n;
}

inline double pe::Math::abs(const double& n)
{
	if (n < 0) return -n;
	return n;
}

inline long double pe::Math::abs(const long double& n)
{
	if (n < 0) return -n;
	return n;
}

int pe::Math::pow(const int& base, const int& power)
{
	if (!power) return 1;
	return base * pow(base, power - 1);
}