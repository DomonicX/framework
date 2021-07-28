#ifndef TEXTBOXSTATE_H
#define TEXTBOXSTATE_H



#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <Level.h>
#include <MenuState.h>
#include <PlayState.h>
#include <iostream>
#include <sstream>
#include <fstream>
class TextBoxState : public GameState
{
public:
    TextBoxState( std::string * FilePath);
    virtual ~TextBoxState();


    void Render()
    {
    TextureManager::Instance()->DrawBackGround("Border",Game::Instance()->GetRenderer());
    TextureManager::Instance()->Draw("Border",200,200,64,64,Game::Instance()->GetRenderer(), SDL_FLIP_NONE);

  std::string s = m_curText.str();
   TextureManager::Instance()->DrawText(s,0,0,64,Game::Instance()->GetRenderer());
     };
    void Update()
    {
        if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Q))
        {
    std::string m_FilePath =  std::string({"asset/LevelGamedata.txt"});
    std::string  m_FileMap=  std::string({"Levels/Map1.txt"});
            Game::Instance()->ChangeGameState(new PlayState(&m_FilePath,&m_FileMap));
            Game::Instance()->PushState(new MenuState());
        }
    }
    bool OnEnter();
    bool onExit();
    void resume();
    std::string GetStateID()
    {
        return "TextBoxState";
    }
protected:

private:
    std::stringstream m_curText;
    std::string m_FilePath;
};

#endif // TEXTBOXSTATE_H
