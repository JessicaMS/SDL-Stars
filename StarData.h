
#define StarData

#include "SDLwindow.h"
#include "SDL/SDL.h"
#include <math.h>

class cStarData
{
private:
	int starSize;
	float starVelocity;
	float x,y;
	int width, height;


public:
	bool Initialize(int width, int height);
	bool Initialize();
	bool Draw(SDL_Surface* screen);
	void moveStar(int mouseX, int mouseY, int ticks);
};

