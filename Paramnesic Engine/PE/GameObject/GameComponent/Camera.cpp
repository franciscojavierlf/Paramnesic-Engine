#include "Camera.hpp"

pe::Camera::Camera(pe::GameObject& object) : pe::GameComponent(object, false)
{
}

pe::Camera::~Camera()
{

}

const float& pe::Camera::getWidth() const
{
	return m_size.x;
}

const float& pe::Camera::getHeight() const
{
	return m_size.y;
}

void pe::Camera::setSize(const float& width, const float& height)
{
	m_size.x = width;
	m_size.y = height;
}