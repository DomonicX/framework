#ifndef TOWERSTATE_H
#define TOWERSTATE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>
#include <TextureManager.h>
#include <Game.h>
class TowerState
{
public:

    TowerState(bool highLight, int width,int height,int cost, int mark, int dmg, int level,std::string BonusDmgType,std::string WeakDmgType,std::string type )
        :
        m_bhighLight(highLight),
        m_width(width),
        m_height(height),
        m_Cost(cost),
        m_dmg(dmg),
        m_level(level),
        m_BonusDmgType(BonusDmgType),
        m_WeakDmgType(WeakDmgType),
        m_type(type)
        {};

        void Printdetails();

          void DrawShopDetails();

    bool m_bhighLight;
    int m_width;
    int m_height;
    int m_Cost;
    int m_Range;
    int m_dmg;
    int m_level;
    std::string m_BonusDmgType;
    std::string m_type;
std::string m_WeakDmgType;
     ~TowerState();

protected:

private:

};

#endif // TOWERSTATE_H
