#include "InputManager.h"

namespace ZEngine
{

	InputManager::InputManager()
	{
	}


	InputManager::~InputManager()
	{
	}


	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::RenderWindow &window)
	{
		sf::IntRect rect(
			{
				static_cast<int>(object.getPosition().x - object.getGlobalBounds().size.x / 2),
				static_cast<int>(object.getPosition().y - object.getGlobalBounds().size.y / 2)
			},
			{
				static_cast<int>(object.getGlobalBounds().size.x),
				static_cast<int>(object.getGlobalBounds().size.y)
			});

		if (rect.contains(sf::Mouse::getPosition(window)) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			return true;
		}

		return false;
	}

	bool InputManager::IsSpriteReleased(sf::Sprite object, sf::RenderWindow &window)
	{
		sf::IntRect rect(
			{
				static_cast<int>(object.getPosition().x - object.getGlobalBounds().size.x / 2),
				static_cast<int>(object.getPosition().y - object.getGlobalBounds().size.y / 2)
			},
			{
				static_cast<int>(object.getGlobalBounds().size.x),
				static_cast<int>(object.getGlobalBounds().size.y)
			});

		if (rect.contains(sf::Mouse::getPosition(window)) && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			return true;
		}

		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}
}