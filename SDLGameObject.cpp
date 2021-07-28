#include "SDLGameObject.h"


void SDLGameObject::Update()
{
//    m_currentFrame = ( ((SDL_GetTicks()/m_frameRate)%m_numFrame)
//                     );


    m_desRect = {m_position.x,m_position.y,m_width,m_height};
}

void SDLGameObject::Load(char* filename)
{
    std::cout<< " "<< filename << " \n";
    std::string m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);

    ifs >> m_textureID;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
    ifs >> m_bisFilled;
    ifs.close();

    m_Type = filename;
    m_position.x = m_desRect.x;
    m_position.y = m_desRect.y;
    m_width = m_desRect.w;
    m_height = m_desRect.h;
    m_isStaticSprite = false;
    //   std::cout<< " :0----- "<< m_textureID << " \n";
    m_isAnimationSprite = false;

}
void SDLGameObject::Draw()
{



    if(m_bisFilled)
        TextureManager::Instance()->DrawRect( m_desRect.x, m_desRect.y, m_desRect.w, m_desRect.h, Game::Instance()->GetRenderer());
    else  if(!m_bisFilled)
    {
        TextureManager::Instance()->DrawRectFilled(m_desRect.x, m_desRect.y, m_desRect.w, m_desRect.h, Game::Instance()->GetRenderer());
        TextureManager::Instance()->Draw(m_textureID,m_desRect.x, m_desRect.y, m_desRect.w, m_desRect.h, Game::Instance()->GetRenderer());
    }
    else if(m_textureID=="TextBox")
    {
        TextureManager::Instance()->DrawText(m_textureID,m_desRect.x, m_desRect.w, m_desRect.h, Game::Instance()->GetRenderer());

        //  std::cout<< " :0----- "<< m_textureID << " \n";
        TextureManager::Instance()->SetColour(0,0,0,255, Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawRectFilled( m_desRect.x, m_desRect.y, m_desRect.w, m_desRect.h, Game::Instance()->GetRenderer());


    }


    if(m_isStaticSprite)
    {
        TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,SDL_FLIP_NONE);

    }
    else
        if(m_bDead)
    {


     TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&m_desRect, &m_srcRect,0,0,SDL_FLIP_NONE);

    }
}
void SDLGameObject::Clean()
{

}
void SDLGameObject::Collision()
{

}
