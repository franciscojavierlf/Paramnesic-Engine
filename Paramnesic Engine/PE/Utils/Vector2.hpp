#pragma once

#include <stdexcept>

namespace pe
{
	struct Vector2 final
	{
	public:
		Vector2();
		Vector2(const float& x, const float& y);
		~Vector2();
		pe::Vector2 operator+(const pe::Vector2& other) const;
		pe::Vector2 operator-(const pe::Vector2& other) const;
		pe::Vector2 operator*(const float& scalar) const;
		pe::Vector2 operator/(const float& scalar) const;

		pe::Vector2& operator=(const pe::Vector2& other);

	public:
		float x;
		float y;
	};
}