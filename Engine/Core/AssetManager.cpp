#include "AssetManager.h"

#include <iostream>
#include <filesystem>
#include <Game/Data/Definitions.h>

#include "Engine/Helpers/ErrorLogging.h"

namespace ZEngine
{

	AssetManager::AssetManager()
	{
		_textures = std::map<std::string, sf::Texture>();

		LoadTexturesFromMedia();
	}


	AssetManager::~AssetManager()
	{

	}

	sf::Texture& AssetManager::TryGetTextureAndLoad(const std::string InName, const std::string InFilePath)
	{
		if (InFilePath == "")
		{
			return GetTexture(InName);
		}

		LoadTexture(InName, InFilePath);
		return GetTexture(InName);
	}

	sf::Font& AssetManager::TryGetFontAndLoad(const std::string InName, const std::string InFilePath)
	{
		LoadFont(InName, InFilePath);
		return GetFont(InName);
	}

	sf::Texture& AssetManager::TryGetTexture(const std::string InName)
	{
		return GetTexture(InName);
	}

	sf::Font& AssetManager::TryGetFont(const std::string InName)
	{
		return GetFont(InName);
	}


	void AssetManager::LoadTexture(const std::string name, const std::string filePath)
	{
		int count = _textures.count(name);
		if (count == 0)
		{
			if (sf::Texture tex; tex.loadFromFile(filePath))
				_textures[name] = tex;
			else
				ErrorLogging::FatalError("AssetManager::LoadTexture - Failed to load " + name + " at filepath " + filePath);
		}

	}

	sf::Texture & AssetManager::GetTexture(const std::string name)
	{
		if (_textures.count(name) == 1)
			return this->_textures.at(name);

		ErrorLogging::LogWarning("AssetManager::GetTexture - Failed to get " + name);
		return _textures["DEBUG"];
	}



	void AssetManager::LoadFont(const std::string name, const std::string filePath)
	{
		if (_fonts.count(name) == 0)
		{
			if (sf::Font font; font.openFromFile(filePath))
				this->_fonts[name] = font;
			else
				throw std::runtime_error("AssetManager::LoadFont - Failed to load " + name + " at filepath " + filePath);
		}
	}

	sf::Font & AssetManager::GetFont(const std::string name)
	{
		if (_fonts.count(name) == 1)
			return this->_fonts.at(name);
		else
			throw std::runtime_error("AssetManager::GetFont - Failed to get " + name);
	}

	void AssetManager::LoadTexturesFromMedia()
	{
		LoadDebugTexture();
		LoadButtons();
	}

	void AssetManager::LoadButtons()
	{
		std::filesystem::path UIPath = std::filesystem::path(std::filesystem::current_path().string() + BUTTON_FOLDER_FILEPATH);

		if (!std::filesystem::exists(UIPath))
		{
			ErrorLogging::LogError("Filesystem can not find: " + UIPath.string());
			return;
		}

		if (!std::filesystem::is_directory(UIPath))
		{
			ErrorLogging::LogError("Path: " + UIPath.string() + " is not a directory!");
			return;
		}

		for (const auto& ButtonFolder : std::filesystem::directory_iterator(UIPath))
		{
			if (ButtonFolder.path().stem() == ".DS_Store")
			{
				continue;
			}

			if (!std::filesystem::is_directory(ButtonFolder.path()))
			{
				ErrorLogging::LogError("Path: " + ButtonFolder.path().string() + " is not a directory!");
				return;
			}

			std::string ButtonName = ButtonFolder.path().stem().string();

			for (const auto& item : std::filesystem::directory_iterator(ButtonFolder.path()))
			{
				// First we have to clean up the path so that SFML looks in the correct place
				std::string filePath = item.path().string();
				int pathStart = filePath.find("Media");
				if (pathStart != std::string::npos)
				{
					filePath = filePath.substr(pathStart, filePath.length() - pathStart);
				}

				// Then we can start to parse the individual parts of the button
				// #TODO [KA]: Add in audio loading here for buttons.
				if (item.path().extension() == ".png")
				{
					if (item.path().stem().string() == "Default")
					{
						LoadTexture(ButtonName + "_DEFAULT", filePath);
					}
					else if (item.path().stem().string() == "Hovered")
					{
						LoadTexture(ButtonName + "_HOVERED", filePath);
					}
					else if (item.path().stem().string() == "Clicked")
					{
						LoadTexture(ButtonName + "_CLICKED", filePath);
					}
				}
				else if (item.path().extension() == ".ttf")
				{
					LoadFont(ButtonName + "_FONT", filePath);
				}
			}
		}
	}

	void AssetManager::LoadDebugTexture()
	{
		std::filesystem::path DebugTexturePath = std::filesystem::path(std::filesystem::current_path().string() + DEBUG_TEXTURE_FILEPATH);
	}
}
