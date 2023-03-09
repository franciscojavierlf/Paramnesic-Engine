#include "PE/Utils/Transform.hpp"

pe::Transform::Transform()
{

}

pe::Transform::~Transform()
{

}


pe::Transform& pe::Transform::operator=(const pe::Transform& other)
{
	position = other.position;
	rotation = other.rotation;
	scale = other.scale;
}