#include "Player.h"

void Player::load(int x, int y, int width, int height, string textureID)
{
  GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
  GameObject::draw(pRenderer);
}

void Player::update()
{
  // SDL_GetTicks()는 밀리세컨드이므로 10프레임
  m_currentFrame = SDL_GetTicks() / 100 % 6;

  m_x--;
}