#ifndef _Player_H_
#define _Player_H_

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}
  void draw();
  void update();
  void clean() {}
};

#endif