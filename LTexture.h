#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL2/SDL_image.h>
#include <string>
class LTexture
{
public:
    LTexture() : m_texture(nullptr) {};
    virtual ~LTexture();
    bool LoadFromFile(std::string path);
    bool LoadFromRenderedText(std::string Texture);
    void Free();
    void SetColor(Uint8 red,Uint8 Green,Uint8 Blue);
    void SetBlendMode(SDL_BlendMode blending);
    void SetAlpha(Uint8 Alpha);
    void Render(int x, int y, SDL_Rect* clip = NULL,double angle = 0.0,SDL_Point* center = NULL,SDL_RendererFlip flip = SDL_FLIP_NONE);
    int GetWidth();
    int GetHeight();
protected:

private:
    SDL_Texture* m_texture;
    int m_width;
    int m_height;
};

#endif // LTEXTURE_H
