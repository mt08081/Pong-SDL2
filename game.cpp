#include "game.hpp"


Game::Game() : window(nullptr), renderer(nullptr){}

Game::~Game()
{
    // Destroy renderer
    if (renderer != nullptr)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    // Destroy window
    if (window != nullptr)
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    // Quit SDL subsystems
    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

bool Game::init()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }

    // If everything initialized fine
    return true;
}

void Game::run()
{
    // while game is running
    //     handle events
    //     update
    //     render
}

void Game::handleEvents()
{
    // while there are events
    //     if event is quit
    //         quit game
    //     if event is keydown
    //         if key is up
    //             move paddle1 up
    //         if key is down
    //             move paddle1 down
    //         if key is w
    //             move paddle2 up
    //         if key is s
    //             move paddle2 down
}

void Game::update()
{
    // move ball
    // check collision between ball and paddle1
    // check collision between ball and paddle2
    // check collision between ball and top wall
    // check collision between ball and bottom wall
    // check collision between paddle1 and top wall
    // check collision between paddle1 and bottom wall
    // check collision between paddle2 and top wall
    // check collision between paddle2 and bottom wall
    // check if ball is out of bounds
}

void Game::render()
{
    // clear screen
    // render paddle1
    // render paddle2
    // render ball
    // render score1
    // render score2
    // update screen
}