#include "BulletLayer.h"
BulletLayer::BulletLayer()
{
    //ctor
}

BulletLayer::~BulletLayer()
{
    //dtor
}


void BulletLayer::Update(Level* pLevel)
{
    ShootAtEnemy(pLevel);
}

void  BulletLayer::ShootTower(int TowerIndex,int EnemyIndex, Level* pLevel)
{

    if(pLevel->GetTower(TowerIndex)->HasAmmo())
    {

        pLevel->GetTower(TowerIndex)->shoot();
        GameObject *bt = GameObjectFactory::Instance()->Create("Bullet");
        BulletObject &btt = *(BulletObject*)bt;

        btt.GetPosition() = pLevel->GetTower(TowerIndex)->GetPosition();
        btt.SetBulletType(pLevel->GetTower(TowerIndex)->GetType());
        btt.SetEnemy(*pLevel->GetGameObject(EnemyIndex));
        btt.Load((char*)pLevel->GetTower(TowerIndex)->GetType().c_str());

        pLevel->Add(bt);
    }
}
void BulletLayer::Render() {}

void  BulletLayer::ShootAtEnemy(Level* pLevel)
{
    for(int i = 0 ; i < pLevel->GetGameObjectSize() ; i++)
    {
        if( pLevel->GetGameObject(i)->Type()=="Towers" && pLevel->GetTower(i)->HasAmmo())

        {
            vec2f vT =  pLevel->GetTower(i)->GetPosition();
            int vTrange = pLevel->GetTower(i)->GetRange();

            for(int j = 0 ; j < pLevel->GetGameObjectSize() ; j++)
                if(pLevel->GetGameObject(j)->Type()=="Enemy" && !pLevel->GetGameObject(j)->Dead())
                {
                    vec2f vE =  pLevel->GetGameObject(j)->GetPosition();

                    if(vT.Dist(vE) <= vTrange)
                        ShootTower(i,j,pLevel);
                }
        }
    }
}
//         std::cout << "bulletLayer "<<"   " << j  << " id      " <<pLevel->GetGameObject(i)->GetPosition().x/24 <<  std::endl;




//  bt->GetPosition() =  vT;
// std::cout << btt->getDes()->x << " :: " <<btt->getDes()->y<< " \n";

//    btt-> = true;#
//  bt->GetPosition() = vT;
//   return;
//  pLevel->GetTower(i)->setCollision(true);
//std::cout << bt->GetPosition().x << " " <<   bt->GetPosition().y << "\n";
