#include "BadJsonFormatException.hpp"

pe::BadJsonFormatException::BadJsonFormatException()
{
	setMessage("Wrong Json structure.");
}

pe::BadJsonFormatException::BadJsonFormatException(const char& character)
{
	pe::StringBuilder res;
	res.append("Wrong Json structure in character '").append(character).append('\'.');

	setMessage(res.toString());
}

pe::BadJsonFormatException::~BadJsonFormatException()
{

}