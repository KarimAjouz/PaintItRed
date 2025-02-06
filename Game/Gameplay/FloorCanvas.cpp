//
// Created by Karim Ajouz  on 23/01/2025.
//

#include "FloorCanvas.h"

#include <iostream>
#include <Engine/Helpers/Utilities.h>
#include <Game/Data/Definitions.h>

FloorCanvas::FloorCanvas(const ZEngine::GameDataRef& data, sf::Vector2u size, sf::Vector2u resolution)
    :
    _data(data),
	_renderTex(size),
    _floorSprite(_floorTex),
    _resolution(resolution)
{
    _resolutionFactor = size.x / resolution.x;

    ClearCanvas();

    _floorSprite.setOrigin(static_cast<sf::Vector2f>(size) / 2.0f);
    _floorSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f));

    _canvasBorder.setSize(static_cast<sf::Vector2f>(size + sf::Vector2u{5, 5}));
    _canvasBorder.setOrigin(_canvasBorder.getSize() / 2.0f);

    _canvasBorder.setPosition(_floorSprite.getPosition());
    _canvasBorder.setFillColor(sf::Color::Transparent);
    _canvasBorder.setOutlineColor(sf::Color::White);
    _canvasBorder.setOutlineThickness(5);
}

FloorCanvas::~FloorCanvas()
{
}

void FloorCanvas::Update(float dT)
{
    _floorTex.update(_floorImage);
    sf::Sprite FloorSpriteBuffer = _floorSprite;
    _floorSprite = sf::Sprite(_floorTex);
    _floorSprite.setOrigin(FloorSpriteBuffer.getOrigin());
    _floorSprite.setPosition(FloorSpriteBuffer.getPosition());
}

void FloorCanvas::Draw()
{
    _data->window.draw(_canvasBorder);
    _data->window.draw(_floorSprite);
}

void FloorCanvas::PaintToCanvas(sf::Vector2u InPos, sf::Color InColor)
{
    if (_floorSprite.getGlobalBounds().contains(sf::Vector2<float>(InPos)))
        PaintCanvasCircle(InPos, 5, InColor);
}

void FloorCanvas::ClearCanvas()
{
    _renderTex.clear(sf::Color::Black);
    _floorTex = _renderTex.getTexture();
    _floorImage = _renderTex.getTexture().copyToImage();

    _maxPixels = _resolution.x * _resolution.y;
    _blackPixels = _maxPixels;
    _redPixels = 0;
    _greenPixels = 0;

    CurrentBlackPercentage = 100.0f;
    CurrentRedPercentage = 0.0f;
    CurrentGreenPercentage = 0.0f;
}

void FloorCanvas::PaintCanvasCircle(sf::Vector2u InPos, int radius, sf::Color InColor)
{
    sf::Vector2u PosNormalized = InPos;
    PosNormalized.x += _floorSprite.getOrigin().x;
    PosNormalized.x -= _floorSprite.getPosition().x;

    PosNormalized.y += _floorSprite.getOrigin().y;
    PosNormalized.y -= _floorSprite.getPosition().y;

    std::vector<sf::Vector2u> OverlappingPixels;
    sf::IntRect OverlappingSquare(sf::Vector2<int>(PosNormalized), sf::Vector2i({radius * 2, radius * 2}));
    int minX =  OverlappingSquare.position.x - radius;
    int minY =  OverlappingSquare.position.y - radius;

    float resFactorF = _resolutionFactor;
    float radSquared = radius * radius;

    for (float x = (minX - minX % (_resolutionFactor) + (resFactorF / 2)); x < PosNormalized.x + radius; x += _resolutionFactor)
    {
        for (float y = (minY - minY % (_resolutionFactor) + (resFactorF / 2)); y < PosNormalized.y + radius; y += _resolutionFactor)
        {
            float distSquared = ZEngine::Utilities::GetVectorMagnitudeSquared(sf::Vector2f({x, y}) - sf::Vector2f(PosNormalized));
            if (distSquared < radSquared)
            {
                const unsigned baseX = static_cast<int>(x - resFactorF / 2);
                const unsigned baseY = static_cast<int>(y - resFactorF / 2);

                PaintCanvasPixel(sf::Vector2u({baseX, baseY}), InColor);
            }
        }
    }
}

void FloorCanvas::PaintCanvasPixel(sf::Vector2u InPosGlobal, sf::Color InColor)
{
    sf::Vector2u PosNormalized = InPosGlobal;

    if (PosNormalized.x < 0
        || PosNormalized.x >= _renderTex.getSize().x
        || PosNormalized.y < 0
        || PosNormalized.y >= _renderTex.getSize().y)
    {
        return;
    }

    if (const sf::Color CurrentColor = _floorImage.getPixel(PosNormalized); CurrentColor != InColor)
    {
        const int baseX = static_cast<int>(PosNormalized.x - PosNormalized.x % _resolutionFactor);
        const int baseY = static_cast<int>(PosNormalized.y - PosNormalized.y % _resolutionFactor);


        for (unsigned x = baseX; x < baseX + _resolutionFactor; x++)
        {
            for (unsigned y = baseY; y < baseY + _resolutionFactor; y++)
            {
                _floorImage.setPixel({x ,y}, InColor);
            }
        }

        if (InColor == sf::Color::Red)
            _redPixels++;
        else if (InColor == sf::Color::Green)
            _greenPixels++;

        if (CurrentColor == sf::Color::Black)
            _blackPixels--;
        else if (CurrentColor == sf::Color::Red)
            _redPixels--;
        else if (CurrentColor == sf::Color::Green)
            _greenPixels--;

        CurrentBlackPercentage = static_cast<float>(_blackPixels * 100) / static_cast<float>(_maxPixels);
        CurrentRedPercentage = static_cast<float>(_redPixels * 100) / static_cast<float>(_maxPixels);
        CurrentGreenPercentage = static_cast<float>(_greenPixels * 100) / static_cast<float>(_maxPixels);

        std::cout << CurrentBlackPercentage << std::endl;
        std::cout << CurrentRedPercentage << std::endl;
        std::cout << CurrentGreenPercentage << std::endl;
    }

}
