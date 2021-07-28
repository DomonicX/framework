#include "LevelCreaterState.h"

LevelCreaterState::LevelCreaterState()
{
    //ctor
}

LevelCreaterState::~LevelCreaterState()
{
    //dtor
}


void LevelCreaterState::Render()
{
    for(int i = 0 ; i < m_row ; i++)
        for(int j = 0 ; j < m_col; j++)
            gameLevelgrid[i][j].Display(*Game::Instance()->GetRenderer(),m_Tile);




}

void LevelCreaterState::Update()
{
    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::LEFT))
    {
        std::cout<< "Entering : "<< GetStateID() << " \n";
        int indexX =InputHandler::Instance()->GetMousePosition().x/m_Tile;
        int indexY = (InputHandler::Instance()->GetMousePosition().y/m_Tile);
        gameLevelgrid[indexY][indexX].ChangeType(CELL_STATE::PATH);
    }


    if(InputHandler::Instance()->GetMouseButtonState(mouse_Buttons::RIGHT))
    {
        std::cout<< "Entering : "<< GetStateID() << " \n";
        int indexX =InputHandler::Instance()->GetMousePosition().x/m_Tile;
          int indexY = InputHandler::Instance()->GetMousePosition().y/m_Tile;
      gameLevelgrid[indexY][indexX].ChangeType(CELL_STATE::ACTIVE);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_Q))
        Load();
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
        Save();
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_E))
        Clear();
}

bool LevelCreaterState::OnEnter()
{
    m_row = Game::Instance()->GetWindow()->getRow();
    m_col  = Game::Instance()->GetWindow()->getColumn();
    m_Tile = Game::Instance()->GetWindow()->getTile();
    for(int i = 0 ; i < m_row ; i++)
        for(int j = 0 ; j < m_col; j++)

            gameLevelgrid[i][j] = Node(vec2f(j*m_Tile,m_Tile*i),CELL_STATE::ACTIVE);

    std::cout<< "Entering : "<< GetStateID() << " \n";
    return true;

}
bool LevelCreaterState::onExit()
{
    std::cout<< "Exiting : "<< GetStateID() << " \n";
}
void LevelCreaterState::resume()
{
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}
void  LevelCreaterState::Save()
{
    std::cout << "Save  \n";
    std::string m_filename = "test.txt";
    std::ofstream ifs;
    ifs.open (m_filename, std::ifstream::out);
    for(int i = 0 ; i < m_Tile ; i++)
    {
        for(int j = 0 ; j < m_Tile ; j++)
        {

            if(gameLevelgrid[i][j].currentState==CELL_STATE::ACTIVE)
            {
                ifs <<1;
            }
            else if(gameLevelgrid[i][j].currentState==CELL_STATE::PATH)
            {
                ifs <<2;

            }
            ifs <<" ";
        }

        ifs <<"\n";
    }
    ifs.close();
}

void  LevelCreaterState::Clear()
{
    std::cout << "Clear  \n";
    for(int i = 0 ; i < m_Tile ; i++)

        for(int j = 0 ; j < m_Tile ; j++)

            gameLevelgrid[i][j].ChangeType(CELL_STATE::ACTIVE);


}
void  LevelCreaterState::Load()
{
    std::cout << "Load  \n";
    std::string m_filename = "test.txt";
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);
    for(int i = 0 ; i < m_Tile ; i++)
    {
        for(int j = 0 ; j < m_Tile ; j++)
        {
            int tempint;
            ifs >> tempint;
            if(tempint==1)gameLevelgrid[i][j].ChangeType(CELL_STATE::ACTIVE);
            else if(tempint==2)gameLevelgrid[i][j].ChangeType(CELL_STATE::PATH);


        }
    }
    ifs.close();
}
  //  gameLevelgrid[indexY-2][indexX].ChangeType(CELL_STATE::PATH);
    //  gameLevelgrid[indexY-1][indexX-1].ChangeType(CELL_STATE::PATH);
    //   gameLevelgrid[indexY+1][indexX+1].ChangeType(CELL_STATE::PATH);
    //   gameLevelgrid[indexY+1][indexX-1].ChangeType(CELL_STATE::PATH);
//ffdxY][indexX+1].ChangeType(CELL_STATE::PATH);
    //   gameLevelgrid[indexY][indexX-1].ChangeType(CELL_STATE::PATH);
    //  gameLevelgrid[indexY-1][indexX].ChangeType(CELL_STATE::PATH);
//gameLevelgrid[indexY+1][ssdexX].ChangeType(CELL_STATE::PATH);
