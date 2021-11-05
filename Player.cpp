#include "Player.h"
#include "InputHandler.h"

void Player::draw()
{
  SDLGameObject::draw(flip);
}

void Player::update()
{
  // SDL_GetTicks()는 밀리세컨드이므로 10프레임
  m_currentFrame = SDL_GetTicks() / 100 % 6;

  handleInput();

  SDLGameObject::update();
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
  {
    m_velocity.setX(-2);
    flip = SDL_FLIP_HORIZONTAL;
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
  {
    m_velocity.setX(2);
    flip = SDL_FLIP_NONE;
  }
  else
    m_velocity.setX(0);

  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    m_velocity.setY(-2);
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    m_velocity.setY(2);
  else
    m_velocity.setY(0);
}