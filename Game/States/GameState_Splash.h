#pragma once

#include <SFML/Graphics.hpp>

#include "Engine/Core/Game.h"
#include "Engine/Core/GameState.h"

class GameState_Splash : public ZEngine::GameState
{
public:
	GameState_Splash(const ZEngine::GameDataRef& data);

protected:
	~GameState_Splash();

public:
	void Init() override;

	void PollEvents() override;

	void Update(float dT) override;

	void Draw() override;

private:
	ZEngine::GameDataRef _data;

	sf::Clock _clock;
	sf::Sprite _bgSprite;

};