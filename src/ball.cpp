#include <raylib.h>

#include "Ball.h"
#include "GameUi.h"


//Variables
void Ball::initVariables()
{
    this-> x = GetScreenWidth()/2;
    this-> y = GetScreenHeight()/2;
    this-> movementSpeed_x = 4.f;
    this-> movementSpeed_y = 4.f;
    this-> radius = 15.f;
    this-> timeSinceLastIncreased = 0;
}

void Ball::initShape()
{
    
}


//Constructor & Destructor
Ball::Ball() : gameUi(nullptr)
{
    initVariables();
    initShape();
}

Ball::~Ball()
{
}


//Modifiers / Setter
void Ball::setGameUi(GameUi * ui)
{
    gameUi = ui;
}


// Functions
void Ball::collision()
{
    //Collision Top or Bottom
    if (y + radius >= GetScreenHeight() || y - radius <= 0)
        movementSpeed_y *= -1;
    
    //Collision Left
    if (x - radius <= 0)
    {
        (*gameUi).increasePlayerScore(1);
        Resetball();

    //Collision Right
    } else if (x + radius >= GetScreenWidth())
    {
        gameUi->increaseCpuScore(1);
        Resetball();
    }
}

void Ball::movement()
{
    x += movementSpeed_x;
    y += movementSpeed_y;
}


void Ball::Resetball()
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speed_choices[2] = {-1, 1};
    movementSpeed_x *= speed_choices[GetRandomValue(0, 1)];
    movementSpeed_y *= speed_choices[GetRandomValue(0, 1)];
}

void Ball::kickdown()
{
    if(IsKeyPressed(KEY_O))
    {
        movementSpeed_x *= 2;
    }
    if(IsKeyPressed(KEY_P))
    {
        movementSpeed_x = 7;
    }
}

void Ball::SpeedIncreaseOverTime()
{
    if (GetTime() - timeSinceLastIncreased >= 30)
    {
        movementSpeed_x*= 2;
        movementSpeed_y *= 2;
    
        timeSinceLastIncreased = GetTime();
    }
}

void Ball::Update()
{

    this->movement();
    this->collision();

    this->kickdown();
    this->SpeedIncreaseOverTime();
}

void Ball::Render()
{
    DrawCircle(x, y, radius, WHITE);
}


