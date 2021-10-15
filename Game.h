#ifndef _Game_H_
#define _Game_H_

#include "SDL.h"
#include "Player.h"

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
    GameObject m_gameobject;
    Player m_player;

    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;

    bool m_bRunning = false;

    int m_currentRow = 0;
    int m_currentFrame = 0;
};

#endif