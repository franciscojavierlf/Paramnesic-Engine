#include "Color.hpp"

pe::Color::Color() : pe::Color(0, 0, 0)
{

}

pe::Color::Color(const pe::String& hex)
{
	unsigned int h = hex.toUnsignedHexadecimal();

	m_r = (h) & 0xFF;
	m_g = (h >> 8) & 0xFF;
	m_b = (h >> 16) & 0xFF;
	m_a = (h >> 24) && 0xFF;
}

pe::Color::Color(const unsigned char& r, const unsigned char& g, const unsigned char& b) : pe::Color(r, g, b, 0)
{

}

pe::Color::Color(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a) :
	m_r(r), m_g(g), m_b(b), m_a(a)
{

}

pe::Color::~Color()
{

}