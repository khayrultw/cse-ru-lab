#ifndef PARTICLE_H
#define PARTICLE_H

#include <cmath>

#include "screen.h"


class Particle
{
    public:

    private:
        float x, y;
        float dir, speed;
        Uint8 r, g, b;

    public:
        Particle();
        virtual ~Particle();
        void update();
        void draw(Screen &screen, int color);
        void init();
};

#endif // PARTICLE_H
