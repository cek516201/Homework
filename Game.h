#ifndef _Game_H_
#define _Game_H_

#include "SDL.h"
#include <vector>
#include "GameObject.h"

using namespace std;

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
    vector<GameObject*> m_gameObjects;

    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;

    bool m_bRunning = false;
};

#endif