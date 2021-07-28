#include "BackGroundLayer.h"

BackGroundLayer::BackGroundLayer()
{
//    m_StaticBackGroundObjects.push_back(GameObjectFactory::Instance()->Create("BoarderMask"));
//    m_StaticBackGroundObjects.back()->Load("asset/SDLGameObject/BoarderMask.txt");
//    m_StaticBackGroundObjects.push_back(GameObjectFactory::Instance()->Create("TopPannel"));
//    m_StaticBackGroundObjects.back()->Load("asset/SDLGameObject//TopPannel.txt");
//    m_StaticBackGroundObjects.push_back(GameObjectFactory::Instance()->Create("TowerSelectionPannel"));
//    m_StaticBackGroundObjects.back()->Load("asset/GUI/TowerSelectionPannel.txt");
//    m_StaticBackGroundObjects.push_back(GameObjectFactory::Instance()->Create("TowerInfoPannel"));
//    m_StaticBackGroundObjects.back()->Load("asset/GUI/TowerInfoPannel.txt");
//    m_StaticBackGroundObjects.push_back(GameObjectFactory::Instance()->Create("GameLevelPannel"));
//    m_StaticBackGroundObjects.back()->Load("asset/GUI/GameLevelPannel.txt");
//    m_StaticBackGroundObjects.push_back(GameObjectFactory::Instance()->Create("WaveInfoPannel"));
//    m_StaticBackGroundObjects.back()->Load("asset/GUI/WaveInfoPannel.txt");
//    m_StaticBackGroundObjects.push_back(GameObjectFactory::Instance()->Create("IOpannel"));
//    m_StaticBackGroundObjects.back()->Load("asset/GUI/IOpannel.txt");


    g = GameObjectFactory::Instance()->Create("GUI_RECT");
    g2 = GameObjectFactory::Instance()->Create("GUI_RECT");
    g3 = GameObjectFactory::Instance()->Create("GUI_RECT");
    g4 = GameObjectFactory::Instance()->Create("GUI_RECT");
    g5 = GameObjectFactory::Instance()->Create("GUI_RECT");
t51 = GameObjectFactory::Instance()->Create("TextBox");
  t51->Load("asset/SDLGameObject/TextBox.txt");
    g->Load("asset/GUI_/GUI_RECT.txt");
    g2->Load("asset/GUI_/GUI_RECT.txt");
    g3->Load("asset/GUI_/GUI_RECT.txt");
    g4->Load("asset/GUI_/GUI_RECT.txt");
    g5->Load("asset/GUI_/GUI_RECT.txt");

int Tile = Game::Instance()->GetWindow()->getTile();
    dynamic_cast<GUI_Object*>(g)->SetSize({0,Tile/4,Tile*4,Tile*4});
    dynamic_cast<GUI_Object*>(g2)->SetSize({0,Tile*2,Tile*8,Tile*8});
    dynamic_cast<GUI_Object*>(g3)->SetSize({Tile*8,0,Tile*2,Tile*4});
    dynamic_cast<GUI_Object*>(g4)->SetSize({Tile*8,Tile*4,Tile*2,Tile*4});
    dynamic_cast<GUI_Object*>(g5)->SetSize({Tile*8,Tile*8,Tile*2,Tile*2});

//
}

BackGroundLayer::~BackGroundLayer()
{
    //dtor
}

void BackGroundLayer::Update(Level* pLevel)
{

   g->Update();
   g2->Update();
  g3->Update();
  g4->Update();
  g5->Update();
t51->Update();
}

void BackGroundLayer::Render()
{
t51->Draw();
 g->Draw();
   //g2->Draw();
 // g3->Draw();
 // g4->Draw();
 // g5->Draw();
}
