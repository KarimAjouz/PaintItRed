#include "GameState_Splash.h"

#include <iostream>

#include "Game/Data/Definitions.h"
#include "GameState_MainMenu.h"

using namespace ZEngine;


GameState_Splash::GameState_Splash(const ZEngine::GameDataRef& data)
	:
	_data(data),
	_bgSprite(data->assetManager.TryGetTextureAndLoad("Splash_BG", SPLASH_SCREEN_BACKGROUND_FILEPATH))
{
}

GameState_Splash::~GameState_Splash()
{
	std::cout << "Splash Screen exit" << std::endl;
}


void GameState_Splash::Init()
{
}

void GameState_Splash::PollEvents()
{
	while (const std::optional event = _data->window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			_data->window.close();
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				_data->window.close();
		}
	}
}

void GameState_Splash::Update(float dT)
{
	if (_clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_SHOW_TIME)
	{
		_data->stateMachine.AddState(std::__1::unique_ptr<GameState>(std::make_unique<GameState_MainMenu>(this->_data)), true);
	}
}

void GameState_Splash::Draw()
{
	_data->window.clear();
	_data->window.draw(_bgSprite);
	_data->window.display();
}