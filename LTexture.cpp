#include "LTexture.h"


LTexture::~LTexture()
{
    SDL_DestroyTexture(m_texture);
    //dtor
}
