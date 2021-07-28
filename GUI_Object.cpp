#include "GUI_Object.h"

GUI_Object::GUI_Object()
{
    //ctor
    m_bisHighLit = false;
}

GUI_Object::~GUI_Object()
{
    //dtor
}

void GUI_Object::Load(char* filename)
{
    int x,y,w,h = 0;
    m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);
    ifs >>  m_textureID;
    ifs >> m_width;
    ifs >> m_height;
    ifs >> m_srcRect.x >> m_srcRect.y >> m_srcRect.w >> m_srcRect.h;
    ifs.close();
    m_desRect = {0,0,48,48};
   // std::cout <<"\n" << m_srcRect.y << "ssssss \n";
};
void GUI_Object::Draw()
{
    // TextureManager::Instance()->SetColour(2,255,255,255,Game::Instance()->GetRenderer());
    // TextureManager::Instance()->DrawRect(m_desRect.x,m_desRect.y,m_desRect.w,m_desRect.h,Game::Instance()->GetRenderer());


    DrawLeftAndRightSide();
    DrawSides();
    DrawCorner();
    DrawCentre();

   // TextureManager::Instance()->Draw("GUI_SelectedTab",0,0,160,32,Game::Instance()->GetRenderer());
   // TextureManager::Instance()->Draw("GUI_TABS",155,0,160,32,Game::Instance()->GetRenderer());
    // TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),m_textureID,&m_srcRect,&l_Rect,0,0,SDL_FLIP_NONE);

}
void GUI_Object::Update()
{
    SDL_Point l_mouse =
    {
        InputHandler::Instance()->GetMousePosition().x,
        InputHandler::Instance()->GetMousePosition().y
    };

    if(InputHandler::Instance()->MousePointInRect(l_mouse,m_desRect))
        m_textureID = "GUI_RECT_HighLit";
    else
        m_textureID = "GUI_RECT";
};
void GUI_Object::Clean() {};
void GUI_Object::Collision() {};

std::string GUI_Object::Texture()
{
    return  m_textureID;
}
std::string GUI_Object::Type()
{
    return  "GUI_Object";
}
int GUI_Object::getHeight()
{
    return m_height;
}
int GUI_Object::getWidth()
{
    return m_width;
}

void  GUI_Object::SetSize(SDL_Rect Rect )
{
    m_desRect = Rect;

    m_width = m_desRect.w/m_srcRect.w;
    m_height = m_desRect.h/m_srcRect.h;

}
void GUI_Object::DrawCentre()
{
    for(int i = 0 ; i < m_height; i++)
    {
        if(i!=0 && i<m_height-1)
        {
            SDL_Rect l_dRect = {m_desRect.x+16,m_desRect.y+(16*i),m_desRect.w-32,m_desRect.h-32,};
            SDL_Rect l_sRect = {16,16,16,16};
            TextureManager::Instance()->DrawTilingRect( m_textureID,&l_sRect,&l_dRect,16,Game::Instance()->GetRenderer());
        }
    }
}
void GUI_Object::DrawCorner()
{
    {
        SDL_Rect l_dRect = {m_desRect.x,m_desRect.y,16,16};
        SDL_Rect l_sRect = {0,0,16,16};
        TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),m_textureID,&l_sRect,&l_dRect,0,0,SDL_FLIP_NONE);
    }
    {
        SDL_Rect l_dRect = {m_desRect.x+m_desRect.w-16,m_desRect.y,16,16};
        SDL_Rect l_sRect = {32,0,16,16};
        TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),m_textureID,&l_sRect,&l_dRect,0,0,SDL_FLIP_NONE);
    }
    {
        SDL_Rect l_dRect = {m_desRect.x,m_desRect.y+m_desRect.h-16,16,16};
        SDL_Rect l_sRect = {0,32,16,16};
        TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),m_textureID,&l_sRect,&l_dRect,0,0,SDL_FLIP_NONE);
    }
    {
        SDL_Rect l_dRect = {m_desRect.x+m_desRect.w-16,m_desRect.y+m_desRect.h-16,16,16};
        SDL_Rect l_sRect = {32,32,16,16};
        TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),m_textureID,&l_sRect,&l_dRect,0,0,SDL_FLIP_NONE);
    }
}
void  GUI_Object::DrawSides()
{
    {
        SDL_Rect l_dRect = {m_desRect.x+16,m_desRect.y,m_desRect.w-32,m_desRect.h,};
        SDL_Rect l_sRect = {16,0,16,16};
        TextureManager::Instance()->DrawTilingRect( m_textureID,&l_sRect,&l_dRect,16,Game::Instance()->GetRenderer());

    }
    {
        SDL_Rect l_dRect = {m_desRect.x+16,m_desRect.y+m_desRect.h-16,m_desRect.w-32,m_desRect.h,};
        SDL_Rect l_sRect = {16,32,16,16};
        TextureManager::Instance()->DrawTilingRect( m_textureID,&l_sRect,&l_dRect,16,Game::Instance()->GetRenderer());

    }

}
void  GUI_Object::DrawLeftAndRightSide()
{
    for(int i = 0 ; i < m_height-1; i++)
    {
        if(i!=0)
        {

            SDL_Rect l_dRect = {m_desRect.x,m_desRect.y+i*16,16,16};
            SDL_Rect l_sRect = {0,16,16,16};
            TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),m_textureID,&l_sRect,&l_dRect,0,0,SDL_FLIP_NONE);

            {

                l_sRect = {32,16,16,16};
                SDL_Rect l_dRect = {m_desRect.x+m_desRect.w-16,m_desRect.y+i*16,16,16};
                TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),m_textureID,&l_sRect,&l_dRect,0,0,SDL_FLIP_NONE);
            }
        }
    }
}
