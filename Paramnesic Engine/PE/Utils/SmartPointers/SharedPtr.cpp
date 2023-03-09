#include "PE/Utils/SmartPointers/SharedPtr.hpp"



pe::ReferenceCount::ReferenceCount() : m_count(0)
{

}

pe::ReferenceCount::~ReferenceCount()
{

}

void pe::ReferenceCount::addReference()
{
	m_count++;
}

void pe::ReferenceCount::removeReference()
{
	if (hasReferences()) m_count--;
}

unsigned int pe::ReferenceCount::getReferenceCount()
{
	return m_count;
}

bool pe::ReferenceCount::hasReferences()
{
	return m_count > 0;
}