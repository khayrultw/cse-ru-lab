#include <iostream>
#include "screen.h"
#include "rectangle.h"

using namespace std;

int main()
{
    Screen screen;
    Rectangle rect;
    if(!screen.init()){

        cout << "Error initializing SDL" << endl;
        return 1;
    }
    rect.initObj(200, 200, 300, 300, 0x0000ff);
    rect.drawObj(screen);
    screen.update();

    SDL_Delay(1000);
    screen.clearScreen();
    rect.tranlateObj(screen, 100, 100);
    screen.update();

    SDL_Delay(1000);
    screen.clearScreen();
    rect.scaleObj(screen, 2,1.5);
    screen.update();

    SDL_Delay(1000);
    for(int i = 0; i < 360; i++){


    }
    int color[] = {0xff0000, 0x00ff00, 0x0000ff};
    bool quit = false;
    SDL_Event event;
    int i, j;
    i = j = 0;
    while(!quit){

        screen.clearScreen();
        rect.rotateObj(screen, 250, 250, i);
        SDL_Delay(50);
        i++;
        while(SDL_PollEvent(&event)!=0){

            if(event.type==SDL_QUIT)
                quit = false;
            if(event.type==SDL_KEYDOWN){

                j = (j+1)%3;
                rect.color = color[j];
            }
        }
        screen.update();
    }
    screen.close();
    return 0;
}
