#include <bits/stdc++.h>
#include <SDL2/SDL.h>
using namespace std;

#define Pair pair<float, float>

int main(){

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cerr << "ERROR" << endl;
        return 0;
    }
    Pair origin = make_pair(100, 500);
    float a0, b0, c0, k1, k2;
    k1 = 0.0009;
    k2 = 0.00009;
    a0 = 300;
    b0 = 250;
    c0 = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);

    for(float i = 0; i <= 600; i+=1){

        //float y1 = 300*pow(10, -i/600);
        //float y2 = 300 - y1;
        float z1 = a0+(k1*c0 - k2*a0*b0)*i/600;
        float z2 = b0+(k1*c0 - k2*a0*b0)*i/600;
        float z3 = c0+(2*k2*a0*b0 - 2*k1*c0)*i/600;
        a0 = z1;
        b0 = z2;
        c0 = z3;
        cout << z1 << " " << z2 << " " << z3 << endl;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(renderer, origin.first, origin.second, 100, 50);
        SDL_RenderDrawLine(renderer, origin.first, origin.second, 700, 500);
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, (int)(i+origin.first), (int)(origin.second - z1));
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderDrawPoint(renderer, (int)(i+origin.first), (int)(origin.second - z2));
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawPoint(renderer, (int)(i+origin.first), (int)(origin.second - z3));
        SDL_RenderPresent(renderer);
        SDL_Delay(30);
    }
    SDL_RenderPresent(renderer);

    bool isRunning = true;
    while(isRunning){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isRunning = false;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
