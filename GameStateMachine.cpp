#include "GameStateMachine.h"

void GameStateMachine::Clean()
{
    while(!m_gameStates.empty())
    {
        m_gameStates.back()->onExit();
        delete m_gameStates.back() ;
        m_gameStates.erase(m_gameStates.begin() + m_gameStates.size()-1);

    }m_gameStates.clear();
}
void GameStateMachine::Update()
{

    if(!m_gameStates.empty() )
    {
        m_gameStates.back()->Update();

    }
}

void GameStateMachine::Render()
{
    if(!m_gameStates.empty())
    {
        for(int i = 0; i < m_gameStates.size() ; i++ )
    m_gameStates[i]->Render();


    }
}
void GameStateMachine::PushState(GameState *pstate)
{
    m_gameStates.push_back(pstate);
    m_gameStates.back()->OnEnter();
}

void GameStateMachine::PopState()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->onExit();
        m_gameStates.pop_back();

    }
    m_gameStates.back()->resume();
}
void GameStateMachine::ChangeState(GameState *pstate)
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->GetStateID() == pstate->GetStateID())
        {
            return ;
        }
        m_gameStates.back()->onExit();

        m_gameStates.pop_back();
    }
    pstate->OnEnter();
    m_gameStates.push_back(pstate);
}
