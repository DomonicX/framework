#ifndef MARIOPLAYER_H
#define MARIOPLAYER_H


#include <string.h>
#include <SDLGameObject.h>
typedef enum {Mario_LEFT,MARIO_RIGHT} mario_Facing;


typedef enum {DUCKING,
              IDLE,
              STANDING,
              JUMMPING,
              RUNNING_LEFT,
              RUNNING_RIGHT,
              SLIDING_LEFT,
              SLIDING_RIGHT,
              FAILING
             } MarioAnmationState;

typedef enum {SMALLMARIO,
              BIGMARIO,
              FIREMARIO,
              STARMARIO
             } MarioState;

class MarioPlayer : public SDLGameObject
{
public:
    MarioPlayer();
    virtual ~MarioPlayer();
    void UpdateGravity();
    void Load(char* filename);
    void Update();
    std::string getState();
    std::string getAnmationState();
bool isBinking(){return m_bisBlinking;}
    void Clean() {}
    void Collision() {}
    void Draw() ;
    void OnKeyBoardEvent();
    void isOnGround()
    {
        m_bisGrounded = true;
    }
    void isInAir()
    {
        m_bisGrounded = false;
    }
    bool isFailling();
    bool isJumping;
    SDL_Rect GetSDLRect()
    {

        switch(m_marioState)
        {
        case SMALLMARIO:
            std::cout <<"SMALLMARIO" << "\n";
            return {m_position.x,m_position.y,m_width,16};
            break;
        case FIREMARIO:
            std::cout <<"SMALLMARIO" << "\n";
            return {m_position.x,m_position.y,m_width,32};
            break;
        case BIGMARIO:
            std::cout <<"SMALLMARIO" << "\n";
            return {m_position.x,m_position.y,m_width,32};
            break;
        case STARMARIO:
            std::cout <<"SMALLMARIO" << "\n";
            return {m_position.x,m_position.y,m_width,32};
            break;
        }
    }


    std::string Type()
    {
        return m_Playertype;
    }
    std::string Texture()
    {
        return "MairoBig";
    } void updateMovements();
protected:

private:
    int m_count;
    std::string m_Playertype;
    float Speed;
    int m_FacingDir;
    float m_oldTime;
    bool m_bisFliped;
    bool m_bisBlinking;
    SDL_RendererFlip m_Flip = SDL_FLIP_NONE;
    int m_maxFrame;
    bool m_bisDucking;
    bool m_bisGrounded;
    bool m_DownPressed;
    bool m_DownReleased;
    int m_marioAnmationState;
    int m_marioState;
};


class  MarioPlayerObjectCreater : public SDLGameObjectCreater
{
    GameObject* CreateGameObject() const
    {
        return  new MarioPlayer();
    }
};

class SmallMario
{
public:
    SmallMario(){};
    ~SmallMario(){};

};

class BigMario
{
public:
    BigMario(){};
    ~BigMario(){};

};

class StarMario
{
public:
    StarMario(){};
    ~StarMario(){};

};

class FireMario
{
public:
    FireMario(){};
    ~FireMario(){};

};
#endif // MARIOPLAYER_H


/** \brief
 *
 * \param
 * \param
 * \return
 *#include "Player.h"
 bool AbleToJump(){}

        state = DUCKING;
//  switch(state)
//    case IDLE:
//    case DUCKING:
//    case STANDING:
//    case JUMMPING:
//    case Failing:
//    case RUNNING_LEFT:
//    case RUNNING_RIGHT:
//    case SLIDING_LEFT:
//    case SLIDING_RIGHT:


void Player::Load(char* filename)
{

    //  m_acceleration = vec2f(0,0.03);
    if((std::string)filename=="PlayerStart")
    {
        m_currentFrame =0;
        m_lastFrame = 4;
        m_startFrame = 0;
        m_numFrame = 3;
        m_frameRate = 100;
        //  Camera::Instance()->SetTarget(new vec2f(m_position.x+(m_width+458),0));
        m_lastFrame = 3;

        //   Camera::Instance()->SetTarget(&GetPosition());
        m_position = vec2f(32,176);
    }
    if((std::string)filename=="Dead")
    {
        m_bUpdating = false;
        m_currentFrame = 6;
        m_height = 32;
        m_force = 70;
        m_bDying = true;
        m_currentRow = 1;
    }
    if((std::string)filename=="JUMMPING")
    {

        state =  MARIRO_STATE::ISJUMMPING;

    }
    if((std::string)filename=="Item-Mushroom")
    {

    }
    if((std::string)filename=="On_Ground")
    {
        m_bFalling = false;
        m_bGround = true;
        m_bJump = false;
    }

    if((std::string)filename=="Falling")
    {
        m_bGround = false;
        m_bJump = false;
        m_bFalling = true;
    }

    if((std::string)filename=="HitRight")
    {
        m_bgoingRight = false;
    }
    if((std::string)filename=="Duck")
    {
        m_currentFrame = 6;
    }
    if((std::string)filename=="RUNRIGHT")
    {
        m_bgoingRight = true;

    }
    if((std::string)filename=="RUNLEFT")
    {
        m_bgoingLeft = true;

        state =  MARIRO_STATE::RUNNING_LEFT;

    }
    if((std::string)filename=="STANDING")
    {
        m_bgoingRight = false;
        m_bgoingLeft = false;
        m_currentFrame =0;

    }
}

void Player::Update()
{

    m_oldpos = m_position;
    m_currentFrame = 0;
    if(InputHandler::Instance()->isKeyDown(SDLK_LEFT)&& InputHandler::Instance()->isKeyDown(SDLK_RIGHT))
    {

        m_bRunning = true;
        m_bMoveLeft = false;
        m_bMoveRight = false;

    }

    if(m_bRunning && m_bMoveLeft)
    {
      if(InputHandler::Instance()->isKeyDown(SDLK_LEFT)&& !InputHandler::Instance()->isKeyDown(SDLK_DOWN))
    {
        m_bMoveLeft = true;
    }

        if(m_acceleration.x<0)
        {
            m_currentFrame = 3;
            m_currentFrame = (((SDL_GetTicks()/m_frameRate)%m_numFrame+1));
        }
        else
        {
            m_currentFrame = 4;
        }

        m_acceleration.x -= 0.67;

        m_isFlipped = SDL_FLIP_NONE;    m_velocity = m_acceleration * Game::Instance()->GetDeltaTime();
    m_position.x -= m_velocity.x;


    }

    if(m_bRunning && m_bMoveRight)
    {
     if(InputHandler::Instance()->isKeyDown(SDLK_RIGHT)&& !InputHandler::Instance()->isKeyDown(SDLK_DOWN))
    {
        m_bMoveRight = true;
    }

        if(m_acceleration.x>0)
        {
            m_currentFrame = 3;
            m_currentFrame = (((SDL_GetTicks()/m_frameRate)%m_numFrame+1));
        }
        else
        {
            m_currentFrame = 4;

        }
        m_acceleration.x += 0.67;

        m_isFlipped = SDL_FLIP_HORIZONTAL;
            m_velocity = m_acceleration * Game::Instance()->GetDeltaTime();
    m_position.x -= m_velocity.x;

    }


    if(InputHandler::Instance()->isKeyDown(SDLK_UP) && !InputHandler::Instance()->isKeyDown(SDLK_DOWN)  && m_bGround)
    {
        m_bCanJump = true;
        m_bJump = true;

    }

    if(m_bJump)
    {
        m_bCanJump = false;
        m_bGround = false;
        m_force = 60;
        m_bJump = false;
        m_bFalling = true;

    }
    if(m_bFalling)
    {
        m_currentFrame = 5;

        m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
        m_position.y -= m_force * Game::Instance()->GetDeltaTime();

    }
    if(m_bGround)
    {
        m_force = 0;
        m_bGround = true;
        m_bCanJump = true;
        if(m_force<0.0)
        {
            //m_velocity *=0.9;
            m_currentFrame = 0;
        }



    }
    if(InputHandler::Instance()->isKeyDown(SDLK_DOWN) && m_bGround)
    {
        m_currentFrame = 6;
    }
    if(m_acceleration.Length()>0.0)
    {
        //m_velocity *=0.9;

    }

}



//    if(state==ISSTANDING)
//    {
//friction =   -m_velocity.Length() *  Game::Instance()->GetDeltaTime();
//        if(m_acceleration.Length()>0)
//        {
//
//        }
//        m_acceleration = vec2f(0,0);
//
//    }
//    if(state==RUNNING_RIGHT)
//    {
//        m_acceleration += 0.06;
//        if(m_acceleration.x >= 3.0)
//            m_acceleration.x = 3;
//    }
//    if(state==RUNNING_LEFT)
//    {
//
//        m_acceleration += -0.06;
//        if(m_acceleration.x >= -3.0)
//            m_acceleration.x = -3;
//    }
//
//    if(state==ISJUMMPING)
//    {
//        m_bGround = false;
//        m_bJumping = false;
//        m_force = 70;
//
        state = DUCKING;
        state =  MARIRO_STATE::ISSTANDING;
        state =  MARIRO_STATE::RUNNING_RIGHT;
        state =  MARIRO_STATE::RUNNING_LEFT;
        state==ISJUMMPING
//    }
//    if(!IsOnGround() && !IsAbleJump())
//    {
//        m_force -= 1;
//        m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//        m_position.y -= m_force * Game::Instance()->GetDeltaTime();
//
//    }
//    m_position.x  += m_acceleration.x;
//
//    if(IsOnGround())
//    {
//
//        m_bJumping = true;
//
//    }
//    velocity += acceleration *= Game::Instance()->GetDeltaTime();
//
////    if(isdying())
//    {
//        m_force -= 1;
//        m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//        m_position.y -= m_force * Game::Instance()->GetDeltaTime();
//
//    }
//    if(m_bUpdating)
//    {
//        m_oldpos = m_position;
//
//        if(!InputHandler::Instance()->isKeyDown(SDLK_DOWN))
//        {
//            if(InputHandler::Instance()->isKeyDown(SDLK_RIGHT))
//            {
//                acceleration  += 0.9;
//                m_isFlipped = SDL_FLIP_NONE;
//                if(velocity>0)
//                {
//                    state = RUNNING_RIGHT;
//
//                }
//                else
//                {
//                    state = SLIDING_RIGHT;
//                }
//            }
//        }
//        if(!InputHandler::Instance()->isKeyDown(SDLK_DOWN))
//        {
//            if(InputHandler::Instance()->isKeyDown(SDLK_LEFT))
//            {
//                acceleration  -= 0.9;
//                m_isFlipped = SDL_FLIP_HORIZONTAL;
//                if(velocity<0)
//                {
//                    state = RUNNING_LEFT;
//                }
//                else
//                {
//                    state = SLIDING_LEFT;
//                }
//            }
//        }
//        if(IsOnGround())
//        {
//            state = IDLE;
//
//            if(InputHandler::Instance()->isKeyDown(SDLK_DOWN))
//            {
//                state = DUCKING;
//            }
//            if(InputHandler::Instance()->isKeyDown(SDLK_UP))
//            {
//std::cout << "state for mario is " << "\n";
//                m_force+= Game::Instance()->GetDeltaTime();
//                m_bJumping = true;
//            }
//        }
//        if(m_bJumping)
//        {
//            m_oldTime+= Game::Instance()->GetDeltaTime();
//            jumptime +=  m_oldTime;
//            m_JumpTimeMax =  Game::Instance()->GetDeltaTime() * 200;
//            if(m_JumpTimeMax<jumptime)
//            {
//                m_force +=  jumptime ;;
//                m_bGround = false;
//                m_bJumping = false;
//            }
//            if(!InputHandler::Instance()->isKeyDown(SDLK_UP))
//            {
//                m_force +=  jumptime;
//                m_bGround = false;
//                m_bJumping = false;
//            }
//
//        }
//        if(!IsOnGround())
//        {
//            jumptime = 0;
//
//            state = JUMMPING;
//
//            m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//           m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
//            //    m_position.y -= m_force * Game::Instance()->GetDeltaTime();
//        }
//        velocity += acceleration *= Game::Instance()->GetDeltaTime();
//if(IsOnGround())
//
//    {
//            m_velocity.y = 0;
//        }
//
//
//        m_velocity.x = velocity*= 0.99;
//        m_position +=  m_velocity;
//
//    }
//  switch(state)
//  {
//    case IDLE:
//
//        m_currentFrame = 0;
//        break;
//    case DUCKING:
//
//        break;
//    case JUMMPING:
//        m_currentFrame = 5;
//        break;
//    case RUNNING_LEFT:
//        m_currentFrame = 3;
//        m_currentFrame = (((SDL_GetTicks()/m_frameRate)%m_numFrame+1));
//        break;
//    case RUNNING_RIGHT:
//        m_currentFrame = 3;
//
//        break;
//    case SLIDING_LEFT:
//        m_currentFrame = 4;
//        break;
//    case SLIDING_RIGHT:
//        m_currentFrame =4;
//        break;
//    }













 */

