// 가독성 향상을 위해 코드 일부 수정

#include "Game.h"
#include "SDL_image.h"

bool Game::init(const char *title, int xpos, int ypos,  int width, int height, int flags) 
{
  /* if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
      }
      else
      {
        return false; // 랜더러 생성 실패
      }
    }
    else
    {
      return false; // 윈도우 생성 실패
    }
  }
  else
  {
    return false; // SDL 초기화 실패
  } */
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    return false; // SDL 초기화 실패
  }

  m_pWindow = SDL_CreateWindow(title, xpos, ypos, width,height, flags);
  if (m_pWindow == 0)
  {
    return false; // 윈도우 생성 실패
  }

  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  if (m_pRenderer == 0)
  {
    return false; // 랜더러 생성 실패
  }

  if( m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer) == false )
  {
    return false;
  }

   m_bRunning = true;

   SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

  return true;
}

void Game::render()
{
   SDL_RenderClear(m_pRenderer);

   m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer, SDL_FLIP_NONE);
   m_textureManager.drawFrame("animate", 100, 100, 128, 82, m_currentRow, m_currentFrame, m_pRenderer, SDL_FLIP_NONE);
   
   SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  // SDL_GetTicks()는 밀리세컨드이므로 10프레임
  m_currentFrame = SDL_GetTicks() / 100 % 6;
}

bool Game::running()
{ 
   return m_bRunning; 
}

void Game::handleEvents() 
{
  SDL_Event event;

  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      m_bRunning = false;
      break;

    
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      {
        case SDLK_LEFT: // 왼쪽키
        //destRect.x--;
        break;
        
        case SDLK_RIGHT: // 오른쪽키
        //destRect.x++;
        break;
        
        case SDLK_UP: // 위쪽키
        //destRect.y--;
        break;

        case SDLK_DOWN: // 아래쪽키
        //destRect.y++;
        break;
      }
      break;
    

    default:
      break;
    }
  }
}

void Game::clean() 
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}