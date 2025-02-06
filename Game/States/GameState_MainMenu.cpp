#include "GameState_MainMenu.h"

#include "GameState_LevelSelect.h"
#include "Game/States/GameState_Gameplay.h"
#include "Game/Data/Definitions.h"




GameState_MainMenu::GameState_MainMenu(const ZEngine::GameDataRef& data)
	:
		_data(data),
		_bgSprite(_data->assetManager.TryGetTextureAndLoad("Menu BG", MENU_SCREEN_BACKGROUND_FILEPATH)),
		_playButton("Play", _data, sf::Vector2f(400.0f, 300.0f), sf::Color::Red, "Menu"),
		_quitButton("Quit", _data, sf::Vector2f(400.0f, 400.0f), sf::Color::Red, "Menu")
{


}


GameState_MainMenu::~GameState_MainMenu()
{
}

void GameState_MainMenu::Init()
{
}

void GameState_MainMenu::PollEvents()
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

void GameState_MainMenu::Update(float dT)
{
	if (_playButton.Active)
		_data->stateMachine.AddState(std::__1::unique_ptr<GameState>(std::make_unique<GameState_LevelSelect>(this->_data)), false);

	if (_quitButton.Active)
		_data->window.close();


	_playButton.Update(dT);
	_quitButton.Update(dT);
}

void GameState_MainMenu::Draw()
{
	_data->window.clear();

	_data->window.draw(_bgSprite);

	_playButton.Draw();
	_quitButton.Draw();
	
	_data->window.display();
}