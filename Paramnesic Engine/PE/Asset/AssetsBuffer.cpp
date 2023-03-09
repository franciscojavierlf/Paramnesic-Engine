#include "PE/Asset/AssetsBuffer.hpp"

pe::AssetsBuffer::AssetsBuffer()
{

}

pe::AssetsBuffer::~AssetsBuffer()
{
	// Deletes all the loaded assets
	for (unsigned int i = 0; i < m_loadedAssets.length(); i++)
		delete m_loadedAssets.objectAt(i);
}

const pe::Asset* pe::AssetsBuffer::getAsset(const pe::String& path) const
{
	int i = m_loadedAssets.indexOfTag(path);

	// If it is already loaded
	if (i >= 0) return m_loadedAssets.objectAt(i);

	throw pe::FileNotFoundException(path);
}

pe::Asset* pe::AssetsBuffer::getAsset(const pe::String& path)
{
	int i = m_loadedAssets.indexOfTag(path);

	// If it is already loaded
	if (i >= 0) return m_loadedAssets.objectAt(i);

	// If it is not loaded
	return loadAsset(path);
}

pe::Asset* pe::AssetsBuffer::loadAsset(const pe::String& path)
{
	pe::File assetFile(path);
	// Checks if the file type is correct
	if (assetFile.getFileType() != "passet")
		throw pe::Exception("File type incorrect. Must be \".passet!\"");

	// Will crash if the file is not found
	assetFile.open();

	// Debug
	std::cout << "Loaded asset \"" << path << '\"' << std::endl;

	pe::Json assetJson = assetFile.getFileString();
	pe::String type = assetJson.getValue("Type");

	// Loads depending on the type of asset
	if (type == "Sprite")
		loadSprite(assetJson);

	assetFile.close();
}

pe::Sprite* pe::AssetsBuffer::loadSprite(pe::Json assetJson)
{
	pe::Sprite* asset = nullptr;
	pe::String cons = assetJson.getValue("Constructor");

	if (cons == "Rectangle")
	{
		asset = new pe::Sprite(pe::Color(assetJson.getValue("Color")),
			pe::String(assetJson.getValue("Width")).toFloat(),
			pe::String(assetJson.getValue("Height")).toFloat());
	}
	else if (cons == "File")
	{
		asset = new pe::Sprite((pe::String)assetJson.getValue("Path"));
	}

	return asset;
}