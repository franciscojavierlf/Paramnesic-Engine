#include "PE/Utils/Exceptions/Exception.hpp"

pe::Exception::Exception()
{

}

pe::Exception::Exception(const pe::String& message)
{

}

pe::Exception::~Exception()
{

}

const char* pe::Exception::what() const throw()
{
	pe::StringBuilder res;
	res.append(m_message).append(" ").append(std::exception::what());

	return res.toString();
}

void pe::Exception::setMessage(const pe::String& message)
{
	m_message = message;
}