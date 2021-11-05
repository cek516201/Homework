#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      TheGame::Instance()->quit();
      break;

    case SDL_KEYUP:
    case SDL_KEYDOWN:
      m_keystates = SDL_GetKeyboardState(0);
      break;

    default:
      break;
    }
  }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
  if(m_keystates != 0 && m_keystates[key] == 1)
  {
    return true;
  }

  return false;
}