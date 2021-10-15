// 완료한 단계 : 7주차 상속, 다형성

#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
    g_game = new Game();
    g_game->init("Test", 100, 100, 600, 300, 0);
    
    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
        SDL_Delay(10);
    }
    
    g_game->clean();
    return 0;
}