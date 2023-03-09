#pragma once

#include "PE/Utils/String.hpp"

namespace pe
{
	struct StringBuilder final
	{
	public:
		StringBuilder();
		~StringBuilder();
		pe::StringBuilder& append(const char& string);
		pe::StringBuilder& append(const char* string);
		pe::StringBuilder& append(const pe::String& string);
		const unsigned int& length() const;
		bool isEmpty() const;
		void clear();
		pe::String toString() const;

	private:
		void expand(const unsigned int& newLength);

		friend std::ostream& operator<<(std::ostream& os, const pe::StringBuilder& string);

	private:
		char* m_string;
		unsigned int m_length;
		unsigned int m_size;
	};
}