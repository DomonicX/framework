#ifndef MARIOLEVELSTATE_H
#define MARIOLEVELSTATE_H
#include <sstream>
#include <GameState.h>
#include <iostream>
#include <Vector2D.h>
#include <map>
#include <Level.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <GUI_Object.h>
#include <math.h>
#include <vector>
#include <MarioPlayer.h>
#include <MenuState.h>
#include <MarioEnemy.h>
class MarioLevelState : public GameState
{
    public:
        MarioLevelState();
        virtual ~MarioLevelState();

 void Render();
 void Update();
 bool OnEnter();
 bool onExit();
 void resume();
 void LoadGround();
 void LoadData1();
 void LoadPannel();
 void LoadPlayer();
 void LoadEnemies();
 void LoadItems();
 void DrawMarioObjects();

  SDLGameObject* Add(std::string type,int x,int y);
 std::string GetStateID(){return "MarioLevelState"; }
 vec2f player;
  float gravity = 9.98;
vec2f    o,vel,acc,pos;
bool m_bisSelected;
std::string m_isSelectedText;
bool m_topcol,m_botcol,m_Rightcol,m_leftcol;


    float timer;

    protected:

    private:
        MarioPlayer * m_MarioPlayer;
        std::vector<SDLGameObject*>MarioBlocks;
        std::vector<SDLGameObject*>MarioItems;
        std::vector<SDLGameObject*>MarioEnemies;
        std::vector<SDLGameObject*>MarioUIs;
   std::map<std::string,std::string> MarioTypes;
};


#endif // MARIOLEVELSTATE_H
