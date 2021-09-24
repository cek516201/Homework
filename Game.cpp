#include "Game.h"

bool Game::init(const char *title, int xpos, int ypos,  int width, int height, int flags) 
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
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
  }

  m_bRunning = true;

  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  // 원본상자 설정
  m_sourceRectangle.x = 0; // 시작 x좌표
  m_sourceRectangle.y = 0; // 시작 y좌표
  m_sourceRectangle.w = 50;
  m_sourceRectangle.h = 50;
  //SDL_QueryTexture(m_pTexture, NULL, NULL, 
  //&m_sourceRectangle.w, &m_sourceRectangle.h); // 너비와 높이

  // 대상상자 설정
  m_destinationRectangle.x = 0; // 시작 x좌표
  m_destinationRectangle.y = 0; // 시작 y좌표
  m_destinationRectangle.w = m_sourceRectangle.w; // 너비
  m_destinationRectangle.h = m_sourceRectangle.h; // 높이
 
  return true;
}

void Game::render()
{
   SDL_RenderClear(m_pRenderer);

   SDL_RenderCopy(m_pRenderer, m_pTexture,
   &m_sourceRectangle, &m_destinationRectangle);
   
   SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{

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