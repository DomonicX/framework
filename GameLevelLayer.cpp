#include "GameLevelLayer.h"

GameLevelLayer::GameLevelLayer(SDL_Rect hitBot) : m_hb(hitBot)
{
}

GameLevelLayer::GameLevelLayer()
{
}

GameLevelLayer::~GameLevelLayer()
{
}

void GameLevelLayer::Update(Level* pLevel)
{

    SelectedRect = nullptr;
    if(SDL_PointInRect(pLevel->GetMousePos(),&m_hb))
    {
        if(InputHandler::Instance()->GetMouseButtonState(SDL_BUTTON_LEFT))
        {
            SelectedRect = &m_hb;
        }
    }

}

void GameLevelLayer::Render()
{

//
//        SDL_SetRenderDrawColor( Game::Instance()->GetRenderer(),0,255,0,26);
//
//    SDL_RenderDrawRect(Game::Instance()->GetRenderer(),&m_hb);
//    SDL_RenderDrawRect(Game::Instance()->GetRenderer(),&m_hb);

    if(SelectedRect!=NULL)

    {
        SDL_RenderFillRect(Game::Instance()->GetRenderer(),SelectedRect);
    }

}
