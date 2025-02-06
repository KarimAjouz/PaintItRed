//
// Created by Karim Ajouz  on 23/01/2025.
//

#pragma once

#include "Engine/Core/Game.h"




class FloorCanvas
{
public:
    FloorCanvas
    (
        const ZEngine::GameDataRef& data,
        sf::Vector2u size,
        sf::Vector2u resolution
    );

    ~FloorCanvas();

    void Update(float dT);
    void Draw();

    void PaintToCanvas(sf::Vector2u InPos, sf::Color InColor);

    void PaintCanvasCircle(sf::Vector2u InPos, int size, sf::Color InColor);

    void ClearCanvas();

    float CurrentBlackPercentage = 100.0f;
    float CurrentRedPercentage = 0.0f;
    float CurrentGreenPercentage = 0.0f;



private:
    ZEngine::GameDataRef _data;

    sf::RectangleShape _canvasBorder;
    sf::RenderTexture _renderTex;
    sf::Texture _floorTex;
    sf::Texture _bufferTex;
    sf::Image _floorImage;

    sf::Sprite _floorSprite;

    sf::Vector2u _resolution;

    int _maxPixels = 0;
    int _blackPixels = 0;
    int _redPixels = 0;
    int _greenPixels = 0;

    int _resolutionFactor = 0;

    void PaintCanvasPixel(sf::Vector2u InPos, sf::Color InColor);


};

