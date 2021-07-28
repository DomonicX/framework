#ifndef GUI_OBJECT_H
#define GUI_OBJECT_H

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
class GUI_Object : public GameObject
{
public:
    GUI_Object();
    virtual ~GUI_Object();

    void Load(char* filename);
    void Draw();
    void Update();
    void Clean();
    void SetSize(SDL_Rect Rect );
    void Collision();
    std::string Texture();
    std::string Type();
    int getHeight();
    int getWidth();
protected:

private:
    std::string m_textureID;
    std::string m_filename;
    int m_height;
    int m_width;
    SDL_Rect m_srcRect;
    SDL_Rect m_desRect;
    void DrawCentre();
  void  DrawSides();
  void DrawLeftAndRightSide();
void DrawCorner();
bool m_bisHighLit;
};

class  GUIObjectCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new GUI_Object();
    }
};
#endif // GUI_OBJECT_H
