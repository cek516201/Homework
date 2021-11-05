// 완료한 단계 : 7주차 상속, 다형성
//              8주차 유일객체 Game, 추상클래스
//              9주차 Vector2D
//              10주차 물리

#include <iostream>
#include "Game.h"

using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
  if( TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false) == false )
  {
    cout << "game init failure " << SDL_GetError() << endl;

    return 1; // 초기화 실패
  }

  Uint32 frameStart, frameTime;

  while( TheGame::Instance()->running() )
  {
    frameStart = SDL_GetTicks();

    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();

    frameTime = SDL_GetTicks() - frameStart;

    if(frameTime < DELAY_TIME)
    {
      SDL_Delay((int)(DELAY_TIME - frameTime));
    }
  }

  TheGame::Instance()->clean();

  return 0;
}