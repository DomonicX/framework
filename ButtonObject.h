#ifndef BUTTONOBJECT_H
#define BUTTONOBJECT_H
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

class ButtonObject: public GameObject
{
    public:
        ButtonObject();
        virtual ~ButtonObject();

    void Load(char* filename){};
    void Draw(){};
    void Update(){};
    void Clean(){};
    void Collision(){};
    std::string Texture(){};
    std::string Type(){};
    int getHeight(){};
    int getWidth(){};
    protected:

    private:
};

#endif // BUTTONOBJECT_H
