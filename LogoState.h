#ifndef LOGOSTATE_H
#define LOGOSTATE_H


#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <Level.h>
#include <GameObjectFactory.h>

class LogoState : public GameState
{
    public:
        LogoState();
      virtual   ~LogoState();

 void Render();
 void Update();
 bool OnEnter();
 bool onExit();
 void resume();
 std::string GetStateID(){return "LogoState"; }
    protected:

    private:
        GameObject* m_background;
};

#endif // LOGOSTATE_H
