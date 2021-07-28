
#ifndef NODE_H
#define NODE_H
#include <algorithm>
#define SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <float.h>
#include <Vector2D.h>
#include <math.h>


enum CELL_STATE {EMPTY,SOLID,EVENT,START,END,ACTIVE,CLOSED,OPEN,PATH};
class Node
{
public:
    Node() {};
    virtual ~Node()
    {
        currentState = EMPTY;
    };
    Node(vec2f Pos,Node &ParentNode,double g,double h,double f) : pos(Pos), parentNode(&ParentNode)
    {
        G=g;
        F=f;
        H=h;
    }
    Node(vec2f Pos) : pos(Pos) {}
    Node(vec2f Pos, CELL_STATE newState) : pos(Pos), currentState(newState) {}
    Node(vec2f Pos,Node *ParentNode) :pos(Pos), parentNode(ParentNode) {};

    Node* parentNode = NULL;
    vec2f pos;

    SDL_Rect Dsrect;
    SDL_Rect Screct;

    float G = FLT_MAX;
    float F = FLT_MAX;
    float H = FLT_MAX;

    CELL_STATE currentState = EMPTY;
    void Display(SDL_Renderer &Rend,int TileSize);
    void init(SDL_Renderer &Rend,int posX,int posY);
    void ChangeType(CELL_STATE type);

protected:
private:


};

#endif // NODE_H

///
///
//tree.m_root->right_node->left_node->m_val;
//
//node b1 = node{2,0,0};
//node b2 = node{3,b5,0};

//node root = node{1,b1,b2};
//root.left_node.left_node.left_node.val
//      r
//   b1    b2
//  b\
//
//class biTree
//{
//public:
//    node* m_root;
//    biTree() : m_root(new node(0)) {};
//    node& GetRoot()
//    {
//        return *m_root;
//    }
//    void toString()
//    {
//        node* tempNode;
//        std::cout << "  " << m_root->m_val << "\n";
//        tempNode = m_root;
//        while(tempNode->left_node!=nullptr)
//        {
//            tempNode = tempNode->left_node;
//            std::cout << "  " << tempNode->m_val << "\n";
//
//        }
////        std::cout << "  " << m_root->m_val << "\n"
////        <<  m_root->left_node->m_val << "  "
////        << m_root->right_node->m_val << "\n";
//    }
//};
//
