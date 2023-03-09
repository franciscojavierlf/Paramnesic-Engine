#pragma once

#include <iostream>
#include <fstream>
#include "PE/Utils/Exceptions/FileNotFoundException.hpp"
#include "PE/Utils/Json.hpp"
#include "PE/Utils/StringBuilder.hpp"

namespace pe
{
	class File final
	{
	public:
		File(const pe::String& path);
		~File();

		void open();
		void close();

		pe::String getFileType() const;
		// Returns a reference to avoid a double copy,
		// since the string can get pretty big
		const pe::String& getFileString();

	private:
		pe::String m_path;
		std::ifstream m_stream;
		bool isOpened;
		pe::String m_fileString;
	};

}