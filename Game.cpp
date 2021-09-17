//bmp파일을 하나 더 만들었고 생성 위치와 이동을 추가했습니다

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

  SDL_QueryTexture(m_pTexture, NULL, NULL, 
  &m_sourceRectangle.w, &m_sourceRectangle.h); // 원본상자 크기

  m_destinationRectangle.w = m_sourceRectangle.w; // 대상상자 크기
  m_destinationRectangle.h = m_sourceRectangle.h;

  m_sourceRectangle.x = 0;
  m_sourceRectangle.y = 0;
  m_destinationRectangle.x = 50; // 그릴위치 설정
  m_destinationRectangle.y = 50;



  SDL_Surface* pTempSurface2 = SDL_LoadBMP("Assets/sad cat.bmp");
  m_pTexture2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface2);
  SDL_FreeSurface(pTempSurface2);

  SDL_QueryTexture(m_pTexture2, NULL, NULL, 
  &m_sourceRectangle2.w, &m_sourceRectangle2.h); // 원본상자 크기

  m_destinationRectangle2.w = m_sourceRectangle2.w; // 대상상자 크기
  m_destinationRectangle2.h = m_sourceRectangle2.h;

  m_sourceRectangle2.x = 0;
  m_sourceRectangle2.y = 0;
  m_destinationRectangle2.x = 300; // 그릴위치 설정
  m_destinationRectangle2.y = 50;

  

  return true;
}

void Game::render()
{
   SDL_RenderClear(m_pRenderer);

   SDL_RenderCopy(m_pRenderer, m_pTexture2,
   &m_sourceRectangle2, &m_destinationRectangle2);

   SDL_RenderCopy(m_pRenderer, m_pTexture,
   &m_sourceRectangle, &m_destinationRectangle);
   
   SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  m_destinationRectangle.x++;
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