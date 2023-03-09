#include "StringBuilder.hpp"

pe::StringBuilder::StringBuilder() : m_size(128), m_length(0)
{
	m_string = new char[m_size];
	m_string[m_length] = 0;
	
}

pe::StringBuilder::~StringBuilder()
{
	delete[] m_string;
}

pe::StringBuilder& pe::StringBuilder::append(const char& string)
{
	m_length++;
	if (m_length >= m_size) expand(m_length);
	m_string[m_length - 1] = string;
	m_string[m_length] = 0;

	return *this;
}

pe::StringBuilder& pe::StringBuilder::append(const char* string)
{
	unsigned int length = pe::String::stringLength(string);
	unsigned int newLength = m_length + length;

	// Expands the necessary amount
	if (newLength >= m_size) expand(newLength);

	for (unsigned int i = m_length; i < newLength; i++)
		m_string[i] = string[i - m_length];

	m_length = newLength;
	m_string[m_length] = 0;

	return *this;
}

pe::StringBuilder& pe::StringBuilder::append(const pe::String& string)
{
	return append(string.m_string);
}

const unsigned int& pe::StringBuilder::length() const
{
	return m_length;
}

bool pe::StringBuilder::isEmpty() const
{
	return m_length == 0;
}

void pe::StringBuilder::clear()
{
	delete[] m_string;

	m_size = 128;
	m_length = 0;
	m_string = new char[m_size];
	m_string[m_length] = 0;
}

pe::String pe::StringBuilder::toString() const
{
	return m_string;
}

void pe::StringBuilder::expand(const unsigned int& newLength)
{
	const char* aux = m_string;
	while(m_size <= newLength) m_size += 128;
	m_string = new char[m_size];

	// Copies values
	for (unsigned int i = 0; i <= m_length; i++)
		m_string[i] = aux[i];


	delete[] aux;
}

std::ostream& pe::operator<<(std::ostream& os, const pe::StringBuilder& string)
{
	os << string.m_string;
	return os;
}