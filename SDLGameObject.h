#ifndef _SDLGameObject_H_
#define _SDLGameObject_H_

#include "GameObject.h"
#include "Vector2D.h"
#include "SDL.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams); // : GameObject(pParams)
  virtual ~SDLGameObject() {}

  virtual void draw(SDL_RendererFlip flip = SDL_FLIP_NONE);
  virtual void update();
  virtual void clean() {}

protected:
  Vector2D m_position; // :  m_position(pParams->getX(),pParams->getY())
  Vector2D m_velocity; // :  m_velocity(0, 0)
  Vector2D m_acceleration; // :  m_acceleration(0, 0)
  
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;
  string m_textureID;
};

#endif