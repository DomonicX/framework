#include "TextureManager.h"
#define scaleOffSet 1
TextureManager *TextureManager::s_pInstance = 0;

bool TextureManager::Load(std::string fileName, std::string id,SDL_Renderer* p_ren)
{
    SDL_Surface *pTempSurFace = IMG_Load(fileName.c_str());
    if(pTempSurFace == NULL)
    {
        std::cout << "ERROR -pTempSurFace TextureManager::Load"<< IMG_GetError() << "\n ERROR - TextureManager::Load"<< id<< "\n";
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(p_ren,pTempSurFace);
    SDL_free(pTempSurFace);
    if(pTexture!=NULL)
    {
        m_TextureMap[id] = pTexture;
        return true;
    }
    std::cout << "ERROR TextureManager::Load" << IMG_GetError() << "\n ";

    return false;
}

void TextureManager::SetColour(char r,char g, char b, char a,SDL_Renderer*   renderer)
{
    if(SDL_SetRenderDrawColor(renderer, r,g, b, a))
        std::cout << "ERROR SDL_SetRenderDrawColor"<< SDL_GetError();
}

std::map<std::string,SDL_Texture *> TextureManager::getTextureMap()
{
    return m_TextureMap;
}
void TextureManager::ClearTextureMap()
{
    m_TextureMap.clear();
}
void TextureManager::ClearFromTextureMap(std::string id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);

}
void TextureManager::DrawPoint(int x,int y,SDL_Renderer *render)
{
    SDL_RenderDrawPoint(render,x,y);
}
void TextureManager::DrawLine(int x,int y,int x1, int y1,SDL_Renderer* p_ren)
{
    SDL_RenderDrawLine(p_ren,x,y,x1,y1);
}
void TextureManager::DrawRect(int x,int y,int w,int h,SDL_Renderer *render)
{
    SDL_Rect tempRect  = {x,y,w,h};
    SDL_RenderDrawRect(render,&tempRect);
}
void TextureManager::DrawRectFilled(int x,int y,int w,int h,SDL_Renderer *render)
{
    SDL_Rect tempRect  = {x,y,w,h};
    SDL_RenderFillRect(render,&tempRect);
}
void TextureManager::SDLDraw(SDL_Renderer * renderer,std::string id, SDL_Rect * srcrect, SDL_Rect * dstrect, double angle, SDL_Point *center, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(renderer,m_TextureMap[id],srcrect,dstrect,0,0,flip);
}
void TextureManager::DrawText(const std::string message, int x,int y,SDL_Renderer *render)
{
    DrawText(message,x,y,10,render);
}

void TextureManager::Drawcircle(SDL_Renderer *renderer,int center_x, int center_y, int radius_)
{
    // Setting the color to be RED with 100% opaque (0% trasparent).
    // Drawing circle
    for(int x=center_x-radius_; x<=center_x+radius_; x++)
    {
        for(int y=center_y-radius_; y<=center_y+radius_; y++)
        {
            if((std::pow(center_y-y,2)+std::pow(center_x-x,2)) <= std::pow(radius_,2))
            {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

void TextureManager::bezier(SDL_Renderer *renderer, int  arr[], int Size, int dense)
{
    int *a = new int[Size * 2];
    for (int i = 0; i < (1 << dense); i++)
    {
        for (int j = 0; j < Size * 2; j++) a[j] = arr[j];
        for (int j = (Size - 1) * 2 - 1; j > 0; j -= 2)
            for (int k = 0; k <= j; k++)
                a[k] = a[k] + (((a[k+2] - a[k]) * i) >> dense);
        Drawcircle(renderer,a[0], a[1], 3);
//   circle(a[0], a[1], 3);  // draw a circle, in Processing
    }
}

void TextureManager::DrawCircleFilled(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void TextureManager::DrawText(const std::string message, int x,int y,int FontSize,SDL_Renderer *render)
{

    int iW,iH;
    TTF_Font *font = TTF_OpenFont("OpenSans-Bold.TTF",FontSize);
    if(font==nullptr)
    {
        std::cout << " 1 erroxxxxr \n";
    }
    SDL_Surface *surf = TTF_RenderText_Shaded(font,message.c_str(), {255,255,255,255}, {0,0,0,0});
    if(surf==nullptr)
    {
        TTF_CloseFont(font);
        std::cout << " 2 errdddor \n";
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surf);
    if(texture==nullptr)
    {
        std::cout << " 3 errddddor \n";
    }
    SDL_QueryTexture(texture,NULL,NULL,&iW,&iH);
    SDL_Rect ss = {x,y,iW,iH};
    SDL_RenderCopyEx(render,texture,NULL,&ss,0,NULL,SDL_FLIP_NONE);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_Renderer* p_ren, SDL_RendererFlip flip)
{


    SDL_Rect srcRect = {0,
                        0,
                        width,
                        height
                       };

    SDL_Rect desRect { x,
                       y,
                       width,
                       height};

    SDL_RenderCopyEx(p_ren,m_TextureMap[id],&srcRect,&desRect,0,0,SDL_FLIP_NONE);
}

void TextureManager::DrawBackGround(std::string id, SDL_Renderer* p_ren)
{
    SDL_RenderCopyEx(p_ren,m_TextureMap[id],NULL,NULL,0,0,SDL_FLIP_NONE);
}

void TextureManager::DrawTilingRect( std::string id, SDL_Rect * srcrect, SDL_Rect * dstrect,int TileSize,SDL_Renderer *render)
{

    srcrect->x;
    srcrect->y;
    srcrect->h = TileSize;
    srcrect->w = TileSize;
    int numOfTiles = (dstrect->w)/TileSize;

    for(int i = 0 ; i < numOfTiles; i++)
    {

        int inc = i*TileSize;
        SDL_Rect tempDstrect = {dstrect->x+inc,dstrect->y,TileSize,TileSize};


        SDL_RenderCopyEx(render,m_TextureMap[id],srcrect,&tempDstrect,0,0,SDL_FLIP_NONE);
    }
}
//void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* p_ren,double angle,int alpha, SDL_RendererFlip flip)
//{
//
//    SDL_Rect srcRect = { width * currentFrame,
//                         height * currentRow,
//                         width,
//                         height
//                       };
//
//
//    SDL_Rect desRect { x,
//                       y,
//                       width,
//                       height};
//
//    SDL_SetTextureAlphaMod(m_TextureMap[id],alpha);
//    SDL_RenderCopyEx(p_ren,m_TextureMap[id],&srcRect,&desRect,0,0,SDL_FLIP_NONE);
//
//}
//
//
//void TextureManager::DrawTile(std::string id, int margin,int spacing,int x, int y,int width, int height,int currentRow, int currentFrame, SDL_Renderer* p_ren)
//{
//
//
//    SDL_Rect srcRect = { margin  + (spacing + width) * currentFrame,
//                         margin  + (spacing + width) * currentRow,
//                         width,
//                         height
//                       };
//
//    SDL_Rect desRect { x,
//                       y,
//                       width,
//                       height};
//
//    SDL_RenderCopyEx(p_ren,m_TextureMap[id],&srcRect,&desRect,0,0,SDL_FLIP_NONE);
//
//}
//void TextureManager::DrawTarget(std::string id, int cropX,int cropY,int x, int y,int width, int height, SDL_Renderer*p_ren, SDL_RendererFlip flip)
//{
//    SDL_Rect srcRect = { width * cropX,
//                         height * cropY,
//                         width,
//                         height
//                       };
//    SDL_Rect desRect { x * scaleOffSet,
//                       y * scaleOffSet,
//                       width * scaleOffSet,
//                       height * scaleOffSet};
//
//    SDL_RenderCopyEx(p_ren,m_TextureMap[id],&srcRect,&desRect,0,0,flip);
//}
//void TextureManager::DrawTarget2(std::string id, int cropX,int cropY,int x, int y,int width, int height, SDL_Renderer*p_ren,double angle, SDL_RendererFlip flip)
//{
//    SDL_Rect srcRect = { width * cropX,
//                         height * cropY,
//                         width,
//                         height
//                       };
//    SDL_Rect desRect   { x*scaleOffSet,
//                         y *scaleOffSet,
//                         width *scaleOffSet,
//                         height *scaleOffSet
//                       };
//    SDL_RenderCopyEx(p_ren,m_TextureMap[id],&srcRect,&desRect,angle,0,flip);
//}

//
//SDL_Texture*  TextureManager::DrawText(const std::string &message, const std::string &fontFlie, SDL_Color color, int fontSize, SDL_Renderer *render)
//{
//    TTF_Font *font = TTF_OpenFont(fontFlie.c_str(),fontSize);
//    if(font==nullptr)
//    {
//        std::cout << " 1 error \n";
//
//    }
//
//    SDL_Surface *surf = TTF_RenderText_Blended(font,message.c_str(),color);
//      if(surf==nullptr)
//    {
//TTF_CloseFont(font);
//        std::cout << " 2 error \n";
//    }
//
//    SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surf);
//    if(texture==nullptr)
//    {
//        std::cout << " 3 error \n";
//    }
//
//
//
//    SDL_FreeSurface(surf);
//    TTF_CloseFont(font);
//
//
//}
