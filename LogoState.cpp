#include "LogoState.h"

LogoState::LogoState()
{
    //ctor
}

LogoState::~LogoState()
{
    //dtor
}

void LogoState::Render()
{
    TextureManager::Instance()->SetColour(77,125,0,125,Game::Instance()->GetRenderer());

    TextureManager::Instance()->DrawRectFilled(0,0,Game::Instance()->GetWindow()->getWidth(),Game::Instance()->GetWindow()->getHeight(),Game::Instance()->GetRenderer());
    m_background->Draw();
}
void LogoState::Update()
{
    m_background->Update();
    if(Game::Instance()->getRandomNumber()%100==4)
        Game::Instance()->GetStateMachine()->PopState();
}
bool LogoState::OnEnter()
{
    m_background  = GameObjectFactory::Instance()->Create("BackGroundImage");
    m_background->Load("asset/State/BackGroundImage.txt");
    std::cout<< "Entering : "<< GetStateID() << " \n";
    return true;
}
bool LogoState::onExit()
{
    std::cout<< "Exiting : "<< GetStateID() << " \n";
}
void LogoState::resume()
{
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}

