#ifndef GAMELEVELLAYER_H
#define GAMELEVELLAYER_H
#include <GameObject.h>
#include <TowerObject.h>
#include <GameObjectFactory.h>
#include <Game.h>
#include <ILayer.h>
#include <iostream>
#include <ILayer.h>
#include <Level.h>

#include <string.h> // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream


class GameLevelLayer: public ILayer
{
public:
    GameLevelLayer();
    GameLevelLayer(SDL_Rect hitBot);
    virtual ~GameLevelLayer();

    void Render();
    void Update(Level* pLevel);
    GameObject * m_selectedMap = nullptr;
    bool selected = false;
protected:

private:


    SDL_Rect m_hb;
    SDL_Rect* SelectedRect;
};

#endif // GAMELEVELLAYER_H
