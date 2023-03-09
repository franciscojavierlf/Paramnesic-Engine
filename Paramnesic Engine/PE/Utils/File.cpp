#include "PE/Utils/File.hpp"

pe::File::File(const pe::String& path) : m_path(path), isOpened(false)
{

}

pe::File::~File()
{

}

void pe::File::open()
{
	m_stream.open((const char*)m_path);

	// Throws an exception if the file is not found
	if (!m_stream.is_open())
		throw pe::FileNotFoundException(m_path);

	// If it was opened correctly
	isOpened = true;
}

void pe::File::close()
{
	m_stream.close();
}

pe::String pe::File::getFileType() const
{
	int i = m_path.find(".", -1);

	if (i < 0) throw pe::Exception("File has no type.");

	return m_path.substring(i + 1, -1);
}

const pe::String& pe::File::getFileString()
{
	pe::StringBuilder dataStr;
	std::string aux;

	// Checks if the file was opened correctly
	if (!isOpened) throw pe::Exception("File was not opened correctly.");

	// Appends all the lines of the file
	while (std::getline(m_stream, aux))
		dataStr.append(aux);

	m_fileString = dataStr.toString();

	return m_fileString;
}