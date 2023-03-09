#pragma once

#include "PE/Utils/Exceptions/Exception.hpp"

namespace pe
{
	struct IndexOutOfRangeException final : pe::Exception
	{
	public:
		IndexOutOfRangeException();
		~IndexOutOfRangeException();
	};
}