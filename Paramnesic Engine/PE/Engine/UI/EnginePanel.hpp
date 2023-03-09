#pragma once

#include "PE/GameObject/GameObject.hpp"
#include "PE/Utils/SmartPointers/SharedPtr.hpp"
#include "PE/GameObject/GameComponent/UI/TextRenderer.hpp"

namespace pe
{
	struct EnginePanel : public pe::GameObject
	{
	public:
		EnginePanel();
		~EnginePanel();

		void tick() override;

	private:
		void setEnginePanel();
	};
}