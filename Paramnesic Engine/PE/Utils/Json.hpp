#pragma once

#include "PE/Utils/Exceptions/BadJsonFormatException.hpp"
#include "PE/Utils/SmartPointers/SharedPtr.hpp"
#include "PE/Utils/Map.hpp"
#include "PE/Utils/String.hpp"

namespace pe
{
	class JsonValue;

	// Not very efficient (various value copies), but works fine at the end
	class Json final
	{
	public:
		Json();
		Json(const pe::String& string);
		Json(const pe::Json& json);
		~Json();

		pe::JsonValue getValue(const pe::String& tag);
		void setValue(const pe::String& tag, const pe::JsonValue& value);

		pe::Json& operator=(const pe::Json& json);

	private:

		friend std::ostream& operator<<(std::ostream& os, const pe::Json& json);

	private:
		// Parses a json. Recursive
		static pe::Json parseString(const pe::String& string, const unsigned int start, int end);

		// Gets the index of the closing bracket of a json. Doesn't care if format is correct
		static int getClosingBracket(const pe::String& string, const unsigned int& start);

 

	private:
		pe::Map<pe::String, pe::JsonValue> m_values;
	};

	class JsonValue final
	{
	public:
		JsonValue();
		JsonValue(const pe::JsonValue& value);
		JsonValue(const int& number);
		JsonValue(const float& number);
		JsonValue(const bool& boolean);
		JsonValue(const pe::String& string);
		JsonValue(const pe::Json& json);
		~JsonValue();

	private:
		// Only when loading from string
		JsonValue(const pe::String& string, const bool& isString);

	public:
		char getType() const;

		// Only accesible when value is json
		pe::JsonValue getValue(const pe::String& tag);

		pe::JsonValue& operator=(const int& number);
		pe::JsonValue& operator=(const float& number);
		pe::JsonValue& operator=(const bool& boolean);
		pe::JsonValue& operator=(const pe::String& string);
		pe::JsonValue& operator=(const pe::Json& json);
		pe::JsonValue& operator=(const pe::JsonValue& value);

		operator int() const;
		operator float() const;
		operator bool() const;
		operator pe::String() const;
		operator pe::Json() const;

	private:
		friend std::ostream& operator<<(std::ostream& os, const pe::JsonValue& value);
		friend class Json;

	private:
		union
		{
			int m_int;
			float m_float;
			bool m_bool;
			pe::String m_string;
			pe::Json m_json;
		};
		char m_type;
	};
}