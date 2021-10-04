// 가독성 향상을 위해 코드 일부 수정

#ifndef __TextureManager__
#define __TextureManager__

#include "SDL.h"
#include <iostream>
#include <map>

using namespace std;

class TextureManager;

typedef TextureManager TheTextureManager;

class TextureManager
{
private:
  TextureManager() {}
  static TextureManager* s_pInstance;

public:
  static TextureManager* Instance()
  {
    if(s_pInstance == 0)
      s_pInstance = new TextureManager();

    return s_pInstance;
  }

  ~TextureManager() {}

  bool load(string fileName, string id, SDL_Renderer* pRenderer);

  // 이미지 그리기
  void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  // 애니메이션 그리기
  void drawFrame(string id, int x, int y, int width, int height,
  int currentRow, int currentFrame,
  SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
  map<string, SDL_Texture*> m_textureMap;
};

#endif