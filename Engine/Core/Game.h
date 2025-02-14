#pragma once

#include <SFML/Graphics.hpp>

#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace ZEngine
{

	struct GameData
	{
		StateMachine stateMachine;
		sf::RenderWindow window;
		AssetManager assetManager;
		InputManager inputManager;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, const std::string& title);
		~Game();


	private:
		const float _dt = 1.0f / 60.0f;
		sf::Clock _clock;
		
		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};

}
