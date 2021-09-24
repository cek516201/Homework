// update를 수정하여 고양이가 더 빠르게 달리도록 수정했고
// SDL_RenderCopyEx를 사용하여 고양이가 반대편으로 달리도록 수정했습니다

#include "Game.h"
#include "SDL_image.h"

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
  }

  m_bRunning = true;

  SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  // 원본상자 설정
  m_sourceRectangle.x = 0; // 시작 x좌표
  m_sourceRectangle.y = 0; // 시작 y좌표
  m_sourceRectangle.w = 128;
  m_sourceRectangle.h = 82;
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

   SDL_RenderCopyEx(m_pRenderer, m_pTexture,
   &m_sourceRectangle, &m_destinationRectangle,
   0, NULL, SDL_FLIP_HORIZONTAL);
   
   SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  m_sourceRectangle.x = 128 * ( (SDL_GetTicks() / 50) % 6 );
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