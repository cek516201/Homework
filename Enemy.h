#ifndef _Enemy_H_
#define _Enemy_H_

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
  Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}
  void draw();
  void update();
  void handleInput();
  void updateSprite();
  void clean() {}

private:
  SDL_RendererFlip flip = SDL_FLIP_NONE;
  int frameCount = 0;
};

#endif