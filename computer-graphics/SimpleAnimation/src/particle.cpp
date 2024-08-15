#include "particle.h"
#include "screen.h"
#include <iostream>
#include <cmath>

#define PI acos(-1)


Particle::Particle()
{
    x = rand()%Screen::WIDTH;
    y = rand()%Screen::HEIGHT;
}

void Particle::init(){

}
Particle::~Particle()
{
    //dtor
}

void Particle::update(){

    float xdir = speed*cos(dir);
    float ydir = speed*sin(dir);
    x += xdir;
    y += ydir;
    if(x< 0 || x>Screen::WIDTH) {

        this->init();
    }
    if(y< 0 || y>Screen::HEIGHT){

        this->init();
    }
}

void Particle::draw(Screen &screen, int color){

    screen.setPixel(x, y, color);
    screen.setPixel(x+1, y, 0xff777777);
    screen.setPixel(x-1, y, 0xff777777);
    screen.setPixel(x, y+1, 0xff777777);
    screen.setPixel(x, y-1, 0xff777777);

}
