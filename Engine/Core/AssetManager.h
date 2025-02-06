#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace ZEngine
{

	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		sf::Texture &TryGetTextureAndLoad(const std::string InName, const std::string InFilePath = "");

		sf::Font &TryGetFontAndLoad(const std::string InName, const std::string InFilePath = "");

		sf::Texture &TryGetTexture(const std::string InName);
		sf::Font &TryGetFont(const std::string InName);


	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

		void LoadFont(const std::string name, const std::string filePath);
		sf::Font &GetFont(const std::string name);

		void LoadTexture(const std::string name, const std::string filePath);
		sf::Texture &GetTexture(const std::string name);

		void LoadTexturesFromMedia();
		void UnloadTextures();

		void LoadButtons();

		void LoadDebugTexture();
	};


}