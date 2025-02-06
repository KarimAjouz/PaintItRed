//
// Created by Karim Ajouz  on 24/01/2025.
//

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

enum ESplatterType
{
    SPLATTYPE_NONE,
    SPLATTYPE_SPLAT,
    SPLATTYPE_STREAK,
    SPLATTYPE_LEAK,
    COUNT
};

class FloorCanvas;

class Splatter
{
public:
    // Returns true when a splatter is generated successfully
    static bool GenerateSplatter(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Color InColor, ESplatterType InType);

private:

    static void MakeSplat(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Color InColor);
    static void MakeStreak(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Vector2u InDir, sf::Color InColor);
    static void MakeLeak(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Color InColor);

};