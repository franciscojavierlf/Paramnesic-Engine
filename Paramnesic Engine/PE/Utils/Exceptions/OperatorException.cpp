#include "OperatorException.hpp"

pe::OperatorException::OperatorException(const pe::String& operatorType)
{
	pe::StringBuilder res;
	res.append("There is no operator '").append(operatorType).append("'.");

	setMessage(res.toString());
}

pe::OperatorException::~OperatorException()
{

}