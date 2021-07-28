#include "MarioItem.h"

MarioItem::MarioItem()
{
    //ctor
}

MarioItem::~MarioItem()
{
    //dtor
}
void MarioItem::Load(char* filename)
{

    // SDLGameObject::Load("asset/Mario/MarioBlock.txt");
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
    if(filenameStr=="RedMushroom")
    {
        m_Type = "RedMushroom";
        m_Itemtype = RedMushroom;
        m_srcRect = {16*8,16*9,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="GreenMushroom")
    {
        m_Type = "GreenMushroom";
        m_Itemtype = GreenMushroom;
        m_srcRect = {16*9,16*9,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    } else if(filenameStr=="Coin")
    {
        m_Type = "Coin";
        m_Itemtype = Coin;
        m_srcRect = {0,16*1,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    } else if(filenameStr=="FireFlower")
    {
        m_Type = "FireFlower";
        m_Itemtype = FireFlower;
        m_srcRect = {16*7,16*9,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    } else if(filenameStr=="StarPower")
    {
        m_Type = "StarPower";
        m_Itemtype = StarPower;
        m_srcRect = {16*7,16*11,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
}
void MarioItem::Update() {m_desRect = GetSDLRect();}
void MarioItem::Clean() {}
void MarioItem::Collision() {}
