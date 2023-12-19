#include "ball.hpp"

Ball::Ball()
{
    x = 0;
    y = 0;
    speed = 10;
    direction = 3;
    radius = 10;
}

void SDL_RenderDrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Ball::move(int windowWidth, int windowHeight)
{
    // Update the ball's position based on its speed and direction
    x += speed * cos(direction);
    y += speed * sin(direction);

    // Check if the ball hit the left or right edge of the window
    if (x - radius <= 0 || x + radius >= windowWidth) // Adjust for the radius of the ball
    {
        // Reflect the direction over the y-axis
        direction = M_PI - direction;
        // Correct the position to prevent the ball from getting stuck in the wall
        x = (x - radius <= 0) ? radius : windowWidth - radius;
    }

    // Check if the ball hit the top or bottom edge of the window
    if (y - radius <= 0 || y + radius >= windowHeight) // Adjust for the radius of the ball
    {
        // Reflect the direction over the x-axis
        if (direction > 0)
            direction = 2 * M_PI - direction;
        else
            direction = -direction;
        // Correct the position to prevent the ball from getting stuck in the wall
        y = (y - radius <= 0) ? radius : windowHeight - radius;
    }
}

void Ball::render(SDL_Renderer* renderer)
{
    // Set the color to draw the ball
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color

    // Draw the ball
    SDL_RenderDrawCircle(renderer, x, y, radius); // Use the radius member variable
}

Ball::~Ball()
{
    // destroy ball
}