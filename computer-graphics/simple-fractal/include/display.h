#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <iostream>
#include <GL/glew.h>
#include <complex>

#define point std::complex<float>


class Display
{

    private:
        int _width, _height;
        SDL_Window *_window;
        SDL_GLContext _glcontext;
        SDL_Event _event;
        bool _isClosed;

    public:
        Display(int width, int height, std::string title);
        virtual ~Display();
        void update();
        bool isClosed();
        void clear(float r, float g, float b, float a);
        void drawLine(point a, point b);
        void drawCircle(float a, float b, float redius);
        void drawPoint(point z);
};

#endif // DISPLAY_H
