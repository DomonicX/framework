#ifndef LEVELCREATERSTATE_H
#define LEVELCREATERSTATE_H




#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <Level.h>
#include <GameObjectFactory.h>
#include <Node.h>
#include <Vector2D.h>
#include <fstream>
#include <sstream>
#include <string>

class LevelCreaterState: public GameState
{

public:
    LevelCreaterState();
    virtual ~LevelCreaterState();


    void Render();
    void Update();
    bool OnEnter();
    bool onExit();
    void resume();
    std::string GetStateID()
    {
        return "LevelCreaterState";
    }
    void Save();
    void Load();
    void Clear();
protected:

private:
   int  m_col;
  int   m_row;
   int  m_Tile;
    Node gameLevelgrid[9][16];
};

#endif // LEVELCREATERSTATE_H
