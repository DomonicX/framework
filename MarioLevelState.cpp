#include "MarioLevelState.h"


MarioLevelState::~MarioLevelState()
{
    m_topcol,m_botcol,m_Rightcol,m_leftcol = false;
    //dtor
}
typedef struct
{
    vec2f Min;
    float Max;
} Arrow;

MarioLevelState::MarioLevelState()
{


}
void MarioLevelState::DrawMarioObjects()
{

    for(int i = 0 ;  i < MarioItems.size(); i++)
    {
        MarioItems[i]->Draw();
    }
    for(int i = 0 ;  i < MarioEnemies.size(); i++)
    {
        MarioEnemies[i]->Draw();
    }
    for(int i = 0 ;  i < MarioBlocks.size(); i++)
    {
        MarioBlocks[i]->Draw();
    }
    for(int i = 0 ;  i < MarioUIs.size(); i++)
    {
        MarioUIs[i]->Draw();
    }
    m_MarioPlayer->Draw();
}
void MarioLevelState::Render()
{
    DrawMarioObjects();

    TextureManager::Instance()->SetColour(146,144,255,255,Game::Instance()->GetRenderer());

    if(m_bisSelected)
        TextureManager::Instance()->DrawText(m_isSelectedText,0,0,24,Game::Instance()->GetRenderer());

    TextureManager::Instance()->SetColour(2,2,255,255,Game::Instance()->GetRenderer());


    TextureManager::Instance()->DrawRect(m_MarioPlayer->GetPosition().x,m_MarioPlayer->GetPosition().y-16,m_MarioPlayer->GetAcceleration().x,m_MarioPlayer->GetAcceleration().y,Game::Instance()->GetRenderer());

    TextureManager::Instance()->SetColour(255,0,0,0,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawRect(m_MarioPlayer->GetPosition().x,m_MarioPlayer->GetPosition().y-32,m_MarioPlayer->GetVelocity().x,m_MarioPlayer->GetVelocity().y,Game::Instance()->GetRenderer());


    if(m_botcol)
        TextureManager::Instance()->DrawRectFilled(m_MarioPlayer->GetPosition().x
                ,m_MarioPlayer->GetPosition().y +m_MarioPlayer->getWidth() + 16
                ,16,16,Game::Instance()->GetRenderer());

    TextureManager::Instance()->SetColour(0,0,255,0,Game::Instance()->GetRenderer());
    if(m_topcol)
        TextureManager::Instance()->DrawRectFilled(m_MarioPlayer->GetPosition().x
                ,m_MarioPlayer->GetPosition().y -16
                ,16,16,Game::Instance()->GetRenderer());




    TextureManager::Instance()->SetColour(146,144,255,255,Game::Instance()->GetRenderer());
}

void MarioLevelState::Update()
{



    vec2f mousepos  = InputHandler::Instance()->GetMousePosition();
    mousepos/=16;
    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {
        MarioBlocks.push_back(Add("Brick",mousepos.x*16,mousepos.y*16));

        std::cout << (int)mousepos.x << "\ " << (int)mousepos.y << "\n";
    }



    m_bisSelected = false;

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
    {
        delete  m_MarioPlayer;
        LoadPlayer();
    }
    float dt = Game::Instance()->GetDeltaTime();
    SDL_Rect S = m_MarioPlayer->GetSDLRect();
    SDL_Point BottomRight = {m_MarioPlayer->BottomRight().x,m_MarioPlayer->BottomRight().y};
    SDL_Point BottomLeft = {m_MarioPlayer->bottomLeft().x,m_MarioPlayer->bottomLeft().y};
    SDL_Point topLeft = {m_MarioPlayer->topLeft().x,m_MarioPlayer->topLeft().y};
    SDL_Point topright = {m_MarioPlayer->topRight().x,m_MarioPlayer->topRight().y};

    m_topcol= false;
    m_botcol = false;
    m_MarioPlayer->isInAir();
    for(int i = 0 ;  i < MarioBlocks.size(); i++)
    {
        SDL_Rect blockRect = {MarioBlocks[i]->GetPosition().x,MarioBlocks[i]->GetPosition().y,MarioBlocks[i]->getWidth(),MarioBlocks[i]->getHeight()};
        if(SDL_HasIntersection(&S,&blockRect))
        {
            if(SDL_PointInRect(&BottomRight,&blockRect) || SDL_PointInRect(&BottomLeft,&blockRect))
            {
                m_botcol = true;
                m_MarioPlayer->isOnGround();


            }
            else if(SDL_PointInRect(&topLeft,&blockRect) || SDL_PointInRect(&topright,&blockRect))
            {
                m_topcol= true;
                m_MarioPlayer->GetVelocity() *= -1;


            }

        }
        MarioBlocks[i]->Update();


        if(InputHandler::Instance()->MouseinRect(MarioBlocks[i]->GetSDLRect()))
        {
            m_bisSelected = true;
            m_isSelectedText = MarioBlocks[i]->Type();
        }
    }
    for(int i = 0 ;  i < MarioItems.size(); i++)
    {
        MarioItems[i]->Update();
        if(InputHandler::Instance()->MouseinRect(MarioItems[i]->GetSDLRect()))
        {
            m_bisSelected = true;
            m_isSelectedText = MarioItems[i]->Type();
        }

    }
    for(int i = 0 ;  i < MarioEnemies.size(); i++)
    {
        MarioEnemies[i]->Update();
        if(InputHandler::Instance()->MouseinRect(MarioEnemies[i]->GetSDLRect()))
        {
            m_bisSelected = true;
            m_isSelectedText = MarioEnemies[i]->Type();
            std::cout << m_isSelectedText;
        }
    }

    for(int i = 0 ;  i < MarioUIs.size(); i++)
    {
        MarioUIs[i]->Update();
        if(InputHandler::Instance()->MouseinRect(MarioUIs[i]->GetSDLRect()))
        {
            m_bisSelected = true;
            m_isSelectedText = MarioUIs[i]->Type();
        }
    }


    m_MarioPlayer->Update();
    if(InputHandler::Instance()->MouseinRect(m_MarioPlayer->GetSDLRect()))
    {
        m_bisSelected = true;
        m_isSelectedText = m_MarioPlayer->getState();
    }








}

bool MarioLevelState::OnEnter()
{




    MarioTypes["Goomba"]                          = "MarioEnemy";
    MarioTypes["BlueGoomba"]                      = "MarioEnemy";
    MarioTypes["GreyGoomba"]                      = "MarioEnemy";
    MarioTypes["GreenTurtle"]                     = "MarioEnemy";
    MarioTypes["BlueTurtle"]                      = "MarioEnemy";
    MarioTypes["RedTurtle"]                       = "MarioEnemy";
    MarioTypes["HammerThrowTurtle"]               = "MarioEnemy";
    MarioTypes["GreyHammerThrowTurtle"]           = "MarioEnemy";
    MarioTypes["ManEatingPlant"]                  = "MarioEnemy";
    MarioTypes["GreyManEatingPlant"]              = "MarioEnemy";


    MarioTypes["BrickGround"]                     = "MarioBlock";
    MarioTypes["Brick"]                           = "MarioBlock";
    MarioTypes["QuestionMarkBlock"]               = "MarioBlock";


    MarioTypes["RedMushroom"]                     = "MarioItem";
    MarioTypes["GreenMushroom"]                   = "MarioItem";
    MarioTypes["StarPower"]                       = "MarioItem";
    MarioTypes["FireFlower"]                      = "MarioItem";
    MarioTypes["Coin"]                            = "MarioItem";




    LoadGround();
    LoadData1();
    LoadPlayer();
    LoadEnemies();
    LoadItems();
    return true;
}
bool MarioLevelState::onExit()
{
    std::cout<< "Exiting : "<< GetStateID() << " \n";
}
void MarioLevelState::resume()
{
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}
void MarioLevelState::LoadGround()
{
    vec2f l_grd = vec2f(0,16*13);

    for(int i = 0; i < 3328/16; i++)
    {
        for(int j= 0 ; j < 2 ; j++)
        {
            int yoffset = l_grd.y-j+1*16;
            MarioBlocks.push_back(Add("BrickGround",16*i,j*16+yoffset));
        }
    }
}
void MarioLevelState::LoadData1()
{
    vec2f l_grd = vec2f(0,16*13);
    MarioBlocks.push_back(Add("QuestionMarkBlock",16*4+16+16,l_grd.y-16-16-16-16-16-16-16));
    MarioBlocks.push_back(Add("Brick",16*4+16,l_grd.y-16-16-16));
    MarioBlocks.push_back(Add("Brick",16*3+16,l_grd.y-16-16-16));
    MarioBlocks.push_back(Add("Brick",16*5+16,l_grd.y-16-16));
}
void MarioLevelState::LoadPlayer()
{
    m_MarioPlayer = new MarioPlayer();
    m_MarioPlayer->Load("MarioPlayerBig_Idie");
    m_MarioPlayer->GetPosition() = vec2f(0,16*11);

}
void MarioLevelState::LoadEnemies()
{
    vec2f l_grd = vec2f(0,Game::Instance()->GetWindowHeight()-16*3);

    MarioEnemies.push_back(Add("Goomba",96+16*1,112));
    MarioEnemies.push_back(Add("BlueGoomba",96+16*2,112));
    MarioEnemies.push_back(Add("GreyGoomba",96+16*3,112));

    MarioEnemies.push_back(Add("GreenTurtle",96+16*4,112));
    MarioEnemies.push_back(Add("RedTurtle",96+16*5,112));
    MarioEnemies.push_back(Add("BlueTurtle",96+16*6,112));

    MarioEnemies.push_back(Add("ManEatingPlant",96+16*7,112));
    MarioEnemies.push_back(Add("GreyManEatingPlant",96+16*8,112));

    MarioEnemies.push_back(Add("HammerThrowTurtle",96+16*9,112));
    MarioEnemies.push_back(Add("GreyHammerThrowTurtle",96+16*10,112));
}


void MarioLevelState::LoadItems()
{

    MarioItems.push_back(Add("RedMushroom",16*3,16*3));
    MarioItems.push_back(Add("GreenMushroom",16*4,16*3));
    MarioItems.push_back(Add("Coin",16*5,16*3));
    MarioItems.push_back(Add("FireFlower",16*6,16*3));
    MarioItems.push_back(Add("StarPower",16*7,16*3));
}

SDLGameObject* MarioLevelState::Add(std::string type,int x,int y)
{
    GameObject * temp = GameObjectFactory::Instance()->Create(MarioTypes[type]);
    SDLGameObject *t = new SDLGameObject();

    temp->Load((char*)type.c_str());
    temp->GetPosition() = vec2f( x,y);
    return (SDLGameObject*)temp ;
}
//TextureManager::Instance()->DrawLine(startpoint.x,startpoint.y,startpointEnd.x,startpointEnd.y,Game::Instance()->GetRenderer());
// TextureManager::Instance()->DrawLine(midpoint.x+a.x,midpoint.y+a.y,midpoint.x+b.x,midpoint.y+ b.y,Game::Instance()->GetRenderer());
// TextureManager::Instance()->DrawLine(midpoint.x+a.x,midpoint.y+a.y,midpoint.x+b.x,midpoint.y- a.y,Game::Instance()->GetRenderer());
//TextureManager::Instance()->DrawBackGround("GUI_RECT",Game::Instance()->GetRenderer());
// TextureManager::Instance()->Draw("GUI_RECT",dsrect.x,dsrect.y,dsrect.w,dsrect.h,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);
// TextureManager::Instance()->Draw("GUI_RECT",dsrec.x,dsrec.y,dsrec.w,dsrec.h,Game::Instance()->GetRenderer(),SDL_FLIP_NONE);
