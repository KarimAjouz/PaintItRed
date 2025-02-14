#pragma once
#include "Button.h"



namespace ZEngine
{
	class Menu_Scale
	{
	public:
		Menu_Scale(const std::string& name, int min, int max, int interval, int currentVal, sf::Vector2f pos, const GameDataRef& data);
		~Menu_Scale();

		void Update(float dT);
		void Draw();

		int GetValue() const;


	protected:

		sf::Text _scaleText;

		std::string _name;
		int _min;
		int _max;
		int _interval;
		int _currentVal;

		GameDataRef _data;

		sf::Vector2f _pos;

		bool TestRight() const;
		bool TestLeft() const;

		Button _lArrow;
		Button _rArrow;

		int _steps;

		void LeftAction();
		void RightAction();


	};

}