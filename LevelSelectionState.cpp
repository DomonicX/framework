#include "LevelSelectionState.h"

LevelSelectionState::LevelSelectionState()
{
    m_ButtonsRects[LevelButtons::level_1] = {0,0,264,48};
    m_ButtonsRects[LevelButtons::level_2] = {0,48,264,32};
    m_ButtonsRects[LevelButtons::level_3] = {0,80,264,32};
    m_ButtonsRects[LevelButtons::level_4] = {0,108,264,32};
    nn = false;
    nr = false;
    m_FilePath = new std::string({"asset/LevelGamedata.txt"});
    m_FileMap= new std::string({"Levels/Map2.txt"});

}

LevelSelectionState::~LevelSelectionState()
{
    //dtor
}
void LevelSelectionState::Render()
{
    TextureManager::Instance()->SetColour(0,0,0,0,Game::Instance()->GetRenderer());

    //  TextureManager::Instance()->DrawRectFilled(0,0,Game::Instance()->GetWindow()->getWidth(),Game::Instance()->GetWindow()->getHeight(),Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawRectFilled(0,0,Game::Instance()->GetWindow()->getWidth(),Game::Instance()->GetWindow()->getHeight(),Game::Instance()->GetRenderer());


    DisplaySelectButton();
    DisplayButtonText();

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::Instance()->GetStateMachine()->PopState();
        Game::Instance()->PushState(new MenuState(m_FilePath,m_FileMap));

    }
    // Game::Instance()->GetStateMachine()->ChangeState(new MenuState(new std::string("asset/LevelGamedata.txt"),new std::string("Levels/Map2.txt")));
}

void LevelSelectionState::Update()
{

    isMouseOverButtons();
    CheckButtonPress();

}
bool LevelSelectionState::OnEnter()
{
    std::cout<< "Entering : "<< GetStateID() << " \n";
    return true;
}
bool LevelSelectionState::onExit()
{
    std::cout<< "Exiting : "<< GetStateID() << " \n";

}
void LevelSelectionState::resume()
{
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}

bool LevelSelectionState::isMouseOverButtons()
{
    if(isInsideBox(0,0,265,142))
    {
        SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                                InputHandler::Instance()->GetMousePosition().y
                               };

        if(SDL_PointInRect(&l_mousePos,&m_ButtonsRects[LevelButtons::level_1]))
            m_ButtonSelection = &m_ButtonsRects[LevelButtons::level_1];
        else
            m_ButtonSelection = nullptr;
    }
}
void LevelSelectionState::DisplaySelectButton()
{
    TextureManager::Instance()->SetColour(125,125,32,125,Game::Instance()->GetRenderer());

    if(m_ButtonSelection!=NULL)
    {
        TextureManager::Instance()->DrawRectFilled(m_ButtonSelection->x,m_ButtonSelection->y,m_ButtonSelection->w,m_ButtonSelection->h,Game::Instance()->GetRenderer());

    }

}
bool LevelSelectionState::CheckButtonPress()
{
    if(clicked())
    {
        LevelSelectionStateToMenuState();
    }
}
bool LevelSelectionState::clicked()
{
    if( InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {
        nn = true;
        nr = false;
    }
    if(nn && !InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {

        nr = true;
        nn = true;
    }
    if(nn && nr)
    {

        nn = false;
        nr = false;
        return true;
    }
    return false;
}
void LevelSelectionState::LevelSelectionStateToMenuState()
{
    SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                            InputHandler::Instance()->GetMousePosition().y
                           };
    if(SDL_PointInRect(&l_mousePos,&m_ButtonsRects[MainMenuButtons::SETTINGS]))
    {
        Game::Instance()->ChangeGameState(new PlayState(m_FilePath,m_FileMap));
        Game::Instance()->PushState(new MenuState(m_FilePath,m_FileMap));
    }
}
bool LevelSelectionState::isInsideBox(int x, int y, int w, int h)
{
    SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                            InputHandler::Instance()->GetMousePosition().y
                           };
    SDL_Rect l_BoxRect = {x,y,w,h};
    if(SDL_PointInRect(&l_mousePos,&l_BoxRect))
        return true;
    else return false;
}



    void  LevelSelectionState::DisplayButtonText()
    {
        TextureManager::Instance()->DrawText("Level1",0,0,32,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawText("Level2",0,40,32,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawText("Level3",0,70,32,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawText("Level4",0,100,32,Game::Instance()->GetRenderer());
    }


