#include "Player.h"

#include "Engine/Helpers/Utilities.h"

/// <summary>
/// Constructs the player object, setting its texture.
/// </summary>
/// <param name="texPath"> The filepath for the player texture. </param>
/// <param name="pos"> The position to spwan the player in. </param>
Player::Player(const std::string& texPath, const sf::Vector2f pos, const ZEngine::GameDataRef& data) :
	sprite(data->assetManager.TryGetTextureAndLoad("Player", texPath)),
	_data(data),
	health(100.0f),
	dead(false) //,
//_healthBar(_data, UI_RELOADBAR, "Ammobar", sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 50.0f))
{
	sprite.setOrigin(sprite.getLocalBounds().size / 2.0f);
	sprite.setScale({0.5f, 0.5f});
	sprite.setPosition(pos);

	// _healthBar.Centralise();
	// _healthBar.ReScaleWidth(5.0f);
	// _healthBar.Move(sf::Vector2f(SCREEN_WIDTH / 2, 50.0f));
	// _healthBar.ResizeForeground(1.0f);
}


Player::~Player()
{
}

void Player::Update(float dT)
{
	Move(dT);
}

void Player::Draw()
{
	_data->window.draw(sprite);
}

/// <summary>
/// Handles player movement, also normalises the speed so that diagonal movement isn't faster than omni-directional movement.
/// </summary>
void Player::Move(float dT)
{
	sf::Vector2f movement = sf::Vector2f(0.f, 0.f);
	sf::Vector2f newPos = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		movement.y += -1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		movement.y +=  1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		movement.x += -1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		movement.x +=  1;
	

	movement = ZEngine::Utilities::NormaliseVector(movement);
	newPos += movement * _speed * dT;

	if(!dead)
		sprite.setPosition(newPos);
}

/// <summary>
/// Returns the position of the sprite in the window.
/// </summary>
/// <returns> Returns the sprites position. </returns>
sf::Vector2f Player::GetPosition()
{
	return sprite.getPosition();
}

/// <summary>
/// Handles the player recieving damage.
/// </summary>
/// <param name="dam"></param>
/// <returns> Returns true if the player received damage, false if not. </returns>
bool Player::TakeDamage(float dam)
{
	// if (damageTimer.Complete() && !dead)
	// {
	// 	health -= dam;
	//
	// 	_healthBar.ResizeForeground(health / 100.0f);
	//
	// 	AugmentKnockback(zombiePosition);
	//
	// 	sprite.setColor(sf::Color(sprite.getColor().r, sprite.getColor().g, sprite.getColor().b, 0.5f * 255.0f));
	// 	damageTimer.Start();
	//
	// 	return true;
	//}

	return false;
}

/// <summary>
/// Adds knockback force to the player.
/// </summary>
/// <param name="amt"></param>
// void Player::AugmentKnockback(sf::Vector2f zombiePosition)
// {
// 	sf::Vector2f temp = sprite.getPosition() - zombiePosition;
// 	temp = ZEngine::Utilities::NormaliseVector(temp);
//
// 	temp = temp * 10.0f;
//
// 	_knockbackAmt += temp;
// }

void Player::Respawn()
{
	// Reset the healthbar back to maximum.
	//_healthBar.ResizeForeground(1.0f);

	//sprite.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	health = 100.0f;
	dead = false;
}