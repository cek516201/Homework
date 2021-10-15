#include "GameObject.h"
#include "TextureManager.h"

void GameObject::load(int x, int y, int width, int height, string textureID)
{
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
  m_textureID = textureID;
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
  TheTextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::update()
{
  // SDL_GetTicks()는 밀리세컨드이므로 10프레임
  m_currentFrame = SDL_GetTicks() / 100 % 6;
  
  m_x++;
}