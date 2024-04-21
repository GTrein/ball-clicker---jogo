
#include "target.h"
#include <raylib.h>
#include "game.h"
#include <iostream>


const float gravity = .1;

Target::Target()
{

}
Target::Target(float x, float y, int radius, float speed_x, float speed_y, int color)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
    this->color = color;


}

Sound hit;
Sound gameOver;
void Target::LoadSound2()
{
    hit = LoadSound("assets/hit.wav");
    gameOver = LoadSound("assets/gameover.mp3");
}

void Target::PlaySoundHit()
{
    PlaySound(hit);
}
void Target::PlaySoundGameOver()
{
    PlaySound(gameOver);
}


void Target::Update()
{

    x += speed_x;
    y += speed_y;
    speed_y += gravity;

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
    {
        speed_x *= -1;
    }


   

}


void Target::Draw()
{
 
    Color colorTop = RED;
    Color colorBottom = BLUE;

   
    float relativeY = (y - radius) / static_cast<float>(GetScreenHeight());

    unsigned char red = static_cast<unsigned char>((1.0f - relativeY) * colorBottom.r + relativeY * colorTop.r);
    unsigned char blue = static_cast<unsigned char>((1.0f - relativeY) * colorBottom.b + relativeY * colorTop.b);
   


    Color colorCircle = { red, 100, blue, 230 };


    DrawCircle(x, y, radius, colorCircle);
}

float Target::GetY()
{
    return y;
}
float Target::GetX()
{
    return x;
}
int Target::GetRadius()
{
    return radius;
}
float Target::GetSpeedY()
{
    return speed_y;
}
float Target::GetSpeedX()
{
    return speed_x;
}



