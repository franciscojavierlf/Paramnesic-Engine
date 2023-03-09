#pragma once

#include "PE/Utils/String.hpp"

namespace pe
{
	class Color final
	{
	public:
		Color();
		Color(const pe::String& hex);
		Color(const unsigned char& r,const unsigned char& g, const unsigned char& b);
		Color(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a);
		~Color();

	private:
		union
		{
			struct
			{
				unsigned char m_r;
				unsigned char m_g;
				unsigned char m_b;
				unsigned char m_a;
			};

			unsigned int hex;
		};
	};
}