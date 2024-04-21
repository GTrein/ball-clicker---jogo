
#include <iostream>
#include <raylib.h>
#include <cmath>
#include <ctime>
#include "game.h"
using namespace std;

const int screen_width = 1280;
const int screen_height = 720;



int main() {
	Game game;
	Target target;
	Bomb bomb;
	srand(time(0));
	SetTargetFPS(60);

	InitWindow(screen_width, screen_height, "TARGET CLICKER - GABRIEL TREIN");
	InitAudioDevice();
	target.LoadSound2();
	bomb.LoadTextures();
	game.Run();





	CloseWindow();
	return 0;
}


