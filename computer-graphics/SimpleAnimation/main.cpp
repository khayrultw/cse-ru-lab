#include <cmath>
#include <iostream>
#include "screen.h"
#include "circle.h"
#include "particle.h"


using namespace std;

int main()
{
    Screen screen;
    Circle circle1(Screen::WIDTH/2, Screen::HEIGHT/2, 50);
    Circle circle2(260, 260, 20);
    Circle circle3(180, 200, 25);
    if(!screen.init()){

        cout << "Error initializing SDL" << endl;
        return 1;
    }
    Particle par[1000];
    SDL_Event event;
    int k, j;
    k = j = 0;
    while(true){

        screen.clearScreen();
        for(int i = 0; i < 1000; i++){

            par[i].draw(screen, 0xffffffff);
        }
        k += 2;
        j++;
        circle1.draw(screen,0, 0xff4444cc);
        circle3.draw(screen, j, 0xffaa5555);
        circle2.draw(screen, k, 0xffaa5555);
        screen.update();
        SDL_Delay(20);
        if(!screen.processEvents())
            break;
    }
    screen.close();
    return 0;
}
