#include "MarioPlayer.h"

MarioPlayer::MarioPlayer() : SDLGameObject()
{
    m_count =0;
    m_velocity = vec2f(0,0);
    m_acceleration = vec2f(0,0);
    Speed = 0.1;
    m_mass = 10;
    m_FacingDir = mario_Facing::MARIO_RIGHT;
    m_bisFliped = false;
    m_bisGrounded = false;
    m_bisDucking = false;
    m_currentFrame =0;
    m_frameRate = 1;
    m_numFrame = 1;
    m_DownPressed = false;
    m_DownReleased = true;
    m_marioAnmationState = MarioAnmationState::IDLE;
    m_marioState = MarioState::BIGMARIO;
m_bisBlinking = false;
}
MarioPlayer::~MarioPlayer()
{

}
void MarioPlayer::Load(char* filename)
{

    m_Playertype = filename;
    std::string m_filename = filename;
    std::ifstream ifs;
    ifs.open (m_filename, std::ifstream::in);

    ifs >> m_textureID;
    ifs >> m_desRect.x >> m_desRect.y >> m_desRect.w >> m_desRect.h;
    ifs >> m_bisFilled;
    ifs.close();

    m_Type = filename;
    m_position.x = m_desRect.x;
    m_position.y = m_desRect.y;
    m_width = 16;
    m_height = 32;
    Speed = 1;
    std::string filenameStr  = filename;


    m_srcRect = {0,0,m_width,m_height};
    m_desRect = {0,0,m_width,m_height};
    m_isStaticSprite = true;
    m_isAnimationSprite = false;
}
void MarioPlayer::Draw()
{

//    for(int i = 0; i  < m_blocks.size(); i++)
//    {   if(!m_blocks[i]->Dead())
//  TextureManager::Instance()->DrawLine( m_position.x,m_position.y,m_blocks[i]->GetPosition().x,m_blocks[i]->GetPosition().y, Game::Instance()->GetRenderer());
//
//    }



if(isBinking())
{

    if(!m_bDead)
    {
        m_desRect.x = m_position.x;
        m_desRect.y = m_position.y;
        TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,m_Flip);

    }
    else if(!m_bDead)
    {
        TextureManager::Instance()->SDLDraw( Game::Instance()->GetRenderer(),Texture(),&m_srcRect, &m_desRect,0,0,m_Flip);

    }
    SDL_Colour s = Game::Instance()->GetWindow()->GetColour();
    Game::Instance()->GetWindow()->SetColour(255,255,255,0);
    if(m_DownReleased)
    {

        TextureManager::Instance()->DrawLine(GameObject::bottomLeft().x,GameObject::bottomLeft().y,GameObject::BottomRight().x,GameObject::BottomRight().y,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawLine(GameObject::topLeft().x,GameObject::topLeft().y,GameObject::topRight().x,GameObject::topRight().y,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawLine(GameObject::topLeft().x,GameObject::topLeft().y, GameObject::bottomLeft().x,GameObject::bottomLeft().y,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawLine(GameObject::topRight().x,GameObject::topRight().y,GameObject::BottomRight().x,GameObject::BottomRight().y,Game::Instance()->GetRenderer());

        TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::BottomRight().x,GameObject::BottomRight().y,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::bottomLeft().x,GameObject::bottomLeft().y,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::topRight().x, GameObject::topRight().y,Game::Instance()->GetRenderer());
        TextureManager::Instance()->DrawLine(GameObject::Centre().x,GameObject::Centre().y,GameObject::topLeft().x,GameObject::topLeft().y,Game::Instance()->GetRenderer());
    }
    Game::Instance()->GetWindow()->SetColour(0,0,0,0);
    Game::Instance()->GetWindow()->SetColour(s.r,s.g,s.b,s.a);
}
}

void MarioPlayer::Update()
{
    m_count++;
    if(m_count> 100)
        m_count = 0;
    if(m_count==100)
    {

if(m_bisBlinking)
{
    m_bisBlinking =false;
}
else m_bisBlinking = true;
     }      m_velocity.y = 0;

 if(m_position.y > Game::Instance()->GetWindowHeight())
    {
        m_position.y = 0;
    }

//m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//        m_position.y -= m_force * Game::Instance()->GetDeltaTime();

    updateMovements();

    float dt = Game::Instance()->GetDeltaTime();
//std::cout << "sdsds\n " << dt << "\n"

    OnKeyBoardEvent();


    if(isFailling())
    {
        m_force.y  = m_mass *  m_gravity * dt;
        m_velocity -= m_force;
 }
//
//    m_acceleration = m_force / m_mass;
////Acceleration = force / mass
//
////Velocity = velocity + acceleration * deltaTime
//
////Position = position + velocity * deltaTime

    m_velocity.x  += m_acceleration.x * dt;

    // m_velocity.x *= 0.9;
    m_position -= m_velocity ;


//
}

void MarioPlayer::updateMovements()
{

}

void MarioPlayer::OnKeyBoardEvent()
{
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {

        m_Flip = SDL_FLIP_NONE;
        m_acceleration.x -= 0.051;
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {

        m_position.y -= 20;
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_DownPressed = true;
        m_DownReleased = false;
    }
    else
    {

        m_DownPressed = false;
        m_DownReleased = true;
    }

//        if(m_bisGrounded)
//        {
//            m_bisDucking = true;
//        }
//        if(m_bisDucking)
//        {
//
//m_srcRect = {16,16,16+16,16};
//        }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_Flip = SDL_FLIP_HORIZONTAL;
        m_acceleration.x  += 0.051;
    }

}
void MarioPlayer::UpdateGravity()
{

    float dt = Game::Instance()->GetDeltaTime();


}

bool MarioPlayer::isFailling()
{
        return !m_bisGrounded;

}
std::string MarioPlayer::getState()
{

    switch(m_marioState)
    {
    case SMALLMARIO:
        return "SmallMario";
        break;
    case BIGMARIO:
        return "BigMario";
        break;
    case STARMARIO:
        return "StarMario";
        break;
    case FIREMARIO:
        return "FireMario";
        break;

    }
}
std::string MarioPlayer::getAnmationState()
{
    switch(m_marioAnmationState)
    {
    case IDLE:
        return "IDLE";
        break;
    case DUCKING:
        return "DUCKING";
        break;
    case STANDING:
        return "STANDING";
        break;
    case JUMMPING:
        return "JUMMPING";
        break;
    case RUNNING_LEFT:
        return "RUNNING_LEFT";
        break;
    case RUNNING_RIGHT:
        return "RUNNING_RIGHT";
        break;
    case SLIDING_LEFT:
        return "SLIDING_LEFT";
        break;
    case SLIDING_RIGHT:
        return "SLIDING_RIGHT";
        break;
    case FAILING:
        return "FAILING";
        break;

    }
}
//dtor


//    m_currentFrame = (((SDL_GetTicks()/m_frameRate)%m_numFrame+1));
//   m_currentFrame = (((SDL_GetTicks()/m_frameRate)%m_numFrame+1));


//   m_lastPos = m_position;
//
//    if(m_oldTime + m_frameRate < SDL_GetTicks())
//    {
//        m_currentFrame++;
//        m_oldTime = SDL_GetTicks();
//    }
//    if(m_currentFrame == m_maxFrame)
//    {
//        m_currentFrame = 0;
//    }
//    // m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//    // m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
//
//m_force -= m_mass * m_gravity * dt
//
//    m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
//    m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
//
//
//
//
//    m_velocity += m_acceleration * Speed *= Game::Instance()->GetDeltaTime();
//    m_position +=  m_velocity;
////
//if(m_position.y>=Game::Instance()->GetWindowHeight())
//{
//    m_position.y =0;

//VEL + acc + dt
//pos  += vel
//f = MA;
//
////        velocity += acceleration *= Game::Instance()->GetDeltaTime();
////        m_velocity.x = velocity*= 0.99;
////        m_position +=  m_velocity;
//    m_force += m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
////           m_velocity.y = m_force * Game::Instance()->GetDeltaTime();
////            //    m_position.y -= m_force * Game::Instance()->GetDeltaTime();
////        } m_force -= 1;
////        m_force -= m_mass *  m_gravity * Game::Instance()->GetDeltaTime();
////        m_position.y -= m_force * Game::Instance()->GetDeltaTime();
////        velocity += acceleration *= Game::Instance()->GetDeltaTime();
//    float l_dt= Game::Instance()->GetDeltaTime();
//m_velocity  -= m_acceleration + l_dt*2;
//m_position  -= m_velocity;
