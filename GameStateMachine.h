#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H
#include <vector>
#include <GameState.h>

#include <string.h>
#include <InputHandler.h>
class GameStateMachine
{
    public:
        GameStateMachine(){std::cout << "GameStateMachine\n"; };
       virtual  ~GameStateMachine(){};
        void Update();
        void Render();
        void PushState(GameState *pState);
        void ChangeState(GameState* pState);
        void PopState();
        void Clean();
        std::vector<GameState*>& GetGameState() {return m_gameStates;}
std::string GetCurrentStateID(){ return m_gameStates.back()->GetStateID();}

    protected:



    private:

std::vector<GameState*>m_gameStates;
};

#endif // GAMESTATEMACHINE_H
