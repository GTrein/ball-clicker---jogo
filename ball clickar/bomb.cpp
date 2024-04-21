
#include "target.h"
#include "bomb.h"
#include <raylib.h>
#include "game.h"
#include <iostream>


const float gravity = .1;

Bomb::Bomb()
{

}
Bomb::Bomb(float x, float y, int radius, float speed_x, float speed_y)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->speed_x = speed_x;
    this->speed_y = speed_y;


}


Texture2D bomb;
Sound explosion;
void Bomb::LoadTextures()
{
    bomb = LoadTexture("assets/bomb.png");
    explosion = LoadSound("assets/explosion.mp3");
}




void Bomb::Update()
{

    x += speed_x;
    y += speed_y;
    speed_y += gravity;

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
    {
        speed_x *= -1;
    }




}

void Bomb::Sound()
{
    PlaySound(explosion);
}


void Bomb::Draw()
{

    DrawTexture(bomb, x-40  ,y-40, WHITE);
}

void Bomb::SetY( float y) {

    this->y = y;
}

int Bomb::GetY() {

    return y;
}
