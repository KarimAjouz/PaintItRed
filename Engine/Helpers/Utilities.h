#pragma once
#include <SFML/Graphics.hpp>

namespace ZEngine
{

	class Utilities
	{
	public:
		Utilities();
		~Utilities();

		static sf::Vector2f NormaliseVector(sf::Vector2f in);
		static float GetVectorMagnitudeSquared(sf::Vector2f in);
		static float GetVectorMagnitude(sf::Vector2f in);

		static float Random();
		static float Random(float max);
		static float Random(float min, float max);

		static float DistSq(sf::Sprite a, sf::Sprite b);
		static float MinDist(sf::Sprite a, sf::Sprite b);

		static bool CircleCollider(sf::Sprite a, sf::Sprite b);

		static bool RectCollider(sf::FloatRect a, sf::FloatRect b);

		static bool CircleIntRectCollider(sf::Sprite circle, sf::IntRect rect);

		static void SeedRandom();



	};

}