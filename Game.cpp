#include "Game.h"
Game *Game::s_pInstance = 0;


Game::Game():m_window(nullptr),
    m_bRunning(false),
    m_pGameStateMachine(nullptr),
    m_blevelComplete(false),
    m_bChangingState(false)
{


    m_backGroundColour = {211,203,190 };
    m_inGroundColour = {125,146,158};

}

void  Game::SetWindowDimension(int w,int h)
{
    SDL_SetWindowSize(m_window->GetWindow(),w,h);
}


bool Game::Init(const char* title, int xpos, int ypos, int width, int height,float RefreshRate,float ResScaler, bool fullscreen,int Tile,int column,int row)
{


    m_bRunning = true;
    m_window = new Window();

    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);

    if(!m_window->init(title,xpos, ypos,width,height,RefreshRate,ResScaler,fullscreen,Tile, column, row))
    {
        m_bRunning = false;

    }
    m_bRunning = true;

    m_pGameStateMachine  = new GameStateMachine();


    return m_bRunning;

}

Game::~Game() {}
void Game::Render()
{
    m_window->ClearDisplay();
    m_pGameStateMachine->Render();
    m_window->RenderPresent();



}
void Game::Clean()
{
    m_pGameStateMachine->Clean();
    m_window->Free();
}
int Game::getRandomNumber()
{
    return rand();
}
float Game::GetDeltaTime()
{
    if(!m_window->IsFocus()) {return 0;}
    return m_deltaTime;
}

int  Game::GetWindowHeight()
{
    return m_window->getHeight();
}
int  Game::GetWindowWidth()
{
    return m_window->getWidth();
}

void  Game::quit()
{
    m_bRunning = false;
}

bool Game::running()
{
    return m_bRunning;
}

GameStateMachine* Game::GetStateMachine() const
{
    return m_pGameStateMachine;
}

void Game::PushState(GameState* s)
{
    m_pGameStateMachine->PushState(s);
}
void Game::ChangeGameState(GameState* s)
{
    m_pGameStateMachine->ChangeState(s);
}
SDL_Renderer* Game::GetRenderer() const
{
    return m_window->GetRender();
}

void  Game::HandleEvent(SDL_Event &e )
{
    while(SDL_PollEvent(&e)!=0)
    {

//std::cout << e.common.timestamp << "\n";
        if(e.type==SDL_QUIT)
            quit();
        m_window->HandleEvent(e);
        InputHandler::Instance()->Update(e);
    }

}
void Game::Update()
{
    m_pGameStateMachine->Update();

}

Window*  Game::GetWindow()
{
    return m_window;
}

//  need to fix
// store the game width and height
//    m_Origin = vec2f(0,0);
//    m_Screen = vec2f(width,height);
//    m_Centre = vec2f(m_Screen.Length()/2,m_Screen.Length()/2);

//     if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
//    {
//     //  GetStateMachine()->PopState();
//
//      // GetStateMachine()->PushState(new MenuState);
//            //    std::cout << "pasued passed" << "\n";
//    }

//    SDL_SetRenderDrawColor(m_pRenderer,1,125,125,255);
// SDL_RenderClear(m_pRenderer);
// SDL_RenderPresent(m_pRenderer);
//const  char* Game::GetTitle()
//    {
//        return m_windowTitle;
//    }
//
//    std::cout << Game::Instance()->GetTitle()  <<  "\n";

//    const char* m_windowTitle;

//const bool  Game::getLevelCompelte()
//{
//
//}
//const bool  Game::getCurrentLevel()
//{
//
//}
//
//bool Game::changingState()
//{
//
//    return m_bChangingState;
//}
//
//void Game::changingState(bool cs)
//{
//    m_bChangingState = cs;
//}
//
//SDL_Texture* RenderText(const std::string &message, const std::string &fontFlie, SDL_Color color, int fontSize, SDL_Renderer *render)
//{
//
//    TTF_Font *font = TTF_OpenFont(fontFlie.c_str(),fontSize);
//
//    if(font==nullptr)
//    {
//        std::cout << " 1 error \n";
//        return nullptr;
//    }
//    SDL_Surface *surf = TTF_RenderText_Blended(font,message.c_str(),color);
//    if(surf==nullptr)
//    {
//        TTF_CloseFont(font);
//        std::cout << " 2 error \n";
//        return nullptr;
//    }
//    SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surf);
//    if(texture==nullptr)
//    {
//        std::cout << " 3 error \n";
//    }
//    srand (time(NULL));
//
//    SDL_FreeSurface(surf);
//    TTF_CloseFont(font);
//    return texture;
//
//
//}


////
////
//  m_windowTitle = title;
//
//    int flags = 0;
//
//    // store the game width and height
//    m_gameWidth = width;
//    m_gameHeight = height;
//    m_Origin = vec2f(0,0);
//    m_Screen = vec2f(width,height);
//    m_Centre = vec2f(m_Screen.Length()/2,m_Screen.Length()/2);

//    m_pCamera = {0,0,width,height};
//    if(fullscreen)
//    {
//        flags = SDL_WINDOW_FULLSCREEN;
//    }
//
//    // attempt to initialise SDL
//    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
//    {
//        TTF_Init();
//      //  std::cout << "SDL init success\n";
//        // init the window
//        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
//
//        if(m_pWindow != 0) // window init success
//        {
//           // std::cout << "window creation success\n";
//            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
//
//            if(m_pRenderer != 0) // renderer init success
//            {
//           //     std::cout << "renderer creation success\n";
//                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
//            }
//            else
//            {
//             //   std::cout << "renderer init fail\n";
//                return true; // renderer init fail
//            }
//        }
//        else
//        {
//          //  std::cout << "window init fail\n";
//            return true; // window init fail
//        }
//    }
//    else
//    {
//        //std::cout << "SDL init fail\n";
//        return true; // SDL init fail
//    }
//

//
//    //GameObjectFactory::Instance()->registerType("GameError",new SDLGameObjectCreater());
//
//    m_pGameStateMachine  = new GameStateMachine();
//    m_pGameStateMachine->ChangeState(new MenuState());
//m_bRunning = true;
//


////  // TextureManager::Instance()->Load("SpaceinvaderAssist/SpaceInvaders1.PNG","SpaceInvader",Game::GetRenderer());
// GameObjectFactory::Instance()->registerType("SpaceEnemy1",new EnemySpaceShipCreator());

// GameObjectFactory::Instance()->registerType("Eskeletor",g EskeletorCreater());

//UI_Selection = NULL;

/*
sdsd

 Map[Player][p]

Widget_TowersSelection

 */
//
//  GameObjectFactory::Instance()->registerType("Cell",new TowerObjectCreater());
//    TextureManager::Instance()->Load("Img/Cell_ExitRed.PNG","Cell_ExitRed",Game::GetRenderer());
//    TextureManager::Instance()->Load("Img/Cell_EnterGreen.PNG","Cell_EnterGreen",Game::GetRenderer());
//    TextureManager::Instance()->Load("Img/GUI/Cell.PNG","Cell",Game::GetRenderer());
//    TextureManager::Instance()->Load("Img/GUI/Cell1.PNG","Cell1",Game::GetRenderer());
//    TextureManager::Instance()->Load("Img/GUI/Label_Decorator.PNG","Label_Decorator",Game::GetRenderer());

//    GameObjectFactory::Instance()->registerType("Bonus01",new TowerObjectCreater());
//    GameObjectFactory::Instance()->registerType("Bonus02",new TowerObjectCreater());
//    GameObjectFactory::Instance()->registerType("Bonus03",new TowerObjectCreater());
//    GameObjectFactory::Instance()->registerType("Bonus04",new TowerObjectCreater());

//  m_pGameStateMachine->ChangeState(new StateLevel());
//StateLevel
//m_pGameStateMachine->PushState(new StateLevel());
//   m_pGameStateMachine->ChangeState(new StateMapEditer());

