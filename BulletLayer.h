#ifndef BULLETLAYER_H
#define BULLETLAYER_H

#include <Level.h>
#include <ILayer.h>
#include <TowerObject.h>
#include <GameObjectFactory.h>
#include <BulletObject.h>
class BulletLayer : public ILayer
{
public:
    BulletLayer();
    virtual ~BulletLayer();
    void Update(Level* pLevel);
    void Render();
    void ShootAtEnemy(Level* pLevel);
    void  ShootTower(int TowerIndex,int EnemyIndex,Level* pLevel);
protected:

private:
};
#endif // BULLETLAYER_H
