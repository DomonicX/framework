#ifndef MARIOBLOCK_H
#define MARIOBLOCK_H
#include <string.h>
#include <SDLGameObject.h>
#include <iostream>
#include <TextureManager.h>
#include <iostream>
#include <string.h>    // std::cout
#include <sstream>      // std::stringstream
#include <fstream>
#include <ostream>
typedef enum
{
    QuestionMarkBlock,
    BrickGround,
    Brick
} MarioBlockType;

class MarioBlock : public SDLGameObject
{
public:
    MarioBlock();
    virtual ~MarioBlock();
    void Load(char* filename);
    void Update();
    void Clean() {}
    void Collision()
    {
       this->m_bDead = true;
    }
    void Draw();
    std::string Texture()
    {
        return "Mario";
    }
SDL_Rect GetSDLRect(){return {m_position.x,m_position.x,m_width,m_height};}
protected:

private:
    int m_BlockState;
    std::string m_blocktype;
};

class  MarioBlockObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioBlock();
    }
};
#endif // MARIOBLOCK_H
