#pragma once

#include "PE/Utils/Exceptions/Exception.hpp"

namespace pe
{
	struct OperatorException final : pe::Exception
	{
	public:
		OperatorException(const pe::String& operatorType);
		~OperatorException();
	};
}