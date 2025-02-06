//
// Created by Karim Ajouz  on 24/01/2025.
//

#include "Splatter.h"

#include <iostream>
#include <Engine/Helpers/Utilities.h>

#include "FloorCanvas.h"
#include "Engine/Helpers/ErrorLogging.h"

bool Splatter::GenerateSplatter(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Color InColor, ESplatterType InType)
{
    if (!InFloor)
    {
        ZEngine::ErrorLogging::LogWarning("Splatter::GenerateSplatter: InFloor can't be null!");
        return false;
    }

    switch (InType)
    {
    case ESplatterType::SPLATTYPE_SPLAT:
        MakeSplat(InFloor, InPos, InMagnitude, InColor);
        break;
    case ESplatterType::SPLATTYPE_STREAK:
        //MakeStreak(InFloor, InPos, InMagnitude, InDir, InColor);
        break;
    case ESplatterType::SPLATTYPE_LEAK:
        MakeLeak(InFloor, InPos, InMagnitude, InColor);
        break;
    default:
        break;
    }
    return true;
}

void Splatter::MakeSplat(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Color InColor)
{
    // We call MakeSplat recursively so we need an early exit for when edge splatters are too small.
    if (InMagnitude < 1.0f)
        return;

    // Generate a list of edge splatters
    InFloor->PaintCanvasCircle(InPos, InMagnitude, InColor);

    for (int i = 0; i < InMagnitude / 3; i++)
    {
        float angle = ZEngine::Utilities::Random(-1, 1) * M_PI * 2;
        int x = std::cos(angle) * (InMagnitude + ZEngine::Utilities::Random(InMagnitude / 2));
        int y = std::sin(angle) * (InMagnitude + ZEngine::Utilities::Random(InMagnitude / 2));

        x += InPos.x;
        y += InPos.y;

        // sf::Color newColor;
        //
        // if (InColor == sf::Color::Red)
        //     newColor = sf::Color::Green;
        // else if (InColor == sf::Color::Green)
        //     newColor = sf::Color::Blue;
        // else if (InColor == sf::Color::Blue)
        //     newColor = sf::Color::Magenta;
        // else if (InColor == sf::Color::Magenta)
        //     newColor = sf::Color::Yellow;

        MakeSplat(InFloor, sf::Vector2u({static_cast<unsigned>(x), static_cast<unsigned>(y)}), InMagnitude / 3, InColor);
    }

    // Push this splatter
}

void Splatter::MakeStreak(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Vector2u InDir, sf::Color InColor)
{

}

void Splatter::MakeLeak(FloorCanvas* InFloor, sf::Vector2u InPos, float InMagnitude, sf::Color InColor)
{

}
