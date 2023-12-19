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
    window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
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
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    isRunning = true;
    while (isRunning)
    {
        frameStart = SDL_GetTicks();

        handleEvents();
        update();
        render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    // while there are events
    while (SDL_PollEvent(&event))
    {
        // if event is quit
        if (event.type == SDL_QUIT)
        {
            // quit game
            isRunning = false;
        }
        // if event is keydown
        else if (event.type == SDL_KEYDOWN)
        {
            // if key is up
            if (event.key.keysym.sym == SDLK_UP)
            {
                // move paddle1 up
                paddle1.moveUp();
            }
            // if key is down
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                // move paddle1 down
                paddle1.moveDown();
            }
            // if key is w
            else if (event.key.keysym.sym == SDLK_w)
            {
                // move paddle2 up
                paddle2.moveUp();
            }
            // if key is s
            else if (event.key.keysym.sym == SDLK_s)
            {
                // move paddle2 down
                paddle2.moveDown();
            }
        }
    }
}

void Game::update()
{
    // move ball
    // check collision between ball and paddle1
    // check collision between ball and paddle2
    // check collision between ball and top wall
    ball.move(screen_width, screen_height);
    // check collision between ball and bottom wall
    // check collision between paddle1 and top wall
    // check collision between paddle1 and bottom wall
    // check collision between paddle2 and top wall
    // check collision between paddle2 and bottom wall
    // check if ball is out of bounds
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    ball.render(renderer);
    SDL_RenderPresent(renderer);
    // clear screen
    // render paddle1
    // render paddle2
    // render ball
    // render score1
    // render score2
    // update screen
}