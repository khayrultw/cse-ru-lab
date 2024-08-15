#include <iostream>
#include <GL/glew.h>
#include <complex>
#include "display.h"

#define H 600
#define W 600
#define point std::complex<float>

void fractal(Display &disp, float x, float y, float redi){

    if(redi<5){

        return ;
    }
    disp.drawCircle(x, y, redi);
    fractal(disp, x+redi, y, redi/2);
    fractal(disp, x-redi, y, redi/2);
    fractal(disp, x, y+redi, redi/2);
    fractal(disp, x, y-redi, redi/2);
}
int k;
void ace(Display &disp, point z){
    k++;
    if(k>10)
        return ;
    std::cout << z << std::endl;
    disp.drawPoint(z);
    point a(-0.05, 0.03);
    ace(disp, z*z+a);
}
int main(){

    Display display(H, W, "Hello");
    display.clear(0, 0, 0, 1);
    // rect.rotateRect(point(200, 200), 1);
    //display.drawRectangle(rect);
    glColor4d(1, 0, 0, 1);
    fractal(display, 10, 10, 300);
    //tree(display, point(0,0), point(0, 100));
    //display.drawCircle(10, 10, 200);
    //k = 0;
    //ace(display, point(0.0, 0.0));
    display.update();
    //Rectangle rect(point(-100, 100), point(-100, -100), point(100, -100), point(100, 100));
    while(!display.isClosed()){

    }
    return 0;
}

