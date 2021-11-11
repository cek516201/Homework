#include "Player.h"
#include "InputHandler.h"

void Player::draw()
{
  SDLGameObject::draw(flip);
}

void Player::update()
{
  handleInput();

  SDLGameObject::update();
}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
  {
    m_velocity.setX(-2);
    m_currentFrame = (frameCount++ / 6 + 1) % 6;
    flip = SDL_FLIP_HORIZONTAL;
  }
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
  {
    m_velocity.setX(2);
    m_currentFrame = (frameCount++ / 6 + 1) % 6;
    flip = SDL_FLIP_NONE;
  }
  else
  {
    m_velocity.setX(0);
    m_currentFrame = 0;
    frameCount = 0;
  }

  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    m_velocity.setY(-2);
  else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    m_velocity.setY(2);
  else
    m_velocity.setY(0);
}