#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <sstream>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
class Window
{
public:
    Window();
    virtual ~Window();
    bool init(const char* title,int xpos,int ypos,int w,int h,float RefreshRate,float resScaler,bool fullscreen,int Tile,int column,int row);
    int GetCentre();
    SDL_Renderer *GetRender();
    SDL_Window *GetWindow();
    const  char* GetTitle();
    int getWidth();
    int getCentreWidth();
    int getCentreHight();
    int getColumn();
    int getRow();
    int getHeight();
    int getTile();
    float getAspectRaito();
    bool IsFocus();
SDL_Colour m_oldColour;
    bool IsFullScreen();
    bool IsMinimize();
    bool IsMouseFocus();
    bool IsKeyboardFocus();
    void IsResizable(bool Resizeable);
SDL_Color GetColour();



    void Free();
    void HandleEvent(SDL_Event& e);
    void SetWindowTitle(char *title);
    void SetColour(char r,char g, char b, char a);
    void SetPosition(int x, int y);
    void SetFrameStart();
    void ClearDisplay();
    void ResizeWindow(int w,int h);
    void RescaleWindow(float  s);
    void RenderPresent();
    void HasWINDOWEVENT_LEAVE();
    void HasWINDOWEVENT_ENTER();
    void ToggleGrid();

protected:

private:

    void DisplayGrid();
    int m_height;
    int m_maxHieght;
    int m_maxWidth;
    int m_RefreshRate;
    int m_width;
    int m_Tile;
    int m_column;
    int m_row;
    float m_aspectRaito;
    float m_resolutionScaler;
    void update();
    char *title;
    SDL_DisplayMode g_dm;
    SDL_Window *g_Window;
    SDL_Renderer *g_Renderer;
    bool m_BShowGrid;
    bool m_bReSizeable;
    bool m_fullScreen;
    bool m_Minimize;
    bool m_MouseFocus;
    bool m_KeyboardFocus;
};

#endif // WINDOW_H


//#define WINDOW_SCALE 1
//#define WINDOW_HEIGHT  720
//#define WINDOW_WIDTH 1280




