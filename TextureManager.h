#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <math.h>
#include <iostream>
#include <string.h>
class TextureManager
{
public:
    static TextureManager* Instance()
    {
        if(s_pInstance == NULL)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
    void bezier(SDL_Renderer *renderer, int arr[], int Size, int dense);
    void SetColour(char r,char g, char b, char a,SDL_Renderer*   renderer);
    void Drawcircle(SDL_Renderer *renderer,int center_x, int center_y, int radius_);
    void DrawPoint(int x,int y,SDL_Renderer *render);
    void DrawTilingRect(std::string id, SDL_Rect *srcrect , SDL_Rect * dstrect,int TileSize,SDL_Renderer *render);
    void DrawLine(int x,int y,int x1, int y1,SDL_Renderer* p_ren);
    void DrawRect(int x,int y,int w,int h,SDL_Renderer *render);
    void DrawCircleFilled(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
    void DrawRectFilled(int x,int y,int w,int h,SDL_Renderer *render);
    void DrawText(const std::string message, int x,int y,SDL_Renderer *render);
    void DrawText(const std::string message, int x,int y,int FontSize,SDL_Renderer *render);

    void Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* p_ren, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void SDLDraw(SDL_Renderer * renderer,std::string id, SDL_Rect * srcrect, SDL_Rect * dstrect, double angle, SDL_Point *center, SDL_RendererFlip flip);
    void DrawBackGround(std::string id,SDL_Renderer* p_ren);

    bool Load(std::string fileName, std::string id,SDL_Renderer* p_ren);
    std::map<std::string,SDL_Texture *> getTextureMap();
    void ClearTextureMap();
    void ClearFromTextureMap(std::string id);

private:

    TextureManager() {};
    ~TextureManager() {}
    static TextureManager* s_pInstance;

    std::map<std::string,SDL_Texture *>m_TextureMap;

};

#endif // TEXTUREMANAGER_H
//void TextureManager::LoadRegisterType(std::string fileName,SDL_Renderer* p_ren)
//{
//}
//    void LoadRegisterType(std::string fileName, SDL_Renderer* p_ren);

//    void DrawTarget2(std::string id, int cropX,int cropY,int x, int y,int width, int height, SDL_Renderer*p_ren,double angle, SDL_RendererFlip flip);
//
//    void DrawTarget(std::string id, int cropX,int cropY,int x, int y,int width, int height, SDL_Renderer*p_ren, SDL_RendererFlip flip);

//    void DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* p_ren,double angle,int alpha, SDL_RendererFlip flip = SDL_FLIP_NONE);
//    void DrawTile(std::string id, int margin,int spacing,int x, int y,int width, int height,int currentRow, int currentFrame, SDL_Renderer*p_ren);

//delete &m_TextureMap;
//    ClearTextureMap();
// bool LoadColour(std::string fileName, char r, char, char b, char a);
// std::map<std::string,SDL_Color *> getcolour();
