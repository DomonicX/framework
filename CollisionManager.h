#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include <vector>
#include <SDL2/SDL.h>
#include <GameObject.h>
#include <iostream>
#include <Game.h>
#include <ILayer.h>
#include <TowerObject.h>
#include <EnemyObject.h>
#include <Node.h>
class CollisionManager
{
public:
    CollisionManager();
    static CollisionManager* Instance()
    {

        if(s_pInstance == NULL)
        {
            s_pInstance = new CollisionManager();
            return s_pInstance;
        }
        return s_pInstance;
    }

    virtual ~CollisionManager();
    void add(TowerObject* tower)
    {
        m_TowerObjects.push_back(tower);
    }
    void add(EnemyObject* Enemy)
    {
        m_EnemyObjects.push_back(Enemy);
    }


    void ScanForEnemy(TowerObject* tower)
    {

    }
//        if(tempin!=0)
//        {
//
//               std::cout <<  tempin <<  "  " << tower->GettextureID()<< " tower->numofTarget \n";
//    }
//        }

    ///// }        //     if(!tower->IsFiring())
    //    {
    //  tower->CreateBullet();
    //  tower->Fire();




protected:

private:

    std::vector<EnemyObject*>m_EnemyObjects;
    std::vector<TowerObject*>m_TowerObjects;
    std::vector<SDL_Rect>collisionBlocks;
    static CollisionManager* s_pInstance;

};

#endif // COLLISIONMANAGER_H
