#ifndef TOWEROBJECT_H
#define TOWEROBJECT_H


#include <SDL2/SDL.h>


#include <iostream>
#include <string.h> // std::string    // std::cout

#include <Game.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <Vector2D.h>

#include <TowerState.h>

struct towerData
{
    bool m_bhighLight;
    int m_width;
    int m_height;
    int m_Cost;
    int m_mark;
    int m_dmg;
    int m_position;
    int m_level;
    SDL_Rect  m_desRect;
    SDL_Rect m_srcRect;
    vec2f m_velocity;
    vec2f m_acceleration;
    std::string  m_textureID;
    std::string BonusDmgType;
    std::string WeakDmgType;
} ;

class TowerObject: public GameObject
{

public:
    TowerObject();
    ~TowerObject();
bool IsMouseOver();
    vec2f& GetAcceleration();
    vec2f& GetVelocity();
    int getHeight();
    int getWidth();
    int GetRange();
    int GetDmg();
    int GetCost();
    std::string GetBonusDmgType();
    std::string GetWeakDmgType();
    bool  HasHighLit();
    std::string GetType();
    bool HasAmmo();
    bool HasBonus() {}

    void SetHighLighted(bool highLight);
    void SetTowerInfo(int cost,int Mark,int dmg );

    void Load(char* filename);
    void Update();
    void Draw();
    void Clean() {};
    void Collision();
    void HandleEvent(SDL_Event& e );
    std::string Type();
    std::string Texture() {};
   void shoot();
    void Reload();


protected:
private:
    int m_height;
    int m_width;

    bool m_isHighLit;
    vec2f m_velocity;
    vec2f m_acceleration;
    std::string m_textureID;
    std::string m_filename;
    int m_Ammo;
    double  dTime;
    int numberofTargets;
    bool m_bCollision;
    bool m_bIsReloading;
    bool m_bIsFiring;
    bool m_bhighLight;
    int m_level;
    int m_mark;
    int m_Cost;
    int m_dmg;
    int m_MaxAmmo;
    float m_reloadTimer;
    float m_MaxReloadTimer;
    std::string BonusDmgType;
    std::string WeakDmgType;
    SDL_Rect m_desRect;
    SDL_Rect m_srcRect;
    TowerState* m_Tstate;
    std::vector<GameObject*>numberOfTargetInRange;
    vec2f m_target;
    int m_emenyId;
};
class  TowerObjectCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new TowerObject();
    }
};


#endif // TOWEROBJECT_H

//    void numofTarget(int NumOfTarget)
//    {
//        numberofTargets = NumOfTarget;
//    }
//
//    bool HasCollision();
//    void setCollision(bool isCollision);

//    bool HasBullet();
//    void setBullet(bool isBullet);
//
//    bool HasReloading();
//    void setReloading(bool isReloading);
