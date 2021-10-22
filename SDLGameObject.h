#ifndef _SDLGameObject_H_
#define _SDLGameObject_H_

#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
  SDLGameObject(const LoaderParams* pParams); // : GameObject(pParams)
  virtual ~SDLGameObject() {}

  virtual void draw();
  virtual void update() {}
  virtual void clean() {}

protected:
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_currentRow;
  int m_currentFrame;
  string m_textureID;
};

#endif