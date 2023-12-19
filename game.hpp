#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

#include "paddle.hpp"
#include "ball.hpp"


class Game {
public:
    Game();
    ~Game();
    bool init();
    void run();
    void handleEvents();
    void update();
    void render();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Paddle paddle1, paddle2;
    Ball ball;
    int score1, score2;
    // SDL related members
};