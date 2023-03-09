#pragma once

#include "PE/Utils/Exceptions/Exception.hpp"

namespace pe
{
	struct BadJsonFormatException final : pe::Exception
	{
	public:
		BadJsonFormatException();
		BadJsonFormatException(const char& character);
		~BadJsonFormatException();
	};
}