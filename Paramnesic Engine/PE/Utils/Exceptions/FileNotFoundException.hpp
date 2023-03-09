#pragma once

#include "PE/Utils/Exceptions/Exception.hpp"

namespace pe
{
	struct FileNotFoundException final : pe::Exception
	{
	public:
		FileNotFoundException(const pe::String& path);
		~FileNotFoundException();
	};
}