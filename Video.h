#ifndef VIDEO_H
#define VIDEO_H

#include "SDL2/SDL.h"

class Video
{
    private:
        Video();

        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        static Video* s_pInstance;

    public:
        static Video* getInstance()
        {
            if(s_pInstance == nullptr){
                s_pInstance = new Video();
            }

            return s_pInstance;
        }
        bool init(const std::string title, int xpos, int ypos, int width, int height, int flags);
        void clean();
        void clear();
        void render();
};

#endif
