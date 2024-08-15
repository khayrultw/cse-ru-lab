#include <bits/stdc++.h>
#include <SDL2/SDL.h>

using namespace std;

#define Pair pair<float, float>

Pair operator-(const Pair &a, const Pair &b){
    float x = a.first -  b.first;
    float y = a.second - b.second;
    return make_pair(x, y);
}


Pair operator+(const Pair &a, const Pair &b){
    float x = a.first +  b.first;
    float y = a.second + b.second;
    return make_pair(x, y);
}

int main(){

    freopen("bomber.txt", "r", stdin);
    pair<float,float> bomber, fighter;
    cin >> bomber.first >> bomber.second;
    cin >> fighter.first >> fighter.second;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cerr << "ERROR" << endl;
        return 0;
    }
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);

    float x, y;
    while(cin >> x >> y){
        Pair unit, next, tmp;
        next = make_pair(x, y);
        unit = next - bomber;

        float c = sqrt(unit.first*unit.first + unit.second*unit.second);
        unit.first /= c;
        unit.second /= c;
        //cout << unit.first << " " << unit.second << endl;
        while(true){
            //cout << bomber.first << " " << bomber.second << endl;
            tmp = next - bomber;
            if(sqrt(tmp.first*tmp.first + tmp.second*tmp.second) < 3)
                break;

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            int z = 5;
            while(z--){
                bomber = bomber + unit;
                SDL_RenderDrawPoint(renderer, (int)bomber.first, (int)bomber.second);
            }

            tmp = bomber - fighter;
            c = sqrt(tmp.first*tmp.first + tmp.second*tmp.second);
            if(c < 5){
                cout << "win" << endl;
                goto STOP;
            }
            tmp.first /= c;
            tmp.second /= c;
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            z = 4;
            while(z--){
                fighter = fighter + tmp;
                SDL_RenderDrawPoint(renderer, (int)fighter.first, (int)fighter.second);
            }

            SDL_RenderPresent(renderer);
            SDL_Delay(50);
        }
    }
    STOP:
    bool isRunning = true;
    while(isRunning){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                isRunning = false;
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
