#pragma once

#include <PE/GameObject.hpp>

namespace pa
{
	class Entity : public pe::GameObject
	{
	protected:
		Entity(const pe::String& name);
		virtual ~Entity() = 0;

	protected:
		pe::String m_name;
	};
}