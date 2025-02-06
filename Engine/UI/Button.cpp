#include "Button.h"

#include <Game/Data/Definitions.h>

namespace ZEngine
{

	Button::Button(const std::string& text, const GameDataRef& data, const sf::Vector2f pos, const sf::Color textColour, std::string  fileName) :
		_data(data),
		_textColour(textColour),
		Engaged(false),
		Active(false),
		_fileName(std::move(fileName)),
		sprite(data->assetManager.TryGetTexture(fileName + "_DEFAULT")),
		_text(data->assetManager.TryGetFont(fileName + "_FONT"))
	{
		_textureDefault = _data->assetManager.TryGetTextureAndLoad(_fileName + "_DEFAULT");
		_textureHovered = _data->assetManager.TryGetTextureAndLoad(_fileName + "_HOVERED");
		_textureClicked = _data->assetManager.TryGetTextureAndLoad(_fileName + "_CLICKED");
		_font = _data->assetManager.TryGetFontAndLoad(_fileName + "_FONT");

		sprite.setPosition(pos);
		_text.setString(text);
		_text.setFillColor(textColour);
		_text.setPosition(pos);

		sprite.setOrigin(sprite.getLocalBounds().size / 2.0f);
		_text.setOrigin(_text.getLocalBounds().size / 2.0f);
	}

	Button::~Button()
	= default;

	void Button::Init()
	{
	}

	void Button::Update(float dT)
	{
		Active = false;

		const sf::IntRect rect(
			sf::Vector2<int>(sprite.getPosition() - (sprite.getGlobalBounds().size / 2.0f)),
			sf::Vector2<int>(sprite.getGlobalBounds().size));

		if (rect.contains(sf::Mouse::getPosition(_data->window)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			Engaged = true;
		
		if (Engaged && !rect.contains(sf::Mouse::getPosition(_data->window)))
			Engaged = false;

		if (rect.contains(sf::Mouse::getPosition(_data->window)) && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && Engaged)
			Activate();

		if (rect.contains(sf::Mouse::getPosition(_data->window)) && !Engaged)
		{
			SetHovered();
		}
		else if (rect.contains(sf::Mouse::getPosition(_data->window)) && Engaged)
		{
			SetClicked();
		}
		else
		{
			SetDefault();
		}
	}

	void Button::Activate()
	{
		Active = true;
		Engaged = false;
	}

	void Button::Draw()
	{
		_data->window.draw(sprite);
		_data->window.draw(_text);
	}

	void Button::SetDefault()
	{
		sprite.setTexture(_textureDefault);
	}

	void Button::SetHovered()
	{
		sprite.setTexture(_textureHovered);
	}

	void Button::SetClicked()
	{
		sprite.setTexture(_textureClicked);
	}

}
