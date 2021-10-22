#ifndef _Enemy_H_
#define _Enemy_H_

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}
  void draw();
  void update();
  void clean() {}
};

#endif