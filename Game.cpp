#include <string>

#include "SDL2/SDL.h"
#include "Video.h"
#include "Game.h"

Game::Game()
{
    video = Video::getInstance();
}

Game::~Game()
{
    video->clean();
}

void Game::init(std::string title, int xpos, int ypos, int width, int height, int flags)
{
    video->init(title, xpos, ypos, width, height, flags);
}


void Game::handleEvents()
{
    SDL_Event event;

    if(SDL_PollEvent(&event)){
       switch(event.type){
        case SDL_QUIT:
            m_bGameRunning = false;
            break;

        default:
            break;

       } 
    }
}

void Game::update()
{

}

void Game::render()
{
    video->render();
}

bool Game::running()
{
    return m_bGameRunning;
}
