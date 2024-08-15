#include "screen.h"
#include <iostream>

Screen::Screen()
{
    window = NULL;
    renderer = NULL;
    buffer = NULL;
    texture = NULL;
}

bool Screen::init(){

    if(SDL_Init(SDL_INIT_VIDEO)<0){

        return false;
    }
    SDL_Window *window = SDL_CreateWindow(

        "welcome",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if(!window){

        SDL_Quit();
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(!renderer){

        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    texture = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STATIC,
        WIDTH, HEIGHT
    );
    if(!texture){

        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        return false;
    }

    buffer = new Uint32[WIDTH*HEIGHT];
    memset(buffer, 0, WIDTH*HEIGHT*sizeof(Uint32));
    return true;
}

void Screen::update(){

    SDL_UpdateTexture(texture, NULL, buffer, WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

bool Screen::processEvents(){

    SDL_Event event;
    while(SDL_PollEvent(&event)){

        if(event.type==SDL_QUIT)
            return false;
    }
    return true;
}

void Screen::close(){

    delete [] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::setPixel(int x, int y, int color){

    int pos = x;
    if(y) pos = (y-1)*WIDTH+x;
    buffer[pos] = color;
}

void Screen::clearScreen(){

    memset(buffer, 0, WIDTH*HEIGHT*sizeof(Uint32));
}
