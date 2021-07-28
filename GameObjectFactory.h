#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#include <map>
#include <iostream>
#include <iterator>
#include <string.h>
#include <GameObject.h>

class BaseCreater
{
public :
    virtual GameObject* CreateGameObject() const = 0;
     ~BaseCreater() {std::cout << " deleting basecreater \n";}
};


class GameObjectFactory
{
public:
    static GameObjectFactory* Instance()
    {
        if(s_pInstance==NULL) s_pInstance = new GameObjectFactory();
        return s_pInstance;
    }
    bool registerType(std::string typeID, BaseCreater* pCreator);
    GameObject* Create(std::string typeID);
protected:


private:
    GameObjectFactory() {}
    virtual ~GameObjectFactory() {}
    std::map<std::string,BaseCreater*>m_creator;
    static GameObjectFactory* s_pInstance;
};


#endif // GAMEOBJECTFACTORY_H
