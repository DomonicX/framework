#include "TowerObject.h"
#include <CollisionManager.h>

TowerObject::TowerObject()
{
    m_width = 50;
    m_height = 50;
    m_Cost = 0;
    m_mark = 0;
    m_dmg = 0;
    m_position = vec2f(0,0);
    m_srcRect = {0,0,0,0};
    m_desRect = {0,0,0,0};
    m_Tstate = new TowerState(true,0,0,0,0,0,0,"NA","NA","NA");
    m_reloadTimer = 0.0f;
    numberofTargets = 0;
    m_isHighLit = false;
    m_Ammo = 1;
    m_MaxAmmo = m_Ammo;
    m_MaxReloadTimer =1.0f;
}

TowerObject::~TowerObject()
{
    delete m_Tstate;
}

void TowerObject::Load(char* filename)
{
    std::ifstream ifs;
    m_filename = filename;
    ifs.open (m_filename, std::ifstream::in);
    ifs >> m_Tstate->m_type;
    ifs>> m_position.x;
    ifs>> m_position.y;
    ifs >>  m_textureID;
    ifs >> m_Tstate->m_BonusDmgType;
    ifs >> m_Tstate->m_WeakDmgType;
    ifs >> m_Tstate->m_width;
    ifs >> m_Tstate->m_height;
    ifs >> m_Tstate->m_Cost;
    ifs >> m_Tstate->m_dmg;
    ifs >> m_Tstate->m_Range;
    ifs >> m_Tstate->m_level;
    ifs >> m_Tstate->m_bhighLight;
    ifs >> m_srcRect.x >> m_srcRect.y >> m_srcRect.w >> m_srcRect.h;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;

    ifs.close();

    m_width =  m_Tstate->m_width;
    m_height = m_Tstate->m_height;
    m_mark = m_Tstate->m_Range;

//std::cout << "\nn ty[e" << m_type;
    // CollisionManager::Instance()->add(this);

}
void TowerObject::Update()
{
    if(IsMouseOver())
    {

        m_isHighLit = true;
    }
    else
    {
        m_isHighLit = false;
    }
    Reload();

}
void TowerObject::Draw()
{
    //SDL_QueryTexture()
   // SDL_SetTextureColorMod(TextureManager::Instance()->getTextureMap()[m_textureID],255,0,0);
//SDL_SetTextureAlphaMod(TextureManager::Instance()->getTextureMap()[m_textureID],0);
    SDL_Rect tempdesRect =   m_desRect;
    tempdesRect.x = m_position.x;
    tempdesRect.y = m_position.y;
    tempdesRect.w = tempdesRect.w;
    tempdesRect.h = tempdesRect.h;
    TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),
                                       "TowerBase",
                                        &m_srcRect, &tempdesRect,
                                        NULL,
                                        NULL,SDL_FLIP_NONE);
    TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),
                                       m_textureID,
                                        &m_srcRect, &tempdesRect,
                                        NULL,
                                        NULL,SDL_FLIP_NONE);
    if(m_isHighLit)
    {
        m_Tstate->DrawShopDetails();
        TextureManager::Instance()->DrawCircleFilled( Game::Instance()->GetRenderer(),
                                                     GetPosition().x+((m_width/2)/2),
                                                     GetPosition().y+((m_height/2)/2),
                                                     m_Tstate->m_Range);
    }
}
void TowerObject::Reload()
{
    if(!HasAmmo())
        m_reloadTimer += Game::Instance()->GetDeltaTime();

    if(m_reloadTimer>=m_MaxReloadTimer)
    {
        m_reloadTimer = 0;
        if(m_Ammo>=m_MaxAmmo)

        {
            m_Ammo = m_MaxAmmo;
        }
        m_Ammo ++;
    }

}

std::string TowerObject::GetType()
{
    return m_Tstate->m_type;
}
void TowerObject::Collision()
{

} void  TowerObject::SetHighLighted(bool highLight)
{
    m_bhighLight = highLight;
}
bool  TowerObject::HasHighLit()
{
    return m_bhighLight;
}
void TowerObject::SetTowerInfo(int cost,int Mark,int dmg )
{
    m_Cost = cost;
    m_mark = Mark;
    m_dmg = dmg;
}
bool TowerObject::IsMouseOver()
{
    vec2f l_mousePos = InputHandler::Instance()->GetMousePosition();
    SDL_Point l_mousePoint =  {l_mousePos.x,l_mousePos.y};

    SDL_Rect tempdesRect =   m_desRect;
    tempdesRect.x = m_position.x;
    tempdesRect.y = m_position.y;
    tempdesRect.w = tempdesRect.w/4;
    tempdesRect.h = tempdesRect.h/4;

    if(InputHandler::Instance()->MousePointInRect(l_mousePoint,tempdesRect))
    {
        return true;
    }
    return false;
}
void TowerObject::HandleEvent(SDL_Event& e )
{

}

std::string TowerObject::GetBonusDmgType()
{
    return m_Tstate->m_BonusDmgType;
}
std::string TowerObject::GetWeakDmgType()
{
    return m_Tstate->m_WeakDmgType;
}
int TowerObject::GetRange()
{
    return  m_Tstate->m_Range;
}
int TowerObject::GetDmg()
{
    return  m_Tstate->m_dmg;
}
int TowerObject::GetCost()
{
    return m_Tstate->m_Cost;
}
std::string TowerObject::Type()
{
    return "Towers";
}

bool TowerObject::HasAmmo()
{
    if(!m_Ammo)return false;
    else return true;
}
void TowerObject::shoot()
{
    if(HasAmmo())m_Ammo --;
}
vec2f& TowerObject::GetAcceleration()
{
    return m_acceleration;
}
vec2f& TowerObject::GetVelocity()
{
    return m_velocity;
}
int TowerObject::getHeight()
{
    return m_height;
}
int TowerObject::getWidth()
{
    return m_width;
}

//    if(HasAmmo())
//    {
//        for(int i = 0; i < m_Ammo ; i++)
//            TextureManager::Instance()->DrawRect(m_position.x+i*10,m_position.y,6,6,Game::Instance()->GetRenderer());
//    }

//
//    m_bCollision = false;
//    m_bIsReloading = false;
//    m_bIsReloading = false;
//    m_bIsFiring = false;
//    dTime = SDL_GetTicks();
//
//
// vec2f l_mousePos = InputHandler::Instance()->GetMousePosition();
//    SDL_Point l_mousePoint =  {l_mousePos.x,l_mousePos.y};
//if(SDL_PointInRect(&l_mousePoint,&m_desRect))
//std::cout << "sdsdsdsds\n handlevent\n";

//  if(HasReloading())
//    {
//        setCollision(false);
//        // setBullet(false);/////////////
//    }
//    else
//    {
//        setCollision(true);
//        //  setBullet(true);
//
//    }
// setCollision(false);
//  if(HasReloading())
//    {
//        if(Game::Instance()->getRandomNumber()%100  < 1)
//        {
//            setReloading(false);
//        }
//    }
//  //  CollisionManager::Instance()->ScanForEnemy(this);
//
//
//
//
//    // if(IsFiring()   && m_currentTimer<=dTime)
//    // {
////std::cout  << "IsFiring() && m_currentTimer>=dTime) \n" ;
//
//    //     m_bIsFiring = false;
//    //      m_bIsReloading = false;
//    // }
//bool TowerObject::HasCollision()
//{
//    return m_bCollision;
//}
//void TowerObject::setCollision(bool isCollision)
//{
//    m_bCollision = isCollision;
//}
//
//bool TowerObject::HasReloading()
//{
//    return  m_bIsReloading;
//}
//void TowerObject::setReloading(bool isReloading)
//{
//    m_bIsReloading = isReloading;
//}

//if(HasBullet())
//    {
//        setBullet(true);
//    }

//
//bool TowerObject::HasBullet()
//{
//}
//void TowerObject::setBullet(bool isBullet)
//{
//
//}
//   TextureManager::Instance()->DrawCircleOutLined( Game::Instance()->GetRenderer(),GetPosition().x+((m_width/2)/2),GetPosition().y+((m_height/2)/2),m_Tstate->m_Range+1);
//  TextureManager::Instance()->DrawCircleOutLined( Game::Instance()->GetRenderer(),GetPosition().x+((m_width/2)/2),GetPosition().y+((m_height/2)/2),m_Tstate->m_Range-1);


// std::cout << "Collision\n";




//    SDL_Point tempMousePoint =
//    {
//        InputHandler::Instance()->GetMousePosition().x,
//        InputHandler::Instance()->GetMousePosition().y
//    };
//
//
//    if(SDL_PointInRect(&tempMousePoint,&tempdesRect))
//    {
//        TextureManager::Instance()->DrawCircleOutLined( Game::Instance()->GetRenderer(),GetPosition().x+((m_width/2)/2),GetPosition().y+((m_height/2)/2),m_Tstate->m_Range);
//
//    }












//   std::cout << " filename "<<  filename << "\n\n";
//  std::string tempname = filename;

//  m_Tstate->Printdetails();// m_position = vec2f(m_desRect.x,m_desRect.y);
//    std::cout << "    " << m_srcRect.w << "    m_srcRectw\n";
//    std::cout << "    " << m_srcRect.x<< "    m_srcRectx\n";
//    std::cout << "    " << m_srcRect.y << "    m_srcRecty\n";
//    std::cout << "    " << m_srcRect.h << "    m_srcRecth\n";
//std::ofstream &write
//write.open(currentMap.mapFileName.c_str());
//  m_srcRect.y = 444;

//update
//    if(m_bIsReloading)
//    {
//        if(m_bIsFiring)
//        {
//            //  std::cout << "m_bIsFiringm_bIsFiring\n \n";
//            m_bIsFiring = false;
//        }
//        m_ReloadTimer--;
//        if(m_ReloadTimer==0)
//        {
//            m_ReloadTimer = 100;
//            m_bIsReloading = false;
//
//        }
//    }


//collision


//
//    if(!m_bIsReloading)
//    {
//        if(!m_bIsFiring)
//            if(m_ReloadTimer==0)
//            {
//                m_ReloadTimer = 100;
//                m_bIsFiring= true;
//                m_bIsReloading = true;
//            }
//    }


//
//     {
//        std::string dd = m_Tstate->m_type + ".txt";
//        std::ofstream ifs;
//        ifs.open (dd, std::ofstream::out);
////        ifs << GetData()->m_level        << "m_level\n";
////
////        ifs << GetCost()                << "GetCost\n";
////        ifs << GetData()->m_bhighLight  << "m_bhighLight\n";
////        ifs << GetDmg()                 << "GetDmg\n";
////        ifs << GetMark()                << "m_mark\n";
////        ifs <<GetData()->m_weaknessType << "m_weaknessType\n";
//
//        ifs << "<m_type>"<< "\n";
//        ifs << "<>" << m_Tstate->m_type      << "\n";
//        ifs  << "<m_type>\n"<< "\n";
//
//        ifs << "<m_textureID>"<< "\n";
//        ifs << "<>" << m_textureID      << "\n";
//        ifs    << "<m_textureID>\n"<< "\n";
//
//        ifs << "<m_height>"<< "\n";
//        ifs << "<>" << m_height      << "\n";
//        ifs    << "<m_height>\n"<< "\n";
//
//        ifs << "<m_width>"<< "\n";
//        ifs << "<>" << m_width      << "\n";
//        ifs    << "<m_width>\n"<< "\n";
//
//        ifs << "<m_srcRect>"<< "\n";
//        ifs <<  "<>" << m_srcRect.x              << "\n";
//        ifs << "<>" << m_srcRect.y              << "\n";
//        ifs << "<>" << m_srcRect.w              << "\n";
//        ifs << "<>" << m_srcRect.h              << "\n";
//        ifs <<"m_srcRect>"<< "\n";
//
//
//        ifs << "<m_desRect>"<< "\n";
//        ifs  << "<>" << m_desRect.x              << "\n";
//        ifs << "<>" << m_desRect.y              << "\n";
//        ifs << "<>" << m_desRect.w              << "\n";
//        ifs << "<>" << m_desRect.h              << "\n";
//        ifs <<"m_desRect>"<< "\n";
//        ifs <<"m_pos>\n<>" << m_position.x << "\n<>" << m_position.y << "\n";
//
//
//    }

//    if(isMouseOver)
//      //  TextureManager::Instance()->DrawTarget(m_textureID,m_cropx,m_cropy,m_position.x,m_position.y,25,25,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);
//  //  SDL_RenderDrawLine(Game::Instance()->GetRenderer(),m_position.x,m_position.y,m_position.x+Game::Instance()->getWindowWidth()*0.05,m_position.y);
//    if(isSelected)
//    {
//        m_position = InputHandler::Instance()->GetMousePosition();
//
//
//}//    SDL_Point m_mouse = { InputHandler::Instance()->GetMousePosition().x, InputHandler::Instance()->GetMousePosition().y};
//    SDL_Rect l_rect = {m_position.x,m_position.y,24,24};
//    if(SDL_PointInRect(&m_mouse,&l_rect) && !isSelected)
//    {
//        isMouseOver = true;
//    }
//    else
//        isMouseOver = false;
//
//
//    if(isSelected)
//    {
//        m_position = InputHandler::Instance()->GetMousePosition();
//    }
//
//    if(isMouseOver &&
//            !isSelected &&
//            InputHandler::Instance()->GetMouseButtonState(LEFT))
//    {
//        isMouseOver = false;
//        isSelected = true;
//        std::cout << m_textureID << "\n";
//    }

