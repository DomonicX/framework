#include "Level.h"
#define White 0 //white //BLUE //RED //GREEN // Black
#define ShowOnlyBackGround 0
#define RED 2
#define  BLUE 3
#define Black -1
#define PURPLE 4
#include "TowerSelectionLayer.h"
#include "GameSettingLayer.h"
#include "GameLevelLayer.h"
#include "WaveLayer.h"
#include "BackGroundLayer.h"
#include "BulletLayer.h"
Level::Level(std::string *FilePath,std::string *FileMap)
{
    m_bIsWaveStarted = false;
    m_bToggleAutoWave = false;
    m_bButtonStartWave= false;
    m_WaveCounter = 0;

    if(LoadMap(FilePath,FileMap))
    {

    }

}
Level::~Level()
{

}

void Level::Add(GameObject *g)
{
    m_gameObject.push_back(std::move(g));
}

void Level::Update()
{

//
    for(int i = 0; i < m_layers.size() ; i++)
        m_layers[i]->Update(this);
    for(int i = 0; i < m_gameObject.size() ; i++)
        m_gameObject[i]->Update();
}

void Level::Render()
{
    for(int i = 0; i < m_layers.size() ; i++)
        m_layers[i]->Render();
    for(int j = 0; j < m_gameObject.size() ; j++)
        m_gameObject[j]->Draw();

}
bool Level::isToggleAutoWave()
{
    return m_bToggleAutoWave;
}
bool Level::isButtonStartWave()
{
    return m_bButtonStartWave;
}
void Level::setToggleAutoWave(bool setAuto)
{
    m_bToggleAutoWave = setAuto;
}
void Level::setButtonStartWave(bool setAuto)
{
    m_bButtonStartWave=  setAuto;
}
int Level::GetGameObjectSize()
{
    return m_gameObject.size();
}
void Level::SetGold(int newgold)
{
    m_Gold = newgold;
}
int Level::getGold()
{
    return m_Gold;
}
int Level::getBonus()
{
    return m_Bonus;
}
int Level::getInterest()
{
    return m_Interest;
}
int Level::getLives()
{
    return m_Lives;
}
int Level::getWaveCounter()
{
    return m_WaveCounter;
}

void Level::SetLives(int lives)
{
    m_Lives = lives;
}

void Level::IncreaseWaveCounter()
{
    m_WaveCounter +=1;
    if(m_WaveCounter>m_MaxWave) m_WaveCounter = m_MaxWave;
}
int Level::getMaxWave()
{
    return m_MaxWave;
}
int Level::getScore()
{
    return m_Score;
}
bool Level::isSelected()
{
    if(m_Selected!=nullptr)
    {
        return true;
    }
    else return false;
}
void Level::Add(GameObject *g);

void Level::Add(std::string type,std::string filePath)
{
    m_Selected = (GameObjectFactory::Instance()->Create(type));
    m_Selected->Load((char*)filePath.c_str());
};
TowerObject* Level::GetTower(int index)
{
    // std::cout << "GetTower : < < "<< m_gameObject[index]->Type() << "-\n";
    return dynamic_cast<TowerObject*>(m_gameObject[index]);

}
EnemyObject* Level::GetEnemy(int index)
{
    //  std::cout << "GetENemy : < < "<< m_gameObject[index]->Type() << "-\n";
    return dynamic_cast<EnemyObject*>(m_gameObject[index]);

}
GameObject* Level::GetGameObject(int index)
{
    return m_gameObject[index];
}

SDL_Point* Level::GetMousePos()
{
    return new SDL_Point{InputHandler::Instance()->GetMousePosition().x,InputHandler::Instance()->GetMousePosition().y};
}

bool Level::isWaveStarted()
{
    return m_bIsWaveStarted;
}

void Level::StartWave()
{
    if(!isWaveStarted()) m_bIsWaveStarted = true;
};


void Level::ClearGameObjects()
{
    for(int i = 0 ; i < m_gameObject.size(); i ++)
    {
        delete m_gameObject[i];
    }
    m_gameObject.clear();
}
void Level::ClearGameObject(std::string str)
{

    //            std::cout << "\--------------------- " << str << "------\n";
    std::vector<GameObject*>L_temp;

    for(int i = 0 ; i < m_gameObject.size() ; i++)
    {
        if(m_gameObject[i]->Type()==str)
        {
            m_gameObject[i]->SetDead();
        }
    }
    for(int i = 0 ; i < m_gameObject.size() ; i++)
    {
        if(m_gameObject[i]->Type()==str)
        {
            L_temp.push_back(std::move(m_gameObject[i]));
            m_gameObject.erase(m_gameObject.begin()+i );
        }
    }

    for(int i = 0 ; i < L_temp.size(); i ++)
    {
        delete L_temp[i];
    }
    L_temp.clear();
}

bool Level::LoadMap(std::string *FilePath,std::string *FileMap)
{
    vec2f m_orgin  = vec2f(0,0);
    std::vector<Node*>m_enemyPath;
    std::vector<Node*>m_TowerPath;
    {
        std::ifstream ifs;
        ifs.open (*FilePath, std::ifstream::in);

        ifs >> m_orgin.x >> m_orgin.y;
        ifs >> m_rows >> m_columns;
        ifs >> m_TileSize;
        ifs >> m_MaxWave;
        ifs >> m_Lives;
        ifs >> m_Gold;
        ifs >> m_Score;
        ifs >> m_Interest;
        ifs >>m_Bonus;
        ifs.close();
    }
    m_orgin =  vec2f(Game::Instance()->GetWindowWidth()/2,Game::Instance()->GetWindowHeight()/2);

    int  Tilstep  = Game::Instance()->GetWindow()->getColumn();
    int  l_TileY  = Game::Instance()->GetWindow()->getRow();
    int  l_TileX  = Game::Instance()->GetWindow()->getColumn();

    int  l_Height  = Game::Instance()->GetWindowHeight();
    int  l_Width  = Game::Instance()->GetWindowWidth();
int  l_WidthHalf  =l_Width/2;
    int  l_HeightHalf  = l_Height/2;


    m_orgin =  vec2f(l_TileY/4,l_TileY*2.2);
    m_TileSize =l_TileY;
    std::cout << "l_TileX >> " << l_TileX << " < \n";
    std::cout << "l_TileY >> " << l_TileY << " < \n\n";
    std::cout << " >>l_WidthHalf " << l_WidthHalf << " < \n";
    std::cout << " l_HeightHalf>> " << l_HeightHalf << " < \n\n";
    std::cout << "l_Width >> " <<l_Width  << " <\n";
    std::cout << " m_columns>> " << m_columns << " <  \n\n";
    std::cout << " m_rows>> " << m_rows << " <  \n\n";
    std::ifstream ifs;
    ifs.open (*FileMap, std::ifstream::in);
    for(int i = 0 ; i < m_columns ; i++)
        for(int j = 0 ; j < m_rows ; j++)
        {
            int t = 0;
            vec2f tempOrigin = (vec2f(j*m_TileSize,i*m_TileSize));
            tempOrigin.x += m_TileSize/2.5-8/2/1.7;
            tempOrigin.y +=(l_Width*0.1)+16+16/1.8;
            ifs >> t;
            if(t==2)
                m_enemyPath.push_back(new Node(tempOrigin,CELL_STATE::PATH));
            if(t==1)
                m_TowerPath.push_back(new Node(tempOrigin,CELL_STATE::ACTIVE));
        }

    ifs.close();
    m_layers.push_back(new BackGroundLayer() );
    SDL_Rect windowRect {0,0,windowRect.h,windowRect.w};

//    SDL_Rect  m_topPannel = {l_TileX/2,l_TileY/2,windowRect.h,windowRect.w};
//    m_layers.push_back(new GameSettingLayer(m_topPannel ));
////
//    SDL_Rect m_GamePannel = {l_TileX,m_orgin.y+windowRect.h,windowRect.w};
//    m_layers.push_back(new GameLevelLayer(m_GamePannel) );
//
//    SDL_Rect m_WaveInfoPannel =  {m_TowerPath[0]->pos.x,m_TowerPath[0]->pos.y,
//                                  m_TowerPath.back()->pos.x+18,
//                                  m_TowerPath[0]->pos.y+(m_TileSize*12)
//                                 };
//    m_layers.push_back(new WaveLayer(m_WaveInfoPannel,m_enemyPath,this) );
//
//    SDL_Rect m_towerSelectionPannel = {Tilstep*8,Tilstep-Tilstep*0.7,Tilstep*3,Tilstep*2};
//    m_layers.push_back(new TowerSelectionLayer(m_towerSelectionPannel,m_TileSize,m_TowerPath));
//    m_layers.push_back(new BulletLayer());
}






// if(InputHandler::Instance()->GetWindowEvent(SDL_WINDOWEVENT_LEAVE))
//    {
//Game::Instance()->GetWindow()->HasWINDOWEVENT_LEAVE();
//   //   std::cout << "SDL_WINDOWEVENT_LEAVE >> " << " < \n";
//    }if(InputHandler::Instance()->GetWindowEvent(SDL_WINDOWEVENT_ENTER))
//    {
//Game::Instance()->GetWindow()->HasWINDOWEVENT_ENTER();
//   //   std::cout << "SDL_WINDOWEVENT_LEAVE >> " << " < \n";
//    }

// if(Game::Instance()->GetWindow()->IsMouseFocus())
//  std::cout << "IsMouseFocus >> " << " < \n";
//int gameWidth = m_columns*m_TileSize;
//int gameHeight =m_rows*m_TileSize;
//std::cout << "\n\n";
//std::cout << "gameWidth gameHeight      "<< gameHeight*2 << "/ "<< gameWidth << "\n\n";
//std::cout << "m_rows m_columns          "<< m_rows << " /"<<  m_columns<< "\n\n";
//std::cout << "m_TileSize                "<< m_TileSize << "\n\n";
////24
//if(Game::Instance()->isFoucs())
//std::cout << "l_mousePIsFocusoint  \n";

//        Game::Instance()->GetStateMachine()->ChangeState(new PauseState);
//                std::cout << m_gameObject.size() << "\n";
//
//
//for(int i = 0 ; i < m_gameObject.size(); i++)
//{
//    if(m_gameObject[i]->dead())
//    {
//
//  delete m_gameObject[i];
//    m_gameObject.erase(m_gameObject.begin()+i);
//
//    }
//}
//

//
//    SDL_Rect m_towerSelectionPannel = {553,11,157,169};
//    vec2f l_mousePos = InputHandler::Instance()->GetMousePosition();
//    SDL_Point l_mousePoint =  {l_mousePos.x,l_mousePos.y};
//
//if(InputHandler::Instance()->MousePointInRect(l_mousePoint,m_towerSelectionPannel))
//std::cout << "sdsdsdsds\n handlevent\n";
//
//
//
//        std::cout << "gameobject size >> " << sizeof(vec2f ) << " < \n";
//        std::cout << "gameobject size >> " << sizeof(Level ) << " < \n";
//        std::cout << "gameobject size >> " << sizeof(EnemyObject ) << " < \n";
//        std::cout << "gameobject size >> " << sizeof(TowerObject ) << " < \n";



//
//

//
//    for(int i = 0; i < m_gameObject.size() ; i++)
//    {
////        if(m_gameObject[i]->dead())
////        {
////            delete m_gameObject[i];
////           m_gameObject.erase(m_gameObject.begin()+i);
////        }
//
//    }




//    SDL_Rect m_GamePannel = {11,91,531,435};
//    SDL_Point tempmouse = *GetMousePos();
//
//    if(SDL_PointInRect(&tempmouse,&m_GamePannel))
//    {
//
//        if(m_Selected!=nullptr)
//        {

//            m_Selected->GetPosition() = vec2f(GetMousePos()->x,GetMousePos()->y);
//
//        }
//    }


//    m_gameObject.push_back(GameObjectFactory::Instance()->Create("Enemy"));
//    m_gameObject.back()->Load("BlueEnemy");
//    m_gameObject.push_back(GameObjectFactory::Instance()->Create("Enemy"));
//    m_gameObject.back()->Load("BlueEnemy");
//
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.push_back(new TowerObject());
//
//
//
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersPurple1.txt");
//
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersPurple2.txt");
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersPurple3.txt");
//
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersRed1.txt");
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersRed2.txt");
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersRed3.txt");
//
//
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersBlue1.txt");
//
//    m_gameObject.push_back(new TowerObject());
//    m_gameObject.back()->Load("asset/towersBlue2.txt");













//
//
//
//
//
//
////void  Level::save()
////{
////    std::vector<vec2f*>m_PathPoints;
//
//    m_PathPoints.push_back(new vec2f(11+24+24,91));
//    m_PathPoints.push_back(new vec2f(m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f(m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f(m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y-24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y-24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y-24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x-24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y-24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y-24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y-24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x,m_PathPoints.back()->y+24));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    m_PathPoints.push_back(new vec2f (m_PathPoints.back()->x+24,m_PathPoints.back()->y));
//    std::string dd = "asset/WavePathWay.txt";
//    std::ofstream ifs;
//    ifs.open (dd, std::ofstream::out);
//
//    for(int i = 0; i < m_PathPoints.size(); i++)
//    {
//        ifs << m_PathPoints[i]->x << " ";
//
//        ifs << m_PathPoints[i]->y << "\n";
//    }
//
//    ifs.close();
//}


