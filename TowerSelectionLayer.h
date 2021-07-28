#ifndef TOWERSELECTIONLAYER_H
#define TOWERSELECTIONLAYER_H
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <Game.h>
#include <ILayer.h>
#include <iostream>
#include <vector>
#include <TowerObject.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <SDL2/SDL_rect.h>
#include <fstream>
#include <ostream>
#include <Vector2D.h>
#include <Node.h>
#include <iostream>
#include <cstring>
#include <string>
#define NumOfTowerType 12

class shopitem
{
public :
    std::string m_tag;
    std::string m_shopItemName;
    int m_cost;
    bool m_bIsHighlit;
    SDL_Rect m_desrect;
    SDL_Rect m_screct;

};

class TowerSelectionLayer : public ILayer
{
public:

    TowerSelectionLayer();
    TowerSelectionLayer(SDL_Rect hitBot,int TileSize,std::vector<Node*> TowerPath);
    ~TowerSelectionLayer();
    void Update(Level* pLevel);
    void Render();
    bool isTowerSelected(Level* pLevel);
void BuyItem(Level* pLevel);
void PlaceItem(Level* pLevel);
protected:

private:

    bool leftClickPressed = false;
    shopitem m_shopitems[NumOfTowerType];
    int m_tileSize;
    SDL_Rect label;
    SDL_Rect  m_hb;
    SDL_Rect* SelectedRect;
    GameObject * m_selectedTower;
    std::vector<Node*>  m_TowerPath;
};
#endif // TOWERSELECTIONLAYER_H
//      void LoadData();// std::cout// std::string  // std::stringstream
