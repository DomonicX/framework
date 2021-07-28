#include "MenuState.h"
#include <PauseState.h>
#include <PlayState.h>
#include <SettingState.h>
#include <LevelSelectionState.h>
MenuState::MenuState()
{
    m_ButtonsRects[MainMenuButtons::PLAY] = {0,0,264,48};
    m_ButtonsRects[MainMenuButtons::LEVEL] = {0,48,264,32};
    m_ButtonsRects[MainMenuButtons::SETTINGS] = {0,80,264,32};
    m_ButtonsRects[MainMenuButtons::QUIT] = {0,108,264,32};
    nn = false;
    nr = false;
    m_FilePath = new std::string({"asset/LevelGamedata.txt"});
    m_FileMap= new std::string({"Levels/Map1.txt"});

    GameState::m_loadingComplete = false;
}

MenuState::MenuState( std::string * FilePath,  std::string * FileMap)
{
    m_ButtonsRects[MainMenuButtons::PLAY] = {0,0,264,48};
    m_ButtonsRects[MainMenuButtons::LEVEL] = {0,48,264,32};
    m_ButtonsRects[MainMenuButtons::SETTINGS] = {0,80,264,32};
    m_ButtonsRects[MainMenuButtons::QUIT] = {0,108,264,32};
    nn = false;
    nr = false;
    m_FilePath =  FilePath;
    m_FileMap = FileMap  ;
    //  m_FilePath = new std::string({"asset/LevelGamedata.txt"});
    //   m_FileMap= new std::string({"asset/LevelGamedata.txt","Levels/Map1.txt"});

}
MenuState::~MenuState()
{
}
void MenuState::Render()
{

    DisplaySelectButton();
    DisplayButtonText();

}
void MenuState::Update()
{


    if(!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        GameState::m_loadingComplete = true;
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE) &&  GameState::m_loadingComplete)
    {
        Game::Instance()->GetStateMachine()->PopState();
        //     Game::Instance()->PushState(new MenuState(m_FilePath,m_FileMap));

    }
    CheckButtonPress();
}

bool MenuState::OnEnter()
{
    std::cout<< "Entering : "<< GetStateID() << " \n";
    return true;
}
bool MenuState::onExit()
{
    std::cout<< "Exiting : "<< GetStateID() << " \n";
}
void MenuState::resume()
{
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}
bool MenuState::isInsideBox(int x, int y, int w, int h)
{
    SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                            InputHandler::Instance()->GetMousePosition().y
                           };
    SDL_Rect l_BoxRect = {x,y,w,h};
    if(SDL_PointInRect(&l_mousePos,&l_BoxRect))
        return true;
    else return false;

}
void MenuState::MenuStateToSettings()
{
    SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                            InputHandler::Instance()->GetMousePosition().y
                           };
    if(SDL_PointInRect(&l_mousePos,&m_ButtonsRects[MainMenuButtons::SETTINGS]))
    {
        Game::Instance()->GetStateMachine()->ChangeState(new SettingState());
    }
}
void MenuState::MenuStateToQuit()
{
    SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                            InputHandler::Instance()->GetMousePosition().y
                           };
    if(SDL_PointInRect(&l_mousePos,&m_ButtonsRects[MainMenuButtons::QUIT]))
    {
        Game::Instance()->quit();
    }
}
void MenuState::MenuStateToLevel()
{
    SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                            InputHandler::Instance()->GetMousePosition().y
                           };
    if(SDL_PointInRect(&l_mousePos,&m_ButtonsRects[MainMenuButtons::LEVEL]))
    {
        Game::Instance()->ChangeGameState(new LevelSelectionState());
    }
}

void MenuState::MenuStateToPlayState()
{
    SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                            InputHandler::Instance()->GetMousePosition().y
                           };
    if(SDL_PointInRect(&l_mousePos,&m_ButtonsRects[MainMenuButtons::PLAY]))
    {

        Game::Instance()->GetStateMachine()->PopState();
        //  Game::Instance()->ChangeGameState(new PlayState(m_FilePath,m_FileMap));
    }
}
bool MenuState::clicked()
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
void MenuState::DisplayButtonText()
{
    TextureManager::Instance()->DrawText("Play",0,0,32,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText("Level",0,40,32,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText("Settings",0,70,32,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText("Quit",0,100,32,Game::Instance()->GetRenderer());
}
void MenuState::DisplaySelectButton()
{
    TextureManager::Instance()->SetColour(125,125,32,125,Game::Instance()->GetRenderer());

    if(m_ButtonSelection!=NULL)
    {
        TextureManager::Instance()->DrawRectFilled(m_ButtonSelection->x,m_ButtonSelection->y,m_ButtonSelection->w,m_ButtonSelection->h,Game::Instance()->GetRenderer());

    }
}
bool MenuState::CheckButtonPress()
{
    if(clicked())
    {
        MenuStateToLevel();
        MenuStateToSettings();
        MenuStateToQuit();
        MenuStateToPlayState();
    }
}
bool MenuState::isMouseOverButtons()
{
    if(isInsideBox(0,0,265,142))
    {
        SDL_Point l_mousePos = {InputHandler::Instance()->GetMousePosition().x,
                                InputHandler::Instance()->GetMousePosition().y
                               };
        if(InputHandler::Instance()->MousePointInRect(l_mousePos,m_ButtonsRects[MainMenuButtons::PLAY]))
        {
            m_ButtonSelection = &m_ButtonsRects[MainMenuButtons::PLAY];
        }
        else if(InputHandler::Instance()->MousePointInRect(l_mousePos,m_ButtonsRects[MainMenuButtons::LEVEL]))
        {
            m_ButtonSelection = &m_ButtonsRects[MainMenuButtons::LEVEL];
        }
        else if(InputHandler::Instance()->MousePointInRect(l_mousePos,m_ButtonsRects[MainMenuButtons::SETTINGS]))
        {
            m_ButtonSelection = &m_ButtonsRects[MainMenuButtons::SETTINGS];
        }
        else if(InputHandler::Instance()->MousePointInRect(l_mousePos,m_ButtonsRects[MainMenuButtons::QUIT]))
        {
            m_ButtonSelection = &m_ButtonsRects[MainMenuButtons::QUIT];
        }
        else
            m_ButtonSelection = nullptr;
    }
}
