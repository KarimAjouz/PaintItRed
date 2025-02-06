//
// Created by Karim Ajouz  on 24/01/2025.
//
#pragma once


#include <Engine/Core/Game.h>
#include <Engine/UI/Button.h>

struct FLevel
{
public:

    sf::Vector2u size;
    sf::Vector2u resolution;

    sf::Color GoalColor;
    int GoalPercentage;

    bool bCompleted = false;

    FLevel(sf::Vector2u InSize, sf::Vector2u InResolution, sf::Color InGoalColor, int InGoalPercentage)
    {
        size = InSize;
        resolution = InResolution;
        GoalColor = InGoalColor;
        GoalPercentage = InGoalPercentage;
    }

    void MarkCompleted() { bCompleted = true; }

};


class GameState_LevelSelect : public ZEngine::GameState
{
public:
    GameState_LevelSelect(const ZEngine::GameDataRef& data);
    virtual ~GameState_LevelSelect();

    void Init() override;

    void PollEvents() override;
    void Update(float dT) override;
    void Draw() override;

private:
    ZEngine::GameDataRef _data;

    ZEngine::Button _levelButton_1;

    ZEngine::Button _backToMainMenuButton;
    std::vector<ZEngine::Button*> _levelButtons;
    sf::Sprite _bgSprite;

};

