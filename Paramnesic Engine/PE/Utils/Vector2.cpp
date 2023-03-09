#include "Vector2.hpp"

pe::Vector2::Vector2(const float& x, const float& y) : x(x), y(y)
{
}

pe::Vector2::Vector2() : Vector2(0, 0)
{
}

pe::Vector2::~Vector2()
{

}

pe::Vector2 pe::Vector2::operator+(const Vector2& other) const
{
	return pe::Vector2(this->x + other.x, this->y + other.y);
}

pe::Vector2 pe::Vector2::operator-(const Vector2& other) const
{
	return pe::Vector2(this->x - other.x, this->y - other.y);
}

pe::Vector2 pe::Vector2::operator*(const float& scalar) const
{
	return pe::Vector2(this->x * scalar, this->y * scalar);
}

pe::Vector2 pe::Vector2::operator/(const float& scalar) const
{
	if (scalar == 0) throw std::overflow_error("Dividing by zero");

	return pe::Vector2(this->x / scalar, this->y / scalar);
}

pe::Vector2& pe::Vector2::operator=(const pe::Vector2& other)
{
	x = other.x;
	y = other.y;
}