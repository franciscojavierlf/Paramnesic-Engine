#pragma once

#include "PE/Utils/Vector2.hpp"

namespace pe
{
	struct Transform final
	{
	public:
		Transform();
		~Transform();

		pe::Transform& operator=(const pe::Transform& other);

	public:
		pe::Vector2 position;
		pe::Vector2 rotation;
		pe::Vector2 scale;
	};
}