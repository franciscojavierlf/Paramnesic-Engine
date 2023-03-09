#include "Animator.hpp"

pe::Animator::Animator(pe::GameObject& object) : GameComponent(object, false)
{

}

pe::Animator::~Animator()
{

}

void pe::Animator::setCurrentAnimation(const char* tag)
{
	//m_currentAnim = m_animations.get(tag);
}

/*
void SpriteAnimator::addAnimation(SpriteAnimation* anim, std::string tag)
{
	animations.push_back(anim);
	animTags.push_back(tag);
}

void SpriteAnimator::play()
{
	if (currentAnim != nullptr)
		currentAnim->play();
}

void SpriteAnimator::pause()
{
	if (currentAnim != nullptr)
		currentAnim->pause();
}

void SpriteAnimator::restart()
{
	if (currentAnim != nullptr)
		currentAnim->restart();
}

void SpriteAnimator::stop()
{
	if (currentAnim != nullptr)
		currentAnim->stop();
}

void SpriteAnimator::tick()
{
	if (currentAnim != nullptr)
	{
		currentAnim->tick();
		object->setSprite(currentAnim->getCurrentSprite());
	}
}
*/