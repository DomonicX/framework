#ifndef LEVELSELECTIONSTATE_H
#define LEVELSELECTIONSTATE_H


#include <GameState.h>
#include <Game.h>
#include <TextureManager.h>
#include <iostream>
#include <MenuState.h>
#include <string.h>
#include <PlayState.h>

typedef enum
{
    level_1,
    level_2,
    level_3,
    level_4
} LevelButtons;
class LevelSelectionState: public GameState
{

public:
    LevelSelectionState();
    virtual  ~LevelSelectionState();
    void Render() ;
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    void DisplayButtonText();
    bool isMouseOverButtons();
    void DisplaySelectButton();
    bool CheckButtonPress();
    bool clicked();

    std::string GetStateID()
    {
        return "LevelSelectionState";
    }


    void LevelSelectionStateToMenuState();

    bool isInsideBox(int x, int y, int w, int h);
    SDL_Rect *m_ButtonSelection = nullptr;
    bool nn  = false;
    bool nr = false;

protected:

private:

    SDL_Rect m_ButtonsRects[4];
    std::string * m_FilePath;
    std::string * m_FileMap;
};

#endif // LEVELSELECTIONSTATE_H








