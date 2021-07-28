#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string.h>
#include <iostream>
#include <vector>
class GameState
{
    public :
        virtual ~GameState(){};
virtual void Render() = 0;
virtual void Update() = 0;
virtual bool OnEnter() = 0;
virtual bool onExit() = 0;
virtual void resume() =0;
virtual std::string GetStateID()=0;
    protected:
        bool m_loadingComplete;
        bool m_exiting;

GameState() : m_loadingComplete(false),m_exiting(false)
{

}
    private:

        };

#endif // GAMESTATE_H
