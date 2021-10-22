// 완료한 단계 : 7주차 상속, 다형성
//              8주차 유일객체 Game

#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
    if( TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false) )
    {
      while( TheGame::Instance()->running() )
      {
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();
        SDL_Delay(10);
      }
    }
    else
    {
      cout << "game init failure " << SDL_GetError() << endl;
      
      return -1;
    }

    TheGame::Instance()->clean();

    return 0;
}