#include "Game.h"
#include "TextureManager.h"
#include "Player.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos,  int width, int height, int flags) 
{
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

  if( TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer) == false)
  {
    return false; // 이미지 로드 실패
  }

  GameObject* m_gameobject = new GameObject();
  GameObject* m_player = new Player();

  m_gameobject->load(200, 100, 128, 82, "animate");
  m_player->load(400, 200, 128, 82, "animate");

  m_gameObjects.push_back(m_gameobject);
  m_gameObjects.push_back(m_player);

  SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

  m_bRunning = true;

  return true;
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  
  for(int i = 0 ; i < m_gameObjects.size() ; i++)
  {
    m_gameObjects[i]->draw(m_pRenderer);
  }
   
  SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
  for(int i = 0 ; i < m_gameObjects.size() ; i++)
  {
    m_gameObjects[i]->update();
  }
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