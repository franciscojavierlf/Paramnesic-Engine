#pragma once

#include "PE/Utils/StringBuilder.hpp"
#include <stdexcept>

namespace pe
{
	class Exception : std::exception
	{
	public:
		Exception();
		Exception(const pe::String& message);
		~Exception();

		const char* what() const throw() override final;

	protected:
		void setMessage(const pe::String& message);

	private:
		pe::String m_message;
	};
}