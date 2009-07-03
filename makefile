#
#`wx-config --cxxflags` `wx-config --libs`
CC = g++

CFLAGS := -Wall `sdl-config --cflags` 
LIBS := `sdl-config --libs`
COMPILE = $(CC) 



all: Linux



Linux: 

	$(COMPILE) main.cpp SDLwindow.cpp timer.cpp -o Execute/stars2Lin.out $(CFLAGS) $(LIBS)


Win:

	$(COMPILE) main.cpp SDLwindow.cpp timer.cpp -o Execute/stars2Win.exe -lmingw32 $(CFLAGS) $(LIBS)

OSX: 

	$(COMPILE) main.cpp SDLwindow.cpp timer.cpp -o Execute/stars2OSX $(CFLAGS) $(LIBS)

