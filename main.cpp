#include <iostream>

#include "Engine/Core/Game.h"
#include "Game/Data/Definitions.h"

int main()
{
    ZEngine::Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST");
    return EXIT_SUCCESS;
}