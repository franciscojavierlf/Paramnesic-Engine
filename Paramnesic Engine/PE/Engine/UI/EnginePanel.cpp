#include "PE/Engine/UI/EnginePanel.hpp"

pe::EnginePanel::EnginePanel() : pe::GameObject("EnginePanel")
{
	setEnginePanel();
}

pe::EnginePanel::~EnginePanel()
{

}

void pe::EnginePanel::tick()
{

}

void pe::EnginePanel::setEnginePanel()
{
	pe::TextRenderer* text = new pe::TextRenderer(*this);
	text->setText("POR FIjkj jkl jlk kl jkhkN!!!");
	addComponent(text);
}