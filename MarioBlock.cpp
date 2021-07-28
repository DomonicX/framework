#include "MarioBlock.h"

MarioBlock::MarioBlock()
{
    m_position = vec2f(0,0);
    //ctor
    m_bDead = false;
}

MarioBlock::~MarioBlock()
{
    //dtor
} void MarioBlock::Load(char* filename)
{
    m_blocktype = filename;
    std::string m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);

    ifs >> m_textureID;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
    ifs >> m_bisFilled;
    ifs.close();

    m_Type = filename;
    m_width = 16;
    m_height = 16;

    std::string filenameStr  = filename;

    if(filenameStr=="QuestionMarkBlock")
    {
        m_BlockState = QuestionMarkBlock;
        m_srcRect = {0,00,16,16};
        m_desRect = {m_position.x,m_position.y,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="BrickGround")
    {
        m_BlockState = BrickGround;
        m_srcRect = {0,32,16,16};
        m_desRect = {m_position.x,m_position.y,16,16};

        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="Brick")
    {
        m_BlockState = Brick;
        m_srcRect = {48,0,16,16};
        m_desRect = {m_position.x,m_position.y,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
}

void MarioBlock::Draw()
{
    if(Dead())
    {
        m_bDead = false;
    }
    else
    {
        if(m_isStaticSprite)
        {
            m_desRect.x = m_position.x;
            m_desRect.y = m_position.y;
            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,SDL_FLIP_NONE);

        }
        else if(m_isAnimationSprite)
        {
            m_desRect.x = m_position.x;
            m_desRect.y = m_position.y;
            TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&m_desRect, &m_srcRect,0,0,SDL_FLIP_NONE);

        }
    }
}

void MarioBlock::Update()
{
    m_desRect = {m_position.x,m_position.y,m_width,m_height};

}
