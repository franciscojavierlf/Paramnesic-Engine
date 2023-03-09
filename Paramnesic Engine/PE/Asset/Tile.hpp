#pragma once

#include "PE\Asset\Asset.hpp"

namespace pe
{
	class Tile final : public pe::Asset
	{
	public:
		Tile();
		~Tile() override;

	private:
		static unsigned int COUNT;
	};
}