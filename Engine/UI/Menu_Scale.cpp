#include "Menu_Scale.h"

#include "Game/Data/Definitions.h"

namespace ZEngine
{
	Menu_Scale::Menu_Scale(const std::string& name, const int min, const int max, const int interval, const int currentVal, const sf::Vector2f pos, const GameDataRef& data) :
		_scaleText(data->assetManager.TryGetFontAndLoad("Scale Font", static_cast<std::string>(SCALE_BUTTON_FOLDER_FILEPATH) + "Font.ttf"),name + ": " + std::to_string(currentVal)),
		_name(name),
		_min(min),
		_max(max),
		_interval(interval),
		_currentVal(currentVal),
		_data(data),
		_pos(pos),
		_lArrow("<", data, pos, sf::Color::Black, "Scale Button"),
		_rArrow(">", data, sf::Vector2f(pos.x + 200.0f, pos.y), sf::Color::Black,
		        "Scale Button"),
		_steps((max - min) / interval)
	{
		_scaleText.setPosition(sf::Vector2f(_pos.x + 100.0f, _pos.y));
		_scaleText.setFillColor(sf::Color::Black);
		_scaleText.setString(_name + ": " + std::to_string(_currentVal));
	}

	Menu_Scale::~Menu_Scale()
	= default;

	void Menu_Scale::Update(const float dT)
	{
		if (TestLeft())
			LeftAction();

		if (TestRight())
			RightAction();

		_lArrow.Update(dT);
		_rArrow.Update(dT);

		_scaleText.setString(_name + ": " + std::to_string(_currentVal));
		_scaleText.setOrigin({_scaleText.getLocalBounds().size.x / 2, _scaleText.getLocalBounds().size.y / 2});
	}

	void Menu_Scale::Draw()
	{
		_lArrow.Draw();
		_rArrow.Draw();

		_data->window.draw(_scaleText);
	}
	
	int Menu_Scale::GetValue() const
	{
		return _currentVal;
	}

	bool Menu_Scale::TestLeft() const
	{
		if (_lArrow.Active)
			return true;

		return false;
	}

	bool Menu_Scale::TestRight() const
	{
		if (_rArrow.Active)
			return true;

		return false;
	}

	void Menu_Scale::LeftAction()
	{
		if(_currentVal > _min)
			_currentVal -= _interval;
	}

	void Menu_Scale::RightAction()
	{
		if (_currentVal < _max)
			_currentVal += _interval;
	}
}