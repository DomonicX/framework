#include "GameSettingLayer.h"
#include "Level.h"
GameSettingLayer::GameSettingLayer(SDL_Rect hitBot) : m_hb(hitBot)
{
    startWave = false;

    SelectedAutoRectWaveStart = nullptr;
    SelectedRectWaveStart = nullptr;
    SelectedRect = nullptr;


    m_RectWaveStart= m_hb;

    m_RectWaveStart.w=m_RectWaveStart.w/2 - 180;
    m_RectWaveStart.h=m_RectWaveStart.h/2 - 5;
    m_RectWaveStart.x+=m_RectWaveStart.x/2 + 230;
    m_RectWaveStart.y+=m_RectWaveStart.y/2;

    m_RectAutoWaveStart= m_hb;

    m_RectAutoWaveStart.w=m_RectAutoWaveStart.w/2 - 180;
    m_RectAutoWaveStart.h=m_RectAutoWaveStart.h/2 - 5;
    m_RectAutoWaveStart.x+=m_RectAutoWaveStart.x/2 + 230;
    m_RectAutoWaveStart.y+=m_RectAutoWaveStart.y/2;
    m_RectAutoWaveStart.y = m_RectWaveStart.y+ m_RectWaveStart.h +3;

//    SDL_Rect label;
//    label = { m_hb.x,m_hb.y,m_hb.w,m_hb.h*0.14};  SDL_SetRenderDrawColor( Game::Instance()->GetRenderer(),23,200,2,26);
//    SDL_RenderDrawRect(Game::Instance()->GetRenderer(),&label);
//
}
//gamelevelgrid x 22 y = 18
GameSettingLayer::~GameSettingLayer()
{
    //dtor
}

void GameSettingLayer::Render()
{
    // SDL_RenderDrawRect(Game::Instance()->GetRenderer(),&m_RectWaeStart);

 TextureManager::Instance()->SetColour(2,255,255,255,Game::Instance()->GetRenderer());
 TextureManager::Instance()->DrawRect(m_hb.x,m_hb.y,m_hb.w,m_hb.h,Game::Instance()->GetRenderer());
    if(SelectedRect!=NULL)
    {
        //   SDL_RenderFillRect(Game::Instance()->GetRenderer(),SelectedRect);
    }
    if(SelectedAutoRectWaveStart!=NULL)
    {
 TextureManager::Instance()->SetColour(255,255,255,255,Game::Instance()->GetRenderer());
        SDL_RenderFillRect(Game::Instance()->GetRenderer(),SelectedAutoRectWaveStart);
    }


    TextureManager::Instance()->DrawText(m_Interest,350,60,10,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText(m_MaxWave,350,40,10,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText(m_Score,350,20,10,Game::Instance()->GetRenderer());


    TextureManager::Instance()->DrawRect(m_RectWaveStart.x,m_RectWaveStart.y,
                                         m_RectWaveStart.w,m_RectWaveStart.h,
                                         Game::Instance()->GetRenderer());

    TextureManager::Instance()->DrawRect(m_RectAutoWaveStart.x,m_RectAutoWaveStart.y,
                                         m_RectAutoWaveStart.w,m_RectAutoWaveStart.h,
                                         Game::Instance()->GetRenderer());

    TextureManager::Instance()->DrawText(m_gold,450,20,10,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText(m_bonus,450,40,10,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText(m_Lives,450,60,10,Game::Instance()->GetRenderer());

    if(!m_gameobjectlistRect.empty())
    {

        for(int i = 0; i < m_gameobjectlistRect.size(); i++)
        {
//            TextureManager::Instance()->DrawRect(m_gameobjectlistRect[i]->x,m_gameobjectlistRect[i]->y,
//                                                 m_gameobjectlistRect[i]->w,m_gameobjectlistRect[i]->h,
//                                                 Game::Instance()->GetRenderer());
//
//            TextureManager::Instance()->DrawText(*m_gameobjectlist[i],m_gameobjectlistRect[i]->x,m_gameobjectlistRect[i]->y,Game::Instance()->GetRenderer());
        }

    }
 TextureManager::Instance()->SetColour(0,0,0,255,Game::Instance()->GetRenderer());
}
void GameSettingLayer::Update(Level* pLevel)
{
    m_gold =        "Gold       | " + std::to_string(pLevel->getGold());
    m_bonus =       "Bonus    | " +std::to_string(pLevel->getBonus());
    m_Lives =       "Lives      | " + std::to_string(pLevel->getLives());
    m_Interest =    ("Interest   | " + std::to_string(pLevel->getInterest()))+"%";
    m_MaxWave = "Wave       |"+ std::to_string(pLevel->getWaveCounter()) + " /"+ std::to_string(pLevel->getMaxWave())  ;
    m_Score = "Score       | " + std::to_string(pLevel->getScore())  ;


    // std::cout << m_gold << "\n";
//

    if(pLevel->GetGameObjectSize() != 0)
        if(pLevel->GetGameObjectSize() != m_gameobjectlist.size())
            for(int i = m_gameobjectlist.size(); i < pLevel->GetGameObjectSize(); i++)
            {
                m_gameobjectlist.push_back(new std::string(pLevel->GetGameObject(i)->Type()));
                if(pLevel->GetGameObject(i)->Type()=="Towers")
                {
                    towerSize++;
                    m_gameobjectlistRect.push_back(new SDL_Rect{630,(towerSize*18)+180,65,18});

                }
                else if(pLevel->GetGameObject(i)->Type()=="Enemy")
                {
                    EnemeySize++;
                    m_gameobjectlistRect.push_back(new SDL_Rect{550,(EnemeySize*18)+180,55,20});

                }
            }
    if(SDL_PointInRect(pLevel->GetMousePos(),&m_RectAutoWaveStart))
    {

        if(InputHandler::Instance()->GetMouseButtonState(SDL_BUTTON_LEFT))
        {

            if(pLevel->isToggleAutoWave()==false)
            {
                pLevel->setToggleAutoWave(true);
                SelectedAutoRectWaveStart  = &m_RectAutoWaveStart;
            }
            else
            {
                pLevel->setToggleAutoWave(false);
                SelectedAutoRectWaveStart  = nullptr;
            }

        }
    }

    SelectedRectWaveStart = nullptr;
    if(SDL_PointInRect(pLevel->GetMousePos(),&m_RectWaveStart))
    {
        if(InputHandler::Instance()->GetMouseButtonState(SDL_BUTTON_LEFT))
        {
            SelectedRectWaveStart = &m_RectWaveStart;
            pLevel->setButtonStartWave(true);
            pLevel->StartWave();
            //    std::cout << "SelectedRectWaveStart\n";
        }

    }
    SelectedRect = nullptr;
    if(SDL_PointInRect(pLevel->GetMousePos(),&m_hb))
    {
        if(InputHandler::Instance()->GetMouseButtonState(SDL_BUTTON_LEFT))
        {
            SelectedRect = &m_hb;
            //      std::cout << "SelectedRect\n";
        }

    }
    // std::cout  << "plevelm_gamesize() " << pLevel->GameObjectsSize() << "\n ";
}









//              std::cout << *m_gameobjectlist[i] << "\n";
//                if(*m_gameobjectlist[i]=="Green_Laser_1")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Green_Laser_2")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Green_Laser_3")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Blue_Ray_1")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Blue_Ray_2")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Purple_Power_1")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Purple_Power_2")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Purple_Power_3")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Red_Refractor")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Little_Red_Spammer")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
//                if(*m_gameobjectlist[i]=="Red_Rockets")
//                {
//                    m_gameobjectTowerlist.push_back(std::move(m_gameobjectlist[i]));
//
//                    m_gameobjectlist.pop_back();
//                    break;
//                }
