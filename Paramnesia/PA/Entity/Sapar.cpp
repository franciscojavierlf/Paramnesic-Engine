#include "PA/Entity/Sapar.hpp"

pa::Sapar::Sapar() : pa::Entity("Sapar")
{
	pe::SpriteRenderer* c = new pe::SpriteRenderer(*this);
	c->setSprite(this->getCurrentScene()->getAsset("Sapar"));
	this->addComponent(c);
}

pa::Sapar::~Sapar()
{

}