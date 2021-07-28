#include "TestState.h"

TestState::TestState()
{
o = vec2f(Game::Instance()->GetWindowWidth()/2,Game::Instance()->GetWindowHeight()/2);

}
TestState::~TestState()
{
    //dtor
}
void TestState::Render()
{
vec2f x = o ;
x += vec2f(0,40);
TextureManager::Instance()->SetColour(0,0,0,0,Game::Instance()->GetRenderer());
//    TextureManager::Instance()->DrawRect(86,86,16,16,Game::Instance()->GetRenderer());
//    TextureManager::Instance()->DrawRect(88,88,12,12,Game::Instance()->GetRenderer());
//    TextureManager::Instance()->DrawLine(pen_pos.x,pen_pos.y,O.x,O.y,Game::Instance()->GetRenderer());
  TextureManager::Instance()->Drawcircle(Game::Instance()->GetRenderer(),x.x,x.y,10);
   TextureManager::Instance()->Drawcircle(Game::Instance()->GetRenderer(),o.x,o.y,10);
    TextureManager::Instance()->SetColour(125,125,125,0,Game::Instance()->GetRenderer());
}

void TestState::Update()
{



    float dt = Game::Instance()->GetDeltaTime();
}

bool TestState::OnEnter()
{

    return true;
}
bool TestState::onExit()
{
    std::cout<< "Exiting : "<< GetStateID() << " \n";
}
void TestState::resume()
{
    std::cout<< "Resuming : "<< GetStateID() << " \n";
}

//    m_force1 = m_mass1 * m_gravity * dt;
//    m_force2 -= m_mass2 * m_gravity * dt;
//    vel1 += acc1 *dt;
//    vel2 += acc2 *dt;
//pos1 -= vel1;
//pos1.y *= m_force1;

//    std::cout << pos1.y<< "ss\n";
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
