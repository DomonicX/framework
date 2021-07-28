#ifndef BACKGROUNDOBJECT_H
#define BACKGROUNDOBJECT_H

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
class BackGroundObject : public GameObject
{
    public:
        BackGroundObject();
        virtual ~BackGroundObject();
void Load(char* filename);
    void Update();
    void Draw() ;
    void Clean() ;

    void Collision() ;
    std::string Type()
    {
        return "BackGround";
    }
    int getHeight()
    {
        return m_height;
    }
    int getWidth()
    {
        return m_width;
    }
    int m_height;
    int m_width;
     std::string Texture(){return m_textureID ;};
    void HandleEvent(SDL_Event& e ) {}
    protected:

    private: std::string m_textureID;
    std::string m_filename;
    bool m_bisFilled;
    SDL_Rect  m_srcRect ;
    SDL_Rect m_desRect;


};

#endif // BACKGROUNDOBJECT_H
class  GameObjectBackGroundCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new BackGroundObject();
    }
};
