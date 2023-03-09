#include "FileNotFoundException.hpp"

pe::FileNotFoundException::FileNotFoundException(const pe::String& path)
{
	pe::StringBuilder res;
	res.append("File located at ").append(path).append(" does not exist!");

	setMessage(res.toString());
}

pe::FileNotFoundException::~FileNotFoundException()
{

}