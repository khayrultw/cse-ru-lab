#include "display.h"

#define point std::complex<float>

Display::Display(int height, int width, std::string title)
{
    _width = width;
    _height = height;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    _window = SDL_CreateWindow(

        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        height, width,
        SDL_WINDOW_OPENGL
    );
    _glcontext = SDL_GL_CreateContext(_window);
    GLenum status = glewInit();
    if(status!=GLEW_OK){

        std::cerr << "Glew fail" << std::endl;
    }
    _isClosed = false;
}

Display::~Display()
{
    SDL_GL_DeleteContext(_glcontext);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Display::update(){

    SDL_GL_SwapWindow(_window);
    while(SDL_PollEvent(&_event)){

        if(_event.type==SDL_QUIT)
            _isClosed = true;
    }
}

bool Display::isClosed(){

    return _isClosed;
}

void Display::clear(float r, float g, float b, float a){

    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::drawPoint(point z){

    glBegin(GL_POINTS);
        glVertex2d(z.real(), z.imag());
    glEnd();
}
void Display::drawLine(point a, point b){

    glBegin(GL_LINES);
        glColor4f(1.0, 0.0, 0.0, 1.0);
        glVertex2d(a.real()/_width, a.imag()/_height);
        glVertex2d(b.real()/_width, b.imag()/_height);
    glEnd();
}

void Display::drawCircle(float a, float b, float redius){

    for(float x = -redius; x <= redius; x = x+0.01){

        float y = sqrt(redius*redius-x*x);
        glBegin(GL_POINTS);
            glVertex2d(a/_width+x/_width, b/_width+y/_width);
            glVertex2d(a/_width+x/_width, b/_width-y/_width);
        glEnd();
    }
}
