#ifndef GAME_H
#define GAME_H

#include <string>
#include "SDL2/SDL.h"

#include "Video.h"

class Game
{
    public:
        Game();
        ~Game();
        void init(std::string title, int xpos, int ypos, int width, int height, int flags);
        void handleEvents();
        void update();
        void render();
        bool running();

    private:
        bool m_bGameRunning = true;
        Video* video = nullptr;

};
#endif
