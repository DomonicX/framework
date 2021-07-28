#ifndef GAMESETTINGLAYER_H
#define GAMESETTINGLAYER_H

#include <GameObject.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <Game.h>
#include <ILayer.h>
#include <iostream>
#include <ILayer.h>
#include <Vector2D.h>
#include <fstream>
#include <istream>
#include <string.h>
class GameSettingLayer : public ILayer
{
public:
    GameSettingLayer(SDL_Rect hitBot);
    virtual ~GameSettingLayer();

    void Render();
    void Update(Level* pLevel);
protected:

private:
    bool spacePressed;
    unsigned int m_numberofBlocks;
    unsigned int m_Margin;
    unsigned int m_Spacing;
    unsigned int m_CellSize;
    int m_numOfTowers;
    int m_numOfEnemies;
    vec2f m_mouse;

    SDL_Rect m_hb;
    SDL_Rect* SelectedRect;
bool startWave;
std::vector<std::string*>m_gameobjectlist;
std::vector<SDL_Rect*>m_gameobjectlistRect;
std::vector<std::string*>m_gameobjectTowerlist;
std::string m_gold;
std::string m_bonus;
std::string m_Lives;
std::string m_Interest;
std::string m_MaxWave;
std::string m_Score;
SDL_Rect m_RectWaveStart;
int towerSize = 0;
int EnemeySize = 0;
    SDL_Rect m_RectAutoWaveStart;
    SDL_Rect* SelectedRectWaveStart;
    SDL_Rect* SelectedAutoRectWaveStart;

};
#endif // GAMESETTINGLAYER_H
