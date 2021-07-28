#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <Level.h>
class PlayState : public GameState
{

public:
    PlayState( std::string * FilePath,  std::string * FileMap);
    virtual    ~PlayState();

    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    std::string GetStateID()
    {
        return "PlayState";
    }
private:
    std::string *m_FilePath;
    std::string *m_FileMap;

    Level *level_1;
};

#endif // PLAYSTATE_H
