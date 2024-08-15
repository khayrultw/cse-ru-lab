#ifndef CIRCLE_H
#define CIRCLE_H

#include "screen.h"


class Circle
{

    private:
        int x, y, r;
    public:
        Circle(int x, int y, int r);
        virtual ~Circle();
        void draw(Screen &Screen, int theta, int color);
        void clear(Screen &screen, int theta);
};

#endif // CIRCLE_H
