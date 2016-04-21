#include "SDL2/SDL.h"

#include "Game.h"

Game* g_pGame = nullptr;

int main(int argc, char* argv[])
{
    g_pGame = new Game();

    g_pGame->init("Game Window", 100, 100, 800, 600, 0);

    while(g_pGame->running()){
        g_pGame->handleEvents();
        g_pGame->update();
        g_pGame->render();

        SDL_Delay(10);
    }

    return 0;
}
