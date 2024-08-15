#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <GL/glew.h>


class Screen
{
    public:
        const static int WIDTH = 800;
        const static int HEIGHT = 600;

    protected:

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        Uint32 *buffer;
    public:
        Screen();
        bool init();
        bool processEvents();
        void close();
        void setPixel(int x, int y, int color);
        void update();
        void clearScreen();

};

#endif // SCREEN_H
