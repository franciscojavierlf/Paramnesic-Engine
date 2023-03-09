#pragma once

namespace pe
{
	struct Math final
	{
	public:
		static char abs(const char& n);
		static short abs(const short& n);
		static int abs(const int& n);
		static long abs(const long& n);
		static long long abs(const long long& n);
		static float abs(const float& n);
		static double abs(const double& n);
		static long double abs(const long double& n);
		static int pow(const int& base, const int& power);

	private:
		Math() = delete;
	};
}