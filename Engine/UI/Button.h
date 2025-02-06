#pragma once

#include <SFML/Graphics.hpp>
#include "Engine/Core/Game.h"



namespace ZEngine
{
	class Button
	{
	public:

		Button(const std::string& text, const GameDataRef& data, sf::Vector2f pos, sf::Color textColour, std::string fileName);
		~Button();

		sf::Sprite sprite;
		
		void Init();
		void Update(float dT);
		void Draw();

		bool Engaged;
		bool Active;

		void Activate();

	private:
		GameDataRef _data;
		sf::Font _font;
		sf::Text _text;
		sf::Color _textColour;

		sf::Texture _textureDefault;
		sf::Texture _textureHovered;
		sf::Texture _textureClicked;

		std::string _fileName;

		void SetDefault();
		void SetHovered();
		void SetClicked();


	};


}