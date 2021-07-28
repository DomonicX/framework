#include "SettingState.h"


SettingState::SettingState() {}
SettingState::~SettingState() {}
void SettingState::Update() {}
void SettingState::Render()
{
    TextureManager::Instance()->DrawText("FullScreen",0,0,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText("Video",0,16,Game::Instance()->GetRenderer());
    TextureManager::Instance()->DrawText("Audio",0,32,Game::Instance()->GetRenderer());
  TextureManager::Instance()->DrawText("Controls",0,48,Game::Instance()->GetRenderer());
}
bool SettingState::isInsideBox(int x, int y, int w, int h) {}
bool SettingState::clicked() {}
void SettingState::DisplayButtonText() {}
bool SettingState::CheckButtonPress() {}
bool SettingState::isMouseOverButtons() {}

bool SettingState::OnEnter()
{
//   Game::Instance()->GetWindow()->RescaleWindow(2);
//    Game::Instance()->SetWindowDimension(20,20);
    std::cout << GetStateID() << " : onEnter\n\n";
    return true;
}
bool SettingState::onExit()
{
    std::cout << GetStateID() << ": onExit\n";

}
void SettingState::resume()
{
    std::cout << GetStateID() << " : Resume\n";
}
