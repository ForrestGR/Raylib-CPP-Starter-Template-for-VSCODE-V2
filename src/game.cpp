#include <raylib.h>

#include "game.h"
#include "ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"


// Private Functions
void Game::initVariables()
{
    
}

void Game::initWindow()
{
        // const int screen_width = 1280;
        // const int screen_height = 800;
        // InitWindow(screen_width, screen_height, "My Pong Game");
        // SetTargetFPS(144);
}


// Constructor & Destructor
Game::Game()
{
    // this->initWindow();
}

Game::~Game()
{
}


//Functions
void Game::run()
{
        while (!WindowShouldClose())
    {
        BeginDrawing();

        this->update();
        this->render();

        EndDrawing();
    }
}

void Game::update()
{
    this->ball.Update();
    this->player.Update(ball);
    this->cpu.Update(ball);
    this->obstacle.update(ball);
}

void Game::render()
{
    ClearBackground(BLACK);
    DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), WHITE);

    this->ball.Render();
    this->player.Render();
    this->cpu.Render();
    this->obstacle.Render();
}
