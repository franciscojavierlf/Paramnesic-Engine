#pragma once

#include "PE\GameObject\GameComponent\GameComponent.hpp"
#include "PE/Utils/Vector2.hpp"

namespace pe
{
	class Camera final : public pe::GameComponent
	{
	public:
		Camera(pe::GameObject& object);
		~Camera() override;

		const float& getWidth() const;
		const float& getHeight() const;
		void setSize(const float& width, const float& height);

	private:
		pe::Vector2 m_size;
	};
}