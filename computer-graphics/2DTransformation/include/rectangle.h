#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "screen.h"

class Rectangle
{
    public:
        int color;

    private:
        int x1, y1, x2, y2;

    public:

        Rectangle();
        void drawObj(Screen &screen);
        void scaleObj(Screen &screen, float xs, float ys);
        int rotateObj(Screen &screen, int xr, int yr, int theta);
        int tranlateObj(Screen &screen, int xt, int yt);
        void initObj(int x1, int y1, int x2, int y2, int color);
        void setColor(int color);

};

#endif // RECTANGLE_H
