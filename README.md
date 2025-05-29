# cse-ru-lab

### Packages to install
sudo apt install libglew-dev libsdl2-dev freeglut3-dev

### To run
g++ main.cpp src/*.cpp -o out `sdl2-config --cflags --libs` -I./include
