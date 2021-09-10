// 창을 3번 출력하며 각 창마다 옵션을 조금 바꾸어보았습니다

#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

void init(const char* title, int xpos, int ypos, 
          int height, int width, int flags);
void render();

int main(int argc, char* argv[])
{
    //첫번째
    init("Test1", 
          SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED, 
          500, 100,
          SDL_WINDOW_SHOWN);

    SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
    render();

    SDL_Delay(1000);
    SDL_Quit();


    //두번째
    init("Test2", 
          SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED, 
          400, 200,
          SDL_WINDOW_BORDERLESS);

    SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 255);
    render();

    SDL_Delay(1000);
    SDL_Quit();
    

    //세번째
    init("Test3", 
          SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED, 
          300, 300,
          SDL_WINDOW_MAXIMIZED);

    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
    render();

    SDL_Delay(1000);
    SDL_Quit();

    return 0;
}

void init(const char* title, int xpos, int ypos, 
          int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        g_pWindow = SDL_CreateWindow( title, 
                                      xpos, ypos, 
                                      height, width, flags);

        if (g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }
}

void render()
{
    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);
}
