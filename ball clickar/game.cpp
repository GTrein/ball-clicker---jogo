#include <iostream>
#include "game.h"
#include <raylib.h>
#include <ctime>
#include "target.h"
#include<cstdlib>


int score;
using namespace std;
Game::Game()
{

}
Target target;
vector<Target> targets;
Bomb bomb;



void Game::NewTarget()
{


	int targetXPos = rand() % 1180 + 50;
	int targetXSpeed = rand() % 21 - 10;
	int targetYSpeed = rand() % 6 + 6;


	targets.push_back(Target(targetXPos, 700, target.GetRadius(), targetXSpeed, targetYSpeed * -1, 1));

}

void Game::NewBomb()
{


	int bombXPos = rand() % 1180 + 50;
	int bombXSpeed = rand() % 21 - 10;
	int bombYSpeed = rand() % 6 + 6;


	bomb = Bomb(bombXPos, 700, 40, bombXSpeed, bombYSpeed * -1);

	

}

void Game::RemoveBomb() {
	
	bomb.SetY(1000);
}



void Game::Level()
{


	
	NewTarget();


}

int distance(Target target) {
	int distanceX = target.x - GetMouseX();
	int distanceY = target.y - GetMouseY();

	return sqrt(distanceX * distanceX + distanceY * distanceY);
}

bool circleOverlap(Target target) {
	

	if (distance(target) < target.radius) {
		return true;
	}
	else {
		return false;
	}

}

int distanceBomb(Bomb bomb) {
	int distanceX = bomb.x - GetMouseX();
	int distanceY = bomb.y - GetMouseY();

	return sqrt(distanceX * distanceX + distanceY * distanceY);
}

bool circleOverlapBomb(Bomb bomb) {


	if (distanceBomb(bomb) < bomb.radius) {
		return true;
	}
	else {
		return false;
	}

}



void Game::Run() {
	bool nextLevel = true;
	bool gameOver = true;
	int ballsPopped = 0;
	int BallsPerLevel = 0;
	int bombSpawn = 0;
	SetTargetFPS(60);
	Color background = { 20, 20, 40, 255 };
	while (!WindowShouldClose()) {
		BeginDrawing();
		
		ClearBackground(background);

		


		if (gameOver) {

			RemoveBomb();
			targets.clear();


			targets.push_back(Target(GetScreenWidth() / 2, GetScreenHeight() / 2, 50, 0, 0, 0));
			if (circleOverlap(targets[0]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				score++;
				ballsPopped++;

				// Remove o alvo clicado da lista
				targets.erase(targets.begin());
				target.PlaySoundHit();


				gameOver = false;
				ballsPopped = 1;
				BallsPerLevel = 0;
				nextLevel = true;
				score = 0;

			}

		}

		//proximo nivel
		if (nextLevel)
		{
			nextLevel = false;

			bombSpawn = rand() % 2;

			RemoveBomb();
			if(bombSpawn == 0)
			NewBomb();
			for (int i = 0; i <= BallsPerLevel; i++) {
				Level();

			}
			BallsPerLevel++;
			ballsPopped = 0;
		}


		if (ballsPopped == BallsPerLevel)
			nextLevel = true;

		
		if (bomb.GetY() > 2000)
		{
			RemoveBomb();
		}

		bomb.Draw();
		bomb.Update();
		for (int i = targets.size() - 1; i >= 0; i--) {
			if (circleOverlap(targets[i]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				score++;
				ballsPopped++;


				targets.erase(targets.begin() + i);
				target.PlaySoundHit();
			}
			else {
				targets[i].Update();
				targets[i].Draw();
				

				if (circleOverlapBomb(bomb) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					RemoveBomb();
					bomb.Sound();
					gameOver = true;
					
				}

				if (targets[i].GetY() - targets[i].GetRadius() > GetScreenHeight())
				{
					target.PlaySoundGameOver();
					gameOver = true;
				}
			}
		}





		DrawText(TextFormat("Level: %01i", BallsPerLevel), 20, 20, 20, ORANGE);
		
	

		

		EndDrawing();
	}

}


