#include "Enemy.h"
#include "SDL.h"

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  // SDL_GetTicks()는 밀리세컨드이므로 10프레임
  m_currentFrame = SDL_GetTicks() / 100 % 6;
  
  m_acceleration.setX(1);

  SDLGameObject::update();
}