/*
	Stars2 Application by Jessica Seibert
	1/31/09/
	
	A second version of my prior Stars application.  This time, the stars
	are drawn with a more platform independent SDL_FillRect, and
	is encapsulated into a single header file.

      _._
    .    ` .
   .       `.
   .________.
    `""``""'
      `  `		
 	 :  :	
       :  :		
       ;  ;		
      .  .		
     '  .
    '  .
   .  .
   ;  :
  .    .
 '      ' mh


*/

//The headers
#include <iostream>

#include "SDL/SDL.h"

#include <string>
#include <math.h>

//Local includes
#include "timer.h"
#include "SDLwindow.h"
#include "StarList.h"
#ifndef StarData
	#include "StarData.h"
#endif


//Global types and constants
#define WANT_TASTY_MUSHROOM 1 //Always


//The screen sttributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;



//Initialize whatever you must
bool GameInitialize()
{

	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		return false;	
	}
	
	//If everything initialized fine
	return true;
}


//❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤
//function:  main
//
//The land of tasty mushrooms.  Accepts no arguments. 
//❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤
int main( int argc, char* args[] )
{
	SDL_Event event;		//The event structure
    	Timer delta;    		//Keeps track of time
	bool quit = false; 		//Quit flag
	int msy, msx;
	int ticks = 0;			//Save the ticks!
	cStarList* myStars;
	myStars = new cStarList(100, 640, 480);

	delta.start();
	
  	Window myWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, "Stars!");
   
	//Initialize SDL and stuff
	if( GameInitialize() == false)
	{
		fprintf(stderr, "GameInitialize() failed: %s\n", SDL_GetError());
		return 1;
	}

	msy = msx = 0;
	srand(delta.get_ticks());
	delta.start();

	//While the user hasn't quit
	while(WANT_TASTY_MUSHROOM && !quit)
	{   
		//While there are events to handle
		while( SDL_PollEvent( &event ) )
		{
			//Handle window events
			myWindow.handle_events(event);
			//Check for ESCAPE key...  oh yeah, touch it
			if( event.key.keysym.sym == SDLK_ESCAPE)
			{
				  quit = true;
			}
			//OS-level quit signal, deal with it!
			if( event.type == SDL_QUIT )
			{
				quit = true; //Quit the program
			}
			
				
			//If the mouse moved
			if( event.type == SDL_MOUSEMOTION )
			{
				//Get the mouse offsets
				msx = event.motion.x;
				msy = event.motion.y;
			}

		}

		myStars->MoveStars(msx, msy, ticks);


		SDL_FillRect( myWindow.screen, & myWindow.screen->clip_rect, SDL_MapRGB( myWindow.screen->format, 0x00, 0x00, 0x00 ) );
		SDL_FillRect( myWindow.screen, & myWindow.screen->clip_rect, SDL_MapRGB( myWindow.screen->format, 0x00, 0x00, 0x00 ) );
		myStars->DrawStars( myWindow.screen);

		//Update the screen
		if( SDL_Flip( myWindow.screen ) == -1 )
		{
			fprintf(stderr, "SDL_Flip() failed: %s\n", SDL_GetError());
			return 1;	
		}

		ticks = delta.get_ticks();
		delta.start();
	} //Farewell, game!


	//myWindow.CleanUp();

	//Clean up
	delete myStars;

	 SDL_Quit();
	fprintf(stdout, "Normal Quit: %s\n",  SDL_GetError());

	return 0;    
}


