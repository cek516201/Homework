#ifndef _Player_H_
#define _Player_H_

#include "SDL.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
  void load(int x, int y, int width, int height, string textureID);
  void draw(SDL_Renderer* pRenderer);
  void update();
  void clean() {};
};

#endif