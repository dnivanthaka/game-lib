#include <iostream>
#include "SDL2/SDL.h"


#include "Video.h"

Video* Video::s_pInstance = nullptr;

Video::Video()
{

}

bool Video::init(const std::string title, int xpos, int ypos, int width, int height, int flags)
{

    if(SDL_Init(SDL_INIT_VIDEO) == 0){
        m_pWindow = SDL_CreateWindow(title.c_str(), xpos, ypos, width, height, flags);

        if(m_pWindow == NULL){
            std::cerr << "SDL Error: Failed to create window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return false;
        }

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

        if(m_pRenderer == NULL){
            std::cerr << "SDL Error: Failed to create renderer: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(m_pWindow);
            SDL_Quit();
            return false;
        }
    }else{
        std::cerr << "SDL Error: Failed to initialize: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Video::clear()
{
    SDL_RenderClear(m_pRenderer);
}

void Video::render()
{
    SDL_RenderPresent(m_pRenderer);
}

void Video::clean()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);

    SDL_Quit();
}
