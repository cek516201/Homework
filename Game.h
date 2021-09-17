#ifndef __Game__
#define __Game__

#include "SDL.h"

class Game
{
public:
    Game() {}
    ~Game() {}

    bool init(const char *title, int xpos, int ypos,  int width, int height, int flags);
    void render();
    void update(); 
    bool running();
    void handleEvents();
    void clean();

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
    
    SDL_Texture* m_pTexture; 
    SDL_Rect m_sourceRectangle; // 원본 상자
    SDL_Rect m_destinationRectangle; // 대상 상자

    SDL_Texture* m_pTexture2; 
    SDL_Rect m_sourceRectangle2; // 원본 상자
    SDL_Rect m_destinationRectangle2; // 대상 상자
};

#endif