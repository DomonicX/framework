#ifndef WAVELAYER_H
#define WAVELAYER_H
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <Game.h>
#include <ILayer.h>
#include <iostream>
#include <ILayer.h>
#include <Node.h>
#include <IPathFinder.h>
#include <PathFinderAstar.h>
#include <EnemyObject.h>

#include "Level.h"
class WaveLayer  : public ILayer
{
public:
    std::vector<ILayer*>m_layers;

    WaveLayer(SDL_Rect hitBot, std::vector<Node*> wavePath, Level* pLevel);
    virtual ~WaveLayer();

    void Render();
    void Update(Level* pLevel);
    void CreateWave(Level* pLevel);
    void InitWave(Level* pLevel);
    void UpdateWavesPath(Level* pLevel);
    void LoadPath(char *filePath);

bool isWaveCleared(Level* pLevel);
protected:

private:
int startFlag;
    SDL_Rect m_hb;
    SDL_Rect m_gamelevelrect = {11,91,531,435};
    SDL_Rect* SelectedRect;
    IPathFinder *PathFinder = NULL;
    Node *endNode;
    Node *startNode;
    int m_enemySize;
    bool m_bWaveEnded;
    std::vector<vec2f*>m_PathPoints;
    std::vector<Node*> m_wavePath;
    std::vector<GameObject*> m_EnemyObjects;
int m_WaveCounter;

    int counter= 0;
};

#endif // WAVELAYER_H

//        void setStart(int x,int y) {m_wavePath[(x+(y*22)/24)]->ChangeType(Node::START);}
//        void setEnd(int x,int y) {m_wavePath[(x+(y*22)/24)]->ChangeType(Node::END);}
//        void setEnd(Node * Enode) {endNode = Enode;}
