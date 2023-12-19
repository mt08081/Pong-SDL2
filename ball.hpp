// ball.hpp
#include "SDL.h"
#include "SDL_image.h"
#include <cmath>

class Ball {
public:
    Ball();
    ~Ball();
    void move(int windowWidth, int windowHeight);
    void render(SDL_Renderer* renderer);
private:
    int x, y, speed, radius;
    float direction;
    // SDL related members
};