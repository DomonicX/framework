#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <vector>
#include <SDL2/SDL.h>
#include <Vector2D.h>
#include <iostream>

enum mouse_Buttons
{
    LEFT = 1,
    MIDDLE = 2,
    RIGHT = 3
};
class InputHandler
{
public:
    virtual ~InputHandler();
    static InputHandler* Instance()
    {

        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    void InitialiseJoyStick();
    bool JoyStickInitialised()const
    {
        return m_bJoyStickInitialised;
    }
    void Reset();
    void Update(SDL_Event &event);
    void Clean() {};
bool MousePointInRect(SDL_Point p,SDL_Rect r);
bool MouseinRect(SDL_Rect r);
    bool GetButtonState(int joy, int buttonNumber) const;
    bool GetMouseButtonState(int buttonNumber);
    vec2f GetMousePosition() const;
    bool isKeyDown(SDL_Scancode  key);

int m_WindowStates;
bool GetWindowEvent(SDL_WindowEventID event);
protected:

private:

    InputHandler();
    void OnKeyUp();
    void OnKeyDown();
    void OnMouseMove(SDL_Event &event);
    void OnMouseButtonDown(SDL_Event &event);
    void OnMouseButtonUp(SDL_Event &event);

    void OnJoyStickButtonUp(SDL_Event &event);
    void OnJoyStickButtonDown(SDL_Event &event);
    void OnJoyStickAxisMove(SDL_Event &event);
    const Uint8 *m_keyState;

    std::vector<std::pair<vec2f*,vec2f*>>m_joyStickValues;
    std::vector<SDL_Joystick*>m_joystick;
    std::vector<bool> m_mouseButtonStates;

    std::vector<std::vector<bool>> m_buttonStates;
    bool m_bJoyStickInitialised;
    static const int m_joystickDeadZone = 10000;
    vec2f m_mousePosition;

    void OnWindowEvent(SDL_Event &event);

    static InputHandler* s_pInstance;
};

#endif // INPUTHANDLER_H
