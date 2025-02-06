#pragma once
#include "Engine/Core/Agent.h"
#include "Engine/Core/Game.h"

#include <SFML/Graphics.hpp>

class Player : public ZEngine::Agent
{
public:
	Player(const std::string& texPath, sf::Vector2f pos, const ZEngine::GameDataRef& data);
	~Player();

	void Update(float dT);
	void Draw();

	bool TakeDamage(float dam);
	void Respawn();

	sf::Vector2f GetPosition();


	sf::Sprite sprite;
	float health;
	bool dead;

private:
	void Move(float dT);
	ZEngine::GameDataRef _data;
	
	//ZEngine::ResourceBar _healthBar;
	float _speed = 100.0f;
	
	//ZEngine::Timer damageTimer;

};

