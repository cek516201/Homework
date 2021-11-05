#ifndef _Game_H_
#define _Game_H_

#include "SDL.h"
#include <vector>
#include "GameObject.h"

class Game;

typedef Game TheGame;

class Game
{
private:
    Game() {}
    static Game* s_pInstance;

public:
    static Game* Instance()
    {
      if(s_pInstance == 0)
        s_pInstance = new Game();

      return s_pInstance;
    }

    ~Game() {}

    bool init(const char *title, int xpos, int ypos,  int width, int height, int flags);
    void render();
    void update(); 
    bool running();
    void handleEvents();
    void clean();
    void quit() { m_bRunning = false; }

    SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
    vector<GameObject*> m_gameObjects;

    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;

    bool m_bRunning = false;
};

#endif