#ifndef _InputHandler_H_
#define _InputHandler_H_

#include "SDL.h"

class InputHandler;

typedef InputHandler TheInputHandler;

class InputHandler
{
private:
  InputHandler() {}
  static InputHandler* s_pInstance;
  
public:
  static InputHandler* Instance()
  {
    if(s_pInstance == 0)
      s_pInstance = new InputHandler();

    return s_pInstance;
  }

  ~InputHandler() {}

  bool isKeyDown(SDL_Scancode key);
  void update();
  void clean() {}

private:
  const Uint8* m_keystates;
};

#endif