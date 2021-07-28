#ifndef TESTSTATE_H
#define TESTSTATE_H

#include <sstream>
#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <Level.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <GUI_Object.h>
#include <math.h>
#include <vector>
class TestState : public GameState
{
    public:
        TestState();
      virtual   ~TestState();

 void Render();
 void Update();
 bool OnEnter();
 bool onExit();
 void resume();
std::string GetStateID(){return "TestState";}
    protected:

    private:

vec2f o;
    float m_gravity = 9.98;
};


#endif // TESTSTATE_H
