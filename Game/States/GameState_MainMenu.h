#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Engine/Core/GameState.h"
#include "Engine/UI/Button.h"

#include "Game/Data/Definitions.h"


class GameState_MainMenu : public ZEngine::GameState
{
public:
	GameState_MainMenu(const ZEngine::GameDataRef& data);
	virtual ~GameState_MainMenu();

	void Init() override;
	
	void PollEvents() override;
	void Update(float dT) override;
	void Draw() override;

private:
	ZEngine::GameDataRef _data;

	sf::Sprite _bgSprite;

	ZEngine::Button _playButton;
	ZEngine::Button _quitButton;

	
};

