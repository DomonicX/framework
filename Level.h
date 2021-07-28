#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <ILayer.h>
#include <Game.h>
#include <GameObjectFactory.h>
#include <string.h>
#include <TowerObject.h>
#include <Node.h>
#include <EnemyObject.h>
class Level
{
public:
    Level(std::string *FilePath,std::string *FileMap);
    ~Level();
    void Update();
    void Render();
//void save();
    bool isToggleAutoWave();
    bool isButtonStartWave();
    void setToggleAutoWave(bool setAuto) ;
    void setButtonStartWave(bool setAuto);
    void SetGold(int newgold);
    bool LoadMap(std::string *FilePath,std::string *FileMap);

    TowerObject* GetTower(int index);
    EnemyObject* GetEnemy(int index);
    GameObject* GetGameObject(int index);
    SDL_Point* GetMousePos();
    int getGold();
    int getBonus();
    int getInterest();
    int getLives();
    int getWaveCounter();
    int getMaxWave();
    int getScore();
    void ClearGameObject(std::string str);
    void ClearGameObjects();
    void SetLives(int lives);
    int  GetGameObjectSize();
    bool isSelected();

    void IncreaseWaveCounter();
    void Add(GameObject *g);
    void Add(std::string type,std::string filePath);
    bool isWaveStarted();
    void StartWave();
protected:

private:
    bool m_bToggleAutoWave;
    bool m_bButtonStartWave;
    int m_WaveCounter;
    int m_MaxWave;
    int m_Lives;
    int m_Gold;
    int m_Score;
    int m_Interest;
    int m_Bonus;
    int m_TileSize ;
    int  m_columns ;
    int  m_rows ;
    bool m_bIsWaveStarted;

    GameObject *m_Selected = nullptr;

    std::vector<ILayer*>m_layers;
    std::vector<GameObject*>m_gameObject;




//    GameObject *m_player;

};


#endif // LEVEL_H


//spawner->pathFinder->isDiagonal = false;
//spawner->pathFinder->isCrossCorner = false;
//spawner->pathFinder->FindPath(*node,&startgrid,&endNode);
//
//IPathFinder *PathFinder = new PathFinderAstar();
//
//Node endNode;
//Node startgrid;
//
//spawner->pathFinder->isDiagonal = false;
//spawner->pathFinder->isCrossCorner = false;
//spawner->pathFinder->FindPath(*node,&startgrid,&endNode);
