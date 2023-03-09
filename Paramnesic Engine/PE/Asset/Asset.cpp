#include "Asset.hpp"

pe::Asset::Asset(const pe::String& path) : m_path(path)
{
	//m_name = m_path.substring(m_path.find("."), m_path.length());
}

pe::Asset::~Asset()
{

}

const pe::String& pe::Asset::getName() const
{
	return m_name;
}

void pe::Asset::setName(const char* name)
{
	if (pe::String::stringIsEmpty(name))
		throw std::invalid_argument("Name must not be empty!");

	this->m_name = name;
}

const pe::String& pe::Asset::toString() const
{
	return m_name;
}

pe::Asset::Asset(const char* type, const unsigned int& count) : pe::Asset::Asset(type)
{
	m_name.append(pe::String::stringParse(count));
}