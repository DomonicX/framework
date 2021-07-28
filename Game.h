#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <GameStateMachine.h>
#include <random>
#include <time.h>
#include <Window.h>
//SDL_Texture* RenderText(const std::string &message, const std::string &fontFlie, SDL_Color color, int fontSize, SDL_Renderer *render);

class Game
{
public:
    static Game* Instance()
    {
        if(s_pInstance == NULL)
        {
            s_pInstance = new Game();
        }
        return s_pInstance;
    }

    void PushState(GameState* s);
    void ChangeGameState(GameState* s);
    bool Init(const char* title,
              int xpos,
              int ypos,
              int width,
              int height,float RefreshRate,float ResScaler,
              bool fullscreen,int Tile,
              int column,
              int row);
    void Render();
    void Update();
    void HandleEvent(SDL_Event &e );
    void Clean();
    void quit();

    bool running();
    Window* GetWindow();
    SDL_Renderer* GetRenderer() const ;
    GameStateMachine* GetStateMachine()const ;

    SDL_Color m_backGroundColour;
    SDL_Color m_inGroundColour;
    void SetWindowDimension(int w,int h);
    int getRandomNumber();
    int GetWindowHeight();
    int GetWindowWidth();
    float GetDeltaTime();
    float SetDeltaTime(float dt)
    {
        m_deltaTime = dt;
    }

protected:

private:
    float m_deltaTime;
    bool m_bChangingState;
    bool m_blevelComplete;
    bool m_bRunning;
    static Game * s_pInstance;
    Window *m_window;
    GameStateMachine *m_pGameStateMachine;
    Game();
    ~Game();
};




#endif // GAME_H
// const bool getCurrentLevel();
// const bool getLevelCompelte();
// bool changingState();
//void changingState(bool cs);



//
//
//class SoundManager
//{
//public:
//
////    std::map<std::string, *>m_TextureMap;
////};
