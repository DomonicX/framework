#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H


#include <SDL2/SDL.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <Game.h>

#include <TextureManager.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>
class SDLGameObject : public GameObject
{
public:
    SDLGameObject(): GameObject() {}
    virtual ~SDLGameObject() {};
    void Load(char* filename);
    void Update();
    void Draw() ;
    void Clean() ;
    void Collision() ;
    std::string Type()
    {
        return m_Type;
    }
     std::string Texture(){};
     void HandleEvent(SDL_Event& e ) {}
    SDL_Rect  m_srcRect ;
    SDL_Rect m_desRect;
bool m_isStaticSprite;
bool m_isAnimationSprite;
    std::string m_textureID;
    std::string m_filename;
    bool m_bisFilled;
    std::string m_Type;
SDL_Rect GetSDLRect(){return {m_position.x,m_position.y,m_width,m_height};}


       int m_currentFrame;
      int m_frameRate;
int m_numFrame;
protected:
private:

    //	SDL_Surface* m_pSprite
};
class  SDLGameObjectCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new SDLGameObject();
    }
};

#endif // SDLGAMEOBJECT_H
