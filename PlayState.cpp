#include "PlayState.h"
#include <MenuState.h>
#include <PauseState.h>
#include <TextBoxState.h>
PlayState::PlayState(std::string *FilePath,std::string *FileMap)
{
    m_FilePath = FilePath;
    m_FileMap = FileMap;
    //ctor '
    m_loadingComplete = false;
    m_exiting = false;
}

PlayState::~PlayState()
{
    //dtor
}

void PlayState::Render()
{
    if(m_loadingComplete)
    {
        level_1->Render();
    }
}
void PlayState::Update()
{
    m_loadingComplete = true;
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
        Game::Instance()->PushState(new MenuState(m_FilePath,m_FileMap));

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))

    {
        std::string s = "s.txt";
        Game::Instance()->ChangeGameState(new TextBoxState(&s));
    }
    if(!Game::Instance()->GetWindow()->IsFocus())
        Game::Instance()->PushState(new MenuState(m_FilePath,m_FileMap));


    level_1->Update();
}
bool PlayState::OnEnter()
{
    level_1 = new Level(m_FilePath,m_FileMap);
    std::cout << GetStateID() << " : onEnter\n\n";
    return true;
}
bool PlayState::onExit()
{
    std::cout << GetStateID() << " : onExit\n";
}
void PlayState::resume()
{
    std::cout << GetStateID() << " : Resume\n";
}
