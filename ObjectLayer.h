#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H


#include <ILayer.h>
#include <CollisionManager.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <Level.h>
#include <Game.h>

class ObjectLayer : public ILayer
{
    public:
        ObjectLayer();
         ~ObjectLayer();
 void Render();
 void Update(Level* pLevel);
   std::vector<GameObject*>* getObjectObjects();
void moveDownShift();
void removeDeadObjects();
    float tick();

    protected:

    private:
        CollisionManager collisionManager;

    std::vector<GameObject*>gameObjects;
    std::vector<std::vector<GameObject*>>gameObjectsPos;



    float m_oldTimer;
    float m_UpdateTimer;
    int speed;
};

#endif // OBJECTLAYER_H
