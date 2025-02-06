#pragma once

namespace ZEngine
{
	class Agent
	{
	public:
		Agent();
		~Agent();

		virtual void Update(float dT) = 0;
		virtual void Draw() = 0;

	private:
	};

}