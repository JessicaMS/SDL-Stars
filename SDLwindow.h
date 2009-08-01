//-----------------------------------------------------------------
// Window controls for a game engine.
// C++ Header - SDLWindow.h
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
//#include <windows.h>
#include "SDL/SDL.h"

//Our window
class Window
{
    private:
    //Whether the window is windowed or not
    bool windowed;
	//Window properties
	int screenWidth, screenHeight, screenBPP;
	//What the window shall display
	//SDL_Surface *screen;

    //Whether the window is fine
    bool windowOK;

    public:
	
	SDL_Surface *screen;
    //Constructor
    Window(int screenWidth, int screenHeight, int screenBPP);

    //Handle window events
    void handle_events(SDL_Event &event);

    //Turn fullscreen on/off
    void toggle_fullscreen();

    //Check if anything's wrong with the window
    bool error();

	
};
