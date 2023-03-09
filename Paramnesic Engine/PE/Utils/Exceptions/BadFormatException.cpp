#include "BadFormatException.hpp"

pe::BadFormatException::BadFormatException()
{
	setMessage("Wrong format.");
}

pe::BadFormatException::BadFormatException(const char& character)
{
	pe::StringBuilder res;
	res.append("Wrong format in character '").append(character).append('\'.');

	setMessage(res.toString());
}

pe::BadFormatException::~BadFormatException()
{

}