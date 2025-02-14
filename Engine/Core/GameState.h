#pragma once
#include <SFML/Graphics.hpp>

namespace ZEngine
{
	class GameState
	{
	public:
		GameState();
		virtual ~GameState();

	public:
		// Initialiser
		virtual void Init() = 0;

		// Polls input events.
		virtual void PollEvents() = 0;

		// Updates game logic for the state.
		virtual void Update(float dT) = 0;

		// Draws to the display. 
		virtual void Draw() = 0;


		// Pauses/Resumes the state we're in.
		virtual void Pause() { }
		virtual void Resume() { }

	};

	typedef std::unique_ptr<GameState> StateRef;

}
