#ifndef _GameObject_H_
#define _GameObject_H_

#include "SDL.h"
#include <string>

using namespace std;

class GameObject
{
public:
  void load(int x, int y, int width, int height, string textureID);

  void draw(SDL_Renderer* pRenderer);
  void update();

  void clean() {};

protected:
  string m_textureID = "";

  int m_x = 0;
  int m_y = 0;
  int m_width = 0;
  int m_height = 0;

  int m_currentRow = 0;
  int m_currentFrame = 0;
};

#endif