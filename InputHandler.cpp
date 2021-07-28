#include "InputHandler.h"

#include <Game.h>
#include <iostream>
InputHandler *InputHandler::s_pInstance = 0;

InputHandler::InputHandler() : m_keyState(new Uint8(0)),
    m_bJoyStickInitialised(false),
    m_mousePosition(vec2f(0,0))
{
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
    m_WindowStates = 0;
}

InputHandler::~InputHandler()
{
    //dtor
}

bool InputHandler::MousePointInRect(SDL_Point p,SDL_Rect r)
{

    return SDL_PointInRect(&p,&r);
}

bool InputHandler::GetWindowEvent(SDL_WindowEventID event)
{


    if(event==m_WindowStates)
    {
m_WindowStates = SDL_WINDOWEVENT_NONE;
        return true;
    }
    else return false;
}

void InputHandler::OnWindowEvent(SDL_Event &event)
{

    m_WindowStates = event.window.event;
}

void InputHandler::Update(SDL_Event &event)
{

        switch(event.type)
        {
     //   case SDL_WINDOWEVENT :
            //OnWindowEvent(event);
     //       break;
        case SDL_MOUSEBUTTONDOWN :
            OnMouseButtonDown(event);
            break;
        case SDL_MOUSEBUTTONUP :
            OnMouseButtonUp(event);
            break;
        case SDL_KEYDOWN :
            OnKeyDown();
            break;
        case SDL_KEYUP:
            OnKeyUp();
            break;
        case SDL_MOUSEMOTION :
            OnMouseMove(event);
            break;
        case SDL_JOYAXISMOTION :
            OnJoyStickAxisMove( event);
            break;
        case SDL_JOYBUTTONUP :
            OnJoyStickButtonUp( event);
            break;
        case SDL_JOYBUTTONDOWN :
            OnJoyStickButtonDown( event);
            break;
        };

}


vec2f InputHandler::GetMousePosition() const
{
    return m_mousePosition;
}

void InputHandler::OnKeyUp()
{
    m_keyState = SDL_GetKeyboardState(0);
}
void InputHandler::OnKeyDown()
{
    m_keyState = SDL_GetKeyboardState(0);
}


bool InputHandler::MouseinRect(SDL_Rect r)
{
    SDL_Point m = {m_mousePosition.x,m_mousePosition.y};
    if(SDL_PointInRect(&m,&r))
    {

        return true;
    }

     return false;
}
void InputHandler::OnMouseMove(SDL_Event &event)
{
    m_mousePosition.x = event.motion.x;
    m_mousePosition.y = event.motion.y;
}
bool InputHandler::GetMouseButtonState(int buttonNumber)
{
    return m_mouseButtonStates[buttonNumber];
}
void InputHandler::OnMouseButtonUp(SDL_Event &event)
{
    switch(event.button.button)
    {
    case SDL_BUTTON_LEFT:
        m_mouseButtonStates[LEFT] = false;
        break;
    case SDL_BUTTON_MIDDLE :
        m_mouseButtonStates[MIDDLE] = false;
        break;
    case SDL_BUTTON_RIGHT:
        m_mouseButtonStates[RIGHT] = false;
        break;
    }
}
void InputHandler::OnMouseButtonDown(SDL_Event &event)
{
    switch(event.button.button)
    {
    case SDL_BUTTON_LEFT:
        m_mouseButtonStates[LEFT] = true;
        break;
    case SDL_BUTTON_MIDDLE :
        m_mouseButtonStates[MIDDLE] = true;
        break;
    case SDL_BUTTON_RIGHT:
        m_mouseButtonStates[RIGHT] = true;
        break;
    }
}
bool InputHandler::isKeyDown(SDL_Scancode  key)
{
    if(m_keyState != 0)
    {
        if(m_keyState[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
void InputHandler::OnJoyStickButtonUp(SDL_Event &event) {}
void InputHandler::OnJoyStickButtonDown(SDL_Event &event) {}
void InputHandler::OnJoyStickAxisMove(SDL_Event &event) {}
