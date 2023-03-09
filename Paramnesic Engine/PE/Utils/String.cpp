#include "String.hpp"
#include "StringBuilder.hpp"

/*
	Static functions
 */
pe::String pe::String::stringParse(const int& n)
{
	ArrayList<int> refs;
	int temp = n;
	unsigned int counter = 0;

	// Counts digits
	while (temp > 0)
	{
		temp /= 10;
		counter++;
	}

	// Resets number
	temp = n;

	// Gets each digit
	for (int i = counter - 1; i >= 0; i--)
	{
		refs.add(temp % 10);
		temp /= 10;
	}

	pe::StringBuilder res;
	char auxPtr[2];
	auxPtr[1] = 0;
	char aux;

	for (unsigned int i = 0; i < refs.length(); i++)
	{
		switch (refs.get(i))
		{
		case 0: aux = '0'; break;
		case 1: aux = '1'; break;
		case 2: aux = '2'; break;
		case 3: aux = '3'; break;
		case 4: aux = '4'; break;
		case 5: aux = '5'; break;
		case 6: aux = '6'; break;
		case 7: aux = '7'; break;
		case 8: aux = '8'; break;
		case 9: aux = '9'; break;
		}

		auxPtr[0] = aux;
		res.append(auxPtr);
	}

	return res.toString();
}

unsigned int pe::String::stringLength(const char* string)
{
	unsigned int count = 0;
	unsigned int i = 0;
	while (string[i++] != 0) count++;

	return count;
}

bool pe::String::stringIsEmpty(const char* string)
{
	return stringLength(string) == 0;
}

bool pe::String::stringEqualsTo(const char* s1, const char* s2)
{
	unsigned int s1Length = stringLength(s1);
	unsigned int s2Length = stringLength(s2);

	// If the length is not the same
	if (s1Length != s2Length)
		return false;

	// If there is a single character that doesn't match
	for (unsigned int i = 0; i < s1Length; i++)
		if (s1[i] != s2[i])
			return false;

	// It is the same
	return true;
}

/*
	Class functions
 */

pe::String::String() : pe::String::String("")
{

}

pe::String::String(const char* string) : m_length(pe::String::stringLength(string))
{
	m_string = new char[m_length + 1];

	// Copies values from the string
	for (unsigned int i = 0; i < m_length; i++)
		m_string[i] = string[i];

	m_string[m_length] = 0;
}


pe::String::String(const pe::String& other) : pe::String(other.m_string)
{

}

pe::String::String(const sf::String& other) : m_length(other.getSize())
{
	m_string = new char[m_length + 1];

	for (unsigned int i = 0; i < m_length; i++)
		m_string[i] = other[i];

	m_string[m_length] = 0;

}

pe::String::String(const std::string& other) : m_length(other.size())
{
	m_string = new char[m_length + 1];

	for (unsigned int i = 0; i < m_length; i++)
		m_string[i] = other[i];

	m_string[m_length] = 0;
}

pe::String::~String()
{
	delete[] m_string;
}

const char& pe::String::charAt(const unsigned int& i) const
{
	if (i < 0 || i >= m_length)
		throw std::out_of_range("Index out of range.");

	return m_string[i];
}

pe::String& pe::String::append(const char* string)
{
	const char* aux = m_string;
	unsigned int oldLength = m_length;
	m_length = oldLength + stringLength(string);
	m_string = new char[m_length + 1];

	for (unsigned int i = 0; i < m_length; i++)
		if (i < oldLength) m_string[i] = aux[i];
		else m_string[i] = string[i - oldLength];

	m_string[m_length] = 0;
	delete[] aux;

	return *this;
}

pe::String pe::String::substring(const unsigned int& start, int length) const
{
	if (start < 0 || start >= m_length)
		throw std::out_of_range("Index out of range.");

	// Gets all the string if the length is negative
	// Gets the rest of the string if it is too large
	else if (length < 0 || length > m_length - start) length = m_length - start;

	char* aux = new char[length + 1];
	for (unsigned int i = 0; i < length; i++)
		aux[i] = this->charAt(start + i);

	aux[length] = 0;

	pe::String res = aux;
	delete[] aux;

	return res;
}

pe::String& pe::String::replace(const char* string, const char* replace)
{
	pe::ArrayList<unsigned int> res  = findAll(string);
	int strLength = (int) stringLength(string);
	int rplLength = (int) stringLength(replace);
	int d = rplLength - strLength;

	// Changes the length
	int oldLength = m_length;
	char* oldString = m_string;
	m_length += d * res.length();
	m_string = new char[m_length + 1];

	// Changes every string
	int offset = 0;
	int rplCount = 0;
	int newi;
	for (int i = 0; i < oldLength; i++)
	{
		newi = i + offset + rplCount * (1 - strLength);
		if (res.contains(i))
		{
			for (int j = 0; j < rplLength; j++)
				m_string[newi + j] = replace[j];

			offset += rplLength - 1;
			i += strLength - 1;
			rplCount++;
		}
		else m_string[newi] = oldString[i];
	}

	m_string[m_length] = 0;

	// Deletes the old string
	delete[] oldString;

	return *this;
}

int pe::String::find(const char* string, const int& skip) const
{
	unsigned int length = stringLength(string);
	int iAux = -1;

	if (length > 0)
	{
		unsigned int pos = 0;
		unsigned int count = 0;
		unsigned int currLength = m_length;
		// Checks if the i reaches the end or if there is not enough letters to continue
		for (unsigned int i = 0; i < m_length || currLength < length; i++, currLength--)
		{
			// Finds the string
			while (i + pos < m_length && pos < length
				&& m_string[i + pos] == string[pos])
				pos++;

			// The string was found
			if (pos == length)
			{
				count++;
				
				// Returns the position if the entire string was found
				// If skip is less than zero, it will find the last string
				if (skip < 0)
					iAux = i;
				else if (count > skip)
					return i;

				// Skips the string
				i += pos - 1; // - 1 because at the end the i++ happens
			}

			// Resets position
			pos = 0;
		}
	}

	return iAux;
}

bool pe::String::contains(const char* string) const
{
	return find(string) >= 0;
}

pe::String pe::String::toLowerCase() const
{
	pe::String res = *this;
	unsigned char d = 'a' - 'A';
	for (unsigned int i = 0; i < res.m_length; i++)
	{
		if (res.m_string[i] >= 'A' && res.m_string[i] <= 'Z')
			res.m_string[i] += d;
	}

	return res;
}

pe::String pe::String::toUpperCase() const
{
	pe::String res = *this;
	unsigned char d = 'a' - 'A';
	for (unsigned int i = 0; i < res.m_length; i++)
	{
		if (res.m_string[i] >= 'a' && res.m_string[i] <= 'z')
			res.m_string[i] -= d;
	}

	return res;
}

bool pe::String::isEmpty() const
{
	return m_length == 0;
}

int pe::String::toInteger() const
{
	if (!m_length) return false;

	int res = 0;
	bool negative;
	if (m_string[0] == '-') negative = true;
	else negative = false;
	if (negative && m_length == 1) return false;
	for (int i = m_length - 1; i >= 0 + negative; i--)
	{
		if (m_string[i] < '0' || m_string[i] > '9')
			throw std::exception("Wrong format.");
		else
			res += (m_string[i] - '0') * pe::Math::pow(10, m_length - i - 1);
	}

	return negative ? -res : res;
}

unsigned int pe::String::toUnsignedHexadecimal() const
{
	if (m_length <= 1 || charAt(0) != '#')
		throw std::exception("Hexadecimal must be in format \"#000000...\".");

	unsigned int res = 0;
	unsigned int aux;
	// Skips the first character '#'
	for (int i = m_length - 1; i > 0; i--)
	{
		if (m_string[i] >= '0' && m_string[i] <= '9')
			res += (m_string[i] - '0') * pe::Math::pow(16, m_length - i - 1);
		else if ((m_string[i] >= 'A' && m_string[i] <= 'F') ||
				 (m_string[i] >= 'a' && m_string[i] <= 'f'))
		{
			aux = 9;
			switch (m_string[i])
			{
			case 'F': case 'f': aux++;
			case 'E': case 'e': aux++;
			case 'D': case 'd': aux++;
			case 'C': case 'c': aux++;
			case 'B': case 'b': aux++;
			case 'A': case 'a': aux++;
			}

			res += aux * pe::Math::pow(16, m_length - i - 1);
		}
		else throw std::exception("Wrong format.");
	}

	return res;
}

float pe::String::toFloat() const
{
	if (!m_length) throw std::exception("Wrong format.");

	float res = 0;
	bool negative;
	bool point = false;
	if (m_string[0] == '-') negative = true;
	else negative = false;
	if (negative && m_length == 1) throw std::exception("Wrong format");

	for (int i = m_length - 1; i >= 0 + negative; i--)
	{
		if (m_string[i] == '.' && point)
			throw std::exception("Wrong format.");
		else if (m_string[i] == '.' && !point)
			point = true;
		else if (m_string[i] < '0' || m_string[i] > '9')
			throw std::exception("Wrong format.");
		else
			res += (m_string[i] - '0') *
			(point ? 1 / pe::Math::pow(10, m_length - i - 1) : pe::Math::pow(10, m_length - i - 1));
	}

	return negative ? -res : res;
}

bool pe::String::toBool() const
{
	return toLowerCase() == "true";
}

bool pe::String::isInteger() const
{
	if (m_length == 0) return false;

	bool negative = m_string[0] == '-';
	if (negative && m_length == 1) return false;
	for (unsigned int i = 0 + negative; i < m_length; i++)
	{
		if (m_string[i] < '0' || m_string[i] > '9')
			return false;
	}

	return true;
}

bool pe::String::isFloat() const
{
	if (m_length == 0) return false;

	bool point = false;
	bool negative = m_string[0] == '-';
	if (negative && m_length == 1) return false;
	for (unsigned int i = 0 + negative; i < m_length; i++)
	{
		if (m_string[i] == '.' && point)
			return false;
		else if (m_string[i] == '.' && !point)
			point = true;
		else if (m_string[i] < '0' || m_string[i] > '9')
			return false;
	}

	return true;
}

bool pe::String::isBool() const
{
	pe::String&& aux = toLowerCase();
	return aux == "true" || aux == "false";
}

const unsigned int& pe::String::length() const
{
	return m_length;
}

pe::String& pe::String::operator=(const pe::String& other)
{
	m_length = other.m_length;
	m_string = new char[m_length + 1];

	// Copies values from the string
	for (unsigned int i = 0; i < m_length; i++)
		m_string[i] = other[i];

	m_string[m_length] = 0;

	return *this;
}

const char& pe::String::operator[](const unsigned int& i) const
{
	return charAt(i);
}

bool pe::String::operator<(const char* other) const
{
	return m_string < other;
}

bool pe::String::operator>(const char* other) const
{
	return m_string > other;
}

bool pe::String::operator<=(const char* other) const
{
	return m_string <= other;
}

bool pe::String::operator>=(const char* other) const
{
	return m_string >= other;
}

bool pe::String::operator==(const char* other) const
{
	unsigned int otherLength = stringLength(other);

	// If the length is not the same
	if (m_length != otherLength)
		return false;

	// If there is a single character that doesn't match
	for (unsigned int i = 0; i < m_length; i++)
		if (m_string[i] != other[i])
			return false;

	// It is the same
	return true;
}

bool pe::String::operator!=(const char* other) const
{
	return !(*this == other);
}

void pe::String::operator+=(const char* other)
{
	append(other);
}

pe::String pe::String::operator+(const char* other) const
{
	return pe::String(*this).append(other);
}

pe::String::operator char*() const
{
	return m_string;
}

pe::String::operator const char*() const
{
	return m_string;
}

pe::String::operator std::string() const
{
	return std::string(m_string);
}

pe::String::operator sf::String() const
{
	return sf::String(m_string);
}

pe::ArrayList<unsigned int> pe::String::findAll(const char* string) const
{
	pe::ArrayList<unsigned int> res;

	unsigned int length = strlen(string);

	if (length > 0)
	{
		unsigned int pos = 0;
		unsigned int count = 0;
		for (unsigned int i = 0; i < this->m_length; i++)
		{
			// Gets out if there is no possible string
			if (i > m_length - length) break;

			// Finds the string
			while (i + pos < m_length && pos < length
				&& m_string[i + pos] == string[pos])
				pos++;

			// The string was found
			if (pos == length) res.add(i);

			// Resets position
			pos = 0;
		}
	}

	return res;
}

std::ostream& pe::operator<<(std::ostream& os, const pe::String& string)
{
	os << string.m_string;
	return os;
}

std::istream& pe::operator>>(std::istream& is, const pe::String& string)
{
	is >> string.m_string;
	return is;
}