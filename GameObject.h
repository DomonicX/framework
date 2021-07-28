#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <Vector2D.h>



class GameObject
{
public:
    virtual  ~GameObject() {};

    virtual void Load(char* filename) = 0;
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual void Clean() =0;
    virtual void Collision() = 0;
    virtual std::string Type() = 0;
    virtual std::string Texture() = 0;
    int getHeight()
    {
        return m_height;
    }
    int getWidth()
    {
        return m_width;
    }



    vec2f topLeft()
    {
        return m_position;
    }
    vec2f topRight()
    {
        return vec2f(m_position.x+m_width,m_position.y);
    }
    vec2f BottomRight()
    {
        return vec2f(m_position.x+m_width,m_position.y+m_height);
    }
    vec2f bottomLeft()
    {
        return vec2f(m_position.x,m_position.y+m_height);
    }
    vec2f Centre()
    {
        return vec2f(m_position.x+(m_width/2),m_position.y+(m_height/2));
    }
    vec2f& GetPosition()
    {
        return m_position;
    }
    vec2f& GetVelocity()
    {
        return m_velocity;
    }
    vec2f& GetAcceleration()
    {
        return m_acceleration;
    }
    vec2f& GetlastPosition()
    {
        return m_lastPos;
    } vec2f& GetForce()
    {
        return m_force;
    } float& GetMass()
    {
        return m_mass;
    }
    bool Dead()
    {
        return m_bDead;
    }

    void SetDead()
    {
        m_bDead = true;
    }


protected:


    GameObject() :
        m_position(0,0),
        m_velocity(0,0),
        m_acceleration(0,0),
        m_lastPos(0,0),
        m_force(0,0),
        m_mass(0),
        m_gravity(9.8),
        m_bDead(false),
        m_height(0),m_width(0)
    {
    }

    int m_height;
    int m_width;
    vec2f m_position;
    vec2f m_lastPos;
    vec2f m_velocity;
    vec2f m_acceleration;
    vec2f m_force;
    float m_mass;


   const float m_gravity;
    bool m_bDead;
};



#endif // GAMEOBJECT_H



//  bool m_bDying;
//        m_bDying(false)

//    void SetDying()
//    {
//        m_bDying = true;
//    }
//   bool Dying()
//    {
//        return m_bDying;
//    }

// bool m_bUpdating;

// m_bUpdating(false),
// int m_height;
////    int m_width;
//    int r,g,b,a;
//    double m_angle;
//    char m_alpha = 0;
//    std::string m_textureID;
//    std::string m_filename;


//      std::string& GettextureID()
//    {
//        return m_textureID;
//    }
//    std::string getFilePath()
//    {
//        return m_filename;
//    }

//        m_velocity(0,0),
//        m_acceleration(0,0),
// m_height(0),
//   m_width(0),
//        m_angle(0),
//        m_alpha(255),
//        r(0),g(0),b(0)
//    void setUpdating(bool updating)
//    {
//        m_bUpdating = updating;
//    }  bool updating()
//    {
//        return m_bUpdating;
//    }
//    void scroll(float scrollSpeed)
//    {
//        if(Type()!= "player")
//        {
//            m_position.x-=scrollSpeed;
//
//        }
//    }

//    int GetLastFrame()
//    {
//        return m_lastFrame;
//    }
//    int GetStartFrame()
//    {
//        return m_startFrame;
//    }

//    } int GetCurrentFrame()
//    {
//        return m_currentFrame;
//    }
//    virtual char getStateID()
//    {
//        return '_';
//    }
//    int GetCurrentRow()
//    {
//        return m_currentRow;
//    }
//        m_currentRow(0),
//        m_currentFrame(0),

//    int  m_Level;
//    int  m_cost;
//    int  m_dmg;
//    int  m_Range;

//    int m_numFrame;
//
//    int m_frameRate;
//    int m_currentRow;
//    int m_currentFrame;
//    int m_startFrame;
//    int m_lastFrame;
