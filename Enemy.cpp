#include "Enemy.h"
#include "InputHandler.h"

void Enemy::draw()
{
  SDLGameObject::draw(flip);
}

void Enemy::update()
{
  handleInput();
  updateSprite();
  SDLGameObject::update();
}

void Enemy::handleInput()
{
  if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
    printf("shoot\n");
}

void Enemy::updateSprite()
{
  Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
  Vector2D* vecToMiddleOfSprite = new Vector2D(m_width/2, m_height/2);
  m_velocity = (*vec - m_position - *vecToMiddleOfSprite) / 100;

  if(m_velocity.getX() < -0.05)
  {
    m_currentFrame = (frameCount++ / 6 + 1) % 6;
    flip = SDL_FLIP_HORIZONTAL;
  }
  else if(m_velocity.getX() > 0.05)
  {
    m_currentFrame = (frameCount++ / 6 + 1) % 6;
    flip = SDL_FLIP_NONE;
  }
  else
  {
    m_currentFrame = 0;
    frameCount = 0;
  }
}