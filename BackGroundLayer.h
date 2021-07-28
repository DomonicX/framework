#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include <ILayer.h>
#include <iostream>

#include <SDL2/SDL_rect.h>
#include <Level.h>
#include <GameObjectFactory.h>
#include <SDLGameObject.h>
#include <BackGroundLayer.h>
#include <TextBoxState.h>
#include <GUI_Object.h>
class BackGroundLayer: public ILayer
{
public:
    BackGroundLayer();
    virtual ~BackGroundLayer();


    void Render();
    void Update(Level* pLevel);
protected:

private:
    GameObject* g;
GameObject* g2;
GameObject* g3;
GameObject* g4;
GameObject* g5;
GameObject* t51;
    std::vector<GameObject*>m_StaticBackGroundObjects;
};

#endif // BACKGROUNDLAYER_H
