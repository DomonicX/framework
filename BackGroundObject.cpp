#include "BackGroundObject.h"

BackGroundObject::BackGroundObject()
{
    //ctor
}

BackGroundObject::~BackGroundObject()
{

}
void BackGroundObject::Load(char* filename)
{
    std::string m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);

    ifs >> m_textureID;
    ifs.close();
}
void BackGroundObject::Update() {}
void BackGroundObject::Draw()
{
    TextureManager::Instance()->SDLDraw(Game::Instance()->GetRenderer(),
                                        m_textureID,
                                        NULL,NULL,
                                        NULL,
                                        NULL,SDL_FLIP_NONE);
}
void BackGroundObject::Clean() {}

void BackGroundObject::Collision() {}
