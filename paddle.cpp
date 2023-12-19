#include "paddle.hpp"
#include "SDL.h"
#include "SDL_image.h"

Paddle::Paddle()
{
    x = 0;
    y = 0;
    speed = 0;
}

void Paddle::moveUp()
{
    y -= speed;
}

void Paddle::moveDown()
{
    y += speed;
}

void Paddle::render()
{
    // render paddle
}

Paddle::~Paddle()
{
    // destroy paddle
}

