//
// Created by Karim Ajouz  on 24/01/2025.
//

#include "GameState_LevelSelect.h"

#include <Game/Data/Definitions.h>

#include "GameState_Gameplay.h"


GameState_LevelSelect::GameState_LevelSelect(const ZEngine::GameDataRef& data)
    :
    _data(data),
    _levelButton_1("Play", _data, sf::Vector2f(400.0f, 300.0f), sf::Color::Red, "LevelSelect"),
    _backToMainMenuButton("BackToMain", _data, sf::Vector2f(400.0f, 400.0f), sf::Color::Red, "Menu"),
    _bgSprite(_data->assetManager.TryGetTextureAndLoad("Menu BG", MENU_SCREEN_BACKGROUND_FILEPATH))
{
}

GameState_LevelSelect::~GameState_LevelSelect()
{
}

void GameState_LevelSelect::Init()
{
}

void GameState_LevelSelect::PollEvents()
{
}

void GameState_LevelSelect::Update(float dT)
{
    if (_levelButton_1.Active)
        _data->stateMachine.AddState(std::__1::unique_ptr<GameState>(std::make_unique<GameState_Gameplay>(this->_data)), true);

    if (_backToMainMenuButton.Active)
        _data->stateMachine.RemoveState();


    _levelButton_1.Update(dT);
    _backToMainMenuButton.Update(dT);
}

void GameState_LevelSelect::Draw()
{
    _data->window.clear();

    _data->window.draw(_bgSprite);

    _levelButton_1.Draw();
    _backToMainMenuButton.Draw();

    _data->window.display();
}