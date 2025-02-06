#include "GameState_Gameplay.h"
#include "Game/Data/Definitions.h"

#include "Engine/Helpers/Utilities.h"

#include "Game/Gameplay/FloorCanvas.h"
#include "Game/Gameplay/Splatter.h"


/// <summary>
/// Creates the Gameplay Gamestate.
/// </summary>
/// <param name="data"></param>
GameState_Gameplay::GameState_Gameplay(ZEngine::GameDataRef data) :
	player(PLAYER_FILEPATH, sf::Vector2f(400.0f, 300.0f), data),
	_data(data),
	_paused(false),
	_floorCanvas(
		new FloorCanvas(
			data,
			sf::Vector2u(200, 200),
			sf::Vector2u(50, 50)))
{
	ZEngine::Utilities::SeedRandom();

	_drawingCircle.setFillColor(sf::Color::Transparent);
	_drawingCircle.setOutlineColor(sf::Color::Magenta);
	_drawingCircle.setOutlineThickness(1);

	_drawingCircle.setRadius(5);
	_drawingCircle.setOrigin(sf::Vector2f({5, 5}));
}


GameState_Gameplay::~GameState_Gameplay()
{
}

void GameState_Gameplay::Init()
{
}

/// <summary>
/// Handles Input Events.
/// </summary>
void GameState_Gameplay::PollEvents()
{
	while (const std::optional event = _data->window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			_data->window.close();
		}

		if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				_data->window.close();
			else if (keyPressed->scancode == sf::Keyboard::Scancode::Space)
			{
				_floorCanvas->ClearCanvas();
			}
		}

		if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
		{
			if (mousePressed->button == sf::Mouse::Button::Left)
			{
				//_lPressed = true;
			}
			else if (mousePressed->button == sf::Mouse::Button::Right)
			{
				//_rPressed = true;
			}
		}

		if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>())
		{
			if (mouseReleased->button == sf::Mouse::Button::Left)
			{
				if (_perm)
				{
					Splatter::GenerateSplatter(
						_floorCanvas,
						sf::Vector2u(sf::Mouse::getPosition(_data->window)),
						20.0f,
						sf::Color::Red,
						ESplatterType::SPLATTYPE_SPLAT);
				}

				//_lPressed = false;
			}
			else if (mouseReleased->button == sf::Mouse::Button::Right)
			{
				//_rPressed = false;
			}
		}

		if (const auto* mouseLeft = event->getIf<sf::Event::MouseLeft>())
		{
			_perm = false;
		}

		if (const auto* mouseEntered = event->getIf<sf::Event::MouseEntered>())
		{
			_perm = true;
		}
	}
}


/// <summary>
/// Updates Gameplay entities.
/// </summary>
/// <param name="dT"></param>
void GameState_Gameplay::Update(float dT)
{
	if (!_paused)
	{
		player.Update(dT);
	}


	if (!_perm)
	{
		return;
	}

	sf::Vector2u pos = sf::Vector2u(sf::Mouse::getPosition(_data->window));

	// if (_lPressed)
	// {
	// 	_floorCanvas->PaintToCanvas(pos, sf::Color::Red);
	// }
	// if (_rPressed)
	// {
	// 	_floorCanvas->PaintToCanvas(pos, sf::Color::Green);
	// }

	_drawingCircle.setPosition(sf::Vector2f(sf::Mouse::getPosition(_data->window)));
	_floorCanvas->Update(dT);
}

/// <summary>
/// Draws Gameplay entities.
/// </summary>
void GameState_Gameplay::Draw()
{
	_data->window.clear();

	_floorCanvas->Draw();

	_data->window.draw(_drawingCircle);

	_data->window.display();
}

void GameState_Gameplay::Pause()
{
	_paused = true;
}

void GameState_Gameplay::Resume()
{
	_paused = false;
}

/// <summary>
/// Exits the game, clearing loaded memory.
/// </summary>
void GameState_Gameplay::Exit()
{
	_data->window.close();
}
