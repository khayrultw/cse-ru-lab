#include <cmath>
#include <complex>

#include "circle.h"
#include "screen.h"

#define PI acos(-1)
#define point std::complex<double>

Circle::Circle(int x, int y, int r)
{
    this-> x = x;
    this-> y = y;
    this-> r = r;
}

Circle::~Circle()
{
    //dtor
}

void Circle::draw(Screen &screen, int theta, int color){

    int xr = Screen::WIDTH/2;
    int yr = Screen::HEIGHT/2;
    for(int i = abs(x-r); i < x+r; i++){

        int y1 = abs(y-sqrt(r*r-(i-x)*(i-x)));
        int y2 = abs(y+sqrt(r*r-(i-x)*(i-x)));
        for(int j = y1; j < y2; j++){

            float x = xr+(i-xr)*cos(PI*theta/180)-(j-yr)*sin(PI*theta/180);
            float y = yr+(i-xr)*sin(PI*theta/180)+(j-yr)*cos(PI*theta/180);
            screen.setPixel(x,y, color);
            screen.setPixel(x+0.9, y, color);
            screen.setPixel(x, y+0.9, color);
            screen.setPixel(x+0.9, y+0.9, color);
        }
    }
}

void Circle::clear(Screen &screen, int theta){

    int xr = Screen::WIDTH/2;
    int yr = Screen::HEIGHT/2;
    for(int i = abs(x-r); i < x+r; i++){

        int y1 = abs(y-sqrt(r*r-(i-x)*(i-x)));
        int y2 = abs(y+sqrt(r*r-(i-x)*(i-x)));
        for(int j = y1; j < y2; j++){
            float th = PI*theta/180;
            point a = (point(i, j)-point(xr, yr))*point(cos(th), sin(th))+point(xr, yr);
            float x = a.real();
            float y = a.imag();
            screen.setPixel(x, y, 0);
            screen.setPixel(x+0.9, y, 0);
            screen.setPixel(x, y+0.9, 0);
            screen.setPixel(x+0.9, y+0.9, 0);
        }
    }
}
