#ifndef SETTINGSTATE_H
#define SETTINGSTATE_H



#include <GameState.h>
#include <LevelSelectionState.h>
typedef enum
{
    Setting0Button,
    Setting1Button,
    Setting2Button,
    Setting3Button
} SettingStateButtons;

class SettingState: public GameState
{

public:
    SettingState();
    virtual    ~SettingState();

   // void SettingState( std::string * FilePath,  std::string * FileMap);

    void Render();

        void Update();
        bool nr = false;
        bool nn = false;
        bool OnEnter();
        bool onExit();
        void resume();
         bool isInsideBox(int x, int y, int w, int h);
        bool clicked();
        void DisplayButtonText();

        void DisplaySelectButton(){}
        bool CheckButtonPress();
        bool isMouseOverButtons();
        std::string GetStateID()
        {
            return "SettingState";
        }
protected:

private:
        SDL_Rect m_ButtonsRects[4];
    };

#endif // SETTINGSTATE_H


