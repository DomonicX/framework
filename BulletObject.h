#ifndef BULLETOBJECT_H
#define BULLETOBJECT_H
#include <Game.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <TextureManager.h>
#include <Vector2D.h>

class BulletObject : public GameObject
{
public:
    BulletObject();
    ~BulletObject();

    void Load(char* filename) ;
    void Draw();
    void Update();
    void Clean();
    void Collision();
    int getHeight()
    {
        return m_height;
    }
    int getWidth()
    {
        return m_width;
    }
    int m_height;
    int m_width;
    std::string m_textureID;
    std::string m_filename;
     std::string Texture(){};

    void SetEnemy(GameObject &enemyobject)
    {
        m_enemy = &enemyobject;


    }

    void SetBulletType(std::string TowerTYPE)
    {
        m_towertype = TowerTYPE;
        if(m_towertype == "Green_Laser_1")
            g = 255,  r = b = a = 0;
        if(m_towertype == "Green_Laser_2")
            g = 255, b = a = 0;
        if(m_towertype == "Green_Laser_3")
            g = 255,r = b = a = 0;
        if(m_towertype == "Red_Refractor")
            r= 255,g= b = a = 0;
        if(m_towertype == "Little_Red_Spammer")
            r= 255,g= b = a = 0;
        if(m_towertype == "Red_Rockets")
            r= 255,g= b = a = 0;
        if(m_towertype == "Purple_Power_1")
            r = 128,b =128;
        if(m_towertype == "Purple_Power_2")
            r = 128,b =128;
        if(m_towertype == "Purple_Power_3")
            r = 128,b =128;
        if(m_towertype == "Blue_Ray_1")
            b= 255,r= g = a = 0;
        if(m_towertype == "Blue_Rays_2")
            b= 255,r= g = a = 0;
    }
    std::string getBulletType()
    {
        return m_towertype;
    }

    std::string Type();
  vec2f& GetAcceleration()
    {
        return m_acceleration;
    }
    vec2f& GetVelocity()
    {
        return m_velocity;
    }
protected:

private:

    vec2f m_velocity;
    vec2f m_acceleration;
    int r,g,b,a;
    double m_angle;
    int m_speed;
    char m_alpha;
    int m_damage;
    vec2f m_target;
    vec2f  m_SpawnPosition;
    int m_enemyIndex;
    GameObject *m_enemy;
    std::string m_towertype;

};

class BulletObjectCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new BulletObject();
    }
};

#endif // BULLETOBJECT_H
