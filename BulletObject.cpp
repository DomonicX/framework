#include "BulletObject.h"

#include <EnemyObject.h>
BulletObject::BulletObject()
{
    //  std::cout << "bulletCreated                        ";
    m_width = 8;
    m_height = 8;
    //  m_velocity = vec2f(Game::Instance()->getRandomNumber()%2,Game::Instance()->getRandomNumber()%2);
    r = g = b = a = 0;
    m_bDead = false;
    m_damage = 10;
    m_speed = 3;
    m_alpha = 0;
}

BulletObject::~BulletObject()
{
    std::cout << "deleting bullet\n";
}
void BulletObject::Load(char* filename)
{
    //std::cout << "loaded " << filename << " \n";

    if(m_towertype == "Green_Laser_1" || m_towertype == "Green_Laser_2" || m_towertype == "Green_Laser_3")
    {

    }

    if(m_towertype == "Red_Refractor" || m_towertype == "Little_Red_Spammer" || m_towertype == "Red_Rockets")
    {

    } if(m_towertype == "Purple_Power_1" || m_towertype == "Purple_Power_2" || m_towertype == "Purple_Power_3")
    {

    } if(m_towertype == "Blue_Ray_1" || m_towertype == "Blue_Rays_2")
    {

    }
}
void BulletObject::Draw()
{

    if(!Dead() && !m_enemy->Dead())
    {
        TextureManager::Instance()->SetColour(r,g,b,a,Game::Instance()->GetRenderer());

        if(m_towertype == "Green_Laser_1")
            TextureManager::Instance()->DrawLine(m_position.x,m_position.y,m_enemy->GetPosition().x,m_enemy->GetPosition().y,Game::Instance()->GetRenderer());
        if(m_towertype == "Green_Laser_2")
            TextureManager::Instance()->DrawLine(m_position.x,m_position.y,m_enemy->GetPosition().x,m_enemy->GetPosition().y,Game::Instance()->GetRenderer());
        if(m_towertype == "Green_Laser_3")
            TextureManager::Instance()->DrawLine(m_position.x,m_position.y,m_enemy->GetPosition().x,m_enemy->GetPosition().y,Game::Instance()->GetRenderer());
        if(m_towertype == "Red_Refractor")
            TextureManager::Instance()->DrawRectFilled(m_position.x-m_width/2,m_position.y-m_height/2,m_width,m_height,Game::Instance()->GetRenderer());
        if(m_towertype == "Little_Red_Spammer")
            TextureManager::Instance()->DrawRectFilled(m_position.x-m_width/2,m_position.y-m_height/2,m_width,m_height,Game::Instance()->GetRenderer());
        if(m_towertype == "Red_Rockets")
            TextureManager::Instance()->DrawRectFilled(m_position.x-m_width/2,m_position.y-m_height/2,m_width,m_height,Game::Instance()->GetRenderer());
        if(m_towertype == "Purple_Power_1")
            TextureManager::Instance()->DrawRectFilled(m_position.x-m_width/2,m_position.y-m_height/2,m_width,m_height,Game::Instance()->GetRenderer());
        if(m_towertype == "Purple_Power_2")
            TextureManager::Instance()->DrawRectFilled(m_position.x-m_width/2,m_position.y-m_height/2,m_width,m_height,Game::Instance()->GetRenderer());
        if(m_towertype == "Purple_Power_3")
            TextureManager::Instance()->DrawRectFilled(m_position.x-m_width/2,m_position.y-m_height/2,m_width,m_height,Game::Instance()->GetRenderer());
        if(m_towertype == "Blue_Ray_1")
            TextureManager::Instance()->Drawcircle(Game::Instance()->GetRenderer(),m_position.x,m_position.y,8);
        if(m_towertype == "Blue_Rays_2")
            TextureManager::Instance()->Drawcircle(Game::Instance()->GetRenderer(),m_position.x,m_position.y,8);



    }
}
void BulletObject::Update()
{

    if(!Dead() && !m_enemy->Dead())
    {
        EnemyObject* t;
        t = (EnemyObject*)m_enemy;
        if(t->IsAtEnd())
        {
            m_bDead = true;
        }

        //  if(dynamic_cast<EnemyObject*>)
//*2
        m_acceleration = vec2f(0.1,-0.1);
        vec2f l_temp = vec2f(m_enemy->GetPosition()-m_position);
        m_velocity = l_temp.Normalise();
        m_position += m_velocity * m_speed ;

        float  s = m_enemy->GetPosition().Dist(m_position);
        std::cout << s << "\n";

//        m_velocity -= m_acceleration * Game::Instance()->GetDeltaTime() * Game::Instance()->GetDeltaTime();

        if(m_enemy->GetPosition().Dist(m_position) == 0.0 ||
                m_enemy->GetPosition().Dist(m_position)<=0.99)
        {
            Collision();
            //   m_bDead = true;
        }


    }
}
void BulletObject::Clean()
{
    m_enemy = nullptr;

}
void BulletObject::Collision()
{
    EnemyObject &enemyObj = *(EnemyObject*)m_enemy;
    enemyObj.SetLife(this->m_damage);
    m_enemy->Collision();
    m_bDead = true;
}
std::string BulletObject::Type()
{
    return "Bullet";
}
// if(m_towertype == "Green_Laser_1" || m_towertype == "Green_Laser_2" || m_towertype == "Green_Laser_3") {}
//    if(m_position.x >   Game::Instance()->GetWindowWidth() ||
//                m_position.y > Game::Instance()->GetWindowHeight() ||
//                m_position.x < 0 || m_position.y < 0)
//        {
//            //  m_bDead = true;
//
//        }
