/*
	Stars Header File by Jessica Seibert
	Last recorded update: 1/31/09/
	
	

      _._
    .    ` .
   .       `.
   .________.
    `""``""'
      `  `		
	:  :	We are pillars of society. You can't run your computers, your fashion houses,   
       :  :		your publishing houses, your damn magazines, you can't do anything 
       ;  ;		in culture without psychedelic people in key positions. 
      .  .		- Terence McKenna
     '  .
    '  .
   .  .
   ;  :
  .    .
 '      ' mh


*/
#include <SDL/SDL.h>
#include <vector>
#include <math.h>
#ifndef StarData
	#include "StarData.h"
#endif

//❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤
//class:  cStarData
//
//Contains data for each star, as well as a method for moving
//	a star based on mouse coordinates
//❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤


//Initializes the data for a star, and assigns the maximum
//height and width it can travel.

//❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤
//class:  cStarList
//
//Contains all of our stars in a STL vector
//
//❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤`•.¸¸.•´´¯`••.¸¸.•´´¯`•´❤
class cStarList
{
private:
	std::vector<cStarData> vStars;
	int height, width;


public:

	cStarList(int StarCount, int width, int height);
	bool MoveStars(int mouseX, int mouseY, int ticks);
	bool DrawStars(SDL_Surface* screen);
	~cStarList();

};


