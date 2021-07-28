#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H

#include <SDL2/SDL.h>
#include <GameObject.h>
#include <GameObjectFactory.h>
#include <Game.h>
#include <sstream>
#include <string.h>
#include <GameObject.h>
#include <iostream>
#include <Vector2D.h>
class TextObject : public GameObject
{
public:
    TextObject();
     ~TextObject();

     void Load(char* filename){};
     void Draw() {};
     void Update(){};
     void Clean() {};
     void Collision(){};
     std::string Type() {};
     std::string Texture(){};

protected:

private:
    int m_FontSize;
    SDL_Color m_backGroundColour;
    SDL_Color m_FontColour;
    SDL_Rect m_rectBox;
};


//	SDL_Surface* m_pSprite

class  TextObjectObjectCreater : public BaseCreater
{
    GameObject* CreateGameObject() const
    {
        return  new TextObject();
    }
};

#endif // TEXTOBJECT_H
