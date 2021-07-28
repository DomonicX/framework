#include "Node.h"
/*
Node::Node()
{
    //ctor
}

Node::~Node()
{
    //dtor
}


*/


void Node::Display(SDL_Renderer &Rend,int TileSize)
{

    SDL_Rect Dsrect;
    SDL_Rect Screct;
    Dsrect = {pos.x,pos.y,TileSize,TileSize};
    Screct = {0,0,TileSize,TileSize};

    switch(currentState)
    {

    case OPEN:
        SDL_SetRenderDrawColor(&Rend,0,155,155,125);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        SDL_RenderFillRect(&Rend,&Dsrect);
        break;

    case CLOSED:
        SDL_SetRenderDrawColor(&Rend,25,0,0,255);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        SDL_RenderFillRect(&Rend,&Dsrect);
        break;
    case EMPTY:
       SDL_SetRenderDrawColor(&Rend,0,222,12,0);
    SDL_RenderDrawRect(&Rend,&Dsrect);
   // SDL_RenderFillRect(&Rend,&Dsrect);
        break;

    case SOLID:
        SDL_SetRenderDrawColor( &Rend,0,255,0,255 );
        SDL_RenderFillRect(&Rend,&Dsrect);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        break;

    case EVENT:

        SDL_SetRenderDrawColor( &Rend,0,0,0,255 );
        SDL_RenderFillRect(&Rend,&Dsrect);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        break;

    case START:
        SDL_SetRenderDrawColor(&Rend,0,255,0,255);
        SDL_RenderFillRect(&Rend,&Dsrect);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        break;


    case ACTIVE:
        SDL_SetRenderDrawColor(&Rend,0,0,0,255);
        SDL_RenderFillRect(&Rend,&Dsrect);
        SDL_SetRenderDrawColor(&Rend,0,125,0,255);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        break;

    case END:

        SDL_SetRenderDrawColor(&Rend,0,0,0,124);
        SDL_RenderFillRect(&Rend,&Dsrect);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        break;

    case PATH:

        SDL_SetRenderDrawColor(&Rend,0,125,0,255);
        SDL_RenderFillRect(&Rend,&Dsrect);
        SDL_SetRenderDrawColor(&Rend,0,125,0,255);
        SDL_RenderDrawRect(&Rend,&Dsrect);
        break;
    }
}


void Node::ChangeType(CELL_STATE type)
{
    switch(type)
    {

    case OPEN:

//std::cout << "type now = OPEN\n";
        currentState = type;
        break;

    case EMPTY:

//std::cout << "type now = Empty\n";
        currentState = type;
        break;

    case SOLID:

//std::cout << "type now = SOLID\n";
        currentState = type;
        break;

    case EVENT:

//std::cout << "type now = EVENT\n";
        currentState = type;
        break;

    case START:

//std::cout << "type now = START\n";
        currentState = type;
        break;

    case END:
//std::cout << "type now = END\n";
        currentState = type;
        break;

    case ACTIVE:
//std::cout << "type now = ACTIVE\n";
        currentState = type;
        break;

    case CLOSED:
//std::cout << "type now = CLOSED\n";
        currentState = type;
        break;

    case PATH:
//std::cout << "type now = PATH\n";
        currentState = type;
        break;
    }
}


void Node::init(SDL_Renderer &Rend,int posX,int posY)
{
    pos.x = posX;
    pos.y = posY;
}
