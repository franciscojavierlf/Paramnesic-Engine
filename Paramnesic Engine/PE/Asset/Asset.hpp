#pragma once

#include "PE/Utils/String.hpp"

namespace pe
{
	// Abstract class Asset
	class Asset
	{
	public:
		Asset(const pe::String& path);
		virtual ~Asset();

		const pe::String& getName() const;
		void setName(const char* name);

		const pe::String& toString() const;

	protected:
		// For generic names
		Asset(const char* type, const unsigned int& count);

	private:
		pe::String m_path;
		pe::String m_name;
	};
}