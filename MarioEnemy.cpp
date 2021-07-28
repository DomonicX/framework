#include "MarioEnemy.h"

MarioEnemy::MarioEnemy()
{
    //ctor
}
MarioEnemy::~MarioEnemy()
{
    //dtor
}  void MarioEnemy::Load(char* filename)
{

    // SDLGameObject::Load("asset/Mario/MarioBlock.txt");
    std::string m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);

    ifs >> m_textureID;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
    ifs >> m_bisFilled;
    ifs.close();

    m_width = 16;
    m_height = 16;
    m_Type = filename;

    std::string filenameStr  = filename;
    if(filenameStr=="GreenTurtle")
    {
        m_Type = "GreenTurtle";
        m_EmenyState = GreenTurtle;
        m_srcRect = {16*20,0,16,32};
        m_desRect = {16,0,16,32};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="RedTurtle")
    {
        m_Type = "RedTurtle";
        m_EmenyState =RedTurtle;
        m_srcRect = {16*20,32,16,32};
        m_desRect = {16,0,16,32};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="BlueTurtle")
    {
        m_Type = "BlueTurtle";
        m_EmenyState =BlueTurtle;
        m_srcRect = {16*20,32*2,16,32};
        m_desRect = {16,0,16,32};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="Goomba")
    {
        m_Type = "Goomba";
        m_EmenyState = Goomba;
        m_srcRect = {16*17,16*1,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="BlueGoomba")
    {
        m_Type = "BlueGoomba";
        m_EmenyState = BlueGoomba;
        m_srcRect = {16*17,16*2,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="GreyGoomba")
    {
        m_Type = "GreyGoomba";
        m_EmenyState = GreyGoomba;
        m_srcRect = {16*17,16*3,16,16};
        m_desRect = {16,0,16,16};
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }

    else if(filenameStr=="GreyManEatingPlant")
    {
        m_Type = "GreyManEatingPlant";
        m_EmenyState = GreyManEatingPlant;
        m_srcRect = {16*24,16*8,16,32};
        m_desRect = {32,0,16,32};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="ManEatingPlant")
    {
        m_Type = "ManEatingPlant";
        m_EmenyState = ManEatingPlant;
        m_srcRect = {16*24,16*6,16,32};
        m_desRect = {32,0,16,32};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="HammerThrowTurtle")
    {
        m_Type = "HammerThrowTurtle";
        m_EmenyState = GreyHammerThrowTurtle;
        m_srcRect = {16*20,16*8,16,32};
        m_desRect = {32,0,16,32};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="GreyHammerThrowTurtle")
    {
        m_Type = "GreyHammerThrowTurtle";
        HammerThrowTurtle,GreyHammerThrowTurtle,
                          m_EmenyState = HammerThrowTurtle;
        m_srcRect = {16*20,16*6,16,32};
        m_desRect = {32,0,16,32};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
    else if(filenameStr=="Browser")
    {
        m_Type = "Browser";
        m_EmenyState = Browser;
        m_srcRect = {32,00,16,16};
        m_desRect = {32,0,16,16};
        m_width = 16;
        m_height = 32;
        m_isStaticSprite = true;
        m_isAnimationSprite = false;
    }
}
