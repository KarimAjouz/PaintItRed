#pragma once
#include "Engine/Core/GameState.h"
#include "Engine/Core/Game.h"
#include "Game/Agents/Player.h"
//#include "Bullet.h"
//#include "Spawner.h"

#include <vector>

// Forward Declarations
class FloorCanvas;

class GameState_Gameplay : public ZEngine::GameState
{
public:
	GameState_Gameplay(ZEngine::GameDataRef _data);
	~GameState_Gameplay();

	void Init();

	void PollEvents();
	void Update(float dT);
	void Draw();

	void Pause();
	void Resume();

	Player player;


private:
	ZEngine::GameDataRef _data;

	bool _paused;
	bool _lPressed = false;
	bool _rPressed = false;
	bool _perm = false;

	FloorCanvas* _floorCanvas;

	sf::CircleShape _drawingCircle;


	void Exit();
};

