#ifndef MARIOENEMY_H
#define MARIOENEMY_H


#include <string.h>
#include <SDLGameObject.h>
typedef enum
{
    GreenTurtle,RedTurtle,BlueTurtle,
    Goomba,BlueGoomba,GreyGoomba,
    ManEatingPlant,GreyManEatingPlant,
    HammerThrowTurtle,GreyHammerThrowTurtle,
    Browser
}   MarioEnemyType;

class MarioEnemy : public SDLGameObject
{
public:
    MarioEnemy();
    virtual ~MarioEnemy();
    void Load(char* filename) ;
    void Draw()
    {
        //    TextureManager::Instance()->SetColour(0,0,255,29,Game::Instance()->GetRenderer());
        SDLGameObject::Draw();
    }
    void Clean() {}
    void Collision() {}
    std::string Texture()
    {
        return "Mario";
    }
protected:

private:
    int m_EmenyState;
    std::string m_Enemytype;

};

class MarioEnemyObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioEnemy();
    }
};

#endif // MARIOENEMY_H
