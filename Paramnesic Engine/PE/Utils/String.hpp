#pragma once

#include <SFML\System.hpp>
#include <iostream>
#include <stdexcept>
#include "PE/Utils/Math.hpp"
#include "PE/Utils/ArrayList.hpp"

namespace pe
{
	class String final
	{
	public:
		static pe::String stringParse(const int& n);
		static unsigned int stringLength(const char* string);
		static bool stringIsEmpty(const char* string);
		static bool stringEqualsTo(const char* s1, const char* s2);


	public:
		String();
		String(const char* string);
		String(const pe::String& other);
		String(const sf::String& other);
		String(const std::string& other);
		~String();

		const char& charAt(const unsigned int& i) const;
		pe::String& append(const char* string);
		pe::String substring(const unsigned int& start, int length) const;
		pe::String& replace(const char* string, const char* replace);
		int find(const char* string, const int& skip = 0) const;
		bool contains(const char* string) const;
		pe::String toLowerCase() const;
		pe::String toUpperCase() const;
		bool isEmpty() const;
		int toInteger() const;
		unsigned int toUnsignedHexadecimal() const;
		float toFloat() const;
		bool toBool() const;
		bool isInteger() const;
		bool isFloat() const;
		bool isBool() const;
		const unsigned int& length() const;

		pe::String& operator=(const pe::String& other);
		const char& operator[](const unsigned int& i) const;

		// Logic operators
		bool operator<(const char* other) const;
		bool operator>(const char* other) const;
		bool operator<=(const char* other) const;
		bool operator>=(const char* other) const;
		bool operator==(const char* other) const;
		bool operator!=(const char* other) const;

		void operator+=(const char* other);
		pe::String operator+(const char* other) const;

		operator char*() const;
		operator const char*() const;
		operator std::string() const;
		operator sf::String() const;

	private:
		pe::ArrayList<unsigned int> findAll(const char* string) const;

		friend std::ostream& operator<<(std::ostream& os, const pe::String& string);
		friend std::istream& operator>>(std::istream& is, const pe::String& string);

		friend struct StringBuilder;

	private:
		char* m_string;
		unsigned int m_length;
	};
}