#ifndef MARIOITEM_H
#define MARIOITEM_H

#include <string.h>
#include <SDLGameObject.h>

typedef enum
{
    RedMushroom,
    GreenMushroom,
    Coin,
    StarPower,
    FireFlower
}   MarioItemType;

class MarioItem : public SDLGameObject
{
public:
    MarioItem();
    virtual ~MarioItem();

    void Load(char* filename);
     void Update() ;
    void Clean();
    void Collision();
    std::string Texture()
    {
        return "Mario";
    }

protected:

private:
    std::string m_Itemtype;
};


class  MarioItemObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioItem();
    }
};






#endif // MARIOITEM_H
