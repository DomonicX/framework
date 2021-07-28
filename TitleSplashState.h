#ifndef TITLESPLASHSTATE_H
#define TITLESPLASHSTATE_H
#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <Level.h>
class TitleSplashState : public GameState
{
    public:
        TitleSplashState();
        virtual ~TitleSplashState();


 void Render();
 void Update();
 bool OnEnter();
 bool onExit();
 void resume();
 std::string GetStateID(){return "TitleSplashState";}
    private:
};

#endif // TITLESPLASHSTATE_H

