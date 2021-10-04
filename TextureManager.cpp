// 가독성 향상을 위해 코드 일부 수정

#include "TextureManager.h"

bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if(pTempSurface == 0)
  {
    return false; // 이미지 로드 실패
  }

  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  /* if(pTexture != 0)
  {
    m_textureMap[id] = pTexture;
    return true; // 성공
  } */
  if(pTexture == 0)
  {
    return false; // 텍스쳐 생성 실패
  }

  m_textureMap[id] = pTexture;

  SDL_FreeSurface(pTempSurface);

  return true;
}

void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
  SDL_Rect srcRect; // 원본상자 
  SDL_Rect destRect; // 대상상자

  // 원본상자 설정
  srcRect.x = 0; // 시작 x좌표
  srcRect.y = 0; // 시작 y좌표
  srcRect.w = width; // 너비
  srcRect.h = height; // 높이

  // 대상상자 설정
  destRect.x = x; // 시작 x좌표
  destRect.y = y; // 시작 y좌표
  destRect.w = width; // 너비
  destRect.h = height; // 높이

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect,
   0, NULL, flip);
}

void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
  SDL_Rect srcRect; // 원본상자 
  SDL_Rect destRect; // 대상상자

  // 원본상자 설정
  srcRect.x = width * currentRow; // 시작 x좌표
  srcRect.y = height * currentFrame; // 시작 y좌표
  srcRect.w = width; // 너비
  srcRect.h = height; // 높이

  // 대상상자 설정
  destRect.x = x; // 시작 x좌표
  destRect.y = y; // 시작 y좌표
  destRect.w = width; // 너비
  destRect.h = height; // 높이

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect,
   0, NULL, flip);
}