#
CC = g++

CFLAGS := -Wall `sdl-config --cflags` 
LIBS := `sdl-config --libs`
COMPILE = $(CC) 



all: Linux
clean: Clean



Linux: 

	$(COMPILE) main.cpp SDLwindow.cpp StarList.cpp StarData.cpp timer.cpp -o Execute/stars3Lin.out $(CFLAGS) $(LIBS)


Win:

	$(COMPILE) main.cpp SDLwindow.cpp StarList.cpp timer.cpp -o Execute/stars3Win.exe -lmingw32 $(CFLAGS) $(LIBS)

OSX: 

	$(COMPILE) main.cpp SDLwindow.cpp StarList.cpp timer.cpp -o Execute/stars3OSX $(CFLAGS) $(LIBS)


Clean:

	rm ./Execute/stars3Lin.out

