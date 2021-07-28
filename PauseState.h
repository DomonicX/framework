#ifndef PAUSESTATE_H
#define PAUSESTATE_H



#include <GameState.h>

class PauseState : public GameState
{
    public :
PauseState() : m_loadingComplete(false),m_exiting(false)
{

    }    virtual ~PauseState();

 void Render(){}
 void Update(){}
 bool OnEnter(){}
 bool onExit(){}
 void resume(){}


 std::string GetStateID(){return "PauseState";}


    protected:
        bool m_loadingComplete;
        bool m_exiting;

    private:

        };

#endif // PAUSESTATE_H
