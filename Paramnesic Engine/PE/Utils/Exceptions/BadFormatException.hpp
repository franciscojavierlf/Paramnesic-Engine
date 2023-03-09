#pragma once

#include "PE/Utils/Exceptions/Exception.hpp"

namespace pe
{
	struct BadFormatException final : pe::Exception
	{
	public:
		BadFormatException();
		BadFormatException(const char& character);
		~BadFormatException();
	};
}