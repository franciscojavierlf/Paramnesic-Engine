#include "PE/Utils/Json.hpp"

/*
	Json
 */

pe::Json::Json()
{

}

pe::Json::Json(const pe::String& string)
{
	*this = pe::Json::parseString(string, 0, -1);
}

pe::Json::Json(const pe::Json& json)
{
	*this = json;
}

pe::Json::~Json()
{

}

pe::Json pe::Json::parseString(const pe::String& string, const unsigned int start = 0, int end = -1)
{
	pe::Json json;
	pe::StringBuilder charBuffer;
	pe::String tag;
	pe::JsonValue value;

	const char* aux;

	bool inObject = false;
	bool inValue = false;
	bool inQuotes = false;
	bool hasTag = false;
	bool hasValue = false;
	bool specialChar = false;

	// If end is less than zero, then it's the whole string
	if (end < 0) end = string.length();

	for (unsigned int i = start; i < end; i++)
	{
		aux = &string[i];

		switch (*aux)
		{
		case '"': // The name of a value
			if (!inObject) throw pe::BadJsonFormatException(*aux);

			if (!specialChar)
			{
				if (inQuotes)
				{
					// Decides if it is a tag
					if (!inValue)
					{
						// There were double commas
						if (hasTag) throw pe::BadJsonFormatException(*aux);

						tag = charBuffer.toString();
						charBuffer.clear();
						hasTag = true;
					}
					else
					{
						if (hasValue) throw pe::BadJsonFormatException(*aux);
						value = pe::JsonValue(charBuffer.toString(), true);
						charBuffer.clear();
						hasValue = true;
					}

					inQuotes = false;
				}
				else
				{
					if (!inValue && hasTag) throw pe::BadJsonFormatException(*aux);
					inQuotes = true;
				}
			}
			else
			{
				charBuffer.append(*aux);
				specialChar = false;
			}
			break;

		case ':':
			if (!inObject) throw pe::BadJsonFormatException(*aux);
			if (!inQuotes)
			{
				if (!inValue && hasTag) inValue = true;
				else throw pe::BadJsonFormatException(*aux);
			}
			else charBuffer.append(*aux);
			break;

		case ',':
			if (!inObject) throw pe::BadJsonFormatException(*aux);
			if (!inQuotes)
			{
				if (inValue)
				{
					// Also checks if there is a valid value
					if (!hasValue && charBuffer.length() == 0)
						throw pe::BadJsonFormatException(*aux);

					if (!hasValue)
					{
						value = pe::JsonValue(charBuffer.toString(), false);
						charBuffer.clear();
					}

					json.setValue(tag, value);
					hasTag = false;
					hasValue = false;
					inValue = false;
				}
				else throw pe::BadJsonFormatException(*aux);
			}
			else charBuffer.append(*aux);
			break;

		case '{': // Enters an object
			if (!inQuotes)
			{
				if (inObject)
				{
					// Creates a json child
					if (inValue)
					{
						int j = getClosingBracket(string, i);

						// There is no closing bracket
						if (j < 0) throw pe::BadJsonFormatException(*aux);

						// j + 1 since it's exclusive
						value = parseString(string, i, j + 1);
						hasValue = true;

						// Skips the whole json child. Not + 1 since at the end it will do it
						i = j;
					}
					else throw pe::BadJsonFormatException(*aux);
				}
				// Enters for the first time in the object
				else inObject = true;
			}
			else charBuffer.append(*aux);
			break;

		case '}': // Exits an object
			if (!inQuotes)
			{
				if (!inObject) throw pe::BadJsonFormatException(*aux);

				// Saves the last value
				if (inValue)
				{
					// Also checks if there is a valid value
					if (!hasValue && charBuffer.length() == 0)
						throw pe::BadJsonFormatException(*aux);

					if (!hasValue)
					{
						value = pe::JsonValue(charBuffer.toString(), false);
						charBuffer.clear();
					}
					json.setValue(tag, value);
				}

				// Checks if there are values beyond this point, which would mean an error
				for (int j = i + 1; j < end; j++)
					if (string.charAt(j) != ' ') throw pe::BadJsonFormatException(string.charAt(j));

				// Releases the json object
				return json;
			}
			else charBuffer.append(*aux);
			break;

		case '\\': // For special characters
			if (!inObject) throw pe::BadJsonFormatException(*aux);
			// Will indicate that a special char is coming
			if (!specialChar) specialChar = true;
			else
			{
				// Adds the '/' since it's the special char
				charBuffer.append(*aux);
				specialChar = false;
			}
			break;



		case '\t':
		case '\n':
				break;

		case ' ': // Spaces
			// Ignores if it is not in quotes
			if (!inQuotes) break;
			// Jumps to default if it is in quotes
		default: // Normal characters
			if (!inObject) throw pe::BadJsonFormatException(*aux);
			charBuffer.append(*aux);
			specialChar = false;
		}

	}

	// Json was not returned, thus something went wrong
	throw pe::BadJsonFormatException();
}

pe::JsonValue pe::Json::getValue(const pe::String& tag)
{
	return m_values[tag];
}

void pe::Json::setValue(const pe::String& tag, const pe::JsonValue& value)
{
	int i = m_values.indexOfTag(tag);

	if (i < 0) m_values.add(tag, value);
	else m_values.replace(tag, value);
}


pe::Json& pe::Json::operator=(const pe::Json& json)
{
	m_values = json.m_values;

	return *this;
}

int pe::Json::getClosingBracket(const pe::String& string, const unsigned int& start)
{
	if (start >= string.length()) return -1;

	unsigned int count = 0;
	bool inJson = false;
	for (unsigned int i = start; i < string.length(); i++)
	{
		switch (string[i])
		{
		case '{':
			if (!inJson) inJson = true;
			count++;
			break;
		case ' ': break;
		case '}':
			if (inJson)
			{
				// Found
				if (count == 1) return i;
				else count--;
			}
			// Wrong format
		default:
			if (!inJson) return -1;
		}
	}

	return -1;
}

std::ostream& pe::operator<<(std::ostream& os, const pe::Json& json)
{
	const pe::JsonValue* aux;
	os << '{';
	for (unsigned int i = 0; i < json.m_values.length(); i++)
	{
		os << '\"' << json.m_values.tagAt(i) << "\":";

		aux = &json.m_values.objectAt(i);
		switch (aux->getType())
		{
		case 'j':
		case 'i':
		case 'f':
		case 'b': os << aux; break;
		case 's': os << '\"' << aux << '\"'; break;
		}

		if (i < json.m_values.length() - 1)
			os << ',';
	}
	os << '}';

	return os;
}

/*
	JsonValue
*/

pe::JsonValue::JsonValue()
{
}

pe::JsonValue::JsonValue(const pe::JsonValue& value)
{
	*this = value;
}

pe::JsonValue::JsonValue(const int& number)
{
	*this = number;
}

pe::JsonValue::JsonValue(const float& number)
{
	*this = number;
}

pe::JsonValue::JsonValue(const bool& boolean)
{
	*this = boolean;
}

pe::JsonValue::JsonValue(const pe::String& string)
{
	*this = string;
}

pe::JsonValue::JsonValue(const pe::Json& json)
{
	*this = json;
}

pe::JsonValue::~JsonValue()
{
}


pe::JsonValue::JsonValue(const pe::String& string, const bool& isString)
{
	if (!isString)
	{
		if (string.isInteger())
		{
			m_int = string.toInteger();
			m_type = 'i';
		}
		else if (string.isFloat())
		{
			m_float = string.toFloat();
			m_type = 'f';
		}
		else if (string.isBool())
		{
			m_bool = string.toBool();
			m_type = 'b';
		}
		else throw pe::BadJsonFormatException();
	}
	else
	{
		*this = string;
		m_type = 's';
	}
}

char pe::JsonValue::getType() const
{
	return m_type;
}

pe::JsonValue pe::JsonValue::getValue(const pe::String& tag)
{
	if (m_type != 'j') throw pe::Exception("Bad operand. Value is not Json!");
	return m_json.getValue(tag);
}

pe::JsonValue& pe::JsonValue::operator=(const int& number)
{
	m_int = number;
	m_type = 'i';
	return *this;
}

pe::JsonValue& pe::JsonValue::operator=(const float& number)
{
	m_float = number;
	m_type = 'f';
	return *this;
}

pe::JsonValue& pe::JsonValue::operator=(const bool& boolean)
{
	m_bool = boolean;
	m_type = 'b';
	return *this;
}

pe::JsonValue& pe::JsonValue::operator=(const pe::String& string)
{
	m_string = string;
	m_type = 's';
	return *this;
}

pe::JsonValue& pe::JsonValue::operator=(const pe::Json& json)
{
	m_json = json;
	m_type = 'j';
	return *this;
}

pe::JsonValue& pe::JsonValue::operator=(const pe::JsonValue& value)
{
	m_type = value.m_type;

	switch (m_type)
	{
	case 'i': m_int = value.m_int; break;
	case 'f': m_float = value.m_float; break;
	case 'b': m_bool = value.m_bool; break;
	case 's': m_string = value.m_string; break;
	case 'j': m_json = value.m_json; break;
	}

	return *this;
}

pe::JsonValue::operator int() const
{
	if (m_type != 'i') throw pe::Exception("Bad conversion. Json value is not int!");
	return m_int;
}

pe::JsonValue::operator float() const
{
	if (m_type != 'f') throw pe::Exception("Bad conversion. Json value is not float!");
	return m_float;
}

pe::JsonValue::operator bool() const
{
	if (m_type != 'b') throw pe::Exception("Bad conversion. Json value is not bool!");
	return m_bool;
}

pe::JsonValue::operator pe::String() const
{
	if (m_type != 's') throw pe::Exception("Bad conversion. Json value is not String!");
	return m_string;
}

pe::JsonValue::operator pe::Json() const
{
	if (m_type != 'j') throw pe::Exception("Bad conversion. Json value is not Json!");
	return m_json;
}

std::ostream& pe::operator<<(std::ostream& os, const pe::JsonValue& value)
{
	switch (value.m_type)
	{
	case 'i': os << value.m_int; break;
	case 'f': os << value.m_float; break;
	case 'b': os << value.m_bool; break;
	case 's': os << value.m_string; break;
	case 'j': os << value.m_json; break;
	}

	return os;
}