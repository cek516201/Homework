#include "Player.h"
#include "SDL.h"

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  // SDL_GetTicks()는 밀리세컨드이므로 10프레임
  m_currentFrame = SDL_GetTicks() / 100 % 6;

  SDLGameObject::update();
}